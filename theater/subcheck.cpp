#include "theater.h"

void subCheck(Head *p, int tag)
{
	int i;

	if(p->nowsituation->garbage>=20)
	{
		gotoxy(88,1);printf(" ┌＠＆▽┐");
		gotoxy(88,2);printf(" │＠§◐│");
		gotoxy(88,3);printf(" │§◎§│ ");
		gotoxy(88,4);printf(" │＠＆▽│");
		gotoxy(88,5);printf(" │♣§◎│");
		gotoxy(88,6);printf(" │＠§◐│");
		gotoxy(88,7);printf(" │§◎§│");
		gotoxy(88,8);printf(" │♣§◎│");
		gotoxy(88,9);printf(" └───┘");
	}
	else if(p->nowsituation->garbage >= 15 && p->nowsituation->garbage < 20)
	{
		gotoxy(88,1);printf(" ┌───┐");
		gotoxy(88,2);printf(" │      │");
		gotoxy(88,3);printf(" │  휴  │ ");
		gotoxy(88,4);printf(" │＠＆▥│");
		gotoxy(88,5);printf(" │♣§◈│");
		gotoxy(88,6);printf(" │＠§◎│");
		gotoxy(88,7);printf(" │§◎＠│");
		gotoxy(88,8);printf(" │♣§◈│");
		gotoxy(88,9);printf(" └───┘");
	}
	else if(p->nowsituation->garbage >=10 && p->nowsituation->garbage <15)
	{
		gotoxy(88,1);printf(" ┌───┐");
		gotoxy(88,2);printf(" │      │");
		gotoxy(88,3);printf(" │  휴  │ ");
		gotoxy(88,4);printf(" │  지  │");
		gotoxy(88,5);printf(" │  통  │");
		gotoxy(88,6);printf(" │＠§◎│");
		gotoxy(88,7);printf(" │♣※▣│");
		gotoxy(88,8);printf(" │＠◐◈│");
		gotoxy(88,9);printf(" └───┘");
	}
	else if(p->nowsituation->garbage >=5 && p->nowsituation->garbage < 10)
	{
		gotoxy(88,1);printf(" ┌───┐");
		gotoxy(88,2);printf(" │      │");
		gotoxy(88,3);printf(" │  휴  │ ");
		gotoxy(88,4);printf(" │  지  │");
		gotoxy(88,5);printf(" │  통  │");
		gotoxy(88,6);printf(" │      │");
		gotoxy(88,7);printf(" │      │");
		gotoxy(88,8);printf(" │＠◐◈│");
		gotoxy(88,9);printf(" └───┘");	}
	else
	{
		gotoxy(88,1);printf(" ┌───┐");
		gotoxy(88,2);printf(" │      │");
		gotoxy(88,3);printf(" │  휴  │ ");
		gotoxy(88,4);printf(" │  지  │");
		gotoxy(88,5);printf(" │  통  │");
		gotoxy(88,6);printf(" │      │");
		gotoxy(88,7);printf(" │      │");
		gotoxy(88,8);printf(" │      │");
		gotoxy(88,9);printf(" └───┘");
	}

	if(tag == 1)
	{
		p->nowsituation->temperature += 0.1;
	}
	if(p->nowsituation->temperature >= 28)
	{
//		gotoxy(2, 6); printf("에어컨!!");
		degreePerson(p);
	}

	if( p->nowsituation->garbage >= 20)
	{
//		gotoxy(2, 7); printf("쓰레기!!");
		trashPerson(p);
	}
	//printf("%d",p->nowsituation->temperature);
}

void trashPerson(Head *p)
{
	int sX;
	int sY;
	int eX;
	int eY;
	int i;
	sX = 10;
	sY = 15;
	eX = 92;
	eY = 10;

	if(sX==eX&&sY==eY)
	{
		gotoxy(sX,sY);printf("  ●");
		gotoxy(sX,sY+1);printf("-│-");
		gotoxy(sX,sY+2);printf(" │");
		gotoxy(sX,sY+3);printf(" ∥");
	}
	
	if(sX<eX) // 오르쪽으로갈때
	{
		for(i=0;i<eX-sX;i++)
		{
			moveStop(p);
			if(i%3==0)
			{
				gotoxy(sX+i,sY);printf("   ●");
				gotoxy(sX+i,sY+1);printf("  //△");
				gotoxy(sX+i,sY+2);printf("  ┃□");
				gotoxy(sX+i,sY+3);printf("  /＼");
				sX=sX+i;
				Sleep(50);
				clrscr(sX,sY,sX+i,sY+3);  
			}
			else if(i%3!=1)
			{
				gotoxy(sX+i,sY);printf("   ●");
				gotoxy(sX+i,sY+1);printf("  //△");
				gotoxy(sX+i,sY+2);printf("  ┃□");
				gotoxy(sX+i,sY+3);printf("  ∥");
				sX=sX+i;
				Sleep(50);
				clrscr(sX,sY,sX+i,sY+3); 
			}
			else if(i%3!=2)
			{
				gotoxy(sX+i,sY);printf("   ●");
				gotoxy(sX+i,sY+1);printf(" //△");
				gotoxy(sX+i,sY+2);printf(" ┃□");
				gotoxy(sX+i,sY+3);printf( "┘┐");
				sX=sX+i;
				Sleep(50);
				clrscr(sX,sY,sX+i,sY+3); 
			}
			clrscr(sX,sY,sX+i+3,sY+3);
		}
	}
	if(sY>eY)
	{
		for(i=0;i<sY-eY;i++) //올라갈떄
		{
			moveStop(p);
			if(i%3==0)
			{
				gotoxy(eX,sY-i); printf("  ∥");
				gotoxy(eX,sY-i-1);printf("□┃");
				gotoxy(eX,sY-i-2);printf("△//");
				gotoxy(eX,sY-i-3);printf("  ●");
				Sleep(50);
				clrscr(eX,sY-i-3,eX+6,sY-i+3);
				
			}
			else if(i%3!=1)
			{
				gotoxy(eX,sY-i);printf("  ∥");
				gotoxy(eX,sY-i-1);printf(" □┃");
				gotoxy(eX,sY-i-2);printf(" △//");
				gotoxy(eX,sY-i-3);printf("  ●");
				Sleep(50);
				clrscr(eX,sY-i-3,eX+6,sY-i+3);
				
			}
			else if(i%3!=2)
			{
				gotoxy(eX,sY-i);printf("  ∥");
				gotoxy(eX,sY-i-1);printf("□┃");
				gotoxy(eX,sY-i-2);printf("△//");
				gotoxy(eX,sY-i-3);printf("  ● ");
				Sleep(50);
				clrscr(eX,sY-i-3,eX+6,sY-i+3);			
			}
		}
		
gotoxy(88,1);printf(" ┌───┐");
 gotoxy(88,2);printf(" │      │");
 gotoxy(88,3);printf(" │  휴  │ ");
 gotoxy(88,4);printf(" │  지  │");
 gotoxy(88,5);printf(" │  통  │");
 gotoxy(88,6);printf(" │      │");
 gotoxy(88,7);printf(" │      │");
 gotoxy(88,8);printf(" │      │");
 gotoxy(88,9);printf(" └───┘");
	}

	sX = 95;
	sY = 12;
	eX = 15;
	eY = 20;

	if(sX>eX)
	{
		for(i=0;i<sX-eX;i++)// 왼쪽으로 갈때 x축
		{
			moveStop(p);
			if(i%3==0)
			{
				gotoxy(sX-i,sY);printf("  ●");
				gotoxy(sX-i,sY+1);printf("△＼＼");
				gotoxy(sX-i,sY+2);printf("□┃");
				gotoxy(sX-i,sY+3);printf(" │＼");
				Sleep(50);
				sX = sX-i;
				clrscr(sX,sY,sX+i+3,sY+4);  
			}
			else if(i%3!=1)
			{
				gotoxy(sX-i,sY);printf("  ●");
				gotoxy(sX-i,sY+1);printf("△＼＼");
				gotoxy(sX-i,sY+2);printf("□┃");
				gotoxy(sX-i,sY+3);printf("  ∥");
				Sleep(50);
				sX = sX-i;
				clrscr(sX,sY,sX+i+3,sY+4);
			}
			else if(i%3!=2)
			{
				gotoxy(sX-i,sY);printf("  ●");
				gotoxy(sX-i,sY+1);printf("△＼＼");
				gotoxy(sX-i,sY+2);printf("□┃");
				gotoxy(sX-i,sY+3);printf(" ┌ ┘");
				Sleep(50);
				sX = sX-i;
				clrscr(sX,sY,sX+i+3,sY+4); 
			}
			clrscr(sX,sY,sX+i+1,sY+4);
		}
	}

	if(sY<eY)
	{
		for(i=0;i<eY-sY;i++) //내려갈때
		{
			moveStop(p);
			if(i%3==0)
			{
				gotoxy(eX,sY+i); printf("  ●");
				gotoxy(eX,sY+i+1);printf(" //△");
				gotoxy(eX,sY+i+2);printf(" ┃□");
				gotoxy(eX,sY+i+3);printf(" ∥");
				Sleep(50);
				clrscr(eX,sY+i-4,eX+5,sY+i+3);
			}
			else if(i%3!=1)
			{
				gotoxy(eX,sY+i);printf("  ●");
				gotoxy(eX,sY+i+1);printf(" //△");
				gotoxy(eX,sY+i+2);printf(" ┃□");
				gotoxy(eX,sY+i+3);printf(" ∥");
				Sleep(50);
				clrscr(eX,sY+i-4,eX+5,sY+i+3);
			}
			else if(i%3!=2)
			{
				gotoxy(eX,sY+i);printf("  ●");
				gotoxy(eX,sY+i+1);printf(" //△");
				gotoxy(eX,sY+i+2);printf(" ┃□");
				gotoxy(eX,sY+i+3);printf(" ∥");
				Sleep(50);
				clrscr(eX,sY+i-4,eX+5,sY+i+3);
			}
		}
	}
	p->nowsituation->garbage = 0;
}

void degreePerson(Head *p)
{
	
	int i;
	int sX,sY,eX,eY;

	sX = 13;
	sY = 18;
	eX = 20;
	eY = 10;

	display(p);

	if(sX==eX&&sY==eY)
	{
		gotoxy(sX,sY);printf("  ●");
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
				gotoxy(sX+i,sY+1);printf("┏╋☞");
				gotoxy(sX+i,sY+2);printf("  ┃");
				gotoxy(sX+i,sY+3);printf("  /＼");
				sX=sX+i;
				Sleep(50);
				clrscr(sX,sY,sX+i,sY+3);  
			}
			else if(i%3!=1)
			{
				gotoxy(sX+i,sY);printf("   ●");
				gotoxy(sX+i,sY+1);printf("┗╋☞");
				gotoxy(sX+i,sY+2);printf("  ┃");
				gotoxy(sX+i,sY+3);printf("  ∥");
				sX=sX+i;
				Sleep(50);
				clrscr(sX,sY,sX+i,sY+3); 
			}
			else if(i%3!=2)
			{
				gotoxy(sX+i,sY);printf("   ●");
				gotoxy(sX+i,sY+1);printf("┏╋☞");
				gotoxy(sX+i,sY+2);printf(" ┃  ");
				gotoxy(sX+i,sY+3);printf( "┘┐");
				sX=sX+i;
				Sleep(50);
				clrscr(sX,sY,sX+i,sY+3); 
			}
			clrscr(sX,sY,sX+i+3,sY+3);
		}
	}
	if(sY>eY)
	{
		for(i=0;i<sY-eY;i++) //올라갈떄
		{
			if(i%3==0)
			{
				gotoxy(eX,sY-i); printf("  ∥");
				gotoxy(eX,sY-i-1);printf("  ┃");
				gotoxy(eX,sY-i-2);printf("☜╋┛");
				gotoxy(eX,sY-i-3);printf("  ●");
				Sleep(50);
				clrscr(eX,sY-i-3,eX+6,sY-i+3);

			}
			else if(i%3!=1)
			{
				gotoxy(eX,sY-i);printf("  ∥");
				gotoxy(eX,sY-i-1);printf("  ┃");
				gotoxy(eX,sY-i-2);printf("☜╋┓");
				gotoxy(eX,sY-i-3);printf("  ●");
				Sleep(50);
				clrscr(eX,sY-i-3,eX+6,sY-i+3);

			}
			else if(i%3!=2)
			{
				gotoxy(eX,sY-i);printf("  ∥");
				gotoxy(eX,sY-i-1);printf("  ┃");
				gotoxy(eX,sY-i-2);printf("☜╋┛");
				gotoxy(eX,sY-i-3);printf("  ● ");
				Sleep(50);
				clrscr(eX,sY-i-3,eX+6,sY-i+3);
			}
		}
	}
	gotoxy(20,11);printf("  ∥");
	gotoxy(20,10);printf("  ┃");
	gotoxy(20,9);printf("☜╋┛");
    gotoxy(20,8);printf("  ● ");
	Sleep(800);
	clrscr(eX,sY-i-3,eX+6,sY-i+3);

	gotoxy(18,7);printf("§  §  §  §  §  § ");
    gotoxy(18,8);printf("  §  §  §  §  §  ");
	Sleep(200);
	gotoxy(18,7);printf("  §  §  §  §  §  ");
	gotoxy(18,8);printf("§  §  §  §  §  §");
	Sleep(200);
	gotoxy(18,7);printf("§  §  §  §  §  § ");
    gotoxy(18,8);printf("  §  §  §  §  §  ");
	Sleep(200);
    gotoxy(18,7);printf("  §  §  §  §  §  ");
	gotoxy(18,8);printf("§  §  §  §  §  §");
	Sleep(200);
	gotoxy(18,7);printf("§  §  §  §  §  § ");
    gotoxy(18,8);printf("  §  §  §  §  §  ");
	Sleep(200);
    gotoxy(18,7);printf("  §  §  §  §  §  ");
	gotoxy(18,8);printf("§  §  §  §  §  §");
	Sleep(200);
	gotoxy(18,7);printf("§  §  §  §  §  § ");
    gotoxy(18,8);printf("  §  §  §  §  §  ");
	Sleep(200);


	sX = 20;
	sY = 10;
	eX = 14;
	eY = 18;
	if(sX>eX)
	{
		for(i=0;i<sX-eX;i++)// 왼쪽으로 갈때 x축
		{
			if(i%3==0)
			{
				gotoxy(sX-i,sY);printf("  ●");
				gotoxy(sX-i,sY+1);printf("☜╋┓");
				gotoxy(sX-i,sY+2);printf("  ┃");
				gotoxy(sX-i,sY+3);printf(" │＼");
				Sleep(50);
				clrscr(sX-i,sY,sX+i+5,sY+4);  
			}
			else if(i%3!=1)
			{
				gotoxy(sX-i,sY);printf("  ●");
				gotoxy(sX-i,sY+1);printf("☜╋┛");
				gotoxy(sX-i,sY+2);printf("  ┃");
				gotoxy(sX-i,sY+3);printf("  ∥");
				Sleep(50);
				clrscr(sX-i,sY,sX+i+5,sY+4);
			}
			else if(i%3!=2)
			{
				gotoxy(sX-i,sY);printf("  ●");
				gotoxy(sX-i,sY+1);printf("☜╋┓");
				gotoxy(sX-i,sY+2);printf("  ┃");
				gotoxy(sX-i,sY+3);printf(" ┌ ┘");
				Sleep(50);
				clrscr(sX-i,sY,sX+i+5,sY+4); 
			}
			clrscr(sX-i,sY,sX+i+1,sY+4);
		}
	}

	if(sY<eY)
	{
		for(i=0;i<eY-sY;i++) //내려갈때
		{
			if(i%3==0)
			{
				gotoxy(eX,sY+i); printf("  ●");
				gotoxy(eX,sY+i+1);printf("┏╋☞");
				gotoxy(eX,sY+i+2);printf("  ┃ ");
				gotoxy(eX,sY+i+3);printf("  ∥");
				Sleep(50);
				clrscr(eX,sY+i,eX+5,sY+i+3);
			}
			else if(i%3!=1)
			{
				gotoxy(eX,sY+i);printf("  ●");
				gotoxy(eX,sY+i+1);printf("┏╋☞");
				gotoxy(eX,sY+i+2);printf("  ┃");
				gotoxy(eX,sY+i+3);printf("  ∥");
				Sleep(50);
				clrscr(eX,sY+i,eX+5,sY+i+3);
			}
			else if(i%3!=2)
			{
				gotoxy(eX,sY+i);printf("  ●");
				gotoxy(eX,sY+i+1);printf("┗╋☞");
				gotoxy(eX,sY+i+2);printf("  ┃");
				gotoxy(eX,sY+i+3);printf("  ∥");
				Sleep(50);
				clrscr(eX,sY+i,eX+5,sY+i+3);
			}
		}
	}
	gotoxy(18,7);printf("                             ");
	gotoxy(18,8);printf("                             ");
	p->nowsituation->temperature = p->nowsituation->temperature-2;
	p->nowsituation->electronic++;
	if(p->nowsituation->electronic >= 3)
	{
		elePerson(p);
		p->nowsituation->electronic = 0;
	}
}

void elePerson(Head *p)
{
    int i;
	int sX,sY,eX,eY;

	sX = 1;
	sY = 22;
	eX = 70;
	eY = 22;

	display(p);
	Sleep(200);
	system("cls");
	textcolor(WHITE, BLACK); 

	printf("                                                                                                              ");
	printf("                                                                                                              ");
	printf("                                                                                                              ");
	printf("                                                                                                              ");
	printf("                                                                                                              ");
	printf("                                                                                                              ");
	printf("                                                                                                              ");
	printf("                                                                                                              ");
	printf("                                                                                                              ");
	printf("                                                                                                              ");
	printf("                                                                                                              ");
	printf("                                                                                                              ");
	printf("                                                                                                              ");
	printf("                                                                                                              ");
	printf("                                                                                                              ");
	printf("                                                                                                              ");
	printf("                                                                                                              ");
	printf("                                                                                                              ");
	printf("                                                                                                              ");
	printf("                                                                                                              ");
	printf("                                                                                                              ");
	printf("                                                                                                              ");
	printf("                                                                                                              ");
	printf("                                                                                                              ");
	printf("                                                                                                              ");
	printf("                                                                                                              ");
	printf("                                                                                                              ");
	printf("                                                                                                              ");
	printf("                                                                                                              ");
	printf("                                                                                                              ");
	printf("                                                                                                              ");
	printf("                                                                                                              ");
	printf("                                                                                                              ");
	printf("                                                                                                              ");
	printf("                                                                                                              ");
	printf("                                                                                                              ");
	printf("                                                                                                              ");
	printf("                                                                                                              ");
	printf("                                                                                                              ");
	printf("                                                                                                              ");
	printf("                                                                                                              ");
	printf("                                                                                                              ");
	printf("                                                                                                              ");
	printf("                                                                                                              ");
	printf("                                                                                                              ");
	printf("                                                                                                              ");
	printf("                                                                                                              ");
	printf("                                                                                                              ");
	printf("                                                                                                              ");
	printf("                                                                                                              ");
	printf("                                                                                                    ");
	/*gotoxy(1,22);
	printf("   ●");
	gotoxy(1,23); 
	printf("  ┖◁□");
	gotoxy(1,24); 
	printf("  ┃");
	gotoxy(1,25);
	printf("  /＼");*/
	if(sX<eX) // 오르쪽으로갈때
	{
		for(i=0;i<eX-sX;i++)
		{
			if(i==10)
			{
				clrscr(sX,sY,sX+i+10,sY+3);
				gotoxy(sX+i,sY);printf("   ●");
				gotoxy(sX+i,sY+1);printf("  ┖◁");textcolor(YELLOW, BLACK);printf("■■■");
				textcolor(WHITE, BLACK);gotoxy(sX+i,sY+2);printf("  ┃");
				gotoxy(sX+i,sY+3);printf("  ∥");
				Sleep(100);
				clrscr(sX,sY,sX+i+10,sY+3);
				gotoxy(sX+i,sY);printf("   ●");
				gotoxy(sX+i,sY+1);printf("  ┖◁");textcolor(YELLOW, BLACK);printf("■■");
				textcolor(WHITE, BLACK);gotoxy(sX+i,sY+2);printf("  ┃");
				gotoxy(sX+i,sY+3);printf("  ∥");
				Sleep(200);
				clrscr(sX,sY,sX+i+10,sY+3);
				gotoxy(sX+i,sY);printf("   ●");
				gotoxy(sX+i,sY+1);textcolor(YELLOW, BLACK);printf("  ■");
				textcolor(WHITE, BLACK);gotoxy(sX+i,sY+2);printf("  ┃");
				gotoxy(sX+i,sY+3);printf("  ∥");
				Sleep(500);
				clrscr(sX,sY,sX+i+10,sY+3);
				gotoxy(sX+i,sY);printf("    ●");
				gotoxy(sX+i,sY+1);textcolor(YELLOW, BLACK);printf("■");textcolor(WHITE, BLACK);printf("▷┛");
				gotoxy(sX+i,sY+2);printf("    ┃");
				gotoxy(sX+i,sY+3);printf("    ∥");
				Sleep(500);
				clrscr(sX,sY,sX+i+10,sY+3);
				gotoxy(sX+i,sY);printf("   ●");
				gotoxy(sX+i,sY+1);textcolor(YELLOW, BLACK);printf("  ■");textcolor(WHITE, BLACK);
				gotoxy(sX+i,sY+2);printf("  ┃");
				gotoxy(sX+i,sY+3);printf("  ∥");
				Sleep(500);
				clrscr(sX,sY,sX+i+10,sY+3);
				gotoxy(sX+i,sY);printf("   ●");
				gotoxy(sX+i,sY+1);printf("  ┖◁");textcolor(YELLOW, BLACK);printf("■■");textcolor(WHITE, BLACK);
				gotoxy(sX+i,sY+2);printf("  ┃");
				gotoxy(sX+i,sY+3);printf("  ∥");
				Sleep(200);
				clrscr(sX,sY,sX+i+10,sY+3);
				gotoxy(sX+i,sY);printf("   ●");
				gotoxy(sX+i,sY+1);printf("  ┖◁");textcolor(YELLOW, BLACK);printf("■■■");textcolor(WHITE, BLACK);
				gotoxy(sX+i,sY+2);printf("  ┃");
				gotoxy(sX+i,sY+3);printf("  ∥");
				Sleep(100);
			}
			if(i%3==0)
			{
				gotoxy(sX+i,sY);printf("   ●  ");textcolor(YELLOW, BLACK);printf("/■■");textcolor(WHITE, BLACK);
				gotoxy(sX+i,sY+1);printf("  ┖◁");textcolor(YELLOW, BLACK);printf("■■■");textcolor(WHITE, BLACK);
				gotoxy(sX+i,sY+2);printf("  ┃  ");textcolor(YELLOW, BLACK);printf("＼■■");textcolor(WHITE, BLACK);
				gotoxy(sX+i,sY+3);printf("  /＼");
				Sleep(50);
				sX=i;
				clrscr(sX,sY,sX+i,sY+3);  
			}
			else if(i%3!=1)
			{  
				gotoxy(sX+i,sY);printf("   ●   ");textcolor(YELLOW, BLACK);printf("/■");textcolor(WHITE, BLACK);
				gotoxy(sX+i,sY+1);printf("  ┖◁");textcolor(YELLOW, BLACK);printf("■■■");textcolor(WHITE, BLACK);
				gotoxy(sX+i,sY+2);printf("  ┃  ");textcolor(YELLOW, BLACK);printf("＼■■");textcolor(WHITE, BLACK);
				gotoxy(sX+i,sY+3);printf("  ∥");
				Sleep(50);
				sX=i;
				clrscr(sX,sY,sX+i,sY+3); 
			}
			else if(i%3!=2)
			{
				gotoxy(sX+i,sY);printf("   ●  ");textcolor(YELLOW, BLACK);printf("/■■");textcolor(WHITE, BLACK);
				gotoxy(sX+i,sY+1);printf("  ┖◁");textcolor(YELLOW, BLACK);printf("■■■");textcolor(WHITE, BLACK);
				gotoxy(sX+i,sY+2);printf("  ┃  ");textcolor(YELLOW, BLACK);printf("＼■■");textcolor(WHITE, BLACK);
				gotoxy(sX+i,sY+3);printf("  ┘┐");
				Sleep(50);
				sX=i;
				clrscr(sX,sY,sX+i,sY+3); 
			}
		}
	}
	textcolor(BLACK,WHITE);
	system("cls");
	display(p);
	sX = 70;
	sY = 12;
	eX = 15;
	eY = 18;
	if(sX>eX)
	{
		for(i=0;i<sX-eX;i++)// 왼쪽으로 갈때 x축
		{
			if(i%3==0)
			{
				gotoxy(sX-i,sY);printf("  ●");
				gotoxy(sX-i,sY+1);printf("▷┛");
				gotoxy(sX-i,sY+2);printf("  ┃");
				gotoxy(sX-i,sY+3);printf(" │＼");
				Sleep(50);
				sX=sX-i;
				clrscr(sX-i,sY,sX+i+10,sY+4);  
			}
			else if(i%3!=1)
			{
				gotoxy(sX-i,sY);printf("  ●");
				gotoxy(sX-i,sY+1);printf("▷┛");
				gotoxy(sX-i,sY+2);printf("  ┃");
				gotoxy(sX-i,sY+3);printf(" ∥");
				Sleep(50);
				sX=sX-i;
				clrscr(sX-i,sY,sX+i+10,sY+4);
			}
			else if(i%3!=2)
			{
				gotoxy(sX-i,sY);printf("  ●");
				gotoxy(sX-i,sY+1);printf("▷┛");
				gotoxy(sX-i,sY+2);printf("  ┃");
				gotoxy(sX-i,sY+3);printf("┌ ┘");
				Sleep(50);
				sX=sX-i;
				clrscr(sX-i,sY,sX+i+10,sY+4); 
			}
			clrscr(sX,sY,sX+i+10,sY+4);
		}
	}

	if(sY<eY)
	{
		for(i=0;i<eY-sY;i++) //내려갈때
		{
			if(i%3==0)
			{
				gotoxy(eX,sY+i); printf("  ●");
				gotoxy(eX,sY+i+1);printf(" □");
				gotoxy(eX,sY+i+2);printf(" ┃");
				gotoxy(eX,sY+i+3);printf(" ∥");
				Sleep(50);
				clrscr(eX,sY+i-4,eX+5,sY+i+3);
			}
			else if(i%3!=1)
			{
				gotoxy(eX,sY+i);printf("   ●");
				gotoxy(eX,sY+i+1);printf(" □");
				gotoxy(eX,sY+i+2);printf(" ┃");
				gotoxy(eX,sY+i+3);printf(" ∥");
				Sleep(50);
				clrscr(eX,sY+i-4,eX+5,sY+i+3);
			}
			else if(i%3!=2)
			{
				gotoxy(eX,sY+i);printf(" ●");
				gotoxy(eX,sY+i+1);printf(" □");
				gotoxy(eX,sY+i+2);printf(" ┃");
				gotoxy(eX,sY+i+3);printf(" ∥");
				Sleep(50);
				clrscr(eX,sY+i-4,eX+5,sY+i+3);
			}
		}
	}
}
