#pragma once
#pragma warning (disable:4996)
#include <time.h> //_strtime()를 위해서 인클루드 함 
#include <windows.h> 
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h> // rand(), srand() 함수를 사용하기 위해서 인클루드 함 

struct time{  //타임 구조체
	unsigned int ti_hour; 
	unsigned int ti_min; 
	unsigned int ti_sec; 
}; 

/*--------------------------------------------------------------------
	각 상영관의 몇 번쨰 영화인지를 구분하는 구조체
	랜덤하게 입장한 손님들의 영화 매표를 위한 변수이다.
	랜덤하게 입장한 손님들이 몇 번째 영화를 선택하느냐에 따라 
	태그 역할을 수행한다.
*/
typedef struct _room Room;
typedef struct _room //룸 구조체 
{
	int firstMovie; // 첫 번째 영화
	int secondMovie; // 두 번째 영화
	int thirdMovie; // 세 번째 영화
}Room;

/*--------------------------------------------------------------------
	좌석 표현 및 영화 매표수를 카운트 하기 위한 구조체
*/
typedef struct _movie Movie;
typedef struct _movie
{
	Room oneRoom[6][10]; // 1상영관
	Room twoRoom[6][10]; // 2상영관
	Room threeRoom[6][10]; // 3상영관
	int movieCount[3]; // 각 배열방은 각 영화의 총 매표수를 카운트함
	int roomCount[3][3]; // 각 배열방은 각 영화의 첫 번째, 두 번째, 세 번째 영화들의 매표수를 카운트함.
}Movie;

/*--------------------------------------------------------------------
	상태창의 값을 저장하기 위한 구조체
*/
typedef struct _state State;
typedef struct _state
{
	char name[100]; // 주인공의 이름
	int age;  // 나이
	int money;  // 현재 자금
	int snack[5];  // 구입한 스택의 종류 
	int restRoom;  // 화장실 이용 여부
	int gameRoom;  // 게임센터 이용 여부
	char movie_name[100];  // 현재 구입한 영화의 제목
	int infoMovie[4];  // 0번 방 : 상영관 정보, 1번 방 : 영화 순서 정보, 2번 방 : 행 정보, 3번 방 : 열 정보
	int movieTimeHour; // 영화 시작 시간(시)
	int movieTimeMin;  // 영화 시작 시간(분)
	int movieTimeSec;  // 영화 시작 시간(초)
}State;

/*--------------------------------------------------------------------
	인텔리전트 및 현재 상황을 표현하기 위한 구조체
*/
typedef struct _nowsituation Nowsituation;
typedef struct _nowsituation
{
	int randNum[540]; // 
	int totalNum; // 손님 총 입장 수
	int currentNum; // 현재 입장한 입장 수
	double temperature; // 현재 온도
	int garbage; // 현재 쓰레기양
	int electronic; // (프로그램 시작한 시점부터) 에어컨 동작 횟수 
	int snackCount[5]; // 스낵 총 구매 수
	int startTime[3]; // 프로그램 시작 시간 ([0] : 시, [1] : 분, [2] : 초)
	int tagInit[9];//게스트 초기화 체킹 변수
}NowSituation;

/*--------------------------------------------------------------------
	좌표를 저장하기 위한 구조체
*/
typedef struct _location Location;
typedef struct _location
{
	int startX; // 시작 지점 x
	int startY; // 시작 지점 y
	int endX; // 끝 지점 x
	int endY; // 끝 지점 y
}Location;

/*--------------------------------------------------------------------
	헤드 구조체
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

void randomNumCreate(int *); // 강사님

void myInit(Head *); // 심규복
void guest(Head *p); // 심규복

void myTicket(Head *p); // 장형철
void mySnack(Head *p); // 장형철
void aryPrint(Head *,int,int); // 장형철
void buy(Head *p);             // 장형철

void guestInit(Head *p); // 강신현
void stateInit(Head *p); // 강신현
void move(Head *p);  // 강신현
void total(Head *p); // 강신현
void stateDisplay(Head *p);  // 강신현
void toilet(Head *p); // 강신현
void game(Head *p);  // 강신현

void subCheck(Head *p, int tag); // 김지수
void trashPerson(Head *p); // 김지수
void degreePerson(Head *p); // 김지수
void elePerson(Head *p); // 김지수
void ticketDisplay(); // 김지수
void ticket(Head *p); // 김지수
void snack(Head *p);  // 김지수

void moveStop(Head *p); // 한유진
void display(Head *p); // 한유진
void randPerson(Head *p); // 한유진
void movieDisplay(Head *p); // 한유진
void setDisplay(Head *p);   // 한유진
void myMovie(Head *p);      // 한유진
int chansec(int hour,int min,int sec); // 한유진


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
