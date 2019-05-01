#include <iostream.h>
#include <conio.h>
#include <graphics.h>

void display(int xc,int yc,int x,int y){
	putpixel(xc+x,yc+y,BLUE);
	putpixel(xc-x,yc-y,BLUE);
	putpixel(xc+x,yc-y,BLUE);
	putpixel(xc-x,yc+y,BLUE);
}

void main(){
	int x,y,xc,yc,rx,ry,gm,gd=DETECT;
	initgraph(&gd,&gm,"D:\\TCPP3\\BGI");
	clrscr();
	cout<<"Enter coordinates of center and radii: "<<endl;
	cin>>xc>>yc>>rx>>ry;
	xc+=320;
	yc=240-yc;
	clrscr();
	//cleardevice();
	setbkcolor(BLACK);
	setcolor(BLACK);
	line(320,0,320,480);
	line(0,240,640,240);
	x=0;
	y=ry;
	double d1=(ry*ry)-(rx*rx*ry)+(0.25*rx*rx);
	double d2=(ry*ry*(x+0.5)*(x+0.5))+(rx*rx*(y-1)*(y-1))-(rx*rx*ry*ry);
	double dx=2*ry*ry*x;
	double dy=2*rx*rx*y;
	do{
		display(xc,yc,x,y);
		if(d1<0){
			x=x+1;
			dx=dx+2*ry*ry;
			d1=d1+dx+ry*ry;
		}else{
			x=x+1;
			y=y-1;
			dx=dx+2*ry*ry;
			dy=dy+2*rx*rx;
			d1=d1+dx-dy+ry*ry;
		}
	}while(dx<dy);
	do{
		display(xc,yc,x,y);
		if(d2>0){
			x=x;
			y=y-1;
			dx+=2*ry*ry;
			d2=d2-dy+rx*rx;
		}else{
			x=x+1;
			y=y-1;
			dx=dx+2*ry*ry;
			dy=dy-2*rx*rx;
			d2=d2+dx-dy+rx*rx;
		}
	}while(y>0);
	getch();
	closegraph();
}
