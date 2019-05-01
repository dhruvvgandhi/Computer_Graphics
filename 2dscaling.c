#include <stdio.h>
#include <graphics.h>
#include <conio.h>
void main()
{
   int gd, gm, n, i;
   float x[10], y[10];
   float tx, ty;
   clrscr();
   detectgraph(&gd, &gm);
   initgraph(&gd, &gm, "c:\\tc\\BGI");
   printf("Enter the number of co-ordinates\n");
   scanf("%d", &n);
   printf("Enter the co-ordinates\n");
   for(i=0; i < n; i++)
	scanf("%f%f", &x[i], &y[i]);

   printf("Enter translation vector\n");
   scanf("%f%f", &tx, &ty);

   for(i=0; i < n-1; i++)
	line(x[i], y[i], x[i+1], y[i+1]);

   line(x[n-1], y[n-1], x[0], y[0]);

   for(i=0; i < n; i++){
	x[i] *= tx;
	y[i] *= ty;
   }

   for(i=0; i < n-1; i++)
	line(x[i], y[i], x[i+1], y[i+1]);

   line(x[n-1], y[n-1], x[0], y[0]);
   getch();
}
