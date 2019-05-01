#include<conio.h>
#include<graphics.h>
#include<stdio.h>

void boundaryfill(int x,int y,int fill,int boundary)
{
int c;
c=getpixel(x,y);
if((c!=boundary)&&(c!=fill))
{
delay(10);
putpixel(x,y,fill);
boundaryfill(x,y-1,boundary,fill);
boundaryfill(x+1,y-1,boundary,fill);
boundaryfill(x+1,y,boundary,fill);
boundaryfill(x+1,y+1,boundary,fill);
boundaryfill(x,y+1,boundary,fill);
boundaryfill(x-1,y+1,boundary,fill);
boundaryfill(x-1,y,boundary,fill);
boundaryfill(x-1,y-1,boundary,fill);

}

}
void main()
{
int driver=DETECT,gmode;
initgraph(&driver,&gmode,"c:\\turboc3\\bgi");
setcolor(4);
rectangle(50,50,100,100);
boundaryfill(55,55,5,4);
getch();
closegraph();

}
