#include "theater.h"

int main()
{
	struct time sttime; 
	gettime(&sttime);
	int i,j;//for문 변수 i,j 초기화할때사용
	char key;// khbit 키 입력 받는 변수
	char temp[20];
	Head p;
	srand(time(0));

	Room room;
	p.room=&room;
	Movie movie;
	p.movie=&movie;
	State state;
	p.state=&state;
	NowSituation nowsituation;
	p.nowsituation=&nowsituation;
	Location location;
	p.location=&location;

	myInit(&p);

	////////////////////////////////////////////////////////////
	//////////////프로그램 시작시간 대입////////////////////////
	///////////////////////////////////////////////////////////
	p.nowsituation->startTime[0]=sttime.ti_hour; 
	p.nowsituation->startTime[1]=sttime.ti_min; 
	p.nowsituation->startTime[2]=sttime.ti_sec;

	//////////////////////////////////////////////////////
	//////////////반복문 시작//////////////////////////////
	///////////////////////////////////////////////////
	p.location->startX=13;
	p.location->startY=13;
	p.location->endX=13;
	p.location->endY=13;
	
	p.nowsituation->temperature = 25;

	strcpy(p.state->name, "넷조");
	p.state->age = 23;
	p.state->money = 50000;
	
	display(&p);
	while(1)
	{
		gettime(&sttime);
//		gotoxy(2, 6); printf("%d", sttime.ti_hour);
//		gotoxy(2, 7); printf("%d", sttime.ti_min+3);
//		gotoxy(2, 8); printf("%d", sttime.ti_sec);
//		gotoxy(2, 6); printf("%d", p.nowsituation->startTime[0]);
//		gotoxy(2, 7); printf("%d", p.nowsituation->startTime[1]);
//		gotoxy(2, 8); printf("%d", p.nowsituation->startTime[2]);
//		display(&p);
//		move(&p);
		guestInit(&p);
		stateInit(&p);
		guest(&p);
		randPerson(&p);//랜덤손님수,휴지통 변화 display
		fflush(stdin);
		if(kbhit())
		{ 
			key=getch(); 
			if(key==ESC) //esc 눌렀을경우 
			{
				total(&p);
				break;
			}
			if(key=='1')  // 1번키 -> 상영관
			{ 
				p.location->endX=58; //아직 미정
				p.location->endY=11; //아직 미정
				move(&p);
				myMovie(&p);
				p.location->startX = 58;
				p.location->startY = 11;
				p.location->endX=58;
				p.location->endY=11; 
			} 
			if(key=='2') // 2번키 -> 매표소
			{
				p.location->endX=61; //아직 미정 47,22 매표소 앞에
				p.location->endY=16; //아직 미정
				move(&p);
				myTicket(&p);
				p.location->startX = p.location->endX;
				p.location->startY = p.location->endY;
			}
			if(key=='3') // 3번키 ->스넥바
			{
				p.location->endX=109; //아직 미정
				p.location->endY=16; //아직 미정
				move(&p);
				mySnack(&p);
				p.location->startX = p.location->endX;
				p.location->startY = p.location->endY;
			}
			if(key=='4') // 4번키 -> 게임장
			{
				p.location->endX=113; //아직 미정
				p.location->endY=15; //아직 미정
				p.state->gameRoom=1;
				move(&p);
				game(&p);
				p.location->startX = p.location->endX;
				p.location->startY = p.location->endY;
			}
			if(key=='5') // 5번키 ->화장실
			{
				p.location->endX=113; //아직 미정
				p.location->endY=10; //아직 미정
				p.state->restRoom=1;
				move(&p);
				toilet(&p);
				p.location->startX = p.location->endX;
				p.location->startY = p.location->endY;
			}
			display(&p);
		}
		moveStop(&p);
		fflush(stdin);
	}
	return 0;
}
