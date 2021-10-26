#include "theater.h"

void snackdisplay();
void menu();

void mySnack(Head *p)
{
	int sel=0;
	char ch;
	guest(p);
	system("cls");
	snackdisplay();
	menu();
	while(1)
	{
		gotoxy(5,32);printf("어떤종류를 구매하시겠습니까? (1:팝콘/2:음료/3:기타) : ");
		fflush(stdin);
		ch=getchar();
		if(ch==ESC) //esc 눌렀을경우 
		{
		    break;
		}
		else if(ch=='1')
		{
			gotoxy(5,33);printf(" 1.대 . 2.중 , 3.소 ? : ");
			scanf("%d",&sel);
			if(sel==1)
			{
				gotoxy(5,34);printf("어떤맛을 추가하시겠습니까?(1.갈릭/2.양파/3.갈비/4.추가안함) : ");
				scanf("%d",&sel);
				if(sel==1)
				{
					if(p->state->money<7500)
					{
						gotoxy(5,35);printf("돈이 모자릅니다.");
						getch();
						clrscr(3,31,70,38);
						continue;
					}
				    p->state->snack[0]=1;
				    p->nowsituation->snackCount[0]++;
				    p->state->money-=7500;
					gotoxy(5,35);printf("더 구매하시겠습니까?(y/n) : ");
					fflush(stdin);
					ch=getchar();
					if(ch=='y'||ch=='Y')
					{
						clrscr(3,31,70,38);
						continue;
					}
					else
					{
						break;
					}
				}
				else if(sel==2)
				{
					if(p->state->money<7700)
					{
						gotoxy(5,35);printf("돈이 모자릅니다.");
						getch();
						clrscr(3,31,70,38);
						continue;
					}
				    p->state->snack[0]=1;
				    p->nowsituation->snackCount[0]++;
				    p->state->money-=7700;
					gotoxy(5,35);printf("더 구매하시겠습니까?(y/n) : ");
					fflush(stdin);
					ch=getchar();
					if(ch=='y'||ch=='Y')
					{
						clrscr(3,31,70,38);
						continue;
					}
					else
					{
						break;
					}
				}
				else if(sel==3)
				{
					if(p->state->money<8000)
					{
						gotoxy(5,35);printf("돈이 모자릅니다.");
						getch();
						clrscr(3,31,70,38);
						continue;
					}
				    p->state->snack[0]=1;
				    p->nowsituation->snackCount[0]++;
				    p->state->money-=8000;
					gotoxy(5,35);printf("더 구매하시겠습니까?(y/n) : ");
					fflush(stdin);
					ch=getchar();
					if(ch=='y'||ch=='Y')
					{
						clrscr(3,31,70,38);
						continue;
					}
					else
					{
						break;
					}
				}
				else if(sel==4)
				{
					if(p->state->money<7000)
					{
						gotoxy(5,35);printf("돈이 모자릅니다.");
						getch();
						clrscr(3,31,70,38);
						continue;
					}
				    p->state->snack[0]=1;
				    p->nowsituation->snackCount[0]++;
				    p->state->money-=7000;
					gotoxy(5,35);printf("더 구매하시겠습니까?(y/n) : ");
					fflush(stdin);
					ch=getchar();
					if(ch=='y'||ch=='Y')
					{
						clrscr(3,31,70,38);
						continue;
					}
					else
					{
						break;
					}
				}
			}
			else if(sel==2)
	     	{
				gotoxy(5,34);printf("어떤맛을 추가하시겠습니까?(1.갈릭/2.양파/3.갈비/4.추가안함) : ");
				scanf("%d",&sel);
				if(sel==1)
				{
					if(p->state->money<5500)
					{
						gotoxy(5,35);printf("돈이 모자릅니다.");
						getch();
						clrscr(3,31,70,38);
						continue;
					}
				    p->state->snack[0]=1;
				    p->nowsituation->snackCount[0]++;
				    p->state->money-=5500;
					gotoxy(5,35);printf("더 구매하시겠습니까?(y/n) : ");
					fflush(stdin);
					ch=getchar();
					if(ch=='y'||ch=='Y')
					{
						clrscr(3,31,70,38);
						continue;
					}
					else
					{
						break;
					}
				}
				else if(sel==2)
				{
					if(p->state->money<5700)
					{
						gotoxy(5,35);printf("돈이 모자릅니다.");
						getch();
						clrscr(3,31,70,38);
						continue;
					}
				    p->state->snack[0]=1;
				    p->nowsituation->snackCount[0]++;
				    p->state->money-=5700;
					gotoxy(5,35);printf("더 구매하시겠습니까?(y/n) : ");
					fflush(stdin);
					ch=getchar();
					if(ch=='y'||ch=='Y')
					{
						clrscr(3,31,70,38);
						continue;
					}
					else
					{
						break;
					}
				}
				else if(sel==3)
				{
					if(p->state->money<6000)
					{
						gotoxy(5,35);printf("돈이 모자릅니다.");
						getch();
						clrscr(3,31,70,38);
						continue;
					}
				    p->state->snack[0]=1;
				    p->nowsituation->snackCount[0]++;
				    p->state->money-=6000;
					gotoxy(5,35);printf("더 구매하시겠습니까?(y/n) : ");
					fflush(stdin);
					ch=getchar();
					if(ch=='y'||ch=='Y')
					{
						clrscr(3,31,70,38);
						continue;
					}
					else
					{
						break;
					}
				}
				else if(sel==4)
				{
					if(p->state->money<5000)
					{
						gotoxy(5,35);printf("돈이 모자릅니다.");
						getch();
						clrscr(3,31,70,38);
						continue;
					}
				    p->state->snack[0]=1;
				    p->nowsituation->snackCount[0]++;
				    p->state->money-=5000;
					gotoxy(5,35);printf("더 구매하시겠습니까?(y/n) : ");
					fflush(stdin);
					ch=getchar();
					if(ch=='y'||ch=='Y')
					{
						clrscr(3,31,70,38);
						continue;
					}
					else
					{
						break;
					}
				}
			}
			else if(sel==3)
			{
				gotoxy(5,34);printf("어떤맛을 추가하시겠습니까?(1.갈릭/2.양파/3.갈비/4.추가안함) : ");
				scanf("%d",&sel);
				if(sel==1)
				{
					if(p->state->money<3500)
					{
						gotoxy(5,35);printf("돈이 모자릅니다.");
						getch();
						clrscr(3,31,70,38);
						continue;
					}
				    p->state->snack[0]=1;
				    p->nowsituation->snackCount[0]++;
				    p->state->money-=3500;
					gotoxy(5,35);printf("더 구매하시겠습니까?(y/n) : ");
					fflush(stdin);
					ch=getchar();
					if(ch=='y'||ch=='Y')
					{
						clrscr(3,31,70,38);
						continue;
					}
					else
					{
						break;
					}
				}
				else if(sel==2)
				{
					if(p->state->money<3700)
					{
						gotoxy(5,35);printf("돈이 모자릅니다.");
						getch();
						clrscr(3,31,70,38);
						continue;
					}
				    p->state->snack[0]=1;
				    p->nowsituation->snackCount[0]++;
				    p->state->money-=3700;
					gotoxy(5,35);printf("더 구매하시겠습니까?(y/n) : ");
					fflush(stdin);
					ch=getchar();
					if(ch=='y'||ch=='Y')
					{
						clrscr(3,31,70,38);
						continue;
					}
					else
					{
						break;
					}
				}
				else if(sel==3)
				{
					if(p->state->money<4000)
					{
						gotoxy(5,35);printf("돈이 모자릅니다.");
						getch();
						clrscr(3,31,70,38);
						continue;
					}
				    p->state->snack[0]=1;
				    p->nowsituation->snackCount[0]++;
				    p->state->money-=4000;
					gotoxy(5,35);printf("더 구매하시겠습니까?(y/n) : ");
					fflush(stdin);
					ch=getchar();
					if(ch=='y'||ch=='Y')
					{
						clrscr(3,31,70,38);
						continue;
					}
					else
					{
						break;
					}
				}
				else if(sel==4)
				{
					if(p->state->money<3000)
					{
						gotoxy(5,35);printf("돈이 모자릅니다.");
						getch();
						clrscr(3,31,70,38);
						continue;
					}
				    p->state->snack[0]=1;
				    p->nowsituation->snackCount[0]++;
				    p->state->money-=3000;
					gotoxy(5,35);printf("더 구매하시겠습니까?(y/n) : ");
					fflush(stdin);
					ch=getchar();
					if(ch=='y'||ch=='Y')
					{
						clrscr(3,31,70,38);
						continue;
					}
					else
					{
						break;
					}
				}
			}
		}
		else if(ch=='2')
		{
			gotoxy(5,33);printf(" 1.콜라 / 2.사이다 : ");
			scanf("%d",&sel);
			if(sel==1)
			{
				gotoxy(5,34);printf(" 1.대 / 2.중 / 3.소 : ");
				scanf("%d",&sel);
				if(sel==1)
				{
					if(p->state->money<2000)
					{
						gotoxy(5,35);printf("돈이 모자릅니다.");
						getch();
						clrscr(3,31,70,38);
						continue;
					}
				    p->state->snack[1]=1;
				    p->nowsituation->snackCount[1]++;
				    p->state->money-=2000;
					gotoxy(5,35);printf("더 구매하시겠습니까?(y/n) : ");
					fflush(stdin);
					ch=getchar();
					if(ch=='y'||ch=='Y')
					{
						clrscr(3,31,70,38);
						continue;
					}
					else
					{
						break;
					}
				}
				else if(sel==2)
				{
					if(p->state->money<1500)
					{
						gotoxy(5,35);printf("돈이 모자릅니다.");
						getch();
						clrscr(3,31,70,38);
						continue;
					}
				    p->state->snack[1]=1;
				    p->nowsituation->snackCount[1]++;
				    p->state->money-=1500;
					gotoxy(5,35);printf("더 구매하시겠습니까?(y/n) : ");
					fflush(stdin);
					ch=getchar();
					if(ch=='y'||ch=='Y')
					{
						clrscr(3,31,70,38);
						continue;
					}
					else
					{
						break;
					}
				}
				else if(sel==3)
				{
					if(p->state->money<1000)
					{
						gotoxy(5,35);printf("돈이 모자릅니다.");
						getch();
						clrscr(3,31,70,38);
						continue;
					}
				    p->state->snack[1]=1;
				    p->nowsituation->snackCount[1]++;
				    p->state->money-=1000;
					gotoxy(5,35);printf("더 구매하시겠습니까?(y/n) : ");
					fflush(stdin);
					ch=getchar();
					if(ch=='y'||ch=='Y')
					{
						clrscr(3,31,70,38);
						continue;
					}
					else
					{
						break;
					}
				}
			}
			else if(sel==2)
			{
		    	gotoxy(5,34);printf(" 1.대 / 2.중 / 3.소 : ");
				scanf("%d",&sel);
				if(sel==1)
				{
					if(p->state->money<2000)
					{
						gotoxy(5,35);printf("돈이 모자릅니다.");
						getch();
						clrscr(3,31,70,38);
						continue;
					}
				    p->state->snack[2]=1;
				    p->nowsituation->snackCount[2]++;
				    p->state->money-=2000;
					gotoxy(5,35);printf("더 구매하시겠습니까?(y/n) : ");
					fflush(stdin);
					ch=getchar();
					if(ch=='y'||ch=='Y')
					{
						clrscr(3,31,70,38);
						continue;
					}
					else
					{
						break;
					}
				}
				else if(sel==2)
				{
					if(p->state->money<1500)
					{
						gotoxy(5,35);printf("돈이 모자릅니다.");
						getch();
						clrscr(3,31,70,38);
						continue;
					}
				    p->state->snack[2]=1;
				    p->nowsituation->snackCount[2]++;
				    p->state->money-=1500;
					gotoxy(5,35);printf("더 구매하시겠습니까?(y/n) : ");
					fflush(stdin);
					ch=getchar();
					if(ch=='y'||ch=='Y')
					{
						clrscr(3,31,70,38);
						continue;
					}
					else
					{
						break;
					}
				}
				else if(sel==3)
				{
					if(p->state->money<1000)
					{
						gotoxy(5,35);printf("돈이 모자릅니다.");
						getch();
						clrscr(3,31,70,38);
						continue;
					}
				    p->state->snack[2]=1;
				    p->nowsituation->snackCount[2]++;
				    p->state->money-=1000;
					gotoxy(5,35);printf("더 구매하시겠습니까?(y/n) : ");
					fflush(stdin);
					ch=getchar();
					if(ch=='y'||ch=='Y')
					{
						clrscr(3,31,70,38);
						continue;
					}
					else
					{
						break;
					}
				}
			}
		}
		else if(ch=='3')
		{
			gotoxy(5,33);printf(" 1.나쵸 / 2.오징어 : ");
			scanf("%d",&sel);
			if(sel==1)
			{
				if(p->state->money<5000)
					{
						gotoxy(5,34);printf("돈이 모자릅니다.");
						getch();
						clrscr(3,31,70,38);
						continue;
					}
			    p->state->snack[3]=1;
			    p->nowsituation->snackCount[3]++;
			    p->state->money-=5000;
			    gotoxy(5,34);printf("더 구매하시겠습니까?(y/n) : ");
				fflush(stdin);
				ch=getchar();
				if(ch=='y'||ch=='Y')
				{
					clrscr(3,31,70,38);
					continue;
				}
				else
				{
					break;
				}
			}
			else if(sel==2)
			{
				if(p->state->money<5000)
					{
						gotoxy(5,34);printf("돈이 모자릅니다.");
						getch();
						clrscr(3,31,70,38);
						continue;
					}
			    p->state->snack[4]=1;
			    p->nowsituation->snackCount[4]++;
			    p->state->money-=5000;
				gotoxy(5,34);printf("더 구매하시겠습니까?(y/n) : ");
				fflush(stdin);
				ch=getchar();
				if(ch=='y'||ch=='Y')
				{
					clrscr(3,31,70,38);
					continue;
				}
				else
				{
					break;
				}
			}
		}
	}
	system("cls");
}

void snackdisplay()
{
	gotoxy(1,1);printf(" ┏━━━━━━━━━━━━━━━━━━━━┓");
	gotoxy(1,2);printf(" ┃                                        ┃");
	gotoxy(1,3);printf(" ┃                                        ┃");
	gotoxy(1,4);printf(" ┃                                        ┃");
	gotoxy(1,5);printf(" ┃                                        ┃");
	gotoxy(1,6);printf(" ┃                                        ┃");
	gotoxy(1,7);printf(" ┃                                        ┃");
	gotoxy(1,8);printf(" ┃                                        ┃");
	gotoxy(1,9);printf(" ┃                                        ┃");
	gotoxy(1,10);printf(" ┃                                        ┃");
	gotoxy(1,11);printf(" ┃                                        ┃");
	gotoxy(1,12);printf(" ┃                                        ┃");
	gotoxy(1,13);printf(" ┃                                        ┃");
	gotoxy(1,14);printf(" ┃                                        ┃");
	gotoxy(1,15);printf(" ┃                                        ┃");
	gotoxy(1,16);printf(" ┃                                        ┃");
	gotoxy(1,17);printf(" ┃                                        ┃");
	gotoxy(1,18);printf(" ┃                                        ┃");
	gotoxy(1,19);printf(" ┃                                        ┃");
	gotoxy(1,20);printf(" ┃                                        ┃");
	gotoxy(1,21);printf(" ┃                                        ┃");
	gotoxy(1,22);printf(" ┗━━━━━━━━━━━━━━━━━━━━┛");

	gotoxy(47,1);printf(" ┏━━━━━━━━━━━━━━━━━━━━┓");
	gotoxy(47,2);printf(" ┃                                        ┃");
	gotoxy(47,3);printf(" ┃                                        ┃");
	gotoxy(47,4);printf(" ┃                                        ┃");
	gotoxy(47,5);printf(" ┃                                        ┃");
	gotoxy(47,6);printf(" ┃                                        ┃");
	gotoxy(47,7);printf(" ┃                                        ┃");
	gotoxy(47,8);printf(" ┃                                        ┃");
	gotoxy(47,9);printf(" ┃                                        ┃");
	gotoxy(47,10);printf(" ┃                                        ┃");
	gotoxy(47,11);printf(" ┃                                        ┃");
	gotoxy(47,12);printf(" ┃                                        ┃");
	gotoxy(47,13);printf(" ┃                                        ┃");
	gotoxy(47,14);printf(" ┃                                        ┃");
	gotoxy(47,15);printf(" ┃                                        ┃");
	gotoxy(47,16);printf(" ┃                                        ┃");
	gotoxy(47,17);printf(" ┃                                        ┃");
	gotoxy(47,18);printf(" ┃                                        ┃");
	gotoxy(47,19);printf(" ┃                                        ┃");
	gotoxy(47,20);printf(" ┃                                        ┃");
	gotoxy(47,21);printf(" ┃                                        ┃");
	gotoxy(47,22);printf(" ┗━━━━━━━━━━━━━━━━━━━━┛");



	gotoxy(92,1);printf(" ┏━━━━━━━━━━━━━━━━━━━━┓");
	gotoxy(92,2);printf(" ┃                                        ┃");
	gotoxy(92,3);printf(" ┃                                        ┃");
	gotoxy(92,4);printf(" ┃                                        ┃");
	gotoxy(92,5);printf(" ┃                                        ┃");
	gotoxy(92,6);printf(" ┃                                        ┃");
	gotoxy(92,7);printf(" ┃                                        ┃");
	gotoxy(92,8);printf(" ┃                                        ┃");
	gotoxy(92,9);printf(" ┃                                        ┃");
	gotoxy(92,10);printf(" ┃                                        ┃");
	gotoxy(92,11);printf(" ┃                                        ┃");
	gotoxy(92,12);printf(" ┃                                        ┃");
	gotoxy(92,13);printf(" ┃                                        ┃");
	gotoxy(92,14);printf(" ┃                                        ┃");
	gotoxy(92,15);printf(" ┃                                        ┃");
	gotoxy(92,16);printf(" ┃                                        ┃");
	gotoxy(92,17);printf(" ┃                                        ┃");
	gotoxy(92,18);printf(" ┃                                        ┃");
	gotoxy(92,19);printf(" ┃                                        ┃");
	gotoxy(92,20);printf(" ┃                                        ┃");
	gotoxy(92,21);printf(" ┃                                        ┃");
	gotoxy(92,22);printf(" ┗━━━━━━━━━━━━━━━━━━━━┛");

	gotoxy(70,24);printf("●");
	gotoxy(70,25);printf("▲");
	gotoxy(47,26);printf("┌─────────────────────┐");
	gotoxy(47,27);printf("└─────────────────────┘");
	gotoxy(70,28);printf("●");
	gotoxy(70,29);printf("▲");
	gotoxy(1,30);printf("┌──────────────────────────────────────────────────────────────────┐");
    gotoxy(1,31);printf("│                                                                                                                                    │");
    gotoxy(1,32);printf("│                                                                                                                                    │");
	gotoxy(1,33);printf("│                                                                                                                                    │");
    gotoxy(1,34);printf("│                                                                                                                                    │");
    gotoxy(1,35);printf("│                                                                                                                                    │");
	gotoxy(1,36);printf("│                                                                                                                                    │");
	gotoxy(1,37);printf("│                                                                                                                                    │");
	gotoxy(1,38);printf("│                                                                                                                                    │");
    gotoxy(1,39);printf("└──────────────────────────────────────────────────────────────────┘");
}
void menu()
{
	gotoxy(18,7);printf(" 팝 콘 ");
	gotoxy(14,9);printf(" 대 : 7000원 ");
	gotoxy(14,10);printf(" 중 : 5000원 ");
	gotoxy(14,11);printf(" 소 : 3000원 ");
	gotoxy(14,13);printf(" 갈릭맛 :  +500원 ");
	gotoxy(14,14);printf(" 양파맛 :  +700원 ");
	gotoxy(14,15);printf(" 갈비맛 : +1000원 ");
	gotoxy(66,6);printf(" 콜 라 ");
	gotoxy(63,8);printf(" 대 : 2000원 ");
	gotoxy(63,9);printf(" 중 : 1500원 ");
	gotoxy(63,10);printf(" 소 : 1000원 ");
	gotoxy(65,12);printf(" 사이다 ");
	gotoxy(63,14);printf(" 대 : 2000원 ");
	gotoxy(63,15);printf(" 중 : 1500원 ");
	gotoxy(63,16);printf(" 소 : 1000원 ");
	gotoxy(106,11);printf(" 나쵸 : 5000원 ");
	gotoxy(106,12);printf(" 오징어 : 5000원 ");
}
