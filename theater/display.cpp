#include "theater.h"

void display(Head *p)
{
	gotoxy(3,1);textcolor(LIGHTMAGENTA, WHITE);printf(" ●/");
	gotoxy(3,2);printf("/▲");
	gotoxy(3,3);printf(" ∥");
	textcolor(BLACK, WHITE);
	randPerson(p);//렌덤 손님입장수
	gotoxy(16,1);printf("┌※─※─※─※─※─※┐ ");
	gotoxy(16,2);printf("※                      ※ ");
	gotoxy(16,3);printf("│                      │ ");
	gotoxy(16,4);printf("※     에  어  컨       ※ ");
	gotoxy(16,5);printf("│                      │ ");
	gotoxy(16,6);printf("└※─※─※─※─※─※┘");

	gotoxy(45,1);printf("||                                     ||   ");
	gotoxy(45,2);printf("||                                     ||   ");
	gotoxy(45,3);printf("||                                     ||   ");
	gotoxy(45,4);printf("||                                     ||  ");
	gotoxy(45,5);printf("||           영 화 관 입 구            ||   ");
	gotoxy(45,6);printf("||                                     ||   ");
	gotoxy(45,7);printf("||                                     ||   ");
	gotoxy(45,8);printf("=====");textcolor(LIGHTGREEN, WHITE);printf("●//");textcolor(BLACK, WHITE);printf("             ===================== ");
	gotoxy(45,9);printf("     ");textcolor(LIGHTGREEN, WHITE);printf("▲");textcolor(BLACK, WHITE);printf("                      ");
	gotoxy(45,10);printf("     ");textcolor(LIGHTGREEN, WHITE);printf("∥");textcolor(BLACK, WHITE);printf("                      ");

	gotoxy(101,1);printf("┌─────────────────┐");
	gotoxy(101,2);printf("│                                  │ ");
	gotoxy(101,3);printf("│                                  │");
	gotoxy(101,4);printf("│     ");textcolor(LIGHTBLUE, WHITE);printf("●");textcolor(LIGHTRED, WHITE);printf("    ●");textcolor(BLACK, WHITE);printf("         화장실      │");
	gotoxy(101,5);printf("│     ");textcolor(LIGHTBLUE, WHITE);printf("╊");textcolor(LIGHTRED, WHITE);printf("    △");textcolor(BLACK, WHITE);printf("                     │");
	gotoxy(101,6);printf("│     ");textcolor(LIGHTBLUE, WHITE);printf("∩");textcolor(LIGHTRED, WHITE);printf("    ∥");textcolor(BLACK, WHITE);printf("                     │");
	gotoxy(101,7);printf("│                                  │");
	gotoxy(101,8);printf("└────");textcolor(CYAN, WHITE);printf("▶        ◀");textcolor(BLACK, WHITE);printf("───────┘");

	gotoxy(122,10);printf(" ┌──────┐");
	gotoxy(122,11);printf(" │            │");
	gotoxy(122,12);printf(" ");textcolor(LIGHTBLUE, WHITE);printf("★");textcolor(BLACK, WHITE);printf("    게      │ ");
	gotoxy(122,13);printf("               │");
	gotoxy(122,14);printf("               │");
	gotoxy(122,15);printf("       임      │ ");
	gotoxy(122,16);printf("               │ ");
	gotoxy(122,17);printf("               │");
	gotoxy(122,18);printf(" ");textcolor(YELLOW, WHITE);printf("★");textcolor(BLACK, WHITE);printf("    장      │");
	gotoxy(122,19);printf(" │            │");
	gotoxy(122,20);printf(" └──────┘");

	gotoxy(1,22);printf("┌==========※    ※=============┐ ");
	gotoxy(1,23);printf("│                               │ ");
	gotoxy(1,24);printf("│          관  리  실           │");
	gotoxy(1,25);printf("│      ");textcolor(GREEN, WHITE);printf("●           ●");textcolor(BLACK, WHITE);printf("          │");
	gotoxy(1,26);printf("│      ");textcolor(GREEN, WHITE);printf("╊◁=	     //△");textcolor(BLACK, WHITE);printf("        │");
	gotoxy(1,27);printf("│      ");textcolor(GREEN, WHITE);printf("∩           ∥");textcolor(BLACK, WHITE);printf("          │");
	gotoxy(1,28);printf("└===============================┘");
	

	gotoxy(47,22);printf("┌=========");textcolor(CYAN, WHITE);printf("◆           ◆");textcolor(BLACK, WHITE);printf("=========┐ ");
	gotoxy(47,23);printf("||                                 || ");
	gotoxy(47,24);printf("||                                 ||");
	gotoxy(47,25);printf("||             매 표 소            ||");
	gotoxy(47,26);printf("||                                 ||");
	gotoxy(47,27);printf("||                                 ||");
	gotoxy(47,28);printf("└=================================┘");


	gotoxy(100,22);printf("┌∞∞");textcolor(CYAN, WHITE);printf("●              ●");textcolor(BLACK, WHITE);printf("∞∞∞∞∞∞┐ ");
	gotoxy(100,23);printf("∞                        ||        ∞");
	gotoxy(100,24);printf("∞                     ┌=||=┐     ∞");
	gotoxy(100,25);printf("∞       팝 콘 / 음료  │■■│     ∞");
	gotoxy(100,26);printf("∞                     │■■│     ∞");
	gotoxy(100,27);printf("∞                     └──┘     ∞");
	gotoxy(100,28);printf("└∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞┘");

	stateDisplay(p);
}

void stateDisplay(Head *p)
{
	struct time sttime;
	gettime(&sttime);
	gotoxy(1,30);printf("┌───────────────────────────────────────────────────────────────────┐");
	gotoxy(1,31);printf("│	                                                      구매목록									                 │");
	gotoxy(1,32);printf("│┌─────────┐                                                                                                                │");
	gotoxy(1,33);printf("││                  ㅣ      이 름:                                                    영화 제목 :                                     │");
	gotoxy(1,34);printf("││  ㅡㅡㅡ  ㅡㅡㅡ  ㅣ                                                                                                                │");
	gotoxy(1,35);printf("││        ㅣ        ㅣ      나 이:                                                     상 영 관 :            좌    석 :               │");
	gotoxy(1,36);printf("││        ㅣ        ㅣ                                                                                                                │");
	gotoxy(1,37);printf("││      ㅡㅡㅡ      ㅣ      자 산:                  이용목록                          시작 시간 :                /                    │");
	gotoxy(1,38);printf("││                  ㅣ                                                                                                                │");
	gotoxy(1,39);printf("│└─────────┘                                                                                                                │");
	gotoxy(1,40);printf("└───────────────────────────────────────────────────────────────────┘");
	gotoxy(38,33);printf("%s",p->state->name);
	gotoxy(38,35);printf("%d",p->state->age);
	gotoxy(38,37);printf("%d",p->state->money);
	///////////////////////////////////// /////////////
	/////////////////구매목록//////////////////////////
	/////////////////////////////////////////////////////////////
	if(p->state->snack[0]==1)
	{
		gotoxy(55,33);textcolor(12, 15 );printf("팝콘"); textcolor(0 , 15 );
	}
	if(p->state->snack[1]==1)
	{
		gotoxy(60,33);textcolor(12, 15 );printf("콜라");  textcolor(0 , 15 );
	}
	if(p->state->snack[2]==1)
	{
		gotoxy(65,33);textcolor(12, 15 );printf("사이다"); textcolor(0 , 15 );
	}
	if(p->state->snack[3]==1)
	{
		gotoxy(55,35);textcolor(12 , 15 );printf("나쵸");textcolor(0, 15 ); 
	}
	if(p->state->snack[4]==1)
	{
		gotoxy(60,35);textcolor(12  , 15 );printf("오징어");textcolor(0 , 15 ); 
	}
	/////////////////////////////////////////////////////////////////////////
	/////////////////////이용 목록//////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////
	if(p->state->restRoom==1)
	{
		gotoxy(55,39);textcolor(12, 15 );printf("화장실"); textcolor(0 , 15 ); 
	}
	if(p->state->gameRoom==1)
	{
		gotoxy(62,39);textcolor(12, 15 );printf("게임장"); textcolor(0 , 15 ); 
	}
	///////////////////////////////////////////////////////////////////////////////////
	/////////////////////영화이름및 시간,상영관 /////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////
	gotoxy(102,33);printf("%s",p->state->movie_name);
	if(p->state->infoMovie[0]==0)
	{
		gotoxy(100,35);printf("");
	}
	else if(p->state->infoMovie[0]==1)
	{
		gotoxy(102,35);printf("1상영관");
	}
	else if(p->state->infoMovie[0]==2)
	{
		gotoxy(102,35);printf("2상영관");
	}
	else if(p->state->infoMovie[0]==3)
	{
		gotoxy(102,35);printf("3상영관");
	}
	gotoxy(123,35);printf("%d행 %d열", p->state->infoMovie[2],p->state->infoMovie[3]); 
	gotoxy(102,37);printf("%d시 %d분 ",p->state->movieTimeHour,p->state->movieTimeMin);
	if(p->state->movieTimeMin-(int)sttime.ti_min<0)
	{
		gotoxy(120,37);printf("");
	}
	else if(p->state->movieTimeMin-(int)sttime.ti_min>0)
	{
		gotoxy(120,37);printf("%d분뒤시작",p->state->movieTimeMin-(int)sttime.ti_min);
	}
}

void randPerson(Head *p)
{
	struct time sttime;
	gettime(&sttime);

	gotoxy(2,4); printf("%3d / %3d", p->nowsituation->currentNum, p->nowsituation->totalNum);
	gotoxy(2,6); printf("매표상황");
	gotoxy(1,7); printf("1관 1st: "); printf("%2d",p->movie->roomCount[0][0]);
	gotoxy(1,8); printf("    2st: "); printf("%2d",p->movie->roomCount[1][0]);
	gotoxy(1,9); printf("    3st: "); printf("%2d",p->movie->roomCount[2][0]);
	gotoxy(1,10); printf("2관 1st: "); printf("%2d",p->movie->roomCount[0][1]);
	gotoxy(1,11); printf("    2st: "); printf("%2d",p->movie->roomCount[1][1]);
	gotoxy(1,12); printf("    3st: "); printf("%2d",p->movie->roomCount[2][1]);
	gotoxy(1,13); printf("3관 1st: "); printf("%2d",p->movie->roomCount[0][2]);
	gotoxy(1,14); printf("    2st: "); printf("%2d",p->movie->roomCount[1][2]);
	gotoxy(1,15); printf("    3st: "); printf("%2d",p->movie->roomCount[2][2]);
	gotoxy(27,5); printf("%.1lf도",p->nowsituation->temperature);

	if((p->state->movieTimeHour*3600)+(p->state->movieTimeMin*60)+(p->state->movieTimeSec)-((int)(sttime.ti_hour*3600)+(int)(sttime.ti_min*60)+(int)(sttime.ti_sec))<0)
	 {
		 gotoxy(120,37);printf("");
	 }
	 else if(p->state->movieTimeHour*3600+(p->state->movieTimeMin-1)*60+p->state->movieTimeSec<(int)(sttime.ti_hour*3600)+(int)(sttime.ti_min*60)+(int)(sttime.ti_sec)<p->state->movieTimeHour*3600+p->state->movieTimeMin*60+p->state->movieTimeSec)
	 {	
	gotoxy(120,37);printf("%d초뒤시작",60-(int)sttime.ti_sec);
	 }
	 else if(p->state->movieTimeHour*3600+p->state->movieTimeMin*60+p->state->movieTimeSec-((int)(sttime.ti_hour*3600)+(int)(sttime.ti_min*60)+(int)(sttime.ti_sec))>60)
	 {	
	  gotoxy(120,37);printf("%d분뒤시작",p->state->movieTimeMin-(int)(sttime.ti_min));
	 }
	 //////////////////////////////////////////////////////////////////////////
	 /////////////////////상영중표시////////////////////////////////////////
	 /////////////////////////////////////////////////////////////////////
	 if((sttime.ti_min>=p->state->movieTimeMin)&&(sttime.ti_min<=((p->state->movieTimeMin)+1)))
	 {
	  gotoxy(120,37);printf("[ 상 영 중 ]");
	}
	 else
	{
	 gotoxy(120,37);printf("");
	 }
}

void move(Head *p)
{
	int i;
	int sX,sY,eX,eY;
	sX=p->location->startX;
	sY=p->location->startY;
	eX=p->location->endX;
	eY=p->location->endY;
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	////////////////같을때......... 찍어주고 움직일때 지워줘야되는데 그 정확하게 지울수 있는방법 연구해야될뜻..////////////
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	if(sX==eX&&sY==eY)
	{
		gotoxy(sX,sY);printf(" ●");
		gotoxy(sX,sY+1);printf("-│-");
		gotoxy(sX,sY+2);printf(" │");
		gotoxy(sX,sY+3);printf(" ∥");
	}
	
	if(sX<eX) // 오르쪽으로갈때
	{
		for(i=0;i<eX-sX;i++)
		{
			if(i%3==0)
			{
				gotoxy(sX+i,sY);printf("   ●");
				gotoxy(sX+i,sY+1);printf("┌│┘");
				gotoxy(sX+i,sY+2);printf(" │");
				gotoxy(sX+i,sY+3);printf("/＼");
				sX=sX+i;
				Sleep(50);
				clrscr(sX,sY,sX+i,sY+3);  
			}
			else if(i%3!=1)
			{
				gotoxy(sX+i,sY);printf("   ●");
				gotoxy(sX+i,sY+1);printf("└│┐");
				gotoxy(sX+i,sY+2);printf(" │");
				gotoxy(sX+i,sY+3);printf("∥");
				sX=sX+i;
				Sleep(50);
				clrscr(sX,sY,sX+i,sY+3); 
			}
			else if(i%3!=2)
			{
				gotoxy(sX+i,sY);printf("   ●");
				gotoxy(sX+i,sY+1);printf("┌│┘");
				gotoxy(sX+i,sY+2);printf(" │");
				gotoxy(sX+i,sY+3);printf("┘┐");
				sX=sX+i;
				Sleep(50);
				clrscr(sX,sY,sX+i,sY+3); 
			}
			
		}clrscr(sX,sY,sX+i+3,sY+4);
	}
	else
	{
		for(i=0;i<sX-eX;i++)// 왼쪽으로 갈때 x축
		{
			if(i%3==0)
			{
				gotoxy(sX-i,sY);printf("  ●");
				gotoxy(sX-i,sY+1);printf("└│┐");
				gotoxy(sX-i,sY+2);printf("  │");
				gotoxy(sX-i,sY+3);printf(" │＼");
				Sleep(50);
				sX = sX-i;
				clrscr(sX-i,sY,sX+i+3,sY+4);  
			}
			else if(i%3!=1)
			{
				gotoxy(sX-i,sY);printf("  ●");
				gotoxy(sX-i,sY+1);printf("┌│┘");
				gotoxy(sX-i,sY+2);printf("  │");
				gotoxy(sX-i,sY+3);printf("  ∥");
				Sleep(50);
				sX = sX-i;
				clrscr(sX-i,sY,sX+i+3,sY+4);
			}
			else if(i%3!=2)
			{
				gotoxy(sX-i,sY);printf("  ●");
				gotoxy(sX-i,sY+1);printf("└│┐");
				gotoxy(sX-i,sY+2);printf("  │");
				gotoxy(sX-i,sY+3);printf(" ┌ ┘");
				Sleep(50);
				sX = sX-i;
				clrscr(sX-i,sY,sX+i+3,sY+4); 
			}
			
		}clrscr(sX-i,sY,sX+i+1,sY+4);
	}
	if(sY>eY)
	{
		for(i=0;i<sY-eY;i++) //올라갈떄
		{
			if(i%3==0)
			{
				gotoxy(eX,sY-i); printf("  ∥");
				gotoxy(eX,sY-i-1);printf("  │");
				gotoxy(eX,sY-i-2);printf("┌│┘");
				gotoxy(eX,sY-i-3);printf("  ●");
				Sleep(50);
				clrscr(eX,sY-i-3,eX+6,sY-i+3);
				
			}
			else if(i%3!=1)
			{
				gotoxy(eX,sY-i);printf("  ∥");
				gotoxy(eX,sY-i-1);printf("  │");
				gotoxy(eX,sY-i-2);printf("┌│┐");
				gotoxy(eX,sY-i-3);printf("  ●");
				Sleep(50);
				clrscr(eX,sY-i-3,eX+6,sY-i+3);
				
			}
			else if(i%3!=2)
			{
				gotoxy(eX,sY-i);printf("  ∥");
				gotoxy(eX,sY-i-1);printf("  │");
				gotoxy(eX,sY-i-2);printf("└│┐");
				gotoxy(eX,sY-i-3);printf("  ● ");
				Sleep(50);
				clrscr(eX,sY-i-3,eX+6,sY-i+3);
				
			}
		}
	}
	else
	{
		for(i=0;i<eY-sY;i++) //내려갈때
		{
			if(i%3==0)
			{
				gotoxy(eX,sY+i); printf("  ●");
				gotoxy(eX,sY+i+1);printf("┌│┘");
				gotoxy(eX,sY+i+2);printf("  │");
				gotoxy(eX,sY+i+3);printf("  ∥");
				Sleep(50);
				clrscr(eX,sY+i-4,eX+5,sY+i+3);
			}
			else if(i%3!=1)
			{
				gotoxy(eX,sY+i);printf("  ●");
				gotoxy(eX,sY+i+1);printf("┌│┐");
				gotoxy(eX,sY+i+2);printf("  │");
				gotoxy(eX,sY+i+3);printf("  ∥");
				Sleep(50);
				clrscr(eX,sY+i-4,eX+5,sY+i+3);
			}
			else if(i%3!=2)
			{
				gotoxy(eX,sY+i);printf("  ●");
				gotoxy(eX,sY+i+1);printf("└│┐");
				gotoxy(eX,sY+i+2);printf("  │");
				gotoxy(eX,sY+i+3);printf("  ∥");
				Sleep(50);
				clrscr(eX,sY+i-4,eX+5,sY+i+3);
			}
		}
	}
}

void moveStop(Head *p)
{
	int sX,sY,eX,eY;
	sX=p->location->startX;
	sY=p->location->startY;
	eX=p->location->endX;
	eY=p->location->endY;
	
	if(sX==eX&&sY==eY)
	{
		gotoxy(sX,sY);printf(" ●");
		gotoxy(sX,sY+1);printf("-│-");
		gotoxy(sX,sY+2);printf(" │");
		gotoxy(sX,sY+3);printf(" ∥");
	}
	
}

void toilet(Head *p)
{
	if(p->state->restRoom==1)
	{
		gotoxy(124,6);printf("[ 이 용 중 ]");
		Sleep(500);
		clrscr(124,6,132,6);
		gotoxy(124,6);printf("[ 이 용 중 ]");
		Sleep(500);
		clrscr(124,6,132,6);
		gotoxy(124,6);printf("[ 이 용 중 ]");
		Sleep(500);
		clrscr(124,6,132,6);
		
	}
}
void setDisplay(Head *p)
{
	int i,j,k;
	gotoxy(19,2);printf(" ┌────────────────────────────────────────────────┐");
	gotoxy(19,3);printf(" │                                                                                                │");
	gotoxy(19,4);printf(" └────────────────────────────────────────────────┘");
	
	for(i = 10; i < 28; i+=3)
	{
		gotoxy(22,i);printf("┌─┐┌─┐     ┌─┐┌─┐┌─┐┌─┐┌─┐┌─┐┌─┐┌─┐┌─┐┌─┐     ┌─┐┌─┐");
		gotoxy(22,i+1);printf("│  ││  │     │  ││  ││  ││  ││  ││  ││  ││  ││  ││  │     │  ││  │");
		gotoxy(22,i+2);printf("└─┘└─┘     └─┘└─┘└─┘└─┘└─┘└─┘└─┘└─┘└─┘└─┘     └─┘└─┘");
	}
	
	
	if(p->state->infoMovie[0]==1)//1관일때
	{

		for(j=0;j<6;j++)
		{
			for(k=0;k<10;k++)
			{
				if(p->state->infoMovie[1]==1)
				{
					if(p->movie->oneRoom[j][k].firstMovie==1)//1관에 첫번째 영화 
					{
						 textcolor(LIGHTRED,WHITE );
						gotoxy(41+(k*6),11+(j*3));printf("●");
						textcolor(BLACK, WHITE);
				
					}
				}
				else if(p->state->infoMovie[1]==2)
				{
					if(p->movie->oneRoom[j][k].secondMovie==1)//1관에 두번째 영화 
					{
						 textcolor(LIGHTRED,WHITE );
						gotoxy(41+(k*6),11+(j*3));printf("●");
						 textcolor(BLACK, WHITE);
					}
				}
				else if(p->state->infoMovie[1]==3)
				{
					if(p->movie->oneRoom[j][k].thirdMovie==1)//1관에 세번째 영화 
					{
						textcolor(LIGHTRED,WHITE );
						 gotoxy(41+(k*6),11+(j*3));printf("●");
						 textcolor(BLACK, WHITE);
					}
				}
			}
		
		}
	}
	else if(p->state->infoMovie[0]==2)//2관일때
	{

		for(j=0;j<6;j++)
		{
			for(k=0;k<10;k++)
			{
				if(p->state->infoMovie[1]==1)
				{
					if(p->movie->twoRoom[j][k].firstMovie==1)//2관에 첫번째 영화 
					{
						 textcolor(LIGHTRED,WHITE );
						gotoxy(41+(k*6),11+(j*3));printf("●");
						textcolor(BLACK, WHITE);
				
					}
				}
				else if(p->state->infoMovie[1]==2)
				{
					if(p->movie->twoRoom[j][k].secondMovie==1)//2관에 두번째 영화 
					{
						 textcolor(LIGHTRED,WHITE );
						gotoxy(41+(k*6),11+(j*3));printf("●");
						 textcolor(BLACK, WHITE);
					}
				}
				else if(p->state->infoMovie[1]==3)
				{
					if(p->movie->twoRoom[j][k].thirdMovie==1)//2관에 세번째 영화 
					{
						textcolor(LIGHTRED,WHITE );
						gotoxy(41+(k*6),11+(j*3));printf("●");
						 textcolor(BLACK, WHITE);
					}
				}
			}
		
		}
	}
	else if(p->state->infoMovie[0]==3)//3관일때
	{

		for(j=0;j<6;j++)
		{
			for(k=0;k<10;k++)
			{
				if(p->state->infoMovie[1]==1)
				{
					if(p->movie->threeRoom[j][k].firstMovie==1)//3관에 첫번째 영화 
					{
						 textcolor(LIGHTRED,WHITE );
						gotoxy(41+(k*6),11+(j*3));printf("●");
						textcolor(BLACK, WHITE);
				
					}
				}
				else if(p->state->infoMovie[1]==2)
				{
					if(p->movie->threeRoom[j][k].secondMovie==1)//3관에 두번째 영화 
					{
						 textcolor(LIGHTRED,WHITE );
						gotoxy(41+(k*6),11+(j*3));printf("●");
						 textcolor(BLACK, WHITE);
					}
				}
				else if(p->state->infoMovie[1]==3)
				{
					if(p->movie->threeRoom[j][k].thirdMovie==1)//3관에 세번째 영화 
					{
						textcolor(LIGHTRED,WHITE );
						gotoxy(41+(k*6),11+(j*3));printf("●");
						 textcolor(BLACK, WHITE);
					}
				}
			}
		
		}
	}
	textcolor(LIGHTBLUE,WHITE);//내가 산 표
	gotoxy(41+((p->state->infoMovie[3]-1)*6),11+((p->state->infoMovie[2]-1)*3));printf("●");
	textcolor(BLACK, WHITE);

	stateDisplay(p);

	return;


}
void movieDisplay(Head *p)
{ 
	
	textcolor(BLACK,LIGHTMAGENTA);
	gotoxy(1,8);printf("┌─────────────────────┐");
    gotoxy(1,9);printf("│                                          │");
    gotoxy(1,10);printf("│                                          │");
	gotoxy(1,11);printf("│                                          │");
    gotoxy(1,12);printf("│                                          │");
    gotoxy(1,13);printf("│                                          │" );
	gotoxy(1,14);printf("│                 1 관                     │");
	gotoxy(1,15);printf("│                                          │");
    gotoxy(1,16);printf("│          ┌〓〓〓〓〓〓〓┐              │");
	gotoxy(1,17);printf("│          │              │              │");
	gotoxy(1,18);printf("│          │●            │              │");
    gotoxy(1,19);printf("└─────┘▲☞          └───────┘");

	gotoxy(110,1);printf("┌────────────┐");
    gotoxy(110,2);printf("│                        │");
    gotoxy(110,3);printf("│                        │");
	gotoxy(110,4);printf("│                        │");
    gotoxy(110,5);printf("│                        │");
    gotoxy(110,6);printf("│                        │" );
	gotoxy(110,7);printf("│                        │");
	gotoxy(110,8);printf("│                        │");
    gotoxy(110,9);printf("│                        │");
	gotoxy(110,10);printf("│                        │");
	gotoxy(110,11);printf("│         3  관          │");
	gotoxy(110,12);printf("│                        │");
	gotoxy(110,13);printf("│                        │");
	gotoxy(110,14);printf("│                        │");
	gotoxy(110,15);printf("│                        │");
	gotoxy(110,16);printf("│                        │");
	gotoxy(110,17);printf("│      ┌〓〓〓〓┐      │");
	gotoxy(110,18);printf("│      │        │      │");
	gotoxy(110,19);printf("│      │●      │      │");
     gotoxy(110,20);printf("└───┘▲☞    └───┘");
	

	gotoxy(55,1);printf("┌──────────────────┐");
    gotoxy(55,2);printf("│                                    │");
    gotoxy(55,3);printf("│                                    │");
	gotoxy(55,4);printf("│                                    │");
    gotoxy(55,5);printf("│                                    │");
    gotoxy(55,6);printf("│                                    │" );
	gotoxy(55,7);printf("│                 2 관               │");
	gotoxy(55,8);printf("│                                    │");
    gotoxy(55,9);printf("│                                    │");
	gotoxy(55,10);printf("│                                    │");
	gotoxy(55,11);printf("│            ┌〓〓〓〓〓┐          │");
	gotoxy(55,12);printf("│            │          │          │");
	gotoxy(55,13);printf("│            │●        │          │");
    gotoxy(55,14);printf("└──────┘▲☞      └─────┘");
	
	textcolor(BLACK,WHITE);
	stateDisplay(p);
}