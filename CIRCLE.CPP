#include<iostream.h>
#include<conio.h>
#include<graphics.h>

void display(int xc,int yc,int x,int y)
{
	putpixel(320+(xc+x),240-(yc+y),15);
	putpixel(320+(xc+x),240-(yc-y),15);
	putpixel(320+(xc-x),240-(yc+y),15);
	putpixel(320+(xc-x),240-(yc-y),15);
	putpixel(320+(xc+x),240-(yc+y),15);
	putpixel(320+(xc+x),240-(yc-y),15);
	putpixel(320+(xc-x),240-(yc+y),15);
	putpixel(320+(xc-x),240-(yc-y),15);
}

int main()
{
	clrscr();
	int gd,gm;
	detectgraph(&gd,&gm);
	initgraph(&gd,&gm,"C:\\TC\\BGI");
	line(0,240,640,240);
	line(320,0,320,480);
	int r,xc,yc;
	cout<<"\nEnter radius : ";
	cin>>r;
	cout<<"\nEnter center : ";
	cin>>xc>>yc;
	int x = 0,y = 0;
	int p0 = 1-r;
	while(x<=y)
	{
		if(p0<0)
		{
			x++;
			p0 = p0 + (2*x) + 1;
		}
		else
		{
			x++;
			y--;
			p0 = p0 + (2*x) - (2*y) + 1;
		}
		display(xc,yc,x,y);
	}
	getch();
	return 0;
}
