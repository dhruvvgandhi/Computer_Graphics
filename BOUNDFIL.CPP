#include<iostream.h>
#include<conio.h>
#include<graphics.h>

void bfill(int x,int y,int ncolor,int bcolor)
{
int current=getpixel(x,y);
if(current!=ncolor && current!=bcolor)
{
putpixel(x,y,ncolor);
bfill(x+1,y,ncolor,bcolor);
bfill(x-1,y,ncolor,bcolor);
bfill(x,y+1,ncolor,bcolor);
bfill(x,y-1,ncolor,bcolor);
}
}
void main()
{
clrscr();
int gdriver=DETECT,gmode;
initgraph(&gdriver,&gmode,"C:\\TC\\BGI");

setcolor(RED);
rectangle(100,100,150,150);
bfill(125,125,CYAN,RED);
getch();
}
