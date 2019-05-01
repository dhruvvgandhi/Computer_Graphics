#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>

void main()
{
 int gd,gm,i,n;
 float t,theta,a[10][2],b[10][2];
 detectgraph(&gd,&gm);
 initgraph(&gd,&gm,"C:\\TC\\BGI");
 printf("enter no of vertices\n");
 scanf("%d",&n);
 printf("enter coordinates\n");
 for(i=0;i<n;i++)
   scanf("%f%f",&a[i][0],&a[i][1]);
 a[n][0]=a[0][0];
 a[n][1]=a[0][1];
 for(i=0;i<n;i++)
  line(a[i][0],a[i][1],a[i+1][0],a[i+1][1]);
 printf("enter angle of rotation\n");
 scanf("%f",&theta);
 t=3.14*(theta/180);
// printf("t=%f\n",t);


 for(i=0;i<n;i++)
 {
  b[i][0]=(a[i][0]*cos(t))-(a[i][1]*sin(t));
  b[i][1]=(a[i][0]*sin(t))+(a[i][1]*cos(t));
  }
  b[n][0]=b[0][0];
  b[n][1]=b[0][1];
  setcolor(GREEN);
 for(i=0;i<n;i++)
   line(b[i][0],b[i][1],b[i+1][0],b[i+1][1]);
 getch();
 closegraph();
 }
