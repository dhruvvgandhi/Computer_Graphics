#include<dos.h>
#include<math.h>
#include<conio.h>
#include<iostream.h>
#include<graphics.h>
void main()
{
   int xmax,ymax,gd=0,gm,tx,ty,k;
   initgraph(&gd,&gm,"c:\\tc\\bgi");
   xmax=getmaxx();
   ymax=getmaxy();
       line(xmax/2,0,xmax/2,ymax);
       line(0,ymax/2,xmax,ymax/2);
       int a[10][10],b[10][10],c[10][10],d[10][10],temp[10][10],i,j,n;
       cout<<"Enter no of vertices:-";
       cin>>n;
       for(i=0;i<n;i++)
       {
         cout<<"\nEnter co-ordi of "<<i+1<<"point:";
          for(j=0;j<3;j++)
           {
              cin>>a[i][j];
           }
       }
       setcolor(46);
   int ch1,ch2,y=1,sx,sy;
   int m=0,q=0,o=0;
   while(y==1)
   {
       for(i=0;i<n-1;i++)
       {
          line(xmax/2+a[i][0],ymax/2-a[i][1],xmax/2+a[i+1][0],ymax/2-a[i+1][1]);
       }
       line(xmax/2+a[i][0],ymax/2-a[i][1],xmax/2+a[0][0],ymax/2-a[0][1]);
        setcolor(15);
        cout<<"\n1.translation \n2.Rotation abt origin\n3.Rotation abt point\n4.Reflection\n5.Scaling";
        cout<<"\nEnter ur choice:-";
        cin>>ch1;
        switch(ch1)
        {
          case 1:
            b[0][0]=1;b[0][1]=0;b[0][2]=0;
            b[1][0]=0;b[1][1]=1;b[1][2]=0;
            cout<<"\nEnter tx and ty:-";
            cin>>tx>>ty;
            b[2][0]=tx;b[2][1]=ty;b[2][2]=1;
            break;
           case 2:
            cout<<"\n1.90 \t2.180\t3.270\t4.360";
            cout<<"\nEnter ur choice:-";
            cin>>ch2;
              switch(ch2)
              {
               case 1:
                b[0][0]=0;b[0][1]=1;b[0][2]=0;
                b[1][0]=-1;b[1][1]=0;b[1][2]=0;
                b[2][0]=0;b[2][1]=0;b[2][2]=1;
                break;
               case 2:
                b[0][0]=-1;b[0][1]=0;b[0][2]=0;
                b[1][0]=0;b[1][1]=-1;b[1][2]=0;
                b[2][0]=0;b[2][1]=0;b[2][2]=1;
                break;
               case 3:
                b[0][0]=0;b[0][1]=-1;b[0][2]=0;
                b[1][0]=1;b[1][1]=0;b[1][2]=0;
                b[2][0]=0;b[2][1]=0;b[2][2]=1;
                break;
               case 4:
                b[0][0]=1;b[0][1]=0;b[0][2]=0;
                b[1][0]=0;b[1][1]=1;b[1][2]=0;
                b[2][0]=0;b[2][1]=0;b[2][2]=1;
                break;
              }    //end rot switch
          break;
          case 3:
               cout<<"\nEnter the co-ords of the fixed point : ";
               cin>>tx>>ty;
               temp[0][0]=1;temp[0][1]=0;temp[0][2]=0;
               temp[1][0]=0;temp[1][1]=1;temp[1][2]=0;
               temp[2][0]=-tx;temp[2][1]=-ty;temp[2][2]=1;
               cout<<"\n1.90 \t2.180\t3.270\t4.360";
            cout<<"\nEnter ur choice:-";
            cin>>ch2;
              switch(ch2)
              {
               case 1:
                b[0][0]=0;b[0][1]=1;b[0][2]=0;
                b[1][0]=-1;b[1][1]=0;b[1][2]=0;
                b[2][0]=0;b[2][1]=0;b[2][2]=1;
                break;
               case 2:
                b[0][0]=-1;b[0][1]=0;b[0][2]=0;
                b[1][0]=0;b[1][1]=-1;b[1][2]=0;
                b[2][0]=0;b[2][1]=0;b[2][2]=1;
                break;
               case 3:
                b[0][0]=0;b[0][1]=-1;b[0][2]=0;
                b[1][0]=1;b[1][1]=0;b[1][2]=0;
                b[2][0]=0;b[2][1]=0;b[2][2]=1;
                break;
               case 4:
                b[0][0]=1;b[0][1]=0;b[0][2]=0;
                b[1][0]=0;b[1][1]=1;b[1][2]=0;
                b[2][0]=0;b[2][1]=0;b[2][2]=1;
                break;
              }
              for(m = 0;m<3;m++)
		    for(q = 0;q<3;q++)
			  for(o = 0;o<3;o++)
				d[m][q] = d[m][q] + (temp[m][o]*b[o][q]);
	      temp[2][0]=-tx;temp[2][1]=-ty;
	      for(m = 0;m<3;m++)
		    for(q = 0;q<3;q++)
			  b[m][q] = 0;
	      for(m = 0;m<3;m++)
		    for(q = 0;q<3;n++)
			  for(o = 0;o<3;o++)
				b[m][q] = b[m][q] + (d[m][o]*temp[o][q]);
	  break;
          case 4:
            cout<<"\n1.Ref thru x axis \n2.Ref thru y axis\n3.Ref thru x=y axis\n4.Ref thru x=-y axis";
            cout<<"\nEnter ur choice:-";
            cin>>ch2;
              switch(ch2)
              {
               case 1:
                b[0][0]=1;b[0][1]=0;b[0][2]=0;
                b[1][0]=0;b[1][1]=-1;b[1][2]=0;
                b[2][0]=0;b[2][1]=0;b[2][2]=1;
                break;
               case 2:
                b[0][0]=-1;b[0][1]=0;b[0][2]=0;
                b[1][0]=0;b[1][1]=1;b[1][2]=0;
                b[2][0]=0;b[2][1]=0;b[2][2]=1;
                break;
               case 3:
                b[0][0]=0;b[0][1]=1;b[0][2]=0;
                b[1][0]=1;b[1][1]=0;b[1][2]=0;
                b[2][0]=0;b[2][1]=0;b[2][2]=1;
                break;
               case 4:
                b[0][0]=0;b[0][1]=-1;b[0][2]=0;
                b[1][0]=-1;b[1][1]=0;b[1][2]=0;
                b[2][0]=0;b[2][1]=0;b[2][2]=1;
                break;
              }    //end ref switch
          break;
          case 5:
            cout<<"\nEnter scaling factors sx and sy:-";
            cin>>sx>>sy;
                b[0][0]=sx;b[0][1]=0;b[0][2]=0;
                b[1][0]=0;b[1][1]=sy;b[1][2]=0;
                b[2][0]=0;b[2][1]=0;b[2][2]=1;
          break;
          default:
          cout<<"\nEnter correct choice:-";
          continue;
     }//end switch
     for(i=0;i<n;i++)
     {
       for(j=0;j<3;j++)
     {
        c[i][j]=0;
        for(k=0;k<3;k++)
         {
           c[i][j]=c[i][j]+a[i][k]*b[k][j];
         }
     }
     }
       setcolor(4);
       for(i=0;i<n-1;i++)
       {
          line(xmax/2+c[i][0],ymax/2-c[i][1],xmax/2+c[i+1][0],ymax/2-c[i+1][1]);
       }
       line(xmax/2+c[i][0],ymax/2-c[i][1],xmax/2+c[0][0],ymax/2-c[0][1]);
       cout<< "do u want to continue(1=yes/0=no):-";
       cin>>y;
       cleardevice();
       clrscr();
       setcolor(15);
       line(xmax/2,0,xmax/2,ymax);
       line(0,ymax/2,xmax,ymax/2);
   }//end while
   getch();
}
