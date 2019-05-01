#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>

int sign(int k)
{
if(k==0)
return 0;

if(k<0)
return -1;

else
return 1;

}

void bresenham(int x1,int y1,int x2,int y2,int color)
{ int dx=abs(x2-x1);
int dy=abs(y2-y1);
int x =x1;
int y=y1;
int p=0;
int xinc = sign(x2-x1);
int yinc= sign(y2-y1);

if(dx>dy)
{
p=2*dy-dx;

for(int k=0;k<dx;k++)
{
if(p<0)
{
p=p+2*dy;
}
else
{
p=p+2*(dx-dy);
y=y+yinc;
}
x=x+xinc;

putpixel(x,y,color);
}
}
else
{
p=p+2*dx-dy;

for(int j=0;j<dy;j++)
{
if(p<0)
{
p=p+2*dx;
}
else
{
p=p+2*(dx-dy);
x=x+xinc;
}
y=y+yinc;
putpixel(x,y,color);
}
}
}

void main()
{
clrscr();

int gdriver = DETECT ,gmode;
initgraph(&gdriver,&gmode,"C:\\TC\\BGI");

cout<<"OK";
bresenham(225,175,225,275,RED);
bresenham(200,275,225,275,GREEN);
bresenham(225,175,200,275,9);


getch();
}






