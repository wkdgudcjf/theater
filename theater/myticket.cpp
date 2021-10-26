#include "theater.h"

void ticketDisplay();
void aryPrint(Head *,int,int);
void buy(Head *p);
void inputT(Head *p,int select,int movietime);

void myTicket(Head *p)
{
	int movietime,select;
	struct time sttime; 
	guest(p);
	gettime(&sttime);
	system("cls");
	while(1)
	{
		ticketDisplay();
		buy(p);
		gotoxy(5,32);printf("»ó¿µÇÏ½Ç ¿µÈ­¸¦ °í¸£½Ã¿À (1/2/3) : ");
		scanf("%d",&select);
		gotoxy(5,33);printf("¿µÈ­ Å¸ÀÓÀ» °í¸£½Ã¿À (1/2/3) : ");
		scanf("%d",&movietime);
		if(select==ESC) //esc ´­·¶À»°æ¿ì 
		{
			break;
		}
		inputT(p,select,movietime);
		if(p->state->infoMovie[0]!=0)
		{
			break;
		}
		clrscr(3,31,70,38);
	}
	system("cls");
	return ;
}
void aryPrint(Head *p,int s,int m)
{
	int i,j;
	gotoxy(40,10);printf(" ¦®¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¯");
	gotoxy(40,11);printf(" ¦­                                                      ¦­");
	gotoxy(40,12);printf(" ¦­                                                      ¦­");
	gotoxy(40,13);printf(" ¦­                                                      ¦­");
	gotoxy(40,14);printf(" ¦­                                                      ¦­");
	gotoxy(40,15);printf(" ¦­                                                      ¦­");
	gotoxy(40,16);printf(" ¦­                                                      ¦­");
	gotoxy(40,17);printf(" ¦­                                                      ¦­");
	gotoxy(40,18);printf(" ¦­                                                      ¦­");
	gotoxy(40,19);printf(" ¦­                                                      ¦­");
	gotoxy(40,20);printf(" ¦­                                                      ¦­");
	gotoxy(40,21);printf(" ¦­                                                      ¦­");
	gotoxy(40,22);printf(" ¦­                                                      ¦­");
	gotoxy(40,23);printf(" ¦­                                                      ¦­");
	gotoxy(40,24);printf(" ¦­                                                      ¦­");
	gotoxy(40,25);printf(" ¦­                                                      ¦­");
	gotoxy(40,26);printf(" ¦­                                                      ¦­");
	gotoxy(40,27);printf(" ¦­                                                      ¦­");
	gotoxy(40,28);printf(" ¦­                                                      ¦­");
	gotoxy(40,29);printf(" ¦±¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦°");
	for(i=0;i<6;i++)
	{
		for(j=0;j<10;j++)
		{
			if(s==1)
			{
				if(m==1)
				{
					gotoxy(45+5*j,12+3*i);
					if(p->movie->oneRoom[i][j].firstMovie==1)
					{
						textcolor(WHITE, LIGHTRED);
						printf("¤±");
						textcolor(BLACK, WHITE);
					}
					else
					{
						textcolor(BLACK, WHITE);
						printf("¤±");
					}
				}
				else if(m==2)
				{
					gotoxy(45+5*j,12+3*i);
					if(p->movie->oneRoom[i][j].secondMovie==1)
					{
						textcolor(WHITE, LIGHTRED);
						printf("¤±");
						textcolor(BLACK, WHITE);
					}
					else
					{
						textcolor(BLACK, WHITE);
						printf("¤±");
					}
				}
				else if(m==3)
				{
					gotoxy(45+5*j,12+3*i);
					if(p->movie->oneRoom[i][j].thirdMovie==1)
					{
						textcolor(WHITE, LIGHTRED);
						printf("¤±");
						textcolor(BLACK, WHITE);
					}
					else
					{
						textcolor(BLACK, WHITE);
						printf("¤±");
					}
				}
			}
			else if(s==2)
			{
				if(m==1)
				{
					gotoxy(45+5*j,12+3*i);
					if(p->movie->twoRoom[i][j].firstMovie==1)
					{
						textcolor(WHITE, LIGHTRED);
						printf("¤±");
						textcolor(BLACK, WHITE);
					}
					else
					{
						textcolor(BLACK, WHITE);
						printf("¤±");
					}
				}
				else if(m==2)
				{
					gotoxy(45+5*j,12+3*i);
					if(p->movie->twoRoom[i][j].secondMovie==1)
					{
						textcolor(WHITE, LIGHTRED);
						printf("¤±");
						textcolor(BLACK, WHITE);
					}
					else
					{
						textcolor(BLACK, WHITE);
						printf("¤±");
					}
				}
				else if(m==3)
				{
					gotoxy(45+5*j,12+3*i);
					if(p->movie->twoRoom[i][j].thirdMovie==1)
					{
						textcolor(WHITE, LIGHTRED);
						printf("¤±");
						textcolor(BLACK, WHITE);
					}
					else
					{
						textcolor(BLACK, WHITE);
						printf("¤±");
					}
				}
			}
			else if(s==3)
			{
				if(m==1)
				{
					gotoxy(45+5*j,12+3*i);
					if(p->movie->threeRoom[i][j].firstMovie==1)
					{
						textcolor(WHITE, LIGHTRED);
						printf("¤±");
						textcolor(BLACK, WHITE);
					}
					else
					{
						textcolor(BLACK, WHITE);
						printf("¤±");
					}
				}
				else if(m==2)
				{
					gotoxy(45+5*j,12+3*i);
					if(p->movie->threeRoom[i][j].secondMovie==1)
					{
						textcolor(WHITE, LIGHTRED);
						printf("¤±");
						textcolor(BLACK, WHITE);
					}
					else
					{
						textcolor(BLACK, WHITE);
						printf("¤±");
					}
				}
				else if(m==3)
				{
					gotoxy(45+5*j,12+3*i);
					if(p->movie->threeRoom[i][j].thirdMovie==1)
					{
						textcolor(WHITE, LIGHTRED);
						printf("¤±");
						textcolor(BLACK, WHITE);
					}
					else
					{
						textcolor(BLACK, WHITE);
						printf("¤±");
					}
				}
			}
		}
	}
}

void ticketDisplay()
{
	gotoxy(1,1);printf(" ¦®¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¯");
	gotoxy(1,2);printf(" ¦­             ¡Ú1°ü »ó¿µ¿µÈ­¡Ú           ¦­");
	gotoxy(1,3);printf(" ¦­                                        ¦­");
	gotoxy(1,4);printf(" ¦­                                        ¦­");
	gotoxy(1,5);printf(" ¦­                                        ¦­");
	gotoxy(1,6);printf(" ¦­                                        ¦­");
	gotoxy(1,7);printf(" ¦­                                        ¦­");
	gotoxy(1,8);printf(" ¦­                                        ¦­");
	gotoxy(1,9);printf(" ¦­                                        ¦­");
	gotoxy(1,10);printf(" ¦­                                        ¦­");
	gotoxy(1,11);printf(" ¦­                                        ¦­");
	gotoxy(1,12);printf(" ¦­                                        ¦­");
	gotoxy(1,13);printf(" ¦­                                        ¦­");
	gotoxy(1,14);printf(" ¦­                                        ¦­");
	gotoxy(1,15);printf(" ¦­                                        ¦­");
	gotoxy(1,16);printf(" ¦­                                        ¦­");
	gotoxy(1,17);printf(" ¦­                                        ¦­");
	gotoxy(1,18);printf(" ¦­                                        ¦­");
	gotoxy(1,19);printf(" ¦­                                        ¦­");
	gotoxy(1,20);printf(" ¦­                                        ¦­");
	gotoxy(1,21);printf(" ¦­                                        ¦­");
	gotoxy(1,22);printf(" ¦±¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦°");

	gotoxy(47,1);printf(" ¦®¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¯");
	gotoxy(47,2);printf(" ¦­            ¡Ú2°ü »ó¿µ¿µÈ­¡Ú            ¦­");
	gotoxy(47,3);printf(" ¦­                                        ¦­");
	gotoxy(47,4);printf(" ¦­                                        ¦­");
	gotoxy(47,5);printf(" ¦­                                        ¦­");
	gotoxy(47,6);printf(" ¦­                                        ¦­");
	gotoxy(47,7);printf(" ¦­                                        ¦­");
	gotoxy(47,8);printf(" ¦­                                        ¦­");
	gotoxy(47,9);printf(" ¦­                                        ¦­");
	gotoxy(47,10);printf(" ¦­                                        ¦­");
	gotoxy(47,11);printf(" ¦­                                        ¦­");
	gotoxy(47,12);printf(" ¦­                                        ¦­");
	gotoxy(47,13);printf(" ¦­                                        ¦­");
	gotoxy(47,14);printf(" ¦­                                        ¦­");
	gotoxy(47,15);printf(" ¦­                                        ¦­");
	gotoxy(47,16);printf(" ¦­                                        ¦­");
	gotoxy(47,17);printf(" ¦­                                        ¦­");
	gotoxy(47,18);printf(" ¦­                                        ¦­");
	gotoxy(47,19);printf(" ¦­                                        ¦­");
	gotoxy(47,20);printf(" ¦­                                        ¦­");
	gotoxy(47,21);printf(" ¦­                                        ¦­");
	gotoxy(47,22);printf(" ¦±¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦°");



	gotoxy(92,1);printf(" ¦®¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¯");
	gotoxy(92,2);printf(" ¦­            ¡Ú3°ü »ó¿µ¿µÈ­¡Ú            ¦­");
	gotoxy(92,3);printf(" ¦­                                        ¦­");
	gotoxy(92,4);printf(" ¦­                                        ¦­");
	gotoxy(92,5);printf(" ¦­                                        ¦­");
	gotoxy(92,6);printf(" ¦­                                        ¦­");
	gotoxy(92,7);printf(" ¦­                                        ¦­");
	gotoxy(92,8);printf(" ¦­                                        ¦­");
	gotoxy(92,9);printf(" ¦­                                        ¦­");
	gotoxy(92,10);printf(" ¦­                                        ¦­");
	gotoxy(92,11);printf(" ¦­                                        ¦­");
	gotoxy(92,12);printf(" ¦­                                        ¦­");
	gotoxy(92,13);printf(" ¦­                                        ¦­");
	gotoxy(92,14);printf(" ¦­                                        ¦­");
	gotoxy(92,15);printf(" ¦­                                        ¦­");
	gotoxy(92,16);printf(" ¦­                                        ¦­");
	gotoxy(92,17);printf(" ¦­                                        ¦­");
	gotoxy(92,18);printf(" ¦­                                        ¦­");
	gotoxy(92,19);printf(" ¦­                                        ¦­");
	gotoxy(92,20);printf(" ¦­                                        ¦­");
	gotoxy(92,21);printf(" ¦­                                        ¦­");
	gotoxy(92,22);printf(" ¦±¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦°");

	gotoxy(70,24);printf("¡Ü");
	gotoxy(70,25);printf("¡ã");
	gotoxy(47,26);printf("¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤");
	gotoxy(47,27);printf("¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥");
	gotoxy(70,28);printf("¡Ü");
	gotoxy(70,29);printf("¡ã");
	gotoxy(1,30);printf("¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤");
	gotoxy(1,31);printf("¦¢                                                                                                                                    ¦¢");
	gotoxy(1,32);printf("¦¢                                                                                                                                    ¦¢");
	gotoxy(1,33);printf("¦¢                                                                                                                                    ¦¢");
	gotoxy(1,34);printf("¦¢                                                                                                                                    ¦¢");
	gotoxy(1,35);printf("¦¢                                                                                                                                    ¦¢");
	gotoxy(1,36);printf("¦¢                                                                                                                                    ¦¢");
	gotoxy(1,37);printf("¦¢                                                                                                                                    ¦¢");
	gotoxy(1,38);printf("¦¢                                                                                                                                    ¦¢");
	gotoxy(1,39);printf("¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥");
}

void buy(Head *p)
{
	struct time sttime;
	gotoxy(5,4);printf("1.¿µÈ­Á¦¸ñ : °ÇÃàÇÐ°³·Ð(8000¿ø)");
	if(p->nowsituation->startTime[1]+2>=60)
	{
		p->state->movieTimeHour=p->nowsituation->startTime[0]+1;
		p->state->movieTimeMin=p->nowsituation->startTime[1]+2-60;
		p->state->movieTimeSec=p->nowsituation->startTime[2];
	}
	else
	{
		p->state->movieTimeHour=p->nowsituation->startTime[0];
		p->state->movieTimeMin=p->nowsituation->startTime[1]+2;
		p->state->movieTimeSec=p->nowsituation->startTime[2];
	}
	gettime(&sttime);
	if(p->nowsituation->startTime[0]*3600+(p->nowsituation->startTime[1]+2)*60+p->nowsituation->startTime[2]<sttime.ti_hour*3600+sttime.ti_min*60+sttime.ti_sec)
	{
		textcolor(RED, WHITE);
	}
	else
	{
		textcolor(BLACK, WHITE);
	}
	gotoxy(5,6);printf("Ã¹¹ø¤Š¿µÈ­½Ã°£ : %d½Ã %dºÐ",p->state->movieTimeHour,p->state->movieTimeMin);
	if(p->nowsituation->startTime[1]+5>60)
	{
		p->state->movieTimeHour=p->nowsituation->startTime[0]+1;
		p->state->movieTimeMin=p->nowsituation->startTime[1]+5-60;
		p->state->movieTimeSec=p->nowsituation->startTime[2];
	}
	else
	{
		p->state->movieTimeHour=p->nowsituation->startTime[0];
		p->state->movieTimeMin=p->nowsituation->startTime[1]+5;
		p->state->movieTimeSec=p->nowsituation->startTime[2];
	}
	gettime(&sttime);
	if(p->nowsituation->startTime[0]*3600+(p->nowsituation->startTime[1]+4)*60+p->nowsituation->startTime[2]<sttime.ti_hour*3600+sttime.ti_min*60+sttime.ti_sec)
	{
		textcolor(RED, WHITE);
	}
	else
	{
		textcolor(BLACK, WHITE);
	}
	gotoxy(5,8);printf("µÎ¹øÂ°¤Š¿µÈ­½Ã°£ : %d½Ã %dºÐ",p->state->movieTimeHour,p->state->movieTimeMin);
	if(p->nowsituation->startTime[1]+8>60)
	{
		p->state->movieTimeHour=p->nowsituation->startTime[0]+1;
		p->state->movieTimeMin=p->nowsituation->startTime[1]+8-60;
		p->state->movieTimeSec=p->nowsituation->startTime[2];
	}
	else
	{
		p->state->movieTimeHour=p->nowsituation->startTime[0];
		p->state->movieTimeMin=p->nowsituation->startTime[1]+8;
		p->state->movieTimeSec=p->nowsituation->startTime[2];
	}
	gettime(&sttime);
	if(p->nowsituation->startTime[0]*3600+(p->nowsituation->startTime[1]+8)*60+p->nowsituation->startTime[2]<sttime.ti_hour*3600+sttime.ti_min*60+sttime.ti_sec)
	{
		textcolor(RED, WHITE);
	}
	else
	{
		textcolor(BLACK, WHITE);
	}
	gotoxy(5,10);printf("¼¼¹ø¤Š¿µÈ­½Ã°£ : %d½Ã %dºÐ",p->state->movieTimeHour,p->state->movieTimeMin);
	textcolor(BLACK, WHITE);
	gotoxy(5,13);printf("ÀÌ¿µÈ­´Â ¸Å¿ì °¨¼ö¼ºÀ» µ¸´Â ¿µÈ­·Î");
	gotoxy(5,15);printf("¼öÁö°¡ ÀÌ»Ú´Ù...");
	gotoxy(50,4);printf("2.¿µÈ­Á¦¸ñ : ½ºÅÜ¾÷4(8000¿ø) ");
	if(p->nowsituation->startTime[1]+3>60)
	{
		p->state->movieTimeHour=p->nowsituation->startTime[0]+1;
		p->state->movieTimeMin=p->nowsituation->startTime[1]+3-60;
		p->state->movieTimeSec=p->nowsituation->startTime[2];
	}
	else
	{
		p->state->movieTimeHour=p->nowsituation->startTime[0];
		p->state->movieTimeMin=p->nowsituation->startTime[1]+3;
		p->state->movieTimeSec=p->nowsituation->startTime[2];
	}
	gettime(&sttime);
	if(p->nowsituation->startTime[0]*3600+(p->nowsituation->startTime[1]+3)*60+p->nowsituation->startTime[2]<sttime.ti_hour*3600+sttime.ti_min*60+sttime.ti_sec)
	{
		textcolor(RED, WHITE);
	}
	else
	{
		textcolor(BLACK, WHITE);
	}
	gotoxy(50,6);printf("Ã¹¹ø¤Š¿µÈ­½Ã°£ : %d½Ã %dºÐ",p->state->movieTimeHour,p->state->movieTimeMin);
	if(p->nowsituation->startTime[1]+6>60)
	{
		p->state->movieTimeHour=p->nowsituation->startTime[0]+1;
		p->state->movieTimeMin=p->nowsituation->startTime[1]+6-60;
		p->state->movieTimeSec=p->nowsituation->startTime[2];
	}
	else
	{
		p->state->movieTimeHour=p->nowsituation->startTime[0];
		p->state->movieTimeMin=p->nowsituation->startTime[1]+6;
		p->state->movieTimeSec=p->nowsituation->startTime[2];
	}
	gettime(&sttime);
	if(p->nowsituation->startTime[0]*3600+(p->nowsituation->startTime[1]+7)*60+p->nowsituation->startTime[2]<sttime.ti_hour*3600+sttime.ti_min*60+sttime.ti_sec)
	{
		textcolor(RED, WHITE);
	}
	else
	{
		textcolor(BLACK, WHITE);
	}
	gotoxy(50,8);printf("µÎ¹ø¤Š¿µÈ­½Ã°£ : %d½Ã %dºÐ",p->state->movieTimeHour,p->state->movieTimeMin);
	if(p->nowsituation->startTime[1]+9>60)
	{
		p->state->movieTimeHour=p->nowsituation->startTime[0]+1;
		p->state->movieTimeMin=p->nowsituation->startTime[1]+9-60;
		p->state->movieTimeSec=p->nowsituation->startTime[2];
	}
	else
	{
		p->state->movieTimeHour=p->nowsituation->startTime[0];
		p->state->movieTimeMin=p->nowsituation->startTime[1]+9;
		p->state->movieTimeSec=p->nowsituation->startTime[2];
	}
	gettime(&sttime);
	if(p->nowsituation->startTime[0]*3600+(p->nowsituation->startTime[1]+9)*60+p->nowsituation->startTime[2]<sttime.ti_hour*3600+sttime.ti_min*60+sttime.ti_sec)
	{
		textcolor(RED, WHITE);
	}
	else
	{
		textcolor(BLACK, WHITE);
	}
	gotoxy(50,10);printf("¼¼¹ø¤Š¿µÈ­½Ã°£ : %d½Ã %dºÐ",p->state->movieTimeHour,p->state->movieTimeMin);
	textcolor(BLACK, WHITE);
	gotoxy(50,13);printf("ÀÌ¿µÈ­´Â ½ºÆ®¸®Æ®´í¼­µéÀÇ °­·ÄÇÑ");
	gotoxy(50,15);printf("Ãã»çÀ§°¡ ÆîÃÄÁø´Ù.");
	gotoxy(95,4);printf("3.¿µÈ­Á¦¸ñ : ·ºÅäÇÇ¾ÆÀÌ¾ß±â(8000¿ø) ");
	if(p->nowsituation->startTime[1]+4>60)
	{
		p->state->movieTimeHour=p->nowsituation->startTime[0]+1;
		p->state->movieTimeMin=p->nowsituation->startTime[1]+4-60;
		p->state->movieTimeSec=p->nowsituation->startTime[2];
	}
	else
	{
		p->state->movieTimeHour=p->nowsituation->startTime[0];
		p->state->movieTimeMin=p->nowsituation->startTime[1]+4;
		p->state->movieTimeSec=p->nowsituation->startTime[2];
	}
	gettime(&sttime);
	if(p->nowsituation->startTime[0]*3600+(p->nowsituation->startTime[1]+4)*60+p->nowsituation->startTime[2]<sttime.ti_hour*3600+sttime.ti_min*60+sttime.ti_sec)
	{
		textcolor(RED, WHITE);
	}
	else
	{
		textcolor(BLACK, WHITE);
	}
	gotoxy(95,6);printf("Ã¹¹ø¤Š¿µÈ­½Ã°£ : %d½Ã %dºÐ",p->state->movieTimeHour,p->state->movieTimeMin);
	if(p->nowsituation->startTime[1]+7>60)
	{
		p->state->movieTimeHour=p->nowsituation->startTime[0]+1;
		p->state->movieTimeMin=p->nowsituation->startTime[1]+7-60;
		p->state->movieTimeSec=p->nowsituation->startTime[2];
	}
	else
	{
		p->state->movieTimeHour=p->nowsituation->startTime[0];
		p->state->movieTimeMin=p->nowsituation->startTime[1]+7;
		p->state->movieTimeSec=p->nowsituation->startTime[2];
	}
	gettime(&sttime);
	if(p->nowsituation->startTime[0]*3600+(p->nowsituation->startTime[1]+7)*60+p->nowsituation->startTime[2]<sttime.ti_hour*3600+sttime.ti_min*60+sttime.ti_sec)
	{
		textcolor(RED, WHITE);
	}
	else
	{
		textcolor(BLACK, WHITE);
	}
	gotoxy(95,8);printf("µÎ¹øÂ°¿µÈ­½Ã°£ : %d½Ã %dºÐ",p->state->movieTimeHour,p->state->movieTimeMin);
	if(p->nowsituation->startTime[1]+10>60)
	{
		p->state->movieTimeHour=p->nowsituation->startTime[0]+1;
		p->state->movieTimeMin=p->nowsituation->startTime[1]+10-60;
		p->state->movieTimeSec=p->nowsituation->startTime[2];
	}
	else
	{
		p->state->movieTimeHour=p->nowsituation->startTime[0];
		p->state->movieTimeMin=p->nowsituation->startTime[1]+10;
		p->state->movieTimeSec=p->nowsituation->startTime[2];
	}
	gettime(&sttime);
	if(p->nowsituation->startTime[0]*3600+(p->nowsituation->startTime[1]+10)*60+p->nowsituation->startTime[2]<sttime.ti_hour*3600+sttime.ti_min*60+sttime.ti_sec)
	{
		textcolor(RED, WHITE);
	}
	else
	{
		textcolor(BLACK, WHITE);
	}
	gotoxy(95,10);printf("¼¼¹øÂ°¿µÈ­½Ã°£ : %d½Ã %dºÐ",p->state->movieTimeHour,p->state->movieTimeMin);
	textcolor(BLACK, WHITE);
	gotoxy(95,13);printf("Ç×Ç×Çã¤¿¤¾´Ï¤Ã´Ù¤Ì´Ï¤¿ÈÄ¤¿¤Ó¤·.");
	gotoxy(95,15);printf("¤·¤¤ÈÖ¤¿´©È÷¤¿´©¤¿¤Ó¤·.");
}

void gettime(struct time *p) // ¿øº» µ¥ÀÌÅÍ¸¦ º¯È¯ÇÒ¼ö ÀÖµµ·Ï Call by pointer ±â¹ý »ç¿ë 
{
	char temp[30]; 
	char *cp; 
	_strtime( temp ); 
	cp = strtok(temp, ":"); 
	p->ti_hour = atoi(cp); 
	cp = strtok(NULL, ":"); 
	p->ti_min = atoi(cp); 
	cp = strtok(NULL, ":"); 
	p->ti_sec = atoi(cp); 
	return ;
}

void textcolor(int foreground, int background) 
{ 
	int color=foreground+background*16; 
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color); 
} 

void inputT(Head *p,int select,int movietime)
{
	struct time sttime; 
	gettime(&sttime);
	int lineRan,colRan;
	if(p->nowsituation->startTime[0]*3600+(p->nowsituation->startTime[1]+(3*movietime+select-2))*60+p->nowsituation->startTime[2]>sttime.ti_hour*3600+sttime.ti_min*60+sttime.ti_sec)
	{
		aryPrint(p,select,movietime);
		gotoxy(5,34);textcolor(BLACK, WHITE);printf("ÁÂ¼®ÀÇ ÇàÀ» ÀÔ·ÂÇÏ½Ã¿À : (1~6) : ");
		scanf("%d",&lineRan);
		gotoxy(5,35);textcolor(BLACK, WHITE);printf("ÁÂ¼®ÀÇ ¿­À» ÀÔ·ÂÇÏ½Ã¿À : (1~10) : ");
		scanf("%d",&colRan);
		if(select==1)
		{
			if(movietime==1)
			{
				if(p->movie->oneRoom[lineRan-1][colRan-1].firstMovie==1)
				{
					gotoxy(5,36);printf("ÀÌ¹Ì ¼±ÅÃµÈÀÚ¼®ÀÔ´Ï´Ù. ´Ù½Ã ¿¹¸ÅÈ­¸éÀ¸·Î µ¹¾Æ°©´Ï´Ù.");
					getch();
				}
				else
				{
					p->movie->oneRoom[lineRan-1][colRan-1].firstMovie=1;
					strcpy(p->state->movie_name,"°ÇÃàÇÐ°³·Ð");
				}
			}
			else if(movietime==2)
			{
				if(p->movie->oneRoom[lineRan-1][colRan-1].secondMovie==1)
				{
					gotoxy(5,36);printf("ÀÌ¹Ì ¼±ÅÃµÈÀÚ¼®ÀÔ´Ï´Ù. ´Ù½Ã ¿¹¸ÅÈ­¸éÀ¸·Î µ¹¾Æ°©´Ï´Ù.");
					getch();
				}
				else
				{
					p->movie->oneRoom[lineRan-1][colRan-1].secondMovie=1;
					strcpy(p->state->movie_name,"°ÇÃàÇÐ°³·Ð");
				}
			}
			else if(movietime==3)
			{
				if(p->movie->oneRoom[lineRan-1][colRan-1].thirdMovie==1)
				{
					gotoxy(5,36);printf("ÀÌ¹Ì ¼±ÅÃµÈÀÚ¼®ÀÔ´Ï´Ù. ´Ù½Ã ¿¹¸ÅÈ­¸éÀ¸·Î µ¹¾Æ°©´Ï´Ù.");
					getch();
				}
				else
				{
					p->movie->oneRoom[lineRan-1][colRan-1].thirdMovie=1;
					strcpy(p->state->movie_name,"°ÇÃàÇÐ°³·Ð");
				}
			}
		}
		else if(select==2)
		{
			if(movietime==1)
			{
				if(p->movie->twoRoom[lineRan-1][colRan-1].firstMovie==1)
				{
					gotoxy(5,36);printf("ÀÌ¹Ì ¼±ÅÃµÈÀÚ¼®ÀÔ´Ï´Ù. ´Ù½Ã ¿¹¸ÅÈ­¸éÀ¸·Î µ¹¾Æ°©´Ï´Ù.");
					getch();
				}
				else
				{
					strcpy(p->state->movie_name,"½ºÅÜ¾÷4");
					p->movie->twoRoom[lineRan-1][colRan-1].firstMovie=1;
				}
			}
			else if(movietime==2)
			{
				if(p->movie->twoRoom[lineRan-1][colRan-1].secondMovie==1)
				{
					gotoxy(5,36);printf("ÀÌ¹Ì ¼±ÅÃµÈÀÚ¼®ÀÔ´Ï´Ù. ´Ù½Ã ¿¹¸ÅÈ­¸éÀ¸·Î µ¹¾Æ°©´Ï´Ù.");
					getch();
				}
				else
				{
					p->movie->twoRoom[lineRan-1][colRan-1].secondMovie=1;
					strcpy(p->state->movie_name,"½ºÅÜ¾÷4");
				}
			}
			else if(movietime==3)
			{
				if(p->movie->twoRoom[lineRan-1][colRan-1].thirdMovie==1)
				{
					gotoxy(5,36);printf("ÀÌ¹Ì ¼±ÅÃµÈÀÚ¼®ÀÔ´Ï´Ù. ´Ù½Ã ¿¹¸ÅÈ­¸éÀ¸·Î µ¹¾Æ°©´Ï´Ù.");
					getch();
				}
				else
				{
					p->movie->twoRoom[lineRan-1][colRan-1].thirdMovie=1;
					strcpy(p->state->movie_name,"½ºÅÜ¾÷4");
				}
			}
		}
		if(select==3)
		{
			if(movietime==1)
			{
				if(p->movie->threeRoom[lineRan-1][colRan-1].firstMovie==1)
				{
					gotoxy(5,36);printf("ÀÌ¹Ì ¼±ÅÃµÈÀÚ¼®ÀÔ´Ï´Ù. ´Ù½Ã ¿¹¸ÅÈ­¸éÀ¸·Î µ¹¾Æ°©´Ï´Ù.");
					getch();
				}
				else
				{
					p->movie->threeRoom[lineRan-1][colRan-1].firstMovie=1;
					strcpy(p->state->movie_name,"·ºÅäÇÇ¾ÆÀÌ¾ß±â");
				}
			}
			else if(movietime==2)
			{
				if(p->movie->threeRoom[lineRan-1][colRan-1].secondMovie==1)
				{
					gotoxy(5,36);printf("ÀÌ¹Ì ¼±ÅÃµÈÀÚ¼®ÀÔ´Ï´Ù. ´Ù½Ã ¿¹¸ÅÈ­¸éÀ¸·Î µ¹¾Æ°©´Ï´Ù.");
					getch();
				}
				else
				{
					p->movie->threeRoom[lineRan-1][colRan-1].secondMovie=1;
					strcpy(p->state->movie_name,"·ºÅäÇÇ¾ÆÀÌ¾ß±â");
				}
			}
			else if(movietime==3)
			{
				if(p->movie->threeRoom[lineRan-1][colRan-1].thirdMovie==1)
				{
					gotoxy(5,36);printf("ÀÌ¹Ì ¼±ÅÃµÈÀÚ¼®ÀÔ´Ï´Ù. ´Ù½Ã ¿¹¸ÅÈ­¸éÀ¸·Î µ¹¾Æ°©´Ï´Ù.");
					getch();
				}
				else
				{
					p->movie->threeRoom[lineRan-1][colRan-1].thirdMovie=1;
					strcpy(p->state->movie_name,"·ºÅäÇÇ¾ÆÀÌ¾ß±â");
				}
			}
		}
		p->movie->movieCount[select-1]++;
		p->movie->roomCount[movietime-1][select-1]++;
		p->state->infoMovie[0]=select;
		p->state->infoMovie[1]=movietime;
		p->state->infoMovie[2]=lineRan;
		p->state->infoMovie[3]=colRan;
		p->state->money-=8000;
		if(p->nowsituation->startTime[1]+(3*movietime+select-2)>60)
		{
			p->state->movieTimeHour=p->nowsituation->startTime[0]+1;
			p->state->movieTimeMin=p->nowsituation->startTime[1]+(3*movietime+select-2)-60;
			p->state->movieTimeSec=p->nowsituation->startTime[2];
		}
		else
		{
			p->state->movieTimeHour=p->nowsituation->startTime[0];
			p->state->movieTimeMin=p->nowsituation->startTime[1]+(3*movietime+select-2);
			p->state->movieTimeSec=p->nowsituation->startTime[2];
		}
	}
    else
	{
		gotoxy(5,34);printf("ÀÌ¹Ì »ó¿µÀÌ Á¾·áµÈ ¿µÈ­ÀÔ´Ï´Ù. ´Ù½Ã °ñ¶óÁÖ¼¼¿ä.");
		getch();
	}
}