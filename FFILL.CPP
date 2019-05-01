#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
#include<dos.h>
void ffill(int x,int y,int ncolor)
{
int current=getpixel(x,y);
if(current==0)
{

delay(2);

putpixel(x,y,ncolor);

ffill(x+1,y,ncolor);
ffill(x-1,y,ncolor);
ffill(x,y-1,ncolor);
ffill(x,y+1,ncolor);

ffill(x+1,y+1,ncolor);
ffill(x-1,y+1,ncolor);
ffill(x-1,y-1,ncolor);
ffill(x+1,y-1,ncolor);

}
}
void main()
{
clrscr();
int gdriver=DETECT,gmode;
initgraph(&gdriver,&gmode,"C:\\TC\\BGI");
setcolor(RED);
rectangle(100,100,150,150);
ffill(115,115,GREEN);
getch();
}