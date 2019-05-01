#include<iostream.h>
#include<conio.h>
#include<graphics.h>
void left(int n,int coordinates[])
{
}
void main(){
	int gd=DETECT,gm,n;
	initgraph(&gd,&gm,"D:\\TCPP3\\BGI");
	clrscr();
	cout<<"Enter no. of vertices: ";
	cin>>n;
	int coordinates[1000],ccoordinates[1000];
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
	cout<<"Enter coordinates of window"<<endl;
	cin>>xwmin>>ywmin>>xwmax>>ywmax;
	setcolor(EGA_BLUE);
	rectangle(xwmin,ywmin,xwmax,ywmax);
	getch();
	int cc[2][4];
	for(i=0;i<4;i++){
		switch(i){
			case 0:
				cc[0][0]=xwmin;
				cc[0][1]=ywmin;
				cc[0][2]=xwmin;
				cc[0][3]=ywmax;
				break;
			case 1:
				cc[0][0]=xwmax;
				cc[0][1]=ywmin;
				cc[0][2]=xwmax;
				cc[0][3]=ywmax;
				break;
			case 2:
				cc[0][0]=xwmin;
				cc[0][1]=ywmin;
				cc[0][2]=xwmax;
				cc[0][3]=ywmin;
				break;
			case 3:
				cc[0][0]=xwmin;
				cc[0][1]=ywmax;
				cc[0][2]=xwman;
				cc[0][3]=ywmax;
				break;
		}
		for(int j=0,k=0;j<2*n;j+=2){
			if(coordinates[i]<xwmin&&coordinates[i+2]<xwmin)
				continue;
			if(coordinates[i]<xwmin&&coordinates[i+2]>xwmin){
				int x=xwmin;
				int y=((x-coordinates[i])*(coordinates[i+3]-coordinates[i+1])/(coordinates[i+2]-coordinates[i]))+coordinates[i+1];
				ccoordinates[k++]=x;
				ccoordinates[k++]=y;
				ccoordinates[k++]=coordinates[i];
				ccoordinates[k++]=coordinates[i+1];
			}
			if(coordinates[i]>xwmin&&coordinates[i+2]<xwmin){
				int x=xwmin;
				int y=((x-coordinates[i])*(coordinates[i+3]-coordinates[i+1])/(coordinates[i+2]-coordinates[i]))+coordinates[i+1];
				ccoordinates[k++]=x;
				ccoordinates[k++]=y;
			}
			if(coordinates[i]>xwmin&&coordinates[i+2]>xwmin){
				ccoordinates[k++]=coordinates[i];
				ccoordinates[k++]=coordinates[i+1];
				ccoordinates[k++]=coordinates[i+2];
				ccoordinates[k++]=coordinates[i+3];
			}
		}
	}
}