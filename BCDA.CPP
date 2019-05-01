#include <iostream.h>
#include <conio.h>
#include <graphics.h>

void display(int xc,int yc,int x,int y){
	putpixel(xc+x,yc+y,BLUE);
	putpixel(xc+x,yc-y,BLUE);
	putpixel(xc-x,yc+y,BLUE);
	putpixel(xc-x,yc-y,BLUE);
	putpixel(xc+y,yc+x,BLUE);
	putpixel(xc+y,yc-x,BLUE);
	putpixel(xc-y,yc+x,BLUE);
	putpixel(xc-y,yc-x,BLUE);
}

void main(){
	int x,y,xc,yc,r,gm,gd=DETECT;
	initgraph(&gd,&gm,"D:\\TCPP3\\BGI");
	clrscr();
	cout<<"Enter coordinates of center and radius: "<<endl;
	cin>>xc>>yc>>r;
	xc+=320;
	yc=240-yc;
	clrscr();
	//cleardevice();
	setbkcolor(BLACK);
	setcolor(BLACK);
	line(320,0,320,480);
	line(0,240,640,240);
	x=0;
	y=r;
	int s=3-2*r;
	while(x<=y){
		if(s<0){
			x++;
			s=s+4*x+6;
		}else{
			x++;
			y--;
			s=s+4*(x-y)+10;
		}
		display(xc,yc,x,y);
	}
	getch();
	closegraph();
}
