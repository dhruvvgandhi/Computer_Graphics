#include <iostream.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>
#include <stdlib.h>

class transform{
	private:
		int n;
		float initmat[1000][2],finalmat[1000][2],transmat[2][2];
	public:
		void init(){
			clrscr();
			cleardevice();
			setbkcolor(EGA_BLACK);
			setcolor(EGA_WHITE);
			line(320,0,320,480);
			line(0,240,640,240);
		}
		void input();
		void matmulti();
		void plot(char x);
		void clear();
		void scale();
		void translate();
		void rotate();
		void reflect();
		void shear();

};
void transform::clear(){
	for(int i=0;i<1000;i++)
		for(int j=0;j<2;j++){
			initmat[i][j]=0;
			finalmat[i][j]=0;
		}
	transmat[0][0]=0;
	transmat[0][1]=0;
	transmat[1][0]=0;
	transmat[1][1]=0;
}
void transform::input(){
	int choice=6;
	init();
	cout<<"Enter no. of edges: ";
	cin>>n;
	cout<<"Enter coordinates:"<<endl;
	for(int i=0;i<n;i++){
		cout<<"x"<<i<<": ";
		cin>>initmat[i][0];
		cout<<"y"<<i<<": ";
		cin>>initmat[i][1];
	}
loop:
	init();
	plot('i');
	cout<<"1.Translate"<<endl
	    <<"2.Scale"<<endl
	    <<"3.Rotate"<<endl
	    <<"4.Reflect"<<endl
	    <<"5.Shear"<<endl
	    <<"6.Exit"<<endl
	    <<"Choice: ";
	cin>>choice;
	switch(choice){
		case 1:
			translate();
			break;
		case 2:
			scale();
			break;
		case 3:
			rotate();
			break;
		case 4:
			reflect();
			break;
		case 5:
			shear();
			break;
		case 6:
			exit(0);
		default:
			cout<<"Enter valid choice!";
			getch();
			goto loop;
	}
	cout<<"Press any key!";
	getch();
	goto loop;

}
void transform::matmulti(){
	for(int i=0;i<n;i++){
		for(int j=0;j<2;j++){
			finalmat[i][j]=0;
			for(int k=0;k<2;k++){
				finalmat[i][j]+=initmat[i][k]*transmat[k][j];
			}
		}
	}
}
void transform::plot(char x){
	if(x=='f'){
		setcolor(EGA_RED);
		for(int i=0;i<n-1;i++)
			line((int)finalmat[i][0]+320,240-(int)finalmat[i][1],(int)finalmat[i+1][0]+320,240-(int)finalmat[i+1][1]);
		line((int)finalmat[i][0]+320,240-(int)finalmat[i][1],(int)finalmat[0][0]+320,240-(int)finalmat[0][1]);
	}else{
		setcolor(EGA_BLUE);
		for(int i=0;i<n-1;i++)
			line((int)initmat[i][0]+320,240-(int)initmat[i][1],(int)initmat[i+1][0]+320,240-(int)initmat[i+1][1]);
		line((int)initmat[i][0]+320,240-(int)initmat[i][1],(int)initmat[0][0]+320,240-(int)initmat[0][1]);
	}
}
void transform::scale(){
	int sx=0,sy=0;
	cout<<"Enter x-scaling factor: ";
	cin>>sx;
	cout<<"Enter y-scaling factor: ";
	cin>>sy;
	transmat[0][0]=sx;
	transmat[0][1]=transmat[1][0]=0;
	transmat[1][1]=sy;
	matmulti();
	plot('f');
}
void transform::translate(){
	int tx=0,ty=0;
	cout<<"Enter x-translation factor: ";
	cin>>tx;
	cout<<"Enter y-translation factor: ";
	cin>>ty;
	for(int i=0;i<n;i++){
		finalmat[i][0]=initmat[i][0]+tx;
		finalmat[i][1]=initmat[i][1]+ty;
	}
	plot('f');
}
void transform::rotate(){
	float angle;
	cout<<"Enter rotation angle: ";
	cin>>angle;
	angle=(3.1412*angle)/180;
	transmat[0][0]=transmat[1][1]=cos(angle);
	transmat[0][1]=sin(angle);
	transmat[1][0]=-sin(angle);
	matmulti();
	plot('f');
}
void transform::reflect(){
	int choice;
startr:
	init();
	plot('i');
	cout<<"1.About X-Axis"<<endl
	    <<"2.About Y-Axis"<<endl
	    <<"3.About Origin"<<endl
	    <<"4.About X=Y"<<endl
	    <<"5.About X=-Y"<<endl
	    <<"6.Exit"<<endl
	    <<"Choice: ";
	cin>>choice;
	switch(choice){
		case 1:
			transmat[0][0]=1;
			transmat[0][1]=transmat[1][0]=0;
			transmat[1][1]=-1;
			break;
		case 2:
			transmat[0][0]=-1;
			transmat[0][1]=transmat[1][0]=0;
			transmat[1][1]=1;
			break;
		case 3:
			transmat[0][0]=-1;
			transmat[0][1]=transmat[1][0]=0;
			transmat[1][1]=-1;
			break;
		case 4:
			transmat[0][0]=transmat[1][1]=0;
			transmat[0][1]=transmat[1][0]=1;
			break;
		case 5:
			transmat[0][0]=transmat[1][1]=0;
			transmat[0][1]=transmat[1][0]=-1;
			break;
		case 6:
			return;
		default:
			cout<<"Enter valid choice!";
			getch();
			goto startr;
	}
	matmulti();
	plot('f');
	cout<<"Press any key!";
	getch();
	goto startr;
}
void transform::shear(){
	int choice,s;
starts:
	init();
	plot('i');
	cout<<"1.X Shear"<<endl
	    <<"2.Y Shear"<<endl
	    <<"3.Exit"<<endl
	    <<"Choice: ";
	cin>>choice;
	switch(choice){
		case 1:
			cout<<"Enter shear factor: ";
			cin>>s;
			transmat[1][1]=transmat[0][0]=1;
			transmat[0][1]=0;
			transmat[1][0]=s;
			break;
		case 2:
			cout<<"Enter shear factor: ";
			cin>>s;
			transmat[1][1]=transmat[0][0]=1;
			transmat[0][1]=s;
			transmat[1][0]=0;
			break;
		case 3:
			return;
		default:
			cout<<"Enter valid choice!";
			getch();
			goto starts;
	}
	matmulti();
	plot('f');
	cout<<"Press any key!";
	getch();
	goto starts;
}

void main(){
	int gm,gd=DETECT;
	initgraph(&gd,&gm,"D:\\tcpp3\\bgi");
	transform t;
	t.input();
	getch();
	closegraph();
}