#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
void main()
{
	clrscr();
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"c:\\TC\\bgi");
	setfillstyle(1,YELLOW);
	fillellipse(320,330,50,50);
	int a[12];
	a[0]=100;a[1]=400;a[2]=200;a[3]=200;a[4]=320;a[5]=350;
	a[6]=450;a[7]=200;a[8]=550;a[9]=400;
	a[10]=a[0];
	a[11]=a[1];
	setfillstyle(1,BROWN);
	fillpoly(6,a);
	getch();
	int y=330;
	for(int i=0;i<100;i++)
	{
                setcolor(CYAN);
		setbkcolor(BLACK);
		delay(10);
		setfillstyle(1,BLACK);
		bar(0,0,640,480);
		setfillstyle(1,YELLOW);
		fillellipse(320,y,50,50);
		y=y-2;
		setfillstyle(1,BROWN);
		fillpoly(6,a);
	}getch();
}