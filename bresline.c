#include<stdio.h>

#include<conio.h>

#include<graphics.h>

#include<math.h>

void main()

{

    int gd=DETECT, gm;

    int x, y, x1, x2, y1, y2, dx, dy, p,a,b;

    clrscr();

    initgraph(&gd, &gm, "C:/TC/BGI");

    printf("Enter coordinates:\nx1 y1 :");

    scanf("%d %d",&x1, &y1);

    printf("\nx2 y2 :");

    scanf("%d %d",&x2, &y2);

    dx= abs(x2-x1);

    dy= abs(y2-y1);

    x = x1;

    y = y1;

    putpixel(x,y,WHITE);

    a=dx/(abs(dx));

    b=dy/(abs(dy));

    while(x!=x2&&y!=y2)

    {

    if(abs(dx)>=abs(dy))

    {

	p=2*abs(dy)-abs(dx);

	if(p<0)

	{

	     p=p+2*abs(dy);

	     x=x+a;

	}

	else

	{

	     p=p+2*abs(dy)-2*abs(dx);

	     x=x+a;

	     y=y+b;

	}


    }

    else

    {   p=p+2*abs(dx)-abs(dy);

	if(p<0)

	{

	    p=p+2*abs(dx);

	    y=y+b;

	}

	else

	{

	    p=p+2*abs(dx)-2*abs(dy);

	    x=x+a;

	    y=y+b;

	}

    }

    putpixel(x,y,WHITE);

    }

    getch();

closegraph();


}
