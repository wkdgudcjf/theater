#include"theater.h"

int myalloc(int **);
void gameinterface(int,int **);
int RanDom(int); 
//void gotoxy(int x, int y);
int menu();
void selectnum(int,int **);
int linecheck(int,int **);
//void textcolor(int,int);
int ftalloc(int **,int **);
void fgameinterface(int **,int **,int);
void selectft(int,int **,int **);
int flinecheck(int **,int **,int);
void bingo();

void game(Head *p)
{
	system("cls");
	gotoxy(48,13);printf("BinGo �����忡 ���Ű� ȯ���մϴ�.");
	gotoxy(48,14);printf("8������ �� �ӻ�δ� ������ �ﰡ���ֽʽÿ�. ");
	gotoxy(48,15);printf("��躸�� ������ �����ߵ�..");
	gotoxy(48,16);printf("��ſ� �ð� �ǽʽÿ�");
	gotoxy(48,17);printf("�ƹ�Ű�� �����ø� ������ ���۵˴ϴ�");
	fflush(stdin);
	getch();
	system("cls");
	bingo();
	system("cls");
	
}
void bingo()
{	
	int *myp=0,sel,num,endgame,*myb,*comb;
	srand( time (0) ); 
	while(1)
	{
		endgame=0;
		sel=menu();
		if(sel==3)
		{
			return ;
		}
		system("cls");
		if(sel==1)
		{
			num=myalloc(&myp);
			while(1)
			{
				gameinterface(num,&myp);
				endgame=linecheck(num,&myp);
				if(endgame==1)
				{
					system("cls");
					gotoxy(10,15);
					printf("���������� ����Ǿ����ϴ�. �ƹ�Ű�� ������ �ָ޴��� ���ư��ϴ�.");
					getch();
					system("cls");
					break;
				}
				selectnum(num,&myp);
			}
			free(myp);
		}
		else
		{
			num=ftalloc(&myb,&comb);
			while(1)
			{
			fgameinterface(&myb,&comb,num);
			endgame=flinecheck(&myb,&comb,num);
			if(endgame==1)
			{
				system("cls");
				gotoxy(10,15);
				printf("�ʰ��̰��!!!!. �ƹ�Ű�� ������ �ָ޴��� ���ư��ϴ�.");
				getch();
				system("cls");
				break;
			}
			if(endgame==3)
			{
				system("cls");
				gotoxy(10,15);
				printf("����....... �ƹ�Ű�� ������ �ָ޴��� ���ư��ϴ�.");
				getch();
				system("cls");
				break;
			}
			if(endgame==2)
			{
				system("cls");
				gotoxy(10,15);
				printf("�ʰ�����ФФФФ�. �ƹ�Ű�� ������ �ָ޴��� ���ư��ϴ�.");
				getch();
				system("cls");
				break;
			}
			else
			{
			selectft(num,&myb,&comb);
			}
			}
			free(myb);
			free(comb);
		}
	}
}
int menu()
{
	int num;
	gotoxy(48,13);
	printf("1 . ��������(���� ������)");
	gotoxy(48,15);
	printf("2 . ��������(��ǻ�Ϳ� ������)");
	gotoxy(48,17);
	printf("3. ������ ������");
	gotoxy(48,19);
	printf("# �޴����� : ");
	scanf("%d",&num);
	return num;
}
int myalloc(int **myp)
{
	int num,i,j,k;
	printf("������� �Ͻðڽ��ϱ�?(Ȧ��) : ");
	while(scanf("%d",&num))
	{
		if(num%2==1)
		{
			break;
		}
		printf("Ȧ�����Է��ϼ��� : ");
	}
	k=num*num;
	*myp=(int *)malloc(sizeof(int)*k);
	for(i=0;i<k;i++)
	{
		(*myp)[i]=RanDom(k);
		for(j=i-1;j>=0;j--)
		{
			if((*myp)[j]==(*myp)[i])
			{
				i--;
				break;
			}
		}
	}
	return num;
}
int RanDom(int n) 
{ 
	int res; 
	res = rand() % n; // 0���� n-1������ ���� ���� �߻� 
	return res+1; 
} 
void gameinterface(int num,int **myp)
{
	int i,k=0;
	system("cls");
	gotoxy(20,10);
	for(i=0;i<num*num;i++)
	{
		if((*myp)[i]==-1)
		{
			textcolor(LIGHTRED,WHITE);
			printf("   X");
			textcolor(BLACK,WHITE);
		}
		else
		{
			printf("%4d",(*myp)[i]);
		}
		if(i%num==num-1)
		{
			k++;
			gotoxy(20,10+k);
		}
	}
	return ;
}
/*void gotoxy(int x, int y) 
{ 
	COORD Pos = {x - 1, y - 1}; 
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos); 
} */
void selectnum(int num,int **myp)
{
	int n,i;
	gotoxy(8,5);
	printf("# ���� ���� �Է�(1~%d) : ",num*num);
	fflush(stdin);
	scanf("%d",&n);
	for(i=0;i<num*num;i++)
	{
		if((*myp)[i]==n)
		{
			(*myp)[i]=-1;
			system("cls");
			return ;
		}
	}
	printf("\t�̹� ������ �����Դϴ�. �ٽ��Է��ϼ���.");
	getch();
}
int linecheck(int num,int **myp)
{
	int i,j,k=0,cnt=0;
	for(i=0;i<num*num;i+=num) //��˻�
	{
		for(j=0;j<num;j++)
		{
			if((*myp)[i+j]==-1)
			{
				k++;
			}
		}
		if(k==num)
		{
			cnt++;
		}
		k=0;
	}
	k=0;
	for(i=0;i<num;i++) //���˻�
	{
		for(j=0;j<num*num;j+=num)
		{
			if((*myp)[i+j]==-1)
			{
				k++;
			}
		}
		if(k==num)
		{
			cnt++;
		}
		k=0;
	}
	k=0;
	for(i=0;i<num*num;i+=(num+1)) //�밢���˻�
	{
		if((*myp)[i]==-1)
		{
			k++;
		}
	}
	if(k==num)
	{
		cnt++;
	}
	k=0;
	for(i=(num-1);i<num*(num-1)+1;i+=(num-1)) //�밢���˻�
	{
		if((*myp)[i]==-1)
		{
			k++;
		}
	}
	if(k==num)
	{
		cnt++;
	}
	gotoxy(10,23);
	if(cnt>=num)
	{
		return 1;
	}
	else
	{
		printf("������� �������� %d�� �Դϴ� ������� %d�� ���ҽ��ϴ�.",cnt,num-cnt);
		return 0;
	}
}
/*void textcolor(int foreground, int background) 
{ 
	int color=foreground+background*16; 
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color); 
} */
int ftalloc(int **myb,int **comb)
{
	int num,i,j,k;
	printf("������� �Ͻðڽ��ϱ�?(Ȧ��) : ");
	while(scanf("%d",&num))
	{
		if(num%2==1)
		{
			break;
		}
		printf("Ȧ���� �Է��ϼ��� : ");
	}
	k=num*num;
	*myb=(int *)malloc(sizeof(int)*k);
	for(i=0;i<k;i++)
	{
		(*myb)[i]=RanDom(k);
		for(j=i-1;j>=0;j--)
		{
			if((*myb)[j]==(*myb)[i])
			{
				i--;
				break;
			}
		}
	}
	*comb=(int *)malloc(sizeof(int)*k);
	for(i=0;i<k;i++)
	{
		(*comb)[i]=RanDom(k);
		for(j=i-1;j>=0;j--)
		{
			if((*comb)[j]==(*comb)[i])
			{
				i--;
				break;
			}
		}
	}
	return num;
}
void fgameinterface(int **myb,int **comb,int num)
{
	int i,k=0;
	system("cls");
	gotoxy(7,10);
	for(i=0;i<num*num;i++)
	{
		if((*myb)[i]==-1)
		{
			textcolor(LIGHTRED,WHITE);
			printf("   X");
			textcolor(BLACK,WHITE);
		}
		else
		{
			printf("%4d",(*myb)[i]);
		}
		if(i%num==num-1)
		{
			k++;
			gotoxy(7,10+k);
		}
	}
	gotoxy(45,10);
	k=0;
	for(i=0;i<num*num;i++)
	{
		if((*comb)[i]==-1)
		{
			textcolor(LIGHTRED,WHITE);
			printf("   X");
			textcolor(BLACK,WHITE);
		}
		else
		{
			printf("%4d",(*comb)[i]);
		}
		if(i%num==num-1)
		{
			k++;
			gotoxy(45,10+k);
		}
	}
	return ;
}
void selectft(int num,int **myb,int **comb)
{
	int n,i,k;
	gotoxy(8,5);
	printf("# ���� ���� �Է�(1~%d) : ",num*num);
	fflush(stdin);
	while(1)
	{
		scanf("%d",&n);
		k=0;
		for(i=0;i<num*num;i++)
		{
			if((*myb)[i]==n)
			{
				(*myb)[i]=-1;
			}
			if((*comb)[i]==n)
			{
				(*comb)[i]=-1;
				k=1;
			}
		}
		if(k==1){break;}
		printf("\n�̹� ������ �����Դϴ�. �ٽ��Է��ϼ���. : ");
	}
	Sleep(1000);
	gotoxy(40,5);
	while(1)
	{
		k=0;
		n=RanDom(num*num);
		for(i=0;i<num*num;i++)
		{
			if((*comb)[i]==n)
			{
				(*comb)[i]=-1;
			}
			if((*myb)[i]==n)
			{
				(*myb)[i]=-1;
				k=1;
			}
		}
		if(k==1){break;}
	}
	printf("��ǻ�Ͱ� �Է��� ���� %d�Դϴ�.",n);
	getch();
	return ;
}
int flinecheck(int **myb,int **comb,int num)
{
	int i,j,k=0,cnt=0,ccnt=0;
	for(i=0;i<num*num;i+=num) //��˻�
	{
		for(j=0;j<num;j++)
		{
			if((*myb)[i+j]==-1)
			{
				k++;
			}
		}
		if(k==num)
		{
			cnt++;
		}
		k=0;
	}
	k=0;
	for(i=0;i<num;i++) //���˻�
	{
		for(j=0;j<num*num;j+=num)
		{
			if((*myb)[i+j]==-1)
			{
				k++;
			}
		}
		if(k==num)
		{
			cnt++;
		}
		k=0;
	}
	k=0;
	for(i=0;i<num*num;i+=(num+1)) //�밢���˻�
	{
		if((*myb)[i]==-1)
		{
			k++;
		}
	}
	if(k==num)
	{
		cnt++;
	}
	k=0;
	for(i=(num-1);i<num*(num-1)+1;i+=(num-1)) //�밢���˻�
	{
		if((*myb)[i]==-1)
		{
			k++;
		}
	}
	if(k==num)
	{
		cnt++;
	}
	gotoxy(1,22);
	printf("�������� %d�� �Դϴ�.\n������� %d�� ���ҽ��ϴ�.",cnt,num-cnt);
	k=0;
	for(i=0;i<num*num;i+=num) //��˻�
	{
		for(j=0;j<num;j++)
		{
			if((*comb)[i+j]==-1)
			{
				k++;
			}
		}
		if(k==num)
		{
			ccnt++;
		}
		k=0;
	}
	k=0;
	for(i=0;i<num;i++) //���˻�
	{
		for(j=0;j<num*num;j+=num)
		{
			if((*comb)[i+j]==-1)
			{
				k++;
			}
		}
		if(k==num)
		{
			ccnt++;
		}
		k=0;
	}
	k=0;
	for(i=0;i<num*num;i+=(num+1)) //�밢���˻�
	{
		if((*comb)[i]==-1)
		{
			k++;
		}
	}
	if(k==num)
	{
		ccnt++;
	}
	k=0;
	for(i=(num-1);i<num*(num-1)+1;i+=(num-1)) //�밢���˻�
	{
		if((*comb)[i]==-1)
		{
			k++;
		}
	}
	if(k==num)
	{
		ccnt++;
	}
	gotoxy(45,22);
	printf("�������� %d�� �Դϴ�.",ccnt);
	gotoxy(45,23);
	printf("������� %d�� ���ҽ��ϴ�.",num-ccnt);
	if(cnt>=5&&ccnt<5)
	{
		return 1;
	}
	if(cnt<5&&ccnt>=5)
	{
		return 2;
	}
	else if(ccnt>=5&&cnt>=5)
	{
		return 3;
	}
	else
	{
		return 0;
	}
}