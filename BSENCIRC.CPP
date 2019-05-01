#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>

void bsencircle(int xc,int yc,int radius,int color)
{
int s=3-2*radius;
int x=0;
int y=radius;

while(x<y)
{
if(s<=0)
{
   s=s+4*x+6;
}
else
{
s=s+4*(x-y)+10;
y--;
}
x++;

putpixel(xc+x,yc+y,color);
putpixel(xc+x,yc-y,color);
putpixel(xc-x,yc+y,color);
putpixel(xc-x,yc-y,color);
putpixel(xc+y,yc+x,color);
putpixel(xc+y,yc-x,color);
putpixel(xc-y,yc+x,color);
putpixel(xc-y,yc-x,color);

}
}

void main()
{
int gdriver = DETECT ,gmode;
initgraph(&gdriver,&gmode,"C:\\TC\\BGI");

bsencircle(300,300,50,BLUE);
getch();
}
