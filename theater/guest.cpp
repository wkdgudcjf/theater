#include "theater.h"

void guest(Head *p)
{ 
	int num; 
	int tag = 0;
	

	if(random(10)==1 && (p->nowsituation->totalNum < 540))
	{
		p->nowsituation->currentNum++;
		p->nowsituation->totalNum++;
		if(random(3)==0)
		{
			snack(p);
		}
		tag = 1;
		ticket(p);
	}
	subCheck(p, tag);
}

int random(int n) 
{ 
	int res; 
	res = rand() % n; // 0���� n-1������ ���� ���� �߻� 
	return res; 
} 

void snack(Head *p)
{ 
	int res;
	int i;

	res = random(6); // 0~5������ ������ �߻���Ŵ 
	
	switch(res)
	{
	case 0 : // �ƹ��͵� ���� �ʴ� ���
		{
		}
	case 1:
		{
			p->nowsituation->snackCount[0]++;
			p->nowsituation->garbage++;
			break;
		}
	case 2:
		{
			p->nowsituation->snackCount[1]++;
			p->nowsituation->garbage++;
			break;
		}
	case 3:
		{
			p->nowsituation->snackCount[2]++;
			p->nowsituation->garbage++;
			break;
		}
	case 4:
		{
			p->nowsituation->snackCount[3]++;
			p->nowsituation->garbage++;
			break;
		}
	case 5:
		{
			p->nowsituation->snackCount[4]++;
			p->nowsituation->garbage++;
			break;
		}
	}
} 

void ticket(Head *p) 
{ 
	int theaterRan; //���� ������ ������ ���ϰ�
	int timeRan; // �ð��� ������ ������ ���ϰ�
	int lineRan; // ���� ������ ������ ���ϰ�
	int colRan; // ���� ������ ������ ���ϰ�
	static int i=0;
	int sit;
    struct time sttime;
	while(1)
	{
		gettime(&sttime);
			if(p->nowsituation->randNum[i] >= 0 && p->nowsituation->randNum[i] <60)
			{
				if(sttime.ti_hour*3600+sttime.ti_min*60+sttime.ti_sec > p->nowsituation->startTime[0]*3600+(p->nowsituation->startTime[1]+2)*60+p->nowsituation->startTime[2])
				{
					i++;
					continue;
				}
				lineRan = (p->nowsituation->randNum[i])/10;
				colRan = (p->nowsituation->randNum[i])%10;
                if((p->movie->oneRoom[lineRan][colRan].firstMovie)==0) // ���� ������ �¼��� ���������
				{
					p->movie->oneRoom[lineRan][colRan].firstMovie=1; // �¼��� ������
					(p->movie->roomCount[0][0])++; // 1���� ù��° ��ȭ���� ������� ++
					p->movie->movieCount[0]++;
					i++;
					return; //return;
				}
				else //�������������
				{
					i++;
					continue; //while������ ���ư���
				}
			}
			else if(p->nowsituation->randNum[i] >=60  && p->nowsituation->randNum[i] <120)
			{
				if(sttime.ti_hour*3600+sttime.ti_min*60+sttime.ti_sec > p->nowsituation->startTime[0]*3600+(p->nowsituation->startTime[1]+5)*60+p->nowsituation->startTime[2])
				{
					i++;
					continue;
				}
				sit = (p->nowsituation->randNum[i])-60;
				lineRan = sit/10;
				colRan = sit%10;
				if((p->movie->oneRoom[lineRan][colRan].secondMovie)==0) // ���� ������ �¼��� ���������
				{
					p->movie->oneRoom[lineRan][colRan].secondMovie=1; // �¼��� ������
					(p->movie->roomCount[1][0])++; // 1���� ù��° ��ȭ���� ������� ++
					p->movie->movieCount[0]++;
					i++;
					return; //return;
				}
				else //�������������
				{
					i++;
					continue; //while������ ���ư���
				}
			}
			else if(p->nowsituation->randNum[i] >=120  && p->nowsituation->randNum[i] <180)
			{
				if(sttime.ti_hour*3600+sttime.ti_min*60+sttime.ti_sec > p->nowsituation->startTime[0]*3600+(p->nowsituation->startTime[1]+8)*60+p->nowsituation->startTime[2])
				{
					i++;
					continue;
				}
				sit =  (p->nowsituation->randNum[i])-120;
				lineRan = sit/10;
				colRan = sit%10;
				if((p->movie->oneRoom[lineRan][colRan].thirdMovie)==0) // ���� ������ �¼��� ���������
				{
					p->movie->oneRoom[lineRan][colRan].thirdMovie=1; // �¼��� ������
					(p->movie->roomCount[2][0])++; // 1���� ù��° ��ȭ���� ������� ++
					p->movie->movieCount[0]++;
					i++;
					return; //return;
				}
				else //�������������
				{
					i++;
					continue; //while������ ���ư���
				}
			}
			else if(p->nowsituation->randNum[i] >=180  && p->nowsituation->randNum[i] <240)
			{
				if(sttime.ti_hour*3600+sttime.ti_min*60+sttime.ti_sec > p->nowsituation->startTime[0]*3600+(p->nowsituation->startTime[1]+3)*60+p->nowsituation->startTime[2])
				{
					i++;
					continue;
				}
				sit = (p->nowsituation->randNum[i])-180;
				lineRan = sit/10;
				colRan = sit%10;
				if((p->movie->twoRoom[lineRan][colRan].firstMovie)==0) // ���� ������ �¼��� ���������
				{
					p->movie->twoRoom[lineRan][colRan].firstMovie=1; // �¼��� ������
					(p->movie->roomCount[0][1])++; // 1���� ù��° ��ȭ���� ������� ++
					p->movie->movieCount[1]++;
					i++;
					return; //return;
				}
				else //�������������
				{
					i++;
					continue; //while������ ���ư���
				}
			}
			else if(p->nowsituation->randNum[i] >=240  && p->nowsituation->randNum[i] <300)
			{
				if(sttime.ti_hour*3600+sttime.ti_min*60+sttime.ti_sec > p->nowsituation->startTime[0]*3600+(p->nowsituation->startTime[1]+6)*60+p->nowsituation->startTime[2])
				{
					i++;
					continue;
				}
				sit = (p->nowsituation->randNum[i])-240;
				lineRan = sit/10;
				colRan = sit%10;
				if((p->movie->twoRoom[lineRan][colRan].secondMovie)==0) // ���� ������ �¼��� ���������
				{
					p->movie->twoRoom[lineRan][colRan].secondMovie=1; // �¼��� ������
					(p->movie->roomCount[1][1])++; // 1���� ù��° ��ȭ���� ������� ++
					p->movie->movieCount[1]++;
					i++;
					return; //return;
				}
				else //�������������
				{
					i++;
					continue; //while������ ���ư���
				}
			}
			else if(p->nowsituation->randNum[i] >=300  && p->nowsituation->randNum[i] <360)
			{
				if(sttime.ti_hour*3600+sttime.ti_min*60+sttime.ti_sec > p->nowsituation->startTime[0]*3600+(p->nowsituation->startTime[1]+9)*60+p->nowsituation->startTime[2])
				{
					i++;
					continue;
				}
				sit = (p->nowsituation->randNum[i])-300;
				lineRan = sit/10;
				colRan = sit%10;
				if((p->movie->twoRoom[lineRan][colRan].thirdMovie)==0) // ���� ������ �¼��� ���������
				{
					p->movie->twoRoom[lineRan][colRan].thirdMovie=1; // �¼��� ������
					(p->movie->roomCount[2][1])++; // 1���� ù��° ��ȭ���� ������� ++
					p->movie->movieCount[1]++;
					i++;
					return; //return;
				}
				else //�������������
				{
					i++;
					continue; //while������ ���ư���
				}
			}
			else if(p->nowsituation->randNum[i] >=360  && p->nowsituation->randNum[i] <420)
			{
				if(sttime.ti_hour*3600+sttime.ti_min*60+sttime.ti_sec > p->nowsituation->startTime[0]*3600+(p->nowsituation->startTime[1]+4)*60+p->nowsituation->startTime[2])
				{
					i++;
					continue;
				}
				sit = (p->nowsituation->randNum[i])-360;
				lineRan = sit/10;
				colRan = sit%10;
				if((p->movie->threeRoom[lineRan][colRan].firstMovie)==0) // ���� ������ �¼��� ���������
				{
					p->movie->threeRoom[lineRan][colRan].firstMovie=1; // �¼��� ������
					(p->movie->roomCount[0][2])++; // 1���� ù��° ��ȭ���� ������� ++
					p->movie->movieCount[2]++;
					i++;
					return; //return;
				}
				else //�������������
				{
					i++;
					continue; //while������ ���ư���
				}
			}
			else if(p->nowsituation->randNum[i] >=420  && p->nowsituation->randNum[i] <480)
			{
				if(sttime.ti_hour*3600+sttime.ti_min*60+sttime.ti_sec > p->nowsituation->startTime[0]*3600+(p->nowsituation->startTime[1]+7)*60+p->nowsituation->startTime[2])
				{
					i++;
					continue;
				}
				sit = (p->nowsituation->randNum[i])-420;
				lineRan = sit/10;
				colRan = sit%10;
				if((p->movie->threeRoom[lineRan][colRan].secondMovie)==0) // ���� ������ �¼��� ���������
				{
					p->movie->threeRoom[lineRan][colRan].secondMovie=1; // �¼��� ������
					(p->movie->roomCount[1][2])++; // 1���� ù��° ��ȭ���� ������� ++
					p->movie->movieCount[2]++;
					i++;
					return; //return;
				}
				else //�������������
				{
					i++;
					continue; //while������ ���ư���
				}
			}
			else if(p->nowsituation->randNum[i] >=480  && p->nowsituation->randNum[i] <540)
			{
				if(sttime.ti_hour*3600+sttime.ti_min*60+sttime.ti_sec > p->nowsituation->startTime[0]*3600+(p->nowsituation->startTime[1]+10)*60+p->nowsituation->startTime[2])
				{
					i++;
					continue;
				}
				sit = (p->nowsituation->randNum[i])-480;
				lineRan = sit/10;
				colRan = sit%10;
				if((p->movie->threeRoom[lineRan][colRan].thirdMovie)==0) // ���� ������ �¼��� ���������
				{
					p->movie->threeRoom[lineRan][colRan].thirdMovie=1; // �¼��� ������
					(p->movie->roomCount[2][2])++; // 1���� ù��° ��ȭ���� ������� ++
					p->movie->movieCount[2]++;
					i++;
					return; //return;
				}
				else //�������������
				{
					i++;
					continue; //while������ ���ư���
				}
			}
		}
	}

