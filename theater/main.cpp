#include "theater.h"

int main()
{
	struct time sttime; 
	gettime(&sttime);
	int i,j;//for�� ���� i,j �ʱ�ȭ�Ҷ����
	char key;// khbit Ű �Է� �޴� ����
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
	//////////////���α׷� ���۽ð� ����////////////////////////
	///////////////////////////////////////////////////////////
	p.nowsituation->startTime[0]=sttime.ti_hour; 
	p.nowsituation->startTime[1]=sttime.ti_min; 
	p.nowsituation->startTime[2]=sttime.ti_sec;

	//////////////////////////////////////////////////////
	//////////////�ݺ��� ����//////////////////////////////
	///////////////////////////////////////////////////
	p.location->startX=13;
	p.location->startY=13;
	p.location->endX=13;
	p.location->endY=13;
	
	p.nowsituation->temperature = 25;

	strcpy(p.state->name, "����");
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
		randPerson(&p);//�����մԼ�,������ ��ȭ display
		fflush(stdin);
		if(kbhit())
		{ 
			key=getch(); 
			if(key==ESC) //esc ��������� 
			{
				total(&p);
				break;
			}
			if(key=='1')  // 1��Ű -> �󿵰�
			{ 
				p.location->endX=58; //���� ����
				p.location->endY=11; //���� ����
				move(&p);
				myMovie(&p);
				p.location->startX = 58;
				p.location->startY = 11;
				p.location->endX=58;
				p.location->endY=11; 
			} 
			if(key=='2') // 2��Ű -> ��ǥ��
			{
				p.location->endX=61; //���� ���� 47,22 ��ǥ�� �տ�
				p.location->endY=16; //���� ����
				move(&p);
				myTicket(&p);
				p.location->startX = p.location->endX;
				p.location->startY = p.location->endY;
			}
			if(key=='3') // 3��Ű ->���ع�
			{
				p.location->endX=109; //���� ����
				p.location->endY=16; //���� ����
				move(&p);
				mySnack(&p);
				p.location->startX = p.location->endX;
				p.location->startY = p.location->endY;
			}
			if(key=='4') // 4��Ű -> ������
			{
				p.location->endX=113; //���� ����
				p.location->endY=15; //���� ����
				p.state->gameRoom=1;
				move(&p);
				game(&p);
				p.location->startX = p.location->endX;
				p.location->startY = p.location->endY;
			}
			if(key=='5') // 5��Ű ->ȭ���
			{
				p.location->endX=113; //���� ����
				p.location->endY=10; //���� ����
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
