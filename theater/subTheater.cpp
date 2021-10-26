#include "theater.h"

#include<stdlib.h> // rand(), srand() 함수를 사용하기 위해서 인클루드 함 
#include<time.h> // time() 함수를 사용하기 위해서 인클루드 함 
#include<stdio.h> 
#include<conio.h>
#define ESC 27


//-------------------------------------------------------------------------------------
void randomNumCreate(int *rNumPtr) // 서로다른 540개의 난수를 발생시키는 함수 
{
	int i, j;

	rNumPtr[0]=random(540);  // 1~540사이의 난수를 발생시켜 저장한다.

	for(i=1; i<540; i++){  // 두번째~네번째 난수 발생시키기
		rNumPtr[i]=random(540);
		for(j=0; j<i; j++){
			if(rNumPtr[i]==rNumPtr[j]){ // 중복난수가 발생했으면 
				rNumPtr[i]=random(540); // 다시 발생시킨 후 
				j=-1;  // 첫번째 발생했던 난수 부터 다시 비교
			}
		}
		
	}

	return;
}

void myInit(Head *p)
{
	int i, j;
	////////////////////////////////
	////room초기화및 p에 대입////////
	////////////////////////////////
	
	p->room->firstMovie=0;
	p->room->secondMovie=0;
	p->room->thirdMovie=0;
	
	//////////////////////////////
	//// movie 초기화및 p에 대입///
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
	////////state 초기화및 p에 대입 ////////////////////
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
	//////////nowsituation초기화및 p에 대입 //////////////////////
	///////////////////////////////////////////////////////////
	
	randomNumCreate(p->nowsituation->randNum);
	p->nowsituation->totalNum=0;
	p->nowsituation->currentNum=0;
	p->nowsituation->temperature=25.0;// 초기 온도 25도
	p->nowsituation->garbage=0;
	p->nowsituation->electronic=0;
	for(i=0;i<5;i++)
	{
		p->nowsituation->snackCount[i]=0;
	}
	
	//////////////////////////////////////////////////////////////
	/////////////location 초기화및 p에 대입///////////////////////
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
	//////////////1상영관 영화일때////////////////////////////////
	////////////////////////////////////////////////////////////////
	if(p->state->infoMovie[0]==1) //infomovie에 값이 있고 만약 +한 시간값이 60이 넘을때!
	{
		if(timeMin+3>=60||timeMin+6>=60||timeMin+9>=60)
		{
			if(p->state->infoMovie[1]==1)//1번째
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
			else if(p->state->infoMovie[1]==2)//2번째 영화
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
			else if(p->state->infoMovie[1]==3)//3번째 영화
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
		else //60분이 안넘을때
		{
			if(p->state->infoMovie[1]==1) //1번째 영화
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
			else if(p->state->infoMovie[1]==2) // 2번째 영화
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
			else if(p->state->infoMovie[1]==3)//3번째영화
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
	///////////////////////2상영관 영화 일때/////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	else if(p->state->infoMovie[0]==2)
	{
		if(timeMin+4>=60||timeMin+7>=60||timeMin+10>=60)
		{
			if(p->state->infoMovie[1]==1) //1번재 영화
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
			else if(p->state->infoMovie[1]==2) //2번째 영화
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
			else if(p->state->infoMovie[1]==3) //3번째 영화
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
		else //////////////////// 60분 안넘을때/////////////
		{
			if(p->state->infoMovie[1]==1)//1번째 영화
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
			else if(p->state->infoMovie[1]==2)//2번째 영화
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
			else if(p->state->infoMovie[1]==3)//3번째 영화
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
	///////////////3상영관 일때////////////////////////////////////
	//////////////////////////////////////////////////////////////
	else if(p->state->infoMovie[0]==3)
	{
		if(timeMin+5>=60||timeMin+8>=60||timeMin+11>=60)
		{
			if(p->state->infoMovie[1]==1) //60분 넘고 1번째 영화
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
			else if(p->state->infoMovie[1]==2) // 2번째 영호ㅏ
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
			else if(p->state->infoMovie[1]==3) // 3번째 영화
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
		else ///////////////////////60분 안넘을때
		{ 
			if(p->state->infoMovie[1]==1)// 1번재 영화
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
			else if(p->state->infoMovie[1]==2) //2번째 영화
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
			else if(p->state->infoMovie[1]==3) // 3번째 영화
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
		//////////////1상영관 체크./////////////////////////////
		/////////////////////////////////////////////////////
		if(i==3||i==6||i==9) //1상영관 1,2,3번째 영화 체크
		{
			if(timeMin+i>=60) //60분 넘는다면
			{
				if(i+timeMin-60==sttime.ti_min)  
				{	
					if(p->nowsituation->tagInit[0]==1) // 3분 지나서 1상영관 끝나있을경우
					{
						if(p->nowsituation->tagInit[3]==0) //6분지나서 1상영관 끝날때
						{
							p->nowsituation->temperature=p->nowsituation->temperature-(p->movie->roomCount[(i-3)/3][0]*0.05); //온도 내려주기
							p->nowsituation->currentNum=p->nowsituation->currentNum-p->movie->roomCount[(i-3)/30][0]; // 현재인원 내려주기							
							p->movie->roomCount[(i-3)/3][0] = 0;
							p->nowsituation->tagInit[3]=1; 
						}
						else // 6분 1상영관 영화가 끝났었으면 9분 1상영관 영화 체크
						{
							if(p->nowsituation->tagInit[6]==0) //9분 1상영관 영화 끝날때
							{
								p->nowsituation->temperature=p->nowsituation->temperature-(p->movie->roomCount[(i-3)/30][0]*0.05); //온도 내려주기
								p->nowsituation->currentNum=p->nowsituation->currentNum-p->movie->roomCount[(i-3)/3][0]; // 현재인원 내려주기
								p->movie->roomCount[(i-3)/3][0] = 0;
								p->nowsituation->tagInit[6]=1;
							}
							else // 9분 1상영관 영화도 끝났었으면 return;
							{
								return ;
							}
						}
					}
					else // 3분때 영화가 끝날때
					{
						p->nowsituation->temperature=p->nowsituation->temperature-(p->movie->roomCount[(i-3)/3][0]*0.05); //온도 내려주기
						p->nowsituation->currentNum=p->nowsituation->currentNum-p->movie->roomCount[(i-3)/3][0]; // 현재인원 내려주기
						p->movie->roomCount[(i-3)/3][0] = 0;
						p->nowsituation->tagInit[0]=1;
					}
				}
			}
			else //60분 안넘는다면
			{
				if(i+timeMin==sttime.ti_min) //1상영관에서 하는 영화가 끝나있을경우
				{	
				
					if(p->nowsituation->tagInit[0]==1) // 1상영관 1번째 영화 끝났었다면
					{
						if(p->nowsituation->tagInit[3]==0) // 1상영관 2번째 영화 끝날때
						{
							p->nowsituation->temperature=p->nowsituation->temperature-(p->movie->roomCount[(i-3)/3][0]*0.05); //온도 내려주기
							p->nowsituation->currentNum=p->nowsituation->currentNum-p->movie->roomCount[(i-3)/3][0]; // 현재인원 내려주기
							p->movie->roomCount[(i-3)/3][0] = 0;
							p->nowsituation->tagInit[3]=1;
						}
						else //1상영관 2번째 영화 끝나있었으면
						{
							if(p->nowsituation->tagInit[6]==0) //1상영관 3번째 영화 끝날때
							{
								p->nowsituation->temperature=p->nowsituation->temperature-(p->movie->roomCount[(i-3)/3][0]*0.05); //온도 내려주기
								p->nowsituation->currentNum=p->nowsituation->currentNum-p->movie->roomCount[(i-3)/3][0]; // 현재인원 내려주기
								p->movie->roomCount[(i-3)/3][0] = 0;
								p->nowsituation->tagInit[6]=1;
							}
							else //1상영관 3번째 영화 끝나있었다면 return ;
							{
								return ;
							}
						}
					}
					else //1번째 영화 끝날때
					{
						p->nowsituation->temperature=p->nowsituation->temperature-(p->movie->roomCount[(i-3)/3][0]*0.05); //온도 내려주기
						p->nowsituation->currentNum=p->nowsituation->currentNum-p->movie->roomCount[(i-3)/3][0]; // 현재인원 내려주기
						p->movie->roomCount[(i-3)/3][0] = 0;
						p->nowsituation->tagInit[0]=1;
					}
				}
			}
		}
		////////////////////////////////////////////////////////////////////
		//////////////2번째 상영관 체크//////////////////////////////////////
		////////////////////////////////////////////////////////////////////
		else if(i==4||i==7||i==10) // 2번째 상영관체크
		{
			if(timeMin+i>=60)
			{
				if(i+timeMin-60==sttime.ti_min) //2상영관에 서 하는 영화가 끝날경우 
				{	
				
					if(p->nowsituation->tagInit[1]==1) // 4분 지나서 2상영관 끝나있을경우
					{
						if(p->nowsituation->tagInit[4]==0) //7분지나서 2상영관 끝날때
						{
							p->nowsituation->temperature=p->nowsituation->temperature-(p->movie->roomCount[(i-4)/3][1]*0.05); //온도 내려주기
							p->nowsituation->currentNum=p->nowsituation->currentNum-p->movie->roomCount[(i-4)/3][1]; // 현재인원 내려주기
							p->movie->roomCount[(i-4)/3][1]=0;
							p->nowsituation->tagInit[4]=1; 
						}
						else // 4분 2상영관 영화가 끝났었으면 7분 2상영관 영화 체크
						{
							if(p->nowsituation->tagInit[7]==0) //10분 2상영관 영화 끝날때
							{
								p->nowsituation->temperature=p->nowsituation->temperature-(p->movie->roomCount[(i-4)/3][1]*0.05); //온도 내려주기
								p->nowsituation->currentNum=p->nowsituation->currentNum-p->movie->roomCount[(i-4)/3][1]; // 현재인원 내려주기
								p->movie->roomCount[(i-4)/3][1]=0;
								p->nowsituation->tagInit[7]=1;
							}
							else // 10분 2상영관 영화도 끝났었으면 return;
							{
								return ;
							}
						}
					}
					else // 4분때 영화가 끝날때
					{
						p->nowsituation->temperature=p->nowsituation->temperature-(p->movie->roomCount[(i-4)/3][1]*0.05); //온도 내려주기
						p->nowsituation->currentNum=p->nowsituation->currentNum-p->movie->roomCount[(i-4)/3][1]; // 현재인원 내려주기
						p->movie->roomCount[(i-4)/3][1]=0;
						p->nowsituation->tagInit[1]=1;
					}
				}
			}
			else
			{
				if(i+timeMin==sttime.ti_min) //2상영관에서 하는 영화가 끝날경우
				{	
				
					if(p->nowsituation->tagInit[1]==1) // 4분 지나서 2상영관 끝나있을경우
					{
						if(p->nowsituation->tagInit[4]==0) //7분지나서 2상영관 끝날때
						{
							p->nowsituation->temperature=p->nowsituation->temperature-(p->movie->roomCount[(i-4)/3][1]*0.05); //온도 내려주기
							p->nowsituation->currentNum=p->nowsituation->currentNum-p->movie->roomCount[(i-4)/3][1]; // 현재인원 내려주기
							p->movie->roomCount[(i-4)/3][1]=0;
							p->nowsituation->tagInit[4]=1; 
						}
						else // 4분 2상영관 영화가 끝났었으면 7분 2상영관 영화 체크
						{
							if(p->nowsituation->tagInit[7]==0) //10분 2상영관 영화 끝날때
							{
								p->nowsituation->temperature=p->nowsituation->temperature-(p->movie->roomCount[(i-4)/3][1]*0.05); //온도 내려주기
								p->nowsituation->currentNum=p->nowsituation->currentNum-p->movie->roomCount[(i-4)/3][1]; // 현재인원 내려주기
								p->movie->roomCount[(i-4)/3][1]=0;
								p->nowsituation->tagInit[7]=1;
							}
							else // 10분 2상영관 영화도 끝났었으면 return;
							{
								return ;
							}
						}
					}
					else // 4분때 영화가 끝날때
					{
						p->nowsituation->temperature=p->nowsituation->temperature-(p->movie->roomCount[(i-4)/3][1]*0.05); //온도 내려주기
						p->nowsituation->currentNum=p->nowsituation->currentNum-p->movie->roomCount[(i-4)/3][1]; // 현재인원 내려주기
						p->movie->roomCount[(i-4)/3][1]=0;
						p->nowsituation->tagInit[1]=1;
					}
				}
			}
		}
		////////////////////////////////////////////////////
		/////////////3상영관 초기화///////////////////////
		///////////////////////////////////////////////////////
		else if(i==5||i==8||i==11)
		{
			if(timeMin+i>=60)
			{
				if(i+timeMin-60==sttime.ti_min) //3상영관에서 하는 영화가 끝날경우
				{	
					if(p->nowsituation->tagInit[2]==1) // 5분 지나서 3상영관 끝나있을경우
					{
						if(p->nowsituation->tagInit[5]==0) //11분지나서 3상영관 끝날때
						{
							p->nowsituation->temperature=p->nowsituation->temperature-(p->movie->roomCount[(i-5)/3][2]*0.05); //온도 내려주기
							p->nowsituation->currentNum=p->nowsituation->currentNum-p->movie->roomCount[(i-5)/3][2]; // 현재인원 내려주기
							p->movie->roomCount[(i-5)/3][2]=0;
							p->nowsituation->tagInit[5]=1; 
						}
						else // 5분 3상영관 영화가 끝났었으면 11분 3상영관 영화 체크
						{
							if(p->nowsituation->tagInit[8]==0) //11분 3상영관 영화 끝날때
							{
								p->nowsituation->temperature=p->nowsituation->temperature-(p->movie->roomCount[(i-5)/3][2]*0.05); //온도 내려주기
								p->nowsituation->currentNum=p->nowsituation->currentNum-p->movie->roomCount[(i-5)/3][2]; // 현재인원 내려주기
								p->movie->roomCount[(i-5)/3][2]=0;
								p->nowsituation->tagInit[8]=1;
							}
							else // 11분 3상영관 영화도 끝났었으면 return;
							{
								return ;
							}
						}
					}
					else // 5분때 영화가 끝날때
					{
						p->nowsituation->temperature=p->nowsituation->temperature-(p->movie->roomCount[(i-5)/3][2]*0.05); //온도 내려주기
						p->nowsituation->currentNum=p->nowsituation->currentNum-p->movie->roomCount[(i-5)/3][2]; // 현재인원 내려주기
						p->movie->roomCount[(i-5)/3][2]=0;
						p->nowsituation->tagInit[2]=1;
					}
				}
			}
			else
			{
				if(i+timeMin==sttime.ti_min) //3상영관에서 하는 영화가 끝날경우
				{	
					if(p->nowsituation->tagInit[2]==1) // 5분 지나서 3상영관 끝나있을경우
					{
						if(p->nowsituation->tagInit[5]==0) //11분지나서 3상영관 끝날때
						{
							p->nowsituation->temperature=p->nowsituation->temperature-(p->movie->roomCount[(i-5)/3][2]*0.05); //온도 내려주기
							p->nowsituation->currentNum=p->nowsituation->currentNum-p->movie->roomCount[(i-5)/3][2]; // 현재인원 내려주기
							p->movie->roomCount[(i-5)/3][2]=0;
							p->nowsituation->tagInit[5]=1; 
						}
						else // 5분 3상영관 영화가 끝났었으면 11분 3상영관 영화 체크
						{
							if(p->nowsituation->tagInit[8]==0) //11분 3상영관 영화 끝날때
							{
								p->nowsituation->temperature=p->nowsituation->temperature-(p->movie->roomCount[(i-5)/3][2]*0.05); //온도 내려주기
								p->nowsituation->currentNum=p->nowsituation->currentNum-p->movie->roomCount[(i-5)/3][2]; // 현재인원 내려주기
								p->movie->roomCount[(i-5)/3][2]=0;
								p->nowsituation->tagInit[8]=1;
							}
							else // 11분 3상영관 영화도 끝났었으면 return;
							{
								return ;
							}
						}
					}
					else // 5분때 영화가 끝날때
					{
						p->nowsituation->temperature=p->nowsituation->temperature-(p->movie->roomCount[(i-5)/3][2]*0.05); //온도 내려주기
						p->nowsituation->currentNum=p->nowsituation->currentNum-p->movie->roomCount[(i-5)/3][2]; // 현재인원 내려주기
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
	gotoxy(45,7);printf("┌ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ┐");
	gotoxy(45,8);printf("│                                                              │");
	gotoxy(45,9);printf("│                                                              │");
	gotoxy(45,10);printf("│                                                              │");
	gotoxy(45,11);printf("│                                                              │");
	gotoxy(45,12);printf("│                                                              │");
	gotoxy(45,13);printf("│                                                              │");
	gotoxy(45,14);printf("│                                                              │");
	gotoxy(45,15);printf("│                                                              │");
	gotoxy(45,16);printf("│                                                              │");
	gotoxy(45,17);printf("│                                                              │");
	gotoxy(45,18);printf("│                                                              │");
	gotoxy(45,19);printf("│                                                              │");
	gotoxy(45,20);printf("│                                                              │");
	gotoxy(45,21);printf("│                                                              │");
	gotoxy(45,22);printf("│                                                              │");
	gotoxy(45,23);printf("│                                                              │");
	gotoxy(45,24);printf("│                                                              │");
	gotoxy(45,25);printf("│                                                              │");
	gotoxy(45,26);printf("│                                                              │");
	gotoxy(45,27);printf("│                                                              │");
	gotoxy(45,28);printf("│                                                              │");
	gotoxy(45,29);printf("│                                                              │");
	gotoxy(45,30);printf("└ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ┘");
	gotoxy(55,11);printf("ㅡㅡㅡㅡ4조 영화관 Totalㅡㅡㅡㅡ"); 
	gotoxy(55,13);printf("총 관객수: %d \n",p->nowsituation->totalNum);//총 관객수
	for(i=0;i<3;i++) //영화 관객수 출력
	{
	gotoxy(55,15+i);	printf("%d번 영화 관객 수: %d \n",i+1, p->movie->movieCount[i] );
	}
	for(i=0;i<5;i++) //스낵 팔린 겟수
	{
	gotoxy(55,19+i);	printf("%d번 스낵 수 : %d \n", i+1,p->nowsituation->snackCount[i]);
	}
	/////////////////////////////////////////////////
	////////////// sum 구하는중 //////////////////////
	//////////////////////////////////////////////// 
	sum+=p->movie->movieCount[0]*10000; //첫 영화
	sum+=p->movie->movieCount[1]*9000; //두번재 영화
	sum+=p->movie->movieCount[2]*6000; //세번째 영화
	sum+=p->nowsituation->snackCount[0]*5000; //첫번째 스넥
	sum+=p->nowsituation->snackCount[1]*3000; //두번째 스넥
	sum+=p->nowsituation->snackCount[2]*4000; //세번쨰 스넥
	sum+=p->nowsituation->snackCount[3]*6000; //네번쨰 스넥
	sum+=p->nowsituation->snackCount[4]*2000; //다섯번째 스넥
	gotoxy(55,25);printf("총 매출 : %d \n", sum);
	gotoxy(55,27);printf("아무키나 누르시면 프로그램의 종료 됩니다. \n");
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
