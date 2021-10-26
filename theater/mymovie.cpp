#include "theater.h"

void myMovie(Head *p)
{
 int now,startime;
 int a=1;
 struct time sttime; //현재시간 받아오는 구조체
 int x=p->state->infoMovie[0];//1관2관3관 여부
 if(p->state->infoMovie[0]==0) //표를 구매하지 않았을때
 {
  printf("표를 예매하지 않았습니다.");
  return ;
 }
 system("cls");
 movieDisplay(p); //상영관 display하는 함수
 //자신의 표에 맞는 상영관을 선택하여 들어가기 위해 좌표를 주고 move 함수 호출
 if(x==1)
 {
  p->location->endX=11;//미정
  p->location->endY=25;//미정
 }
 else if(x==2)
 {
  p->location->endX=65;
  p->location->endY=25;
 }
 else if(x==3)
 {
  p->location->endX=18;
  p->location->endY=25;
 }
 p->location->startX=59;
 p->location->startY=25;
 move(p);
 system("cls");

 /////////////*영화관 입장전에 시간을 확인해 주는 조건 체크*///////////
 gettime(&sttime); //현재시간 받아오기
 now=chansec(sttime.ti_hour, sttime.ti_min, sttime.ti_sec);
 startime=chansec(p->state->movieTimeHour,p->state->movieTimeMin,p->state->movieTimeSec);//영화시간 받아오기

 if(startime-(2*60)<=now&&now<startime) //상영 2분전에 미리 입장가능 
 {
  setDisplay(p);//좌석정보 찍어주기
 }
 else
 {
  gotoxy(55,20);printf("상영시간이 맞지않아 입장이 불가능 합니다.");
  Sleep(700);
  system("cls");
  return;
 }

 gotoxy(23,3);printf("대기시간:     초");
 if(now<startime)
 {
  gotoxy(46,3);printf("♬♬♬♬♬       광     고     중       ♬♬♬♬♬");
 }
 clrscr(120, 37, 130, 37);
 while(a)
 {

  gettime(&sttime); //현재시간 받아오기
  now=chansec(sttime.ti_hour, sttime.ti_min, sttime.ti_sec);

  if(a!=now)
  {
   gotoxy(34,3);printf("%3d",(startime+(1*60))-now);
   a=now;
  }
  if(now==startime)
  {
   gotoxy(46,3);printf("★★★★★       상     영     중       ★★★★★");
  }
  if(now==startime+(1*60))
  {
   gotoxy(46,3);printf("※※※※※      상    영    종    료     ※※※※※");
   Sleep(500);
   break;
  }
 }




 system("cls");
 return ;

}
int chansec(int hour,int min,int sec)
{
 return (hour*3600)+(min*60)+(sec);
}