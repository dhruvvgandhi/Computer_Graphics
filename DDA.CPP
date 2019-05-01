#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>

int round(int k)
{
return int(k+1);
}

void DDA(int x1,int y1,int x2,int y2,int color)
{
float x,y;
int steps;
int dx=x2-x1;
int dy=y2-y1;

if(abs(dx)>abs(dy))
{
steps=dx;
}
else
{
steps=dy;
}

float xinc = float(dx)/steps;
float yinc = float(dy)/steps;

x=x1;
y=y1;
putpixel(x,y,color);

for(int k=0;k<steps;k++)
{
x=x+xinc;
y=y+yinc;
putpixel(round(x),round(y),color);
}
}

void main()
{
int gdriver = DETECT ,gmode;
initgraph(&gdriver,&gmode,"C:\\TC\\BGI");

DDA(100,100,500,100,RED);

getch();
}
