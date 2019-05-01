#include<stdio.h>
#include<graphics.h>
#include<conio.h>

void main()
{
 int gd,gm,x0,y0,x,y,xc,yc,pk,p0,r;
 clrscr();
 detectgraph(&gd,&gm);
 initgraph(&gd,&gm,"c: \\tc\\BGI");
 printf("enter centre and radius");
 scanf("%d %d %d",&x0,&y0,&r);
 putpixel(x0,y0,RED);
 xc=x0;
 yc=y0+r;
 putpixel(xc,yc,WHITE);
 yc=y0;
 p0=3-2*r;
 pk=p0;
 x=0;
 y=r;
 while(x<y)
 {
  if(pk<0)
  {
   x =x+1;
   y=y;
   pk=pk+4*x +6;
  }
  else if(pk>0)
  {
   x=x+1;
   y=y-1;
   pk=pk+4*(x-y)+10;
  }
  putpixel(xc+x,yc+y,WHITE);
  putpixel(xc-x,yc+y,WHITE);
  putpixel(xc+x,yc-y,WHITE);
  putpixel(xc-x,yc-y,WHITE);
  putpixel(xc+y,yc+x,WHITE);
  putpixel(xc-y,yc+x,WHITE);
  putpixel(xc+y,yc-x,WHITE);
  putpixel(xc-y,yc-x,WHITE);
  delay(100);
 }
 getch();
 }
