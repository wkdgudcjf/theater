#include "theater.h"

void myMovie(Head *p)
{
 int now,startime;
 int a=1;
 struct time sttime; //����ð� �޾ƿ��� ����ü
 int x=p->state->infoMovie[0];//1��2��3�� ����
 if(p->state->infoMovie[0]==0) //ǥ�� �������� �ʾ�����
 {
  printf("ǥ�� �������� �ʾҽ��ϴ�.");
  return ;
 }
 system("cls");
 movieDisplay(p); //�󿵰� display�ϴ� �Լ�
 //�ڽ��� ǥ�� �´� �󿵰��� �����Ͽ� ���� ���� ��ǥ�� �ְ� move �Լ� ȣ��
 if(x==1)
 {
  p->location->endX=11;//����
  p->location->endY=25;//����
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

 /////////////*��ȭ�� �������� �ð��� Ȯ���� �ִ� ���� üũ*///////////
 gettime(&sttime); //����ð� �޾ƿ���
 now=chansec(sttime.ti_hour, sttime.ti_min, sttime.ti_sec);
 startime=chansec(p->state->movieTimeHour,p->state->movieTimeMin,p->state->movieTimeSec);//��ȭ�ð� �޾ƿ���

 if(startime-(2*60)<=now&&now<startime) //�� 2������ �̸� ���尡�� 
 {
  setDisplay(p);//�¼����� ����ֱ�
 }
 else
 {
  gotoxy(55,20);printf("�󿵽ð��� �����ʾ� ������ �Ұ��� �մϴ�.");
  Sleep(700);
  system("cls");
  return;
 }

 gotoxy(23,3);printf("���ð�:     ��");
 if(now<startime)
 {
  gotoxy(46,3);printf("�ݢݢݢݢ�       ��     ��     ��       �ݢݢݢݢ�");
 }
 clrscr(120, 37, 130, 37);
 while(a)
 {

  gettime(&sttime); //����ð� �޾ƿ���
  now=chansec(sttime.ti_hour, sttime.ti_min, sttime.ti_sec);

  if(a!=now)
  {
   gotoxy(34,3);printf("%3d",(startime+(1*60))-now);
   a=now;
  }
  if(now==startime)
  {
   gotoxy(46,3);printf("�ڡڡڡڡ�       ��     ��     ��       �ڡڡڡڡ�");
  }
  if(now==startime+(1*60))
  {
   gotoxy(46,3);printf("�ءءءء�      ��    ��    ��    ��     �ءءءء�");
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