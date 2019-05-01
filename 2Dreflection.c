#include<stdio.h>
#include<conio.h>
#include<graphics.h>

void main()
{
  int gd,gm;
  int a[10][2],b[10][2],n,i;
  detectgraph(&gd,&gm);
  initgraph(&gd,&gm,"C:\\TC\\BGI");
  printf("enter no of vertices\n");
  scanf("%d",&n);
  printf("enter coordinates\n");
  for(i=0;i<n;i++)
   scanf("%d %d",&a[i][0],&a[i][1]);
  a[n][0]=a[0][0];
  a[n][1]=a[0][1];
  line(320,0,320,480);
  line(0,240,640,240);
  for(i=0;i<n;i++)
  line(a[i][0]+320,a[i][1]+240,a[i+1][0]+320,a[i+1][1]+240);
  for(i=0;i<=n;i++)
  {
    b[i][0]=a[i][0];
    b[i][1]=-a[i][1];
  }
  for(i=0;i<n;i++)
  line(b[i][0]+320,b[i][1]+240,b[i+1][0]+320,b[i+1][1]+240);

  for(i=0;i<=n;i++)
  {
    b[i][0]=-a[i][0];
    b[i][1]=a[i][1];
  }
  for(i=0;i<n;i++)
  line(b[i][0]+320,b[i][1]+240,b[i+1][0]+320,b[i+1][1]+240);

  getch();
  closegraph();
  }
