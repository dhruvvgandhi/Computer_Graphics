#include<iostream.h>
#include<dos.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>

int sign(int k)
{
if(k==0)
{
return 0;
}
if(k<0)
return -1;

else
return 1;

}

void bsenline(int x1,int y1,int x2,int y2,int color)
{

int dx=abs(x2-x1);
int dy =abs(y2-y1);
int p=0;
int xinc = sign(x2-x1);
int yinc = sign(y2-y1);
int x=x1;
int y=y1;

if(dx>dy)
{
p=p+2*dy-dx;

for(int j=0;j<dx;j++)
{
delay(10);
if(p<0)
{
p=p+2*dy;
}
else
{
p=p-2*(dy-dx);
y=y+yinc;
}
x=x+xinc;

putpixel(x,y,color);

}
}
else
{
p=p+2*dx-dy;

for(int q=0;q<dy;q++)
{
delay(10);
if(p<0)
{
p=p+2*dx;
}
else
{
p=p-2*(dx-dy);
x=x+xinc;
}
y=y+yinc;

putpixel(x,y,color);
}
}
}

void plot(int xc,int yc,int x,int y,int color)
{
putpixel(xc+x,yc+y,color);
putpixel(xc+x,yc-y,color);
putpixel(xc-x,yc+y,color);
putpixel(xc-x,yc-y,color);
delay(10);
putpixel(xc+y,yc+x,color);
putpixel(xc+y,yc-x,color);
putpixel(xc-y,yc+x,color);
putpixel(xc-y,yc-x,color);

}

void bsencircle(int xc,int yc,int radius,int color)
{
int x,y,s;
x=0;
y=radius;
s=3-2*radius;

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

plot(xc,yc,x,y,color);
}
}

int round(int p)
{
return int(p+0.5);
}
void dda(int x1,int y1,int x2,int y2,int color)
{
float x=x1;
float y =y1;
int dx=x2-x1;
int dy=y2-y1;
int steps;
if(abs(dx)>abs(dy))
{
steps=dx;
}
else
steps=dy;

float xinc= float(dx)/steps;
float yinc = float(dy)/steps;

for(int k =0;k<steps;k++)
{
putpixel(round(x),round(y),color);
x=x+xinc;
y=y+yinc;
}

}

void mpcircle(int xc,int yc,int radius,int color)
{
int x=0;
int y=radius;
int p=1-radius;

while(x<y)
{
if(p<0)
{
p=p+2*x+1;
}
else
{
p=p+2*(x-y)+1;
y--;
}
x++;

plot(xc,yc,x,y,color);
}
}


void main()
{
clrscr();

int gdriver=DETECT,gmode;
initgraph(&gdriver,&gmode,"C:\\TC\\BGI");


mpcircle(300,150,50,BLUE);
mpcircle(300,150,25,BLUE);
bsencircle(150,150,50,CYAN);
bsencircle(150,150,25,CYAN);
bsenline(225,175,225,275,RED);
bsenline(200,275,225,275,GREEN);
bsenline(225,175,200,275,9);
ellipse(225,375,0,360,40,50);
bsenline(100,150,300,150,CYAN);
getch();
}




