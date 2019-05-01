#include <iostream.h>
#include <conio.h>
#include <graphics.h>
#include <stdlib.h>
void floodfill(int x,int y,int fill,int oldcolor){
	if(getpixel(x,y)==oldcolor){
		setcolor(fill);
		putpixel(x,y,fill);
		floodfill(x+1,y,fill,oldcolor);
		floodfill(x-1,y,fill,oldcolor);
		floodfill(x,y+1,fill,oldcolor);
		floodfill(x,y-1,fill,oldcolor);
	}
}
void main(){
	int n=0,gm,gd=DETECT;
	initgraph(&gd,&gm,"D:\\TCPP3\\BGI");
	clrscr();
	cout<<"Enter no. of vertices: ";
	cin>>n;
	int coordinates[1000];
	cout<<"Enter coordinates:"<<endl;
	for(int i=0;i<2*n;i+=2){
		cout<<"x"<<(i/2)<<": ";
		cin>>coordinates[i];
		cout<<"y"<<(i/2)<<": ";
		cin>>coordinates[i+1];
	}
	coordinates[2*n]=coordinates[0];
	coordinates[2*n+1]=coordinates[1];
	clrscr();
	cleardevice();
	//setbkcolor(9);
	//setcolor(EGA_WHITE);
	drawpoly(n+1,coordinates);
	floodfill(coordinates[0]+1,coordinates[1]+1,BLUE,BLACK);
	getch();
	closegraph();
}