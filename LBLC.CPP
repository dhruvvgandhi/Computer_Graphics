#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>

void main(){
	int gm,gd=DETECT,x1,y1,x2,y2,xwmin,ywmin,xwmax,ywmax;
	float p[4],q[4];
	initgraph(&gd,&gm,"D:\\TCPP3\\BGI");
	cout<<"Enter coordinates of line"<<endl;
	cin>>x1>>y1>>x2>>y2;
	cout<<"Enter coordinates of window"<<endl;
	cin>>xwmin>>ywmin>>xwmax>>ywmax;
	cleardevice();
	setcolor(EGA_BLUE);
	rectangle(xwmin,ywmin,xwmax,ywmax);
	setcolor(EGA_RED);
	line(x1,y1,x2,y2);
	getch();
	cleardevice();
	setcolor(EGA_BLUE);
	rectangle(xwmin,ywmin,xwmax,ywmax);
	setcolor(EGA_GREEN);
	p[0]=x1-x2;
	p[1]=x2-x1;
	p[2]=y1-y2;
	p[3]=y2-y1;
	q[0]=x1-xwmin;
	q[1]=xwmax-x1;
	q[2]=y1-ywmin;
	q[3]=ywmax-y1;
	for(int i=0;i<4;i++){
		if(p[i]==0){
			cout<<"\nLine is parallel to "<<i<<" boundary";
			if(q[i]<0){
				cout<<"\nLine is completely outside.\nDiscarding the Line";
				getch();
				exit(0);
			}else{
				if(i<2){
					if(y1<ywmin)
						y1=ywmin;
					if(y2>ywmax)
						y2=ywmax;
					line(x1,y1,x2,y2);
				}
				if(i>1){
					if(x1<xwmin)
						x1=xwmin;
					if(x2>xwmax)
						x2=xwmax;
					line(x1,y1,x2,y2);
				}
				getch();
				exit(0);
			}
		}
	}
	float t1=0,t2=1;
	for(i=0;i<4;i++){
		float qp= q[i]/p[i];
		if(p[i]<0&&t1<=qp)
			t1=qp;
		if(p[i]>0&&t2>qp)
			t2=qp;
	}
	if(t1<t2){
		int xx1=x1+t1*p[1];
		int xx2=x1+t2*p[1];
		int yy1=y1+t1*p[3];
		int yy2=y1+t2*p[3];
		line(xx1,yy1,xx2,yy2);
	}
	getch();
	closegraph();
}