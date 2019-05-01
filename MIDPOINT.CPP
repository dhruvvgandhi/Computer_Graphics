#include<iostream.h>
#include<graphics.h>
#include<conio.h>

void midpoint(int xc,int yc,int radius)
{
int p=1-radius;

int x=0;
int y=radius;
while(x<y)
{
x++;
if(p<0)
{
p=p+2*x+1;
}
else
{
y--;
p=p+2*x-2*y+1;
}

putpixel(xc+x,yc+y,RED);
putpixel(xc+x,yc-y,RED);
putpixel(xc-x,yc+y,RED);
putpixel(xc-x,yc-y,RED);
putpixel(xc+y,yc+x,RED);
putpixel(xc-y,yc+x,RED);
putpixel(xc+y,yc-x,RED);
putpixel(xc-y,yc-x,RED);

}
}

void main()
{
int gdriver = DETECT ,gmode;
initgraph(&gdriver,&gmode,"C:\\TC\\BGI");

midpoint(200,300,100);
getch();
}