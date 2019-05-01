#include <graphics.h>

#include <stdio.h>

#include <conio.h>





void main()

{

    int gd, gm, i ,j;

    float u, cx, cy;

    float x[4];

    float y[4];

    clrscr();

    detectgraph(&gd, &gm);

    initgraph(&gd, &gm, "c:\\tc\\BGI");

    

    printf("Enter the co-ordinates");

    

    for(i=0; i < 4; i++){

        scanf("%f%f", &x[i], &y[i]);

        putpixel(x[i], y[i], YELLOW);

    }

    

    for(u=0; u < 1.0; u += 0.0005){

        cx = (x[0] * (1-u) * (1-u) * (1-u)) + (3  * x[1] * u * (1-u) * (1-u) )

        + (3 * x[2] * u * u * (1-u)) + (x[3] * u * u * u);

        

        cy = (y[0] * (1-u) * (1-u) * (1-u)) + (3  * y[1] * u * (1-u) * (1-u) )

        + (3 * y[2] * u * u * (1-u)) + (y[3] * u * u * u);

        

        putpixel(cx, cy, 255);

    }



    getch();

}
