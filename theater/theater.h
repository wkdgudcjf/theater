#pragma once
#pragma warning (disable:4996)
#include <time.h> //_strtime()�� ���ؼ� ��Ŭ��� �� 
#include <windows.h> 
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h> // rand(), srand() �Լ��� ����ϱ� ���ؼ� ��Ŭ��� �� 

struct time{  //Ÿ�� ����ü
	unsigned int ti_hour; 
	unsigned int ti_min; 
	unsigned int ti_sec; 
}; 

/*--------------------------------------------------------------------
	�� �󿵰��� �� ���� ��ȭ������ �����ϴ� ����ü
	�����ϰ� ������ �մԵ��� ��ȭ ��ǥ�� ���� �����̴�.
	�����ϰ� ������ �մԵ��� �� ��° ��ȭ�� �����ϴ��Ŀ� ���� 
	�±� ������ �����Ѵ�.
*/
typedef struct _room Room;
typedef struct _room //�� ����ü 
{
	int firstMovie; // ù ��° ��ȭ
	int secondMovie; // �� ��° ��ȭ
	int thirdMovie; // �� ��° ��ȭ
}Room;

/*--------------------------------------------------------------------
	�¼� ǥ�� �� ��ȭ ��ǥ���� ī��Ʈ �ϱ� ���� ����ü
*/
typedef struct _movie Movie;
typedef struct _movie
{
	Room oneRoom[6][10]; // 1�󿵰�
	Room twoRoom[6][10]; // 2�󿵰�
	Room threeRoom[6][10]; // 3�󿵰�
	int movieCount[3]; // �� �迭���� �� ��ȭ�� �� ��ǥ���� ī��Ʈ��
	int roomCount[3][3]; // �� �迭���� �� ��ȭ�� ù ��°, �� ��°, �� ��° ��ȭ���� ��ǥ���� ī��Ʈ��.
}Movie;

/*--------------------------------------------------------------------
	����â�� ���� �����ϱ� ���� ����ü
*/
typedef struct _state State;
typedef struct _state
{
	char name[100]; // ���ΰ��� �̸�
	int age;  // ����
	int money;  // ���� �ڱ�
	int snack[5];  // ������ ������ ���� 
	int restRoom;  // ȭ��� �̿� ����
	int gameRoom;  // ���Ӽ��� �̿� ����
	char movie_name[100];  // ���� ������ ��ȭ�� ����
	int infoMovie[4];  // 0�� �� : �󿵰� ����, 1�� �� : ��ȭ ���� ����, 2�� �� : �� ����, 3�� �� : �� ����
	int movieTimeHour; // ��ȭ ���� �ð�(��)
	int movieTimeMin;  // ��ȭ ���� �ð�(��)
	int movieTimeSec;  // ��ȭ ���� �ð�(��)
}State;

/*--------------------------------------------------------------------
	���ڸ���Ʈ �� ���� ��Ȳ�� ǥ���ϱ� ���� ����ü
*/
typedef struct _nowsituation Nowsituation;
typedef struct _nowsituation
{
	int randNum[540]; // 
	int totalNum; // �մ� �� ���� ��
	int currentNum; // ���� ������ ���� ��
	double temperature; // ���� �µ�
	int garbage; // ���� �������
	int electronic; // (���α׷� ������ ��������) ������ ���� Ƚ�� 
	int snackCount[5]; // ���� �� ���� ��
	int startTime[3]; // ���α׷� ���� �ð� ([0] : ��, [1] : ��, [2] : ��)
	int tagInit[9];//�Խ�Ʈ �ʱ�ȭ üŷ ����
}NowSituation;

/*--------------------------------------------------------------------
	��ǥ�� �����ϱ� ���� ����ü
*/
typedef struct _location Location;
typedef struct _location
{
	int startX; // ���� ���� x
	int startY; // ���� ���� y
	int endX; // �� ���� x
	int endY; // �� ���� y
}Location;

/*--------------------------------------------------------------------
	��� ����ü
*/
typedef struct _head Head;
typedef struct _head 
{
	Movie *movie; 
	Room *room;
	State *state;
	NowSituation *nowsituation;
	Location *location;
}Head;

void gettime(struct time *); 
void gotoxy(int x, int y); 
void clrscr(int, int, int, int); 
void textcolor(int foreground, int background);
int random(int); 

void randomNumCreate(int *); // �����

void myInit(Head *); // �ɱԺ�
void guest(Head *p); // �ɱԺ�

void myTicket(Head *p); // ����ö
void mySnack(Head *p); // ����ö
void aryPrint(Head *,int,int); // ����ö
void buy(Head *p);             // ����ö

void guestInit(Head *p); // ������
void stateInit(Head *p); // ������
void move(Head *p);  // ������
void total(Head *p); // ������
void stateDisplay(Head *p);  // ������
void toilet(Head *p); // ������
void game(Head *p);  // ������

void subCheck(Head *p, int tag); // ������
void trashPerson(Head *p); // ������
void degreePerson(Head *p); // ������
void elePerson(Head *p); // ������
void ticketDisplay(); // ������
void ticket(Head *p); // ������
void snack(Head *p);  // ������

void moveStop(Head *p); // ������
void display(Head *p); // ������
void randPerson(Head *p); // ������
void movieDisplay(Head *p); // ������
void setDisplay(Head *p);   // ������
void myMovie(Head *p);      // ������
int chansec(int hour,int min,int sec); // ������


#define ESC 27 

#define BLACK 0 
#define BLUE 1 
#define GREEN 2 
#define CYAN 3 
#define RED 4 
#define MAGENTA 5 
#define BROWN 6 
#define LIGHTGRAY 7 
#define DARKGRAY 8 
#define LIGHTBLUE 9 
#define LIGHTGREEN 10 
#define LIGHTCYAN 11 
#define LIGHTRED 12 
#define LIGHTMAGENTA 13 
#define YELLOW 14 
#define WHITE 15 
