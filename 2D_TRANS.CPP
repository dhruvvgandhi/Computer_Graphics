/*IMPLEMENTATION OF 2D TRANSFORMATION
  ROLL NO : 32 C12  */
#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<stdio.h>
#include<math.h>
void main()
{
	clrscr();
	int gd=DETECT, gm;
	detectgraph(&gd,&gm);
	initgraph(&gd,&gm,"c:\\TC\\bgi");
	int a[10];
	int b[10];
	cout<<"Enter cordinates of 4-sided polygon\n";
	for(int i=0;i<8;i++)
	{
		cin>>a[i];
		b[i]=a[i];
		if(i%2==0)
			a[i]=a[i]+320;
		else
			a[i]=240-a[i];
	}
	a[8]=a[0];
	a[9]=a[1];
	drawpoly(5,a);
	line(320,0,320,480);
	line(0,240,640,240);
	int n=0;
	do
	{
		cout<<"-----Menu-----\n1. Translation\n2. Rotation\n3. Scaling\n4. Reflection\n5. Shear\n6. Exit\n";
		cout<<"Enter choice\n";
		cin>>n;
		if(n==1)
		{
			int tx,ty;
			int ans[4][3]={0,0,0,0,0,0,0,0,0,0,0,0};
			cout<<"Enter tx and ty\n";
			cin>>tx>>ty;
			int cord[4][3]={b[0],b[1],1,b[2],b[3],1,b[4],b[5],1,b[6],b[7],1};
			int t[3][3]={1,0,0,0,1,0,tx,ty,1};
			for(int i=0;i<4;i++)
			{
				for(int j=0;j<3;j++)
				{
					for(int k=0;k<3;k++)
					{
					ans[i][j]=ans[i][j]+cord[i][k]*t[k][j];
					}
				}
			}
			for(i=0;i<4;i++)
			{
				ans[i][0]=ans[i][0]+320;
				ans[i][1]=240-ans[i][1];
			}
			int poly[10];
			int z=0;
			for(i=0;i<4;i++)
			{
				for(int j=0;j<2;j++)
				{
				poly[z]=ans[i][j];
				z++;
				}
			}
			poly[8]=ans[0][0];
			poly[9]=ans[0][1];
			drawpoly(5,poly);
		}
		if(n==2)
		{       float ang;
			cout<<"Enter angle";
			cin>>ang;
			ang=ang*3.14/180;
			int cord[4][3]={b[0],b[1],1,b[2],b[3],1,b[4],b[5],1,b[6],b[7],1};
			float r[3][3]={cos(ang),sin(ang),0,-sin(ang),cos(ang),0,0,0,1};
			int ans[4][3]={0,0,0,0,0,0,0,0,0,0,0,0};
			for(int i=0;i<4;i++)
			{
				for(int j=0;j<3;j++)
				{
					for(int k=0;k<3;k++)
					{
					ans[i][j]=ans[i][j]+cord[i][k]*r[k][j];

					}
				}
			}
			for(i=0;i<4;i++)
			{
				ans[i][0]=ans[i][0]+320;
				ans[i][1]=240-ans[i][1];
			}
			int poly[10];
			int z=0;
			for(i=0;i<4;i++)
			{
				for(int j=0;j<2;j++)
				{
				poly[z]=ans[i][j];
				z++;
				}
			}
			poly[8]=ans[0][0];
			poly[9]=ans[0][1];
			drawpoly(5,poly);
		}
		if(n==3)
		{
			float sx,sy;
			cout<<"Enter sx and sy\n";
			cin>>sx>>sy;
			int s[3][3]={sx,0,0,0,sy,0,0,0,1};
			int cord[4][3]={b[0],b[1],1,b[2],b[3],1,b[4],b[5],1,b[6],b[7],1};
			int ans[4][3]={0,0,0,0,0,0,0,0,0,0,0,0};
			for(int i=0;i<4;i++)
			{
				for(int j=0;j<3;j++)
				{
					for(int k=0;k<3;k++)
					{
					ans[i][j]=ans[i][j]+cord[i][k]*s[k][j];

					}
				}
			}
			for(i=0;i<4;i++)
			{
				ans[i][0]=ans[i][0]+320;
				ans[i][1]=240-ans[i][1];
			}
			int poly[10];
			int z=0;
			for(i=0;i<4;i++)
			{
				for(int j=0;j<2;j++)
				{
				poly[z]=ans[i][j];
				z++;
				}
			}
			poly[8]=ans[0][0];
			poly[9]=ans[0][1];
			drawpoly(5,poly);
		}
		if(n==4)
		{
			int r[3][3]={-1,0,0,0,-1,0,0,0,1};
			int cord[4][3]={b[0],b[1],1,b[2],b[3],1,b[4],b[5],1,b[6],b[7],1};
			int ans[4][3]={0,0,0,0,0,0,0,0,0,0,0,0};
			for(int i=0;i<4;i++)
			{
				for(int j=0;j<3;j++)
				{
					for(int k=0;k<3;k++)
					{
					ans[i][j]=ans[i][j]+cord[i][k]*r[k][j];

					}
				}
			}
			for(i=0;i<4;i++)
			{
				ans[i][0]=ans[i][0]+320;
				ans[i][1]=240-ans[i][1];
			}
			int poly[10];
			int z=0;
			for(i=0;i<4;i++)
			{
				for(int j=0;j<2;j++)
				{
				poly[z]=ans[i][j];
				z++;
				}
			}
			poly[8]=ans[0][0];
			poly[9]=ans[0][1];
			drawpoly(5,poly);
		}
		if(n==5)
		{       int n2;
			cout<<"1. X-shear\n2. Y-shear\n";
			cin>>n2;
			int cord[4][3]={b[0],b[1],1,b[2],b[3],1,b[4],b[5],1,b[6],b[7],1};
			int ans[4][3]={0,0,0,0,0,0,0,0,0,0,0,0};
			if(n2==1)
			{       int x;
				cout<<"Enter x";
				cin>>x;
				int x_shr[3][3]={1,0,0,x,1,0,0,0,1};
			for(int i=0;i<4;i++)
			{
				for(int j=0;j<3;j++)
				{
					for(int k=0;k<3;k++)
					{
					ans[i][j]=ans[i][j]+cord[i][k]*x_shr[k][j];
					}
				}
			}
			}
			if(n2==2)
			{
				int y;
				cout<<"Enter y";
				cin>>y;
				int y_shr[3][3]={1,y,0,0,1,0,0,0,1};
			for(int i=0;i<4;i++)
			{
				for(int j=0;j<3;j++)
				{
					for(int k=0;k<3;k++)
					{
					ans[i][j]=ans[i][j]+cord[i][k]*y_shr[k][j];
					}
				}
			}
			}
				for(i=0;i<4;i++)
			{
				ans[i][0]=ans[i][0]+320;
				ans[i][1]=240-ans[i][1];
			}
			int poly[10];
			int z=0;
			for(i=0;i<4;i++)
			{
				for(int j=0;j<2;j++)
				{
				poly[z]=ans[i][j];
				z++;
				}
			}
			poly[8]=ans[0][0];
			poly[9]=ans[0][1];
			drawpoly(5,poly);
		  }

	}while(n!=6);
	getch();
}