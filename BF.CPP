#include <iostream.h>
#include <conio.h>
#include <graphics.h>
#include <stdlib.h>
void boundryfill(int x,int y,int fill,int boundry){
	int current;
	current=getpixel(x,y);
	if(current!=boundry&&current!=fill){
		setcolor(fill);
		putpixel(x,y,fill);
		boundryfill(x+1,y,fill,boundry);
		boundryfill(x-1,y,fill,boundry);
		boundryfill(x,y+1,fill,boundry);
		boundryfill(x,y-1,fill,boundry);
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
	setbkcolor(9);
	//setcolor(EGA_WHITE);
	drawpoly(n+1,coordinates);
	boundryfill(coordinates[0]+1,coordinates[1]+1,6,WHITE);
	getch();
	closegraph();
}