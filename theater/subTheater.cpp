#include "theater.h"

#include<stdlib.h> // rand(), srand() �Լ��� ����ϱ� ���ؼ� ��Ŭ��� �� 
#include<time.h> // time() �Լ��� ����ϱ� ���ؼ� ��Ŭ��� �� 
#include<stdio.h> 
#include<conio.h>
#define ESC 27


//-------------------------------------------------------------------------------------
void randomNumCreate(int *rNumPtr) // ���δٸ� 540���� ������ �߻���Ű�� �Լ� 
{
	int i, j;

	rNumPtr[0]=random(540);  // 1~540������ ������ �߻����� �����Ѵ�.

	for(i=1; i<540; i++){  // �ι�°~�׹�° ���� �߻���Ű��
		rNumPtr[i]=random(540);
		for(j=0; j<i; j++){
			if(rNumPtr[i]==rNumPtr[j]){ // �ߺ������� �߻������� 
				rNumPtr[i]=random(540); // �ٽ� �߻���Ų �� 
				j=-1;  // ù��° �߻��ߴ� ���� ���� �ٽ� ��
			}
		}
		
	}

	return;
}

void myInit(Head *p)
{
	int i, j;
	////////////////////////////////
	////room�ʱ�ȭ�� p�� ����////////
	////////////////////////////////
	
	p->room->firstMovie=0;
	p->room->secondMovie=0;
	p->room->thirdMovie=0;
	
	//////////////////////////////
	//// movie �ʱ�ȭ�� p�� ����///
	//////////////////////////////
	for(i=0;i<6;i++)
	{
		for(j=0;j<10;j++)
		{
			p->movie->oneRoom[i][j].firstMovie=0;
			p->movie->oneRoom[i][j].secondMovie=0;
			p->movie->oneRoom[i][j].thirdMovie=0;
			p->movie->twoRoom[i][j].firstMovie=0;
			p->movie->twoRoom[i][j].secondMovie=0;
			p->movie->twoRoom[i][j].thirdMovie=0;
			p->movie->threeRoom[i][j].firstMovie=0;
			p->movie->threeRoom[i][j].secondMovie=0;
			p->movie->threeRoom[i][j].thirdMovie=0;
		}
	}
	p->movie->movieCount[0]=0;
	p->movie->movieCount[1]=0;
	p->movie->movieCount[2]=0;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			p->movie->roomCount[i][j]=0;
		}
	}
	///////////////////////////////////////////////////
	////////state �ʱ�ȭ�� p�� ���� ////////////////////
	//////////////////////////////////////////////////
	strcpy(p->state->name,"");
	strcpy(p->state->movie_name,"");
	p->state->age=0;
	p->state->money=0;
	for(i=0;i<5;i++)
	{
		p->state->snack[i]=0;
	}	
	p->state->restRoom=0;
	p->state->gameRoom=0;
	for(i=0;i<4;i++)
	{
		p->state->infoMovie[i]=0;
	}
	p->state->movieTimeHour=0;
	p->state->movieTimeMin=0;  
	p->state->movieTimeSec=0;   
	
	////////////////////////////////////////////////////////////
	//////////nowsituation�ʱ�ȭ�� p�� ���� //////////////////////
	///////////////////////////////////////////////////////////
	
	randomNumCreate(p->nowsituation->randNum);
	p->nowsituation->totalNum=0;
	p->nowsituation->currentNum=0;
	p->nowsituation->temperature=25.0;// �ʱ� �µ� 25��
	p->nowsituation->garbage=0;
	p->nowsituation->electronic=0;
	for(i=0;i<5;i++)
	{
		p->nowsituation->snackCount[i]=0;
	}
	
	//////////////////////////////////////////////////////////////
	/////////////location �ʱ�ȭ�� p�� ����///////////////////////
	////////////////////////////////////////////////////////////
	
	p->location->startX=0;
	p->location->startY=0;
	p->location->endX=0;
	p->location->endY=0;
	
	return;
}

void stateInit(Head *p)
{
	int timeMin,j;
	struct time sttime;
	gettime(&sttime);
	timeMin=p->nowsituation->startTime[1];
	/////////////////////////////////////////////////////////////
	//////////////1�󿵰� ��ȭ�϶�////////////////////////////////
	////////////////////////////////////////////////////////////////
	if(p->state->infoMovie[0]==1) //infomovie�� ���� �ְ� ���� +�� �ð����� 60�� ������!
	{
		if(timeMin+3>=60||timeMin+6>=60||timeMin+9>=60)
		{
			if(p->state->infoMovie[1]==1)//1��°
			{
				if(timeMin+3-60==sttime.ti_min)
				{
					for(j=0;j<4;j++)
					{
						p->state->infoMovie[j]=0;
					}
					strcpy(p->state->movie_name,"");
					p->state->movieTimeHour=0;
					p->state->movieTimeMin=0;
					stateDisplay(p);
				}
			}
			else if(p->state->infoMovie[1]==2)//2��° ��ȭ
			{
				if(timeMin+6-60==sttime.ti_min)
				{
					for(j=0;j<4;j++)
					{
						p->state->infoMovie[j]=0;
					}
					strcpy(p->state->movie_name,"");
					p->state->movieTimeHour=0;
					p->state->movieTimeMin=0;	
					stateDisplay(p);
				}
			}
			else if(p->state->infoMovie[1]==3)//3��° ��ȭ
			{
				if(timeMin+9-60==sttime.ti_min)
				{
					for(j=0;j<4;j++)
					{
						p->state->infoMovie[j]=0;
					}
					strcpy(p->state->movie_name,"");
					p->state->movieTimeHour=0;
					p->state->movieTimeMin=0;
					stateDisplay(p);
				}
			}
		}
		else //60���� �ȳ�����
		{
			if(p->state->infoMovie[1]==1) //1��° ��ȭ
			{
				if(timeMin+3==sttime.ti_min)
				{
					for(j=0;j<4;j++)
					{
						p->state->infoMovie[j]=0;
					}
					strcpy(p->state->movie_name,"");
					p->state->movieTimeHour=0;
					p->state->movieTimeMin=0;
					stateDisplay(p);
				}
			}
			else if(p->state->infoMovie[1]==2) // 2��° ��ȭ
			{
				if(timeMin+6==sttime.ti_min)
				{
					for(j=0;j<4;j++)
					{
						p->state->infoMovie[j]=0;
					}
					strcpy(p->state->movie_name,"");
					p->state->movieTimeHour=0;
					p->state->movieTimeMin=0;
					stateDisplay(p);
				}
			}
			else if(p->state->infoMovie[1]==3)//3��°��ȭ
			{
				if(timeMin+9==sttime.ti_min)
				{
					for(j=0;j<4;j++)
					{
						p->state->infoMovie[j]=0;
					}
					strcpy(p->state->movie_name,"");
					p->state->movieTimeHour=0;
					p->state->movieTimeMin=0;
					stateDisplay(p);
				}
			}
		}
	}
	//////////////////////////////////////////////////////////////////////
	///////////////////////2�󿵰� ��ȭ �϶�/////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	else if(p->state->infoMovie[0]==2)
	{
		if(timeMin+4>=60||timeMin+7>=60||timeMin+10>=60)
		{
			if(p->state->infoMovie[1]==1) //1���� ��ȭ
			{
				if(timeMin+4-60==sttime.ti_min)
				{
					for(j=0;j<4;j++)
					{
						p->state->infoMovie[j]=0;
					}
					strcpy(p->state->movie_name,"");
					p->state->movieTimeHour=0;
					p->state->movieTimeMin=0;
					stateDisplay(p);
				}
			}
			else if(p->state->infoMovie[1]==2) //2��° ��ȭ
			{
				if(timeMin+7-60==sttime.ti_min)
				{
					for(j=0;j<4;j++)
					{
						p->state->infoMovie[j]=0;
					}
					strcpy(p->state->movie_name,"");
					p->state->movieTimeHour=0;
					p->state->movieTimeMin=0;
					stateDisplay(p);
				}
			}
			else if(p->state->infoMovie[1]==3) //3��° ��ȭ
			{
				if(timeMin+10-60==sttime.ti_min)
				{
					for(j=0;j<4;j++)
					{
						p->state->infoMovie[j]=0;
					}
					strcpy(p->state->movie_name,"");
					p->state->movieTimeHour=0;
					p->state->movieTimeMin=0;
					stateDisplay(p);
				}
			}
		}
		else //////////////////// 60�� �ȳ�����/////////////
		{
			if(p->state->infoMovie[1]==1)//1��° ��ȭ
			{
				if(timeMin+4==sttime.ti_min)
				{
					for(j=0;j<4;j++)
					{
						p->state->infoMovie[j]=0;
					}
					strcpy(p->state->movie_name,"");
					p->state->movieTimeHour=0;
					p->state->movieTimeMin=0;
					stateDisplay(p);
				}
			}
			else if(p->state->infoMovie[1]==2)//2��° ��ȭ
			{
				if(timeMin+7==sttime.ti_min)
				{
					for(j=0;j<4;j++)
					{
						p->state->infoMovie[j]=0;
					}
					strcpy(p->state->movie_name,"");
					p->state->movieTimeHour=0;
					p->state->movieTimeMin=0;
					stateDisplay(p);
				}
			}
			else if(p->state->infoMovie[1]==3)//3��° ��ȭ
			{
				if(timeMin+10==sttime.ti_min)
				{
					for(j=0;j<4;j++)
					{
						p->state->infoMovie[j]=0;
					}
					strcpy(p->state->movie_name,"");
					p->state->movieTimeHour=0;
					p->state->movieTimeMin=0;
					stateDisplay(p);
				}
			}
		}
	}
	//////////////////////////////////////////////////////////////
	///////////////3�󿵰� �϶�////////////////////////////////////
	//////////////////////////////////////////////////////////////
	else if(p->state->infoMovie[0]==3)
	{
		if(timeMin+5>=60||timeMin+8>=60||timeMin+11>=60)
		{
			if(p->state->infoMovie[1]==1) //60�� �Ѱ� 1��° ��ȭ
			{
				if(timeMin+5-60==sttime.ti_min)
				{
					for(j=0;j<4;j++)
					{
						p->state->infoMovie[j]=0;
					}
					strcpy(p->state->movie_name,"");
					p->state->movieTimeHour=0;
					p->state->movieTimeMin=0;
					stateDisplay(p);
				}
			}
			else if(p->state->infoMovie[1]==2) // 2��° ��ȣ��
			{
				if(timeMin+8-60==sttime.ti_min)
				{
					for(j=0;j<4;j++)
					{
						p->state->infoMovie[j]=0;
					}
					strcpy(p->state->movie_name,"");
					p->state->movieTimeHour=0;
					p->state->movieTimeMin=0;
					stateDisplay(p);
				}
			}
			else if(p->state->infoMovie[1]==3) // 3��° ��ȭ
			{
				if(timeMin+11-60==sttime.ti_min)
				{
					for(j=0;j<4;j++)
					{
						p->state->infoMovie[j]=0;
					}
					strcpy(p->state->movie_name,"");
					p->state->movieTimeHour=0;
					p->state->movieTimeMin=0;
					stateDisplay(p);
				}
			}
		}
		else ///////////////////////60�� �ȳ�����
		{ 
			if(p->state->infoMovie[1]==1)// 1���� ��ȭ
			{
				if(timeMin+5==sttime.ti_min)
				{
					for(j=0;j<4;j++)
					{
						p->state->infoMovie[j]=0;
					}
					strcpy(p->state->movie_name,"");
					p->state->movieTimeHour=0;
					p->state->movieTimeMin=0;
					stateDisplay(p);
				}
			}
			else if(p->state->infoMovie[1]==2) //2��° ��ȭ
			{
				if(timeMin+8==sttime.ti_min)
				{
					for(j=0;j<4;j++)
					{
						p->state->infoMovie[j]=0;
					}
					strcpy(p->state->movie_name,"");
					p->state->movieTimeHour=0;
					p->state->movieTimeMin=0;
					stateDisplay(p);
				}
			}
			else if(p->state->infoMovie[1]==3) // 3��° ��ȭ
			{
				if(timeMin+11==sttime.ti_min)
				{
					for(j=0;j<4;j++)
					{
						p->state->infoMovie[j]=0;
					}
					strcpy(p->state->movie_name,"");
					p->state->movieTimeHour=0;
					p->state->movieTimeMin=0;
					stateDisplay(p);
				}
			}
		}
	}
}


void guestInit(Head *p)
{
	int i,timeMin,j; 
	struct time sttime;
	gettime(&sttime);
	timeMin=p->nowsituation->startTime[1];
	
	for(i=3;i<=11;i++)
	{
		//////////////////////////////////1//////////////////////
		//////////////1�󿵰� üũ./////////////////////////////
		/////////////////////////////////////////////////////
		if(i==3||i==6||i==9) //1�󿵰� 1,2,3��° ��ȭ üũ
		{
			if(timeMin+i>=60) //60�� �Ѵ´ٸ�
			{
				if(i+timeMin-60==sttime.ti_min)  
				{	
					if(p->nowsituation->tagInit[0]==1) // 3�� ������ 1�󿵰� �����������
					{
						if(p->nowsituation->tagInit[3]==0) //6�������� 1�󿵰� ������
						{
							p->nowsituation->temperature=p->nowsituation->temperature-(p->movie->roomCount[(i-3)/3][0]*0.05); //�µ� �����ֱ�
							p->nowsituation->currentNum=p->nowsituation->currentNum-p->movie->roomCount[(i-3)/30][0]; // �����ο� �����ֱ�							
							p->movie->roomCount[(i-3)/3][0] = 0;
							p->nowsituation->tagInit[3]=1; 
						}
						else // 6�� 1�󿵰� ��ȭ�� ���������� 9�� 1�󿵰� ��ȭ üũ
						{
							if(p->nowsituation->tagInit[6]==0) //9�� 1�󿵰� ��ȭ ������
							{
								p->nowsituation->temperature=p->nowsituation->temperature-(p->movie->roomCount[(i-3)/30][0]*0.05); //�µ� �����ֱ�
								p->nowsituation->currentNum=p->nowsituation->currentNum-p->movie->roomCount[(i-3)/3][0]; // �����ο� �����ֱ�
								p->movie->roomCount[(i-3)/3][0] = 0;
								p->nowsituation->tagInit[6]=1;
							}
							else // 9�� 1�󿵰� ��ȭ�� ���������� return;
							{
								return ;
							}
						}
					}
					else // 3�ж� ��ȭ�� ������
					{
						p->nowsituation->temperature=p->nowsituation->temperature-(p->movie->roomCount[(i-3)/3][0]*0.05); //�µ� �����ֱ�
						p->nowsituation->currentNum=p->nowsituation->currentNum-p->movie->roomCount[(i-3)/3][0]; // �����ο� �����ֱ�
						p->movie->roomCount[(i-3)/3][0] = 0;
						p->nowsituation->tagInit[0]=1;
					}
				}
			}
			else //60�� �ȳѴ´ٸ�
			{
				if(i+timeMin==sttime.ti_min) //1�󿵰����� �ϴ� ��ȭ�� �����������
				{	
				
					if(p->nowsituation->tagInit[0]==1) // 1�󿵰� 1��° ��ȭ �������ٸ�
					{
						if(p->nowsituation->tagInit[3]==0) // 1�󿵰� 2��° ��ȭ ������
						{
							p->nowsituation->temperature=p->nowsituation->temperature-(p->movie->roomCount[(i-3)/3][0]*0.05); //�µ� �����ֱ�
							p->nowsituation->currentNum=p->nowsituation->currentNum-p->movie->roomCount[(i-3)/3][0]; // �����ο� �����ֱ�
							p->movie->roomCount[(i-3)/3][0] = 0;
							p->nowsituation->tagInit[3]=1;
						}
						else //1�󿵰� 2��° ��ȭ �����־�����
						{
							if(p->nowsituation->tagInit[6]==0) //1�󿵰� 3��° ��ȭ ������
							{
								p->nowsituation->temperature=p->nowsituation->temperature-(p->movie->roomCount[(i-3)/3][0]*0.05); //�µ� �����ֱ�
								p->nowsituation->currentNum=p->nowsituation->currentNum-p->movie->roomCount[(i-3)/3][0]; // �����ο� �����ֱ�
								p->movie->roomCount[(i-3)/3][0] = 0;
								p->nowsituation->tagInit[6]=1;
							}
							else //1�󿵰� 3��° ��ȭ �����־��ٸ� return ;
							{
								return ;
							}
						}
					}
					else //1��° ��ȭ ������
					{
						p->nowsituation->temperature=p->nowsituation->temperature-(p->movie->roomCount[(i-3)/3][0]*0.05); //�µ� �����ֱ�
						p->nowsituation->currentNum=p->nowsituation->currentNum-p->movie->roomCount[(i-3)/3][0]; // �����ο� �����ֱ�
						p->movie->roomCount[(i-3)/3][0] = 0;
						p->nowsituation->tagInit[0]=1;
					}
				}
			}
		}
		////////////////////////////////////////////////////////////////////
		//////////////2��° �󿵰� üũ//////////////////////////////////////
		////////////////////////////////////////////////////////////////////
		else if(i==4||i==7||i==10) // 2��° �󿵰�üũ
		{
			if(timeMin+i>=60)
			{
				if(i+timeMin-60==sttime.ti_min) //2�󿵰��� �� �ϴ� ��ȭ�� ������� 
				{	
				
					if(p->nowsituation->tagInit[1]==1) // 4�� ������ 2�󿵰� �����������
					{
						if(p->nowsituation->tagInit[4]==0) //7�������� 2�󿵰� ������
						{
							p->nowsituation->temperature=p->nowsituation->temperature-(p->movie->roomCount[(i-4)/3][1]*0.05); //�µ� �����ֱ�
							p->nowsituation->currentNum=p->nowsituation->currentNum-p->movie->roomCount[(i-4)/3][1]; // �����ο� �����ֱ�
							p->movie->roomCount[(i-4)/3][1]=0;
							p->nowsituation->tagInit[4]=1; 
						}
						else // 4�� 2�󿵰� ��ȭ�� ���������� 7�� 2�󿵰� ��ȭ üũ
						{
							if(p->nowsituation->tagInit[7]==0) //10�� 2�󿵰� ��ȭ ������
							{
								p->nowsituation->temperature=p->nowsituation->temperature-(p->movie->roomCount[(i-4)/3][1]*0.05); //�µ� �����ֱ�
								p->nowsituation->currentNum=p->nowsituation->currentNum-p->movie->roomCount[(i-4)/3][1]; // �����ο� �����ֱ�
								p->movie->roomCount[(i-4)/3][1]=0;
								p->nowsituation->tagInit[7]=1;
							}
							else // 10�� 2�󿵰� ��ȭ�� ���������� return;
							{
								return ;
							}
						}
					}
					else // 4�ж� ��ȭ�� ������
					{
						p->nowsituation->temperature=p->nowsituation->temperature-(p->movie->roomCount[(i-4)/3][1]*0.05); //�µ� �����ֱ�
						p->nowsituation->currentNum=p->nowsituation->currentNum-p->movie->roomCount[(i-4)/3][1]; // �����ο� �����ֱ�
						p->movie->roomCount[(i-4)/3][1]=0;
						p->nowsituation->tagInit[1]=1;
					}
				}
			}
			else
			{
				if(i+timeMin==sttime.ti_min) //2�󿵰����� �ϴ� ��ȭ�� �������
				{	
				
					if(p->nowsituation->tagInit[1]==1) // 4�� ������ 2�󿵰� �����������
					{
						if(p->nowsituation->tagInit[4]==0) //7�������� 2�󿵰� ������
						{
							p->nowsituation->temperature=p->nowsituation->temperature-(p->movie->roomCount[(i-4)/3][1]*0.05); //�µ� �����ֱ�
							p->nowsituation->currentNum=p->nowsituation->currentNum-p->movie->roomCount[(i-4)/3][1]; // �����ο� �����ֱ�
							p->movie->roomCount[(i-4)/3][1]=0;
							p->nowsituation->tagInit[4]=1; 
						}
						else // 4�� 2�󿵰� ��ȭ�� ���������� 7�� 2�󿵰� ��ȭ üũ
						{
							if(p->nowsituation->tagInit[7]==0) //10�� 2�󿵰� ��ȭ ������
							{
								p->nowsituation->temperature=p->nowsituation->temperature-(p->movie->roomCount[(i-4)/3][1]*0.05); //�µ� �����ֱ�
								p->nowsituation->currentNum=p->nowsituation->currentNum-p->movie->roomCount[(i-4)/3][1]; // �����ο� �����ֱ�
								p->movie->roomCount[(i-4)/3][1]=0;
								p->nowsituation->tagInit[7]=1;
							}
							else // 10�� 2�󿵰� ��ȭ�� ���������� return;
							{
								return ;
							}
						}
					}
					else // 4�ж� ��ȭ�� ������
					{
						p->nowsituation->temperature=p->nowsituation->temperature-(p->movie->roomCount[(i-4)/3][1]*0.05); //�µ� �����ֱ�
						p->nowsituation->currentNum=p->nowsituation->currentNum-p->movie->roomCount[(i-4)/3][1]; // �����ο� �����ֱ�
						p->movie->roomCount[(i-4)/3][1]=0;
						p->nowsituation->tagInit[1]=1;
					}
				}
			}
		}
		////////////////////////////////////////////////////
		/////////////3�󿵰� �ʱ�ȭ///////////////////////
		///////////////////////////////////////////////////////
		else if(i==5||i==8||i==11)
		{
			if(timeMin+i>=60)
			{
				if(i+timeMin-60==sttime.ti_min) //3�󿵰����� �ϴ� ��ȭ�� �������
				{	
					if(p->nowsituation->tagInit[2]==1) // 5�� ������ 3�󿵰� �����������
					{
						if(p->nowsituation->tagInit[5]==0) //11�������� 3�󿵰� ������
						{
							p->nowsituation->temperature=p->nowsituation->temperature-(p->movie->roomCount[(i-5)/3][2]*0.05); //�µ� �����ֱ�
							p->nowsituation->currentNum=p->nowsituation->currentNum-p->movie->roomCount[(i-5)/3][2]; // �����ο� �����ֱ�
							p->movie->roomCount[(i-5)/3][2]=0;
							p->nowsituation->tagInit[5]=1; 
						}
						else // 5�� 3�󿵰� ��ȭ�� ���������� 11�� 3�󿵰� ��ȭ üũ
						{
							if(p->nowsituation->tagInit[8]==0) //11�� 3�󿵰� ��ȭ ������
							{
								p->nowsituation->temperature=p->nowsituation->temperature-(p->movie->roomCount[(i-5)/3][2]*0.05); //�µ� �����ֱ�
								p->nowsituation->currentNum=p->nowsituation->currentNum-p->movie->roomCount[(i-5)/3][2]; // �����ο� �����ֱ�
								p->movie->roomCount[(i-5)/3][2]=0;
								p->nowsituation->tagInit[8]=1;
							}
							else // 11�� 3�󿵰� ��ȭ�� ���������� return;
							{
								return ;
							}
						}
					}
					else // 5�ж� ��ȭ�� ������
					{
						p->nowsituation->temperature=p->nowsituation->temperature-(p->movie->roomCount[(i-5)/3][2]*0.05); //�µ� �����ֱ�
						p->nowsituation->currentNum=p->nowsituation->currentNum-p->movie->roomCount[(i-5)/3][2]; // �����ο� �����ֱ�
						p->movie->roomCount[(i-5)/3][2]=0;
						p->nowsituation->tagInit[2]=1;
					}
				}
			}
			else
			{
				if(i+timeMin==sttime.ti_min) //3�󿵰����� �ϴ� ��ȭ�� �������
				{	
					if(p->nowsituation->tagInit[2]==1) // 5�� ������ 3�󿵰� �����������
					{
						if(p->nowsituation->tagInit[5]==0) //11�������� 3�󿵰� ������
						{
							p->nowsituation->temperature=p->nowsituation->temperature-(p->movie->roomCount[(i-5)/3][2]*0.05); //�µ� �����ֱ�
							p->nowsituation->currentNum=p->nowsituation->currentNum-p->movie->roomCount[(i-5)/3][2]; // �����ο� �����ֱ�
							p->movie->roomCount[(i-5)/3][2]=0;
							p->nowsituation->tagInit[5]=1; 
						}
						else // 5�� 3�󿵰� ��ȭ�� ���������� 11�� 3�󿵰� ��ȭ üũ
						{
							if(p->nowsituation->tagInit[8]==0) //11�� 3�󿵰� ��ȭ ������
							{
								p->nowsituation->temperature=p->nowsituation->temperature-(p->movie->roomCount[(i-5)/3][2]*0.05); //�µ� �����ֱ�
								p->nowsituation->currentNum=p->nowsituation->currentNum-p->movie->roomCount[(i-5)/3][2]; // �����ο� �����ֱ�
								p->movie->roomCount[(i-5)/3][2]=0;
								p->nowsituation->tagInit[8]=1;
							}
							else // 11�� 3�󿵰� ��ȭ�� ���������� return;
							{
								return ;
							}
						}
					}
					else // 5�ж� ��ȭ�� ������
					{
						p->nowsituation->temperature=p->nowsituation->temperature-(p->movie->roomCount[(i-5)/3][2]*0.05); //�µ� �����ֱ�
						p->nowsituation->currentNum=p->nowsituation->currentNum-p->movie->roomCount[(i-5)/3][2]; // �����ο� �����ֱ�
						p->movie->roomCount[(i-5)/3][2]=0;
						p->nowsituation->tagInit[2]=1;
					}
				}
			}
		}
	}
}

void total(Head *p)
{
	int i,sum=0;
	system("cls");
	gotoxy(45,7);printf("���ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѦ�");
	gotoxy(45,8);printf("��                                                              ��");
	gotoxy(45,9);printf("��                                                              ��");
	gotoxy(45,10);printf("��                                                              ��");
	gotoxy(45,11);printf("��                                                              ��");
	gotoxy(45,12);printf("��                                                              ��");
	gotoxy(45,13);printf("��                                                              ��");
	gotoxy(45,14);printf("��                                                              ��");
	gotoxy(45,15);printf("��                                                              ��");
	gotoxy(45,16);printf("��                                                              ��");
	gotoxy(45,17);printf("��                                                              ��");
	gotoxy(45,18);printf("��                                                              ��");
	gotoxy(45,19);printf("��                                                              ��");
	gotoxy(45,20);printf("��                                                              ��");
	gotoxy(45,21);printf("��                                                              ��");
	gotoxy(45,22);printf("��                                                              ��");
	gotoxy(45,23);printf("��                                                              ��");
	gotoxy(45,24);printf("��                                                              ��");
	gotoxy(45,25);printf("��                                                              ��");
	gotoxy(45,26);printf("��                                                              ��");
	gotoxy(45,27);printf("��                                                              ��");
	gotoxy(45,28);printf("��                                                              ��");
	gotoxy(45,29);printf("��                                                              ��");
	gotoxy(45,30);printf("���ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѦ�");
	gotoxy(55,11);printf("�ѤѤѤ�4�� ��ȭ�� Total�ѤѤѤ�"); 
	gotoxy(55,13);printf("�� ������: %d \n",p->nowsituation->totalNum);//�� ������
	for(i=0;i<3;i++) //��ȭ ������ ���
	{
	gotoxy(55,15+i);	printf("%d�� ��ȭ ���� ��: %d \n",i+1, p->movie->movieCount[i] );
	}
	for(i=0;i<5;i++) //���� �ȸ� �ټ�
	{
	gotoxy(55,19+i);	printf("%d�� ���� �� : %d \n", i+1,p->nowsituation->snackCount[i]);
	}
	/////////////////////////////////////////////////
	////////////// sum ���ϴ��� //////////////////////
	//////////////////////////////////////////////// 
	sum+=p->movie->movieCount[0]*10000; //ù ��ȭ
	sum+=p->movie->movieCount[1]*9000; //�ι��� ��ȭ
	sum+=p->movie->movieCount[2]*6000; //����° ��ȭ
	sum+=p->nowsituation->snackCount[0]*5000; //ù��° ����
	sum+=p->nowsituation->snackCount[1]*3000; //�ι�° ����
	sum+=p->nowsituation->snackCount[2]*4000; //������ ����
	sum+=p->nowsituation->snackCount[3]*6000; //�׹��� ����
	sum+=p->nowsituation->snackCount[4]*2000; //�ټ���° ����
	gotoxy(55,25);printf("�� ���� : %d \n", sum);
	gotoxy(55,27);printf("�ƹ�Ű�� �����ø� ���α׷��� ���� �˴ϴ�. \n");
	getch();
	return ;
}

void gotoxy(int x, int y) 
{ 
	COORD Pos = {x - 1, y - 1}; 
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos); 
} 

void clrscr(int startX, int startY, int endX, int endY) 
{ 
	int i,j; 
	for(i=startY; i<=endY; i++){ 
		for(j=startX; j<=endX; j++){ 
			gotoxy(j,i); 
			putch(' '); 
		} 
	} 
} 
