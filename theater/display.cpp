#include "theater.h"

void display(Head *p)
{
	gotoxy(3,1);textcolor(LIGHTMAGENTA, WHITE);printf(" ≒/");
	gotoxy(3,2);printf("/∼");
	gotoxy(3,3);printf(" ‵");
	textcolor(BLACK, WHITE);
	randPerson(p);//溶渾 槳椒殮濰熱
	gotoxy(16,1);printf("忙≦式≦式≦式≦式≦式≦忖 ");
	gotoxy(16,2);printf("≦                      ≦ ");
	gotoxy(16,3);printf("弛                      弛 ");
	gotoxy(16,4);printf("≦     縑  橫  鐘       ≦ ");
	gotoxy(16,5);printf("弛                      弛 ");
	gotoxy(16,6);printf("戌≦式≦式≦式≦式≦式≦戎");

	gotoxy(45,1);printf("||                                     ||   ");
	gotoxy(45,2);printf("||                                     ||   ");
	gotoxy(45,3);printf("||                                     ||   ");
	gotoxy(45,4);printf("||                                     ||  ");
	gotoxy(45,5);printf("||           艙 ?? 婦 殮 掘            ||   ");
	gotoxy(45,6);printf("||                                     ||   ");
	gotoxy(45,7);printf("||                                     ||   ");
	gotoxy(45,8);printf("=====");textcolor(LIGHTGREEN, WHITE);printf("≒//");textcolor(BLACK, WHITE);printf("             ===================== ");
	gotoxy(45,9);printf("     ");textcolor(LIGHTGREEN, WHITE);printf("∼");textcolor(BLACK, WHITE);printf("                      ");
	gotoxy(45,10);printf("     ");textcolor(LIGHTGREEN, WHITE);printf("‵");textcolor(BLACK, WHITE);printf("                      ");

	gotoxy(101,1);printf("忙式式式式式式式式式式式式式式式式式忖");
	gotoxy(101,2);printf("弛                                  弛 ");
	gotoxy(101,3);printf("弛                                  弛");
	gotoxy(101,4);printf("弛     ");textcolor(LIGHTBLUE, WHITE);printf("≒");textcolor(LIGHTRED, WHITE);printf("    ≒");textcolor(BLACK, WHITE);printf("         ?倣敶?      弛");
	gotoxy(101,5);printf("弛     ");textcolor(LIGHTBLUE, WHITE);printf("虫");textcolor(LIGHTRED, WHITE);printf("    ﹦");textcolor(BLACK, WHITE);printf("                     弛");
	gotoxy(101,6);printf("弛     ");textcolor(LIGHTBLUE, WHITE);printf("↘");textcolor(LIGHTRED, WHITE);printf("    ‵");textcolor(BLACK, WHITE);printf("                     弛");
	gotoxy(101,7);printf("弛                                  弛");
	gotoxy(101,8);printf("戌式式式式");textcolor(CYAN, WHITE);printf("Ⅱ        ９");textcolor(BLACK, WHITE);printf("式式式式式式式戎");

	gotoxy(122,10);printf(" 忙式式式式式式忖");
	gotoxy(122,11);printf(" 弛            弛");
	gotoxy(122,12);printf(" ");textcolor(LIGHTBLUE, WHITE);printf("≠");textcolor(BLACK, WHITE);printf("    啪      弛 ");
	gotoxy(122,13);printf("               弛");
	gotoxy(122,14);printf("               弛");
	gotoxy(122,15);printf("       歜      弛 ");
	gotoxy(122,16);printf("               弛 ");
	gotoxy(122,17);printf("               弛");
	gotoxy(122,18);printf(" ");textcolor(YELLOW, WHITE);printf("≠");textcolor(BLACK, WHITE);printf("    濰      弛");
	gotoxy(122,19);printf(" 弛            弛");
	gotoxy(122,20);printf(" 戌式式式式式式戎");

	gotoxy(1,22);printf("忙==========≦    ≦=============忖 ");
	gotoxy(1,23);printf("弛                               弛 ");
	gotoxy(1,24);printf("弛          婦  葬  褒           弛");
	gotoxy(1,25);printf("弛      ");textcolor(GREEN, WHITE);printf("≒           ≒");textcolor(BLACK, WHITE);printf("          弛");
	gotoxy(1,26);printf("弛      ");textcolor(GREEN, WHITE);printf("虫８=	     //﹦");textcolor(BLACK, WHITE);printf("        弛");
	gotoxy(1,27);printf("弛      ");textcolor(GREEN, WHITE);printf("↘           ‵");textcolor(BLACK, WHITE);printf("          弛");
	gotoxy(1,28);printf("戌===============================戎");
	

	gotoxy(47,22);printf("忙=========");textcolor(CYAN, WHITE);printf("﹣           ﹣");textcolor(BLACK, WHITE);printf("=========忖 ");
	gotoxy(47,23);printf("||                                 || ");
	gotoxy(47,24);printf("||                                 ||");
	gotoxy(47,25);printf("||             衙 ル 模            ||");
	gotoxy(47,26);printf("||                                 ||");
	gotoxy(47,27);printf("||                                 ||");
	gotoxy(47,28);printf("戌=================================戎");


	gotoxy(100,22);printf("忙＿＿");textcolor(CYAN, WHITE);printf("≒              ≒");textcolor(BLACK, WHITE);printf("＿＿＿＿＿＿忖 ");
	gotoxy(100,23);printf("＿                        ||        ＿");
	gotoxy(100,24);printf("＿                     忙=||=忖     ＿");
	gotoxy(100,25);printf("＿       で 夔 / 擠猿  弛﹥﹥弛     ＿");
	gotoxy(100,26);printf("＿                     弛﹥﹥弛     ＿");
	gotoxy(100,27);printf("＿                     戌式式戎     ＿");
	gotoxy(100,28);printf("戌＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿戎");

	stateDisplay(p);
}

void stateDisplay(Head *p)
{
	struct time sttime;
	gettime(&sttime);
	gotoxy(1,30);printf("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖");
	gotoxy(1,31);printf("弛	                                                      掘衙跡煙									                 弛");
	gotoxy(1,32);printf("弛忙式式式式式式式式式忖                                                                                                                弛");
	gotoxy(1,33);printf("弛弛                  太      檜 葷:                                                    艙?? 薯跡 :                                     弛");
	gotoxy(1,34);printf("弛弛  天天天  天天天  太                                                                                                                弛");
	gotoxy(1,35);printf("弛弛        太        太      釭 檜:                                                     鼻 艙 婦 :            謝    戮 :               弛");
	gotoxy(1,36);printf("弛弛        太        太                                                                                                                弛");
	gotoxy(1,37);printf("弛弛      天天天      太      濠 骯:                  檜辨跡煙                          衛濛 衛除 :                /                    弛");
	gotoxy(1,38);printf("弛弛                  太                                                                                                                弛");
	gotoxy(1,39);printf("弛戌式式式式式式式式式戎                                                                                                                弛");
	gotoxy(1,40);printf("戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎");
	gotoxy(38,33);printf("%s",p->state->name);
	gotoxy(38,35);printf("%d",p->state->age);
	gotoxy(38,37);printf("%d",p->state->money);
	///////////////////////////////////// /////////////
	/////////////////掘衙跡煙//////////////////////////
	/////////////////////////////////////////////////////////////
	if(p->state->snack[0]==1)
	{
		gotoxy(55,33);textcolor(12, 15 );printf("で夔"); textcolor(0 , 15 );
	}
	if(p->state->snack[1]==1)
	{
		gotoxy(60,33);textcolor(12, 15 );printf("屬塭");  textcolor(0 , 15 );
	}
	if(p->state->snack[2]==1)
	{
		gotoxy(65,33);textcolor(12, 15 );printf("餌檜棻"); textcolor(0 , 15 );
	}
	if(p->state->snack[3]==1)
	{
		gotoxy(55,35);textcolor(12 , 15 );printf("釭蹶");textcolor(0, 15 ); 
	}
	if(p->state->snack[4]==1)
	{
		gotoxy(60,35);textcolor(12  , 15 );printf("螃癒橫");textcolor(0 , 15 ); 
	}
	/////////////////////////////////////////////////////////////////////////
	/////////////////////檜辨 跡煙//////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////
	if(p->state->restRoom==1)
	{
		gotoxy(55,39);textcolor(12, 15 );printf("?倣敶?"); textcolor(0 , 15 ); 
	}
	if(p->state->gameRoom==1)
	{
		gotoxy(62,39);textcolor(12, 15 );printf("啪歜濰"); textcolor(0 , 15 ); 
	}
	///////////////////////////////////////////////////////////////////////////////////
	/////////////////////艙?倣抶完? 衛除,鼻艙婦 /////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////
	gotoxy(102,33);printf("%s",p->state->movie_name);
	if(p->state->infoMovie[0]==0)
	{
		gotoxy(100,35);printf("");
	}
	else if(p->state->infoMovie[0]==1)
	{
		gotoxy(102,35);printf("1鼻艙婦");
	}
	else if(p->state->infoMovie[0]==2)
	{
		gotoxy(102,35);printf("2鼻艙婦");
	}
	else if(p->state->infoMovie[0]==3)
	{
		gotoxy(102,35);printf("3鼻艙婦");
	}
	gotoxy(123,35);printf("%dч %d翮", p->state->infoMovie[2],p->state->infoMovie[3]); 
	gotoxy(102,37);printf("%d衛 %d碟 ",p->state->movieTimeHour,p->state->movieTimeMin);
	if(p->state->movieTimeMin-(int)sttime.ti_min<0)
	{
		gotoxy(120,37);printf("");
	}
	else if(p->state->movieTimeMin-(int)sttime.ti_min>0)
	{
		gotoxy(120,37);printf("%d碟菴衛濛",p->state->movieTimeMin-(int)sttime.ti_min);
	}
}

void randPerson(Head *p)
{
	struct time sttime;
	gettime(&sttime);

	gotoxy(2,4); printf("%3d / %3d", p->nowsituation->currentNum, p->nowsituation->totalNum);
	gotoxy(2,6); printf("衙ル鼻??");
	gotoxy(1,7); printf("1婦 1st: "); printf("%2d",p->movie->roomCount[0][0]);
	gotoxy(1,8); printf("    2st: "); printf("%2d",p->movie->roomCount[1][0]);
	gotoxy(1,9); printf("    3st: "); printf("%2d",p->movie->roomCount[2][0]);
	gotoxy(1,10); printf("2婦 1st: "); printf("%2d",p->movie->roomCount[0][1]);
	gotoxy(1,11); printf("    2st: "); printf("%2d",p->movie->roomCount[1][1]);
	gotoxy(1,12); printf("    3st: "); printf("%2d",p->movie->roomCount[2][1]);
	gotoxy(1,13); printf("3婦 1st: "); printf("%2d",p->movie->roomCount[0][2]);
	gotoxy(1,14); printf("    2st: "); printf("%2d",p->movie->roomCount[1][2]);
	gotoxy(1,15); printf("    3st: "); printf("%2d",p->movie->roomCount[2][2]);
	gotoxy(27,5); printf("%.1lf紫",p->nowsituation->temperature);

	if((p->state->movieTimeHour*3600)+(p->state->movieTimeMin*60)+(p->state->movieTimeSec)-((int)(sttime.ti_hour*3600)+(int)(sttime.ti_min*60)+(int)(sttime.ti_sec))<0)
	 {
		 gotoxy(120,37);printf("");
	 }
	 else if(p->state->movieTimeHour*3600+(p->state->movieTimeMin-1)*60+p->state->movieTimeSec<(int)(sttime.ti_hour*3600)+(int)(sttime.ti_min*60)+(int)(sttime.ti_sec)<p->state->movieTimeHour*3600+p->state->movieTimeMin*60+p->state->movieTimeSec)
	 {	
	gotoxy(120,37);printf("%d蟾菴衛濛",60-(int)sttime.ti_sec);
	 }
	 else if(p->state->movieTimeHour*3600+p->state->movieTimeMin*60+p->state->movieTimeSec-((int)(sttime.ti_hour*3600)+(int)(sttime.ti_min*60)+(int)(sttime.ti_sec))>60)
	 {	
	  gotoxy(120,37);printf("%d碟菴衛濛",p->state->movieTimeMin-(int)(sttime.ti_min));
	 }
	 //////////////////////////////////////////////////////////////////////////
	 /////////////////////鼻艙醞ル衛////////////////////////////////////////
	 /////////////////////////////////////////////////////////////////////
	 if((sttime.ti_min>=p->state->movieTimeMin)&&(sttime.ti_min<=((p->state->movieTimeMin)+1)))
	 {
	  gotoxy(120,37);printf("[ 鼻 艙 醞 ]");
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
	////////////////偽擊陽......... 鎰橫輿堅 遺霜橾陽 雖錶醜撿腎朝等 斜 薑?旁炾? 雖選熱 氈朝寞徹 翱掘п撿腆嗆..////////////
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	if(sX==eX&&sY==eY)
	{
		gotoxy(sX,sY);printf(" ≒");
		gotoxy(sX,sY+1);printf("-弛-");
		gotoxy(sX,sY+2);printf(" 弛");
		gotoxy(sX,sY+3);printf(" ‵");
	}
	
	if(sX<eX) // 螃腦薹戲煎陞陽
	{
		for(i=0;i<eX-sX;i++)
		{
			if(i%3==0)
			{
				gotoxy(sX+i,sY);printf("   ≒");
				gotoxy(sX+i,sY+1);printf("忙弛戎");
				gotoxy(sX+i,sY+2);printf(" 弛");
				gotoxy(sX+i,sY+3);printf("/′");
				sX=sX+i;
				Sleep(50);
				clrscr(sX,sY,sX+i,sY+3);  
			}
			else if(i%3!=1)
			{
				gotoxy(sX+i,sY);printf("   ≒");
				gotoxy(sX+i,sY+1);printf("戌弛忖");
				gotoxy(sX+i,sY+2);printf(" 弛");
				gotoxy(sX+i,sY+3);printf("‵");
				sX=sX+i;
				Sleep(50);
				clrscr(sX,sY,sX+i,sY+3); 
			}
			else if(i%3!=2)
			{
				gotoxy(sX+i,sY);printf("   ≒");
				gotoxy(sX+i,sY+1);printf("忙弛戎");
				gotoxy(sX+i,sY+2);printf(" 弛");
				gotoxy(sX+i,sY+3);printf("戎忖");
				sX=sX+i;
				Sleep(50);
				clrscr(sX,sY,sX+i,sY+3); 
			}
			
		}clrscr(sX,sY,sX+i+3,sY+4);
	}
	else
	{
		for(i=0;i<sX-eX;i++)// 豭薹戲煎 陞陽 x蹴
		{
			if(i%3==0)
			{
				gotoxy(sX-i,sY);printf("  ≒");
				gotoxy(sX-i,sY+1);printf("戌弛忖");
				gotoxy(sX-i,sY+2);printf("  弛");
				gotoxy(sX-i,sY+3);printf(" 弛′");
				Sleep(50);
				sX = sX-i;
				clrscr(sX-i,sY,sX+i+3,sY+4);  
			}
			else if(i%3!=1)
			{
				gotoxy(sX-i,sY);printf("  ≒");
				gotoxy(sX-i,sY+1);printf("忙弛戎");
				gotoxy(sX-i,sY+2);printf("  弛");
				gotoxy(sX-i,sY+3);printf("  ‵");
				Sleep(50);
				sX = sX-i;
				clrscr(sX-i,sY,sX+i+3,sY+4);
			}
			else if(i%3!=2)
			{
				gotoxy(sX-i,sY);printf("  ≒");
				gotoxy(sX-i,sY+1);printf("戌弛忖");
				gotoxy(sX-i,sY+2);printf("  弛");
				gotoxy(sX-i,sY+3);printf(" 忙 戎");
				Sleep(50);
				sX = sX-i;
				clrscr(sX-i,sY,sX+i+3,sY+4); 
			}
			
		}clrscr(sX-i,sY,sX+i+1,sY+4);
	}
	if(sY>eY)
	{
		for(i=0;i<sY-eY;i++) //螢塭陞??
		{
			if(i%3==0)
			{
				gotoxy(eX,sY-i); printf("  ‵");
				gotoxy(eX,sY-i-1);printf("  弛");
				gotoxy(eX,sY-i-2);printf("忙弛戎");
				gotoxy(eX,sY-i-3);printf("  ≒");
				Sleep(50);
				clrscr(eX,sY-i-3,eX+6,sY-i+3);
				
			}
			else if(i%3!=1)
			{
				gotoxy(eX,sY-i);printf("  ‵");
				gotoxy(eX,sY-i-1);printf("  弛");
				gotoxy(eX,sY-i-2);printf("忙弛忖");
				gotoxy(eX,sY-i-3);printf("  ≒");
				Sleep(50);
				clrscr(eX,sY-i-3,eX+6,sY-i+3);
				
			}
			else if(i%3!=2)
			{
				gotoxy(eX,sY-i);printf("  ‵");
				gotoxy(eX,sY-i-1);printf("  弛");
				gotoxy(eX,sY-i-2);printf("戌弛忖");
				gotoxy(eX,sY-i-3);printf("  ≒ ");
				Sleep(50);
				clrscr(eX,sY-i-3,eX+6,sY-i+3);
				
			}
		}
	}
	else
	{
		for(i=0;i<eY-sY;i++) //頂溥陞陽
		{
			if(i%3==0)
			{
				gotoxy(eX,sY+i); printf("  ≒");
				gotoxy(eX,sY+i+1);printf("忙弛戎");
				gotoxy(eX,sY+i+2);printf("  弛");
				gotoxy(eX,sY+i+3);printf("  ‵");
				Sleep(50);
				clrscr(eX,sY+i-4,eX+5,sY+i+3);
			}
			else if(i%3!=1)
			{
				gotoxy(eX,sY+i);printf("  ≒");
				gotoxy(eX,sY+i+1);printf("忙弛忖");
				gotoxy(eX,sY+i+2);printf("  弛");
				gotoxy(eX,sY+i+3);printf("  ‵");
				Sleep(50);
				clrscr(eX,sY+i-4,eX+5,sY+i+3);
			}
			else if(i%3!=2)
			{
				gotoxy(eX,sY+i);printf("  ≒");
				gotoxy(eX,sY+i+1);printf("戌弛忖");
				gotoxy(eX,sY+i+2);printf("  弛");
				gotoxy(eX,sY+i+3);printf("  ‵");
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
		gotoxy(sX,sY);printf(" ≒");
		gotoxy(sX,sY+1);printf("-弛-");
		gotoxy(sX,sY+2);printf(" 弛");
		gotoxy(sX,sY+3);printf(" ‵");
	}
	
}

void toilet(Head *p)
{
	if(p->state->restRoom==1)
	{
		gotoxy(124,6);printf("[ 檜 辨 醞 ]");
		Sleep(500);
		clrscr(124,6,132,6);
		gotoxy(124,6);printf("[ 檜 辨 醞 ]");
		Sleep(500);
		clrscr(124,6,132,6);
		gotoxy(124,6);printf("[ 檜 辨 醞 ]");
		Sleep(500);
		clrscr(124,6,132,6);
		
	}
}
void setDisplay(Head *p)
{
	int i,j,k;
	gotoxy(19,2);printf(" 忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖");
	gotoxy(19,3);printf(" 弛                                                                                                弛");
	gotoxy(19,4);printf(" 戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎");
	
	for(i = 10; i < 28; i+=3)
	{
		gotoxy(22,i);printf("忙式忖忙式忖     忙式忖忙式忖忙式忖忙式忖忙式忖忙式忖忙式忖忙式忖忙式忖忙式忖     忙式忖忙式忖");
		gotoxy(22,i+1);printf("弛  弛弛  弛     弛  弛弛  弛弛  弛弛  弛弛  弛弛  弛弛  弛弛  弛弛  弛弛  弛     弛  弛弛  弛");
		gotoxy(22,i+2);printf("戌式戎戌式戎     戌式戎戌式戎戌式戎戌式戎戌式戎戌式戎戌式戎戌式戎戌式戎戌式戎     戌式戎戌式戎");
	}
	
	
	if(p->state->infoMovie[0]==1)//1婦橾陽
	{

		for(j=0;j<6;j++)
		{
			for(k=0;k<10;k++)
			{
				if(p->state->infoMovie[1]==1)
				{
					if(p->movie->oneRoom[j][k].firstMovie==1)//1婦縑 羅廓簞 艙?? 
					{
						 textcolor(LIGHTRED,WHITE );
						gotoxy(41+(k*6),11+(j*3));printf("≒");
						textcolor(BLACK, WHITE);
				
					}
				}
				else if(p->state->infoMovie[1]==2)
				{
					if(p->movie->oneRoom[j][k].secondMovie==1)//1婦縑 舒廓簞 艙?? 
					{
						 textcolor(LIGHTRED,WHITE );
						gotoxy(41+(k*6),11+(j*3));printf("≒");
						 textcolor(BLACK, WHITE);
					}
				}
				else if(p->state->infoMovie[1]==3)
				{
					if(p->movie->oneRoom[j][k].thirdMovie==1)//1婦縑 撮廓簞 艙?? 
					{
						textcolor(LIGHTRED,WHITE );
						 gotoxy(41+(k*6),11+(j*3));printf("≒");
						 textcolor(BLACK, WHITE);
					}
				}
			}
		
		}
	}
	else if(p->state->infoMovie[0]==2)//2婦橾陽
	{

		for(j=0;j<6;j++)
		{
			for(k=0;k<10;k++)
			{
				if(p->state->infoMovie[1]==1)
				{
					if(p->movie->twoRoom[j][k].firstMovie==1)//2婦縑 羅廓簞 艙?? 
					{
						 textcolor(LIGHTRED,WHITE );
						gotoxy(41+(k*6),11+(j*3));printf("≒");
						textcolor(BLACK, WHITE);
				
					}
				}
				else if(p->state->infoMovie[1]==2)
				{
					if(p->movie->twoRoom[j][k].secondMovie==1)//2婦縑 舒廓簞 艙?? 
					{
						 textcolor(LIGHTRED,WHITE );
						gotoxy(41+(k*6),11+(j*3));printf("≒");
						 textcolor(BLACK, WHITE);
					}
				}
				else if(p->state->infoMovie[1]==3)
				{
					if(p->movie->twoRoom[j][k].thirdMovie==1)//2婦縑 撮廓簞 艙?? 
					{
						textcolor(LIGHTRED,WHITE );
						gotoxy(41+(k*6),11+(j*3));printf("≒");
						 textcolor(BLACK, WHITE);
					}
				}
			}
		
		}
	}
	else if(p->state->infoMovie[0]==3)//3婦橾陽
	{

		for(j=0;j<6;j++)
		{
			for(k=0;k<10;k++)
			{
				if(p->state->infoMovie[1]==1)
				{
					if(p->movie->threeRoom[j][k].firstMovie==1)//3婦縑 羅廓簞 艙?? 
					{
						 textcolor(LIGHTRED,WHITE );
						gotoxy(41+(k*6),11+(j*3));printf("≒");
						textcolor(BLACK, WHITE);
				
					}
				}
				else if(p->state->infoMovie[1]==2)
				{
					if(p->movie->threeRoom[j][k].secondMovie==1)//3婦縑 舒廓簞 艙?? 
					{
						 textcolor(LIGHTRED,WHITE );
						gotoxy(41+(k*6),11+(j*3));printf("≒");
						 textcolor(BLACK, WHITE);
					}
				}
				else if(p->state->infoMovie[1]==3)
				{
					if(p->movie->threeRoom[j][k].thirdMovie==1)//3婦縑 撮廓簞 艙?? 
					{
						textcolor(LIGHTRED,WHITE );
						gotoxy(41+(k*6),11+(j*3));printf("≒");
						 textcolor(BLACK, WHITE);
					}
				}
			}
		
		}
	}
	textcolor(LIGHTBLUE,WHITE);//頂陛 骯 ル
	gotoxy(41+((p->state->infoMovie[3]-1)*6),11+((p->state->infoMovie[2]-1)*3));printf("≒");
	textcolor(BLACK, WHITE);

	stateDisplay(p);

	return;


}
void movieDisplay(Head *p)
{ 
	
	textcolor(BLACK,LIGHTMAGENTA);
	gotoxy(1,8);printf("忙式式式式式式式式式式式式式式式式式式式式式忖");
    gotoxy(1,9);printf("弛                                          弛");
    gotoxy(1,10);printf("弛                                          弛");
	gotoxy(1,11);printf("弛                                          弛");
    gotoxy(1,12);printf("弛                                          弛");
    gotoxy(1,13);printf("弛                                          弛" );
	gotoxy(1,14);printf("弛                 1 婦                     弛");
	gotoxy(1,15);printf("弛                                          弛");
    gotoxy(1,16);printf("弛          忙㏑㏑㏑㏑㏑㏑㏑忖              弛");
	gotoxy(1,17);printf("弛          弛              弛              弛");
	gotoxy(1,18);printf("弛          弛≒            弛              弛");
    gotoxy(1,19);printf("戌式式式式式戎∼Ｃ          戌式式式式式式式戎");

	gotoxy(110,1);printf("忙式式式式式式式式式式式式忖");
    gotoxy(110,2);printf("弛                        弛");
    gotoxy(110,3);printf("弛                        弛");
	gotoxy(110,4);printf("弛                        弛");
    gotoxy(110,5);printf("弛                        弛");
    gotoxy(110,6);printf("弛                        弛" );
	gotoxy(110,7);printf("弛                        弛");
	gotoxy(110,8);printf("弛                        弛");
    gotoxy(110,9);printf("弛                        弛");
	gotoxy(110,10);printf("弛                        弛");
	gotoxy(110,11);printf("弛         3  婦          弛");
	gotoxy(110,12);printf("弛                        弛");
	gotoxy(110,13);printf("弛                        弛");
	gotoxy(110,14);printf("弛                        弛");
	gotoxy(110,15);printf("弛                        弛");
	gotoxy(110,16);printf("弛                        弛");
	gotoxy(110,17);printf("弛      忙㏑㏑㏑㏑忖      弛");
	gotoxy(110,18);printf("弛      弛        弛      弛");
	gotoxy(110,19);printf("弛      弛≒      弛      弛");
     gotoxy(110,20);printf("戌式式式戎∼Ｃ    戌式式式戎");
	

	gotoxy(55,1);printf("忙式式式式式式式式式式式式式式式式式式忖");
    gotoxy(55,2);printf("弛                                    弛");
    gotoxy(55,3);printf("弛                                    弛");
	gotoxy(55,4);printf("弛                                    弛");
    gotoxy(55,5);printf("弛                                    弛");
    gotoxy(55,6);printf("弛                                    弛" );
	gotoxy(55,7);printf("弛                 2 婦               弛");
	gotoxy(55,8);printf("弛                                    弛");
    gotoxy(55,9);printf("弛                                    弛");
	gotoxy(55,10);printf("弛                                    弛");
	gotoxy(55,11);printf("弛            忙㏑㏑㏑㏑㏑忖          弛");
	gotoxy(55,12);printf("弛            弛          弛          弛");
	gotoxy(55,13);printf("弛            弛≒        弛          弛");
    gotoxy(55,14);printf("戌式式式式式式戎∼Ｃ      戌式式式式式戎");
	
	textcolor(BLACK,WHITE);
	stateDisplay(p);
}