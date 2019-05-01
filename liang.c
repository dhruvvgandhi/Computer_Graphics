#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<process.h>
void main()
{
float x1,y1,x2,y2,xmin,xmax,ymin,ymax,dx,dy;
float p[4],q[4],r[4];
float max,min,u1,u2;
float xi,xii,yi,yii;
int gd,gm,i;
gd=DETECT;
initgraph(&gd,&gm,"c:\\tc\\bgi");
clrscr();
printf("\n enter the line co-ordinates");
printf("\n enter 1st x=");
scanf("%f",&x1);
printf("\t 1st y=");
scanf("%f",&y1);
printf("\n enter 2nd x=");
scanf("%f",&x2);
printf("\t 2nd y=");
scanf("%f",&y2);
printf("\n enter window boundry");
printf("\n xmin=");
scanf("%f",&xmin);
printf("\n ymin=");
scanf("%f",&ymin);
printf("\n xmax=");
scanf("%f",&xmax);
printf("\n ymax=");
scanf("%f",&ymax);
dx=x2-x1;
dy=y2-y1;
cleardevice();
line(x1,y1,x2,y2);
rectangle(xmin,ymin,xmax,ymax);
p[0]=-dx;
q[0]=x1-xmin;
p[1]=dx;
q[1]=xmax-x1;
p[2]=-dy;
q[2]=y1-ymin;
p[3]=dy;
q[3]=ymax-y1;
for(i=0;i<4;i++)
{
if(p[i]==0 && q[i]<0)
{
printf("Line is outside the boundry,it is not a clipping candidate\n");
getch();
exit(0);
}
}
for(i=0;i<4;i++)
{
r[i]=q[i]/p[i];
//printf("\n r[%d]=%f",i,r[i]);
}
max=0;min=1;
for(i=0;i<4;i++)
if(p[i]<0)
{
if(r[i]>max)
max=r[i];
}
else
{
if(r[i]<min)
min=r[i];
}
u1=max;
u2=min;
//printf("\n u1=%f",u1);
//printf("\n u2=%f",u2);
if(u1>u2)
{
printf("\n line is completely outside");
getch();
exit(0);
}
xi=x1+(u1*dx);
yi=y1+(u1*dy);
xii=x1+(u2*dx);
yii=y1+(u2*dy);
rectangle(xmin,ymin,xmax,ymax);
setcolor(9);
line(xi,yi,xii,yii);
getch();
closegraph();
}
