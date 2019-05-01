#include<dos.h>
#include<graphics.h>
#include<iostream.h>

void main()
{
int gd= DETECT, gm;

initgraph(&gd, &gm, "C:\\TC\\BGI");
int maxx,maxy;
maxx = getmaxx();
maxy= getmaxy();
cout<<"Max x : "<<maxx;
cout<<"   Max y : "<<maxy;

//putpixel(100,200,WHITE);
//int color= getpixel(100,200);
//int color2 = getpixel(200,300);

//cout<<" Color No for white is : "<<color;
//cout<<"   Color for black is : "<<color2;

int i=0;
int p_color;
int startx,starty;
startx=100;
starty=300;

int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
int antdir=0;
while(i<32767)
{
 if(startx==639)
	antdir=0;
 if(startx==0)
	antdir=3;
 if(starty==479)
	antdir=4;
 if(starty==0)
	antdir=2;


 sleep(0.5);
 p_color=getpixel(startx,starty);

 if(p_color==15)
 {
  putpixel(startx,starty,0);
  antdir = (antdir+1)%4;

 }
 else
 {

  putpixel(startx,starty,15);
  antdir = (antdir+3)%4;

 }
 startx = startx + dir[antdir][0];
 starty=starty + dir[antdir][1];





}
}