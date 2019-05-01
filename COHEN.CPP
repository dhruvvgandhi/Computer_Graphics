#include<iostream.h>
#include<conio.h>
#include<dos.h>
#include<graphics.h>
 
typedef struct co
{
	int x,y;
	char code[4];
}PT;
 
void window()
{
	line(150,100,450,100);
	line(450,100,450,350);
	line(450,350,150,350);
	line(150,350,150,100);
}
void drawline(PT p1,PT p2,int c)
{
	setcolor(c);
	line(p1.x,p1.y,p2.x,p2.y);
}
 
PT setcode(PT p)
{
	PT temp;
	if(p.y<100)
	temp.code[0]='1';
	else
	temp.code[0]='0';
	if(p.y>350)
	temp.code[1]='1';
	else
	temp.code[1]='0';
	if(p.x>450)
	temp.code[2]='1';
	else
	temp.code[2]='0';
	if(p.x<150)
	temp.code[3]='1';
	else
	temp.code[3]='0';
 
	temp.x=p.x;
	temp.y=p.y;
	return(temp);
}
 
int visibility(PT p1,PT p2)
{
	int i,flag=0;
	for(i=0;i<4;i++)
	{
		if((p1.code[i]!='0') || (p2.code[i]!='0'))
		{flag=1;}
	}
	if(flag==0)
	return(0);
	for(i=0;i<4;i++)
	{
		if((p1.code[i]==p2.code[i]) && (p1.code[i]=='1'))
		flag=0;
	}
	if(flag==0)
	return(1);
	return(2);
}
 
PT resetendpt(PT p1,PT p2)
{
	PT temp;
	int x,y,i;
	float m,k;
	if(p1.code[3]=='1')
	x=150;
	if(p1.code[2]=='1')
	x=450;
 
	if((p1.code[3]=='1') || (p1.code[2]=='1'))
	{
		m=(float)(p2.y-p1.y)/(p2.x-p1.x);
		k=(p1.y+(m*(x-p1.x)));
		temp.y=k;
		temp.x=x;
		if((temp.x<150 || temp.x>450) && (temp.y<100 || temp.y>350))
		temp.x=temp.y=0;
 
		for(i=0;i<4;i++)
		temp.code[i]=p1.code[i];
		return (temp);
	}
	if(p1.code[1]=='1')
	y=350;
	if(p1.code[0]=='1')
	y=100;
 
	if((p1.code[1]=='1') || (p1.code[0]=='1'))
	{
		m=(float)(p2.y-p1.y)/(p2.x-p1.x);
		k=(float)p1.x+(float)(y-p1.y)/m;
		temp.x=k;
		temp.y=y;
 
		if((temp.y<100 || temp.y>350) && (temp.x<150 || temp.x>450))
		temp.x=temp.y=0;
 
		for(i=0;i<4;i++)
		return(temp);
	}
	return(p1);
}
int main()
{
	int gd=DETECT,gm,v;
	PT p1,p2;
	initgraph(&gd,&gm,"C:\\TC\\BGI");
	cleardevice();
	cout<<"point1"<<endl;
	cin>>p1.x>>p1.y;
	cout<<"point2"<<endl;
	cin>>p2.x>>p2.y;
	window();
	getch();
	drawline(p1,p2,15);
	getch();
	p1=setcode(p1);
	p2=setcode(p2);
	v=visibility(p1,p2);
	switch(v)
	{
	case 0: cleardevice();
		window();
		drawline(p1,p2,15);
		break;
	case 1:cleardevice();
		window();
		break;
	case 2:cleardevice();
		p1=resetendpt(p1,p2);
		p2=resetendpt(p2,p1);
		window();
		drawline(p1,p2,15);
		break;
	}
	getch();
	closegraph();
	return(0);
}