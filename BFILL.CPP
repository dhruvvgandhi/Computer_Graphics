#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
#include<dos.h>
void bfill(int x,int y,int bcolor,int ncolor)
{
int current=getpixel(x,y);
if(current!=ncolor&&current!=bcolor)
{

delay(2);

putpixel(x,y,ncolor);
bfill(x+1,y,bcolor,ncolor);
bfill(x-1,y,bcolor,ncolor);
bfill(x,y-1,bcolor,ncolor);
bfill(x,y+1,bcolor,ncolor);
}
}
void main()
{
clrscr();
int gdriver=DETECT,gmode;
initgraph(&gdriver,&gmode,"C:\\TC\\BGI");
setcolor(RED);
rectangle(100,100,150,150);
bfill(125,125,RED,GREEN);
getch();
}