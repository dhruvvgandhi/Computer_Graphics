#include<iostream.h>
#include<graphics.h>
#include<math.h>
#include<conio.h>
#include<dos.h>

void fldfill(int x,int y,int color)
{
delay(2);
int current = getpixel(x,y);
if(current==0)
{
	putpixel(x,y,color);
	fldfill(x-1,y,color);
	fldfill(x-1,y-1,color);
	fldfill(x-1,y+1,color);
	fldfill(x+1,y,color);
	fldfill(x+1,y-1,color);
	fldfill(x+1,y+1,color);
	fldfill(x,y+1,color);
	fldfill(x,y-1,color);

       }
}

void main()
{
clrscr();
int gdriver=DETECT,gmode;
initgraph(&gdriver,&gmode,"C:\\TC\\BGI");

setcolor(CYAN);
rectangle(100,100,150,150);
fldfill(125,125,RED);
getch();
}
