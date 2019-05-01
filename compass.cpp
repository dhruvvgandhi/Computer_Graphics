#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<graphics.h>
#include<dos.h>
#include<math.h>
void circ_bre(int x,int y,int rad);
void display(int,int,int,int);
void bresenham(int x1,int y1,int x2, int y2);
int sign (float arg);

void main()
{
	int gd = DETECT, gm, x,y,r;
	initgraph(&gd,&gm,"c:\\tc\\bgi");
	cleardevice();
	circ_bre(200,200,100);
	bresenham(200,100,200,300);
	bresenham(100,200,300,200);
	bresenham(200,130,180,180);
	bresenham(200,130,220,180);
	bresenham(100,200,180,180);
	bresenham(100,200,180,220);
	bresenham(200,270,180,220);
	bresenham(200,270,220,220);
	bresenham(300,200,220,180);
	bresenham(300,200,220,220);
	/*Use of inbuilt function ellipse(x,y,stangle,endangle,xrad,yrad) :
	This function draws an elliptical arc.Here (x,y) are the co-ordinates of center of the ellipse.(stangle,endangle) 
	are the starting and ending angles.If stangle=0 and endangle=360 then this function draws complete ellipse.
	e.g.ellipse(100,150,0,360,100,50); */

	ellipse(200,112,0,180,50,25);
	ellipse(200,288,180,360,50,25);
	ellipse(112,200,90,270,25,50);
	ellipse(288,200,270,90,25,50);

	getch();
	closegraph();
}
void circ_bre(int x,int y,int rad)
{
	float dp;	    //initialising the descision parameter.
	int x1,y1;
	x1 = 0;       	   //initialisng the X,Y cordinates.
	y1 = rad;
	dp = 3 - 2*rad;
	while(x1<=y1)
	{
		if(dp<=0)
			dp += (4 * x1) + 6;
		else
		{
			dp += 4*(x1-y1)+10;
			y1--;
		}
		x1++;
		display(x1,y1,x,y);
	}
}
void display (int x1,int y1,int x,int y)
{
	putpixel(x1+x,y1+y,WHITE);	//plotting the pixels.
	putpixel(x1+x,y-y1,WHITE);
	putpixel(x-x1,y1+y,WHITE);
	putpixel(x-x1,y-y1,WHITE);
	putpixel(x+y1,y+x1,WHITE);
	putpixel(x+y1,y-x1,WHITE);
	putpixel(x-y1,y+x1,WHITE);
	putpixel(x-y1,y-x1,WHITE);
}
void bresenham(int x1,int y1,int x2,int y2)
{
	int s1,s2,exchange,y,x,i;
	float dx,dy,g,temp;
	dx = abs(x2 - x1);
	dy = abs(y2 - y1);
	x = x1;
	y = y1;
	s1 = sign(x2-x1);
	s2 = sign(y2-y1);	/* interchange dx & dy depending on the slope of 																								the line */
	if(dy>dx)
	{
		temp = dx;
		dx = dy;
		dy = temp;
		exchange  = 1;
	}
	else
		exchange = 0;
	g = 2 * dy - dx;
	i = 1;
	while(i<=dx)
	{
		putpixel(x,y,WHITE);
		delay(10);
		while(g>=0)
		{
			if(exchange ==1)
				x = x + s1;
			else
				y = y + s2;
			g = g - 2 * dx;
		}
		if(exchange==1)
			y = y + s2;
		else
			x = x + s1;
		g = g + 2 * dy;
		i++;
	}
}
int sign(float arg)
	{
	if (arg<0)
		return -1;
		else if(arg==0)
			return 0;
				 else return 1;
	}

