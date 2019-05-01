#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<graphics.h>

void main()
{
 int gd=DETECT,gm,k;
 float x1,y1,x2,y2,dx,dy,xinc,yinc,p[100],x,y;
 initgraph(&gd,&gm,"C:\\TurboC3\\BGI");
 printf("Enter co ordinates of points\n");
 scanf("%f %f %f %f",&x1,&y1,&x2,&y2);
  x = x1;
  y = y1;
 dx = x2-x1;
 dy = y2-y1;
 while(x!=x2)
 {
 if(abs(dx)>=abs(dy))  //slope is less than 1
 {
  p[0] = 2*abs(dy) - abs(dx);
  k=0;
  if(p[k++]<0)
  {
   xinc = dx/abs(dx);
   yinc = 0;
   p[k+1] = p[k] + 2*abs(dy);
  }
  else
  {
   xinc = dx/abs(dx);
   yinc = dy/abs(dy);
   p[k+1] = p[k] + 2*abs(dy) - 2*abs(dx);
  }
 }
 else //slope is greater than 1
 {
  p[0] = 2*abs(dx) - abs(dy);
  k=0;
  if(p[k++]<0)
  {
   xinc = 0;
   yinc = dy/abs(dy);
   p[k+1] = p[k] + 2*abs(dx);
  }
  else
  {
   xinc = dx/abs(dx);
   yinc = dy/abs(dy);
   p[k+1] = p[k] + 2*abs(dx) - 2*abs(dy);
  }
 }
  x = x + xinc;
  y = y + yinc;
  putpixel(x,y,WHITE);
 }
}
