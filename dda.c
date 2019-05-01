
#include<stdio.h>
#include<math.h>
#include<graphics.h>

void main()
{
 int gdriver = DETECT,gmode;
 float x1,x2,y1,y2,x,y,step,dx,dy,i,xinc,yinc;
 initgraph(&gdriver,&gmode,"c:\\TurboC3\\BGI");
// clrscr();
 printf("Enter end pt co-ordinates\n");
 scanf("%f %f %f %f",&x1,&y1,&x2,&y2);
 dx = x2 - x1;
 dy = y2 - y1;
 putpixel(x1,y1,WHITE);
 if(abs(dx)>=abs(dy))
  step = abs(dx);
 else step = abs(dy);
 xinc = dx/step;
 yinc = dy/step;
 x = x1;
 y = y1;
 while(x!=x2 || y!=y2)
 {
  x = x + xinc;
  y = y + yinc;
  putpixel(x,y,WHITE);
 }
// closegraph();
}
