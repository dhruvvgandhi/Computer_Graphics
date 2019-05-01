#include<stdio.h>
#include<conio.h>
#include<graphics.h>

void main()
{
// this is midpoint circle generation algorithm implemented on turbo C.
int gm,gd,x0,y0,r,xi,yi,pk;
 detectgraph(&gd,&gm);
 initgraph(&gd,&gm,"C://TC//BGI");

// printf("enter \n");
 scanf("%d%d%d",&x0,&y0,&r);
 putpixel(x0,y0,WHITE);
 pk=1-r;
// printf("%d",pk);
 xi=x0;
 yi=r;
 while(xi<=yi)
 {
 if(pk<0)
 {
 pk=pk + 2*xi + 3;
   xi=xi+1;

   yi=yi;

  // printf("\t%d\t%d\t%d\n",xi,yi,pk);
 }
 else
 {
 pk=pk+2*(xi-yi)+5;
   xi=xi+ 1;
   yi=yi-1;


  // printf("\t%d\t%d\t%d\n",xi,yi,pk);
 }
 delay(100);
 putpixel(xi,yi,WHITE);
 putpixel(yi,xi,WHITE);
 putpixel(yi,-xi,WHITE);
 putpixel(-xi,yi,WHITE);
 putpixel(-xi,-yi,WHITE);
 putpixel(-yi,-xi,WHITE);
 putpixel(-yi,xi,WHITE);
 putpixel(xi,-yi,WHITE);
 }
 getch();
 }
