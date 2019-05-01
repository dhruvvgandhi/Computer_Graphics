#include<iostream.h>
#include<dos.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
void main()
{


int gd,gm,i;
detectgraph(&gd,&gm);
initgraph(&gd,&gm,"C:\\TC\\BGI");
setfillstyle(SOLID_FILL,RED);
i=0;
while(!kbhit())
{
for(i=0;i<=300;i+=10)
{
fillellipse(320,50+i,50,50);
cleardevice();
if(i==300)
break;
cleardevice();
}
for(i=300;i>=100;i-=10)
{
fillellipse(320,50+i,50,50);
cleardevice();
if(i==100)
break;
}
delay(10);
}
getch();
closegraph();
}