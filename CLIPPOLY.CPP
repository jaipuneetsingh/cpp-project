#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
void dda(int,int,int,int,int,int,int,int);
void dda(int x1,int y1,int x2,int y2,int xmin,int ymin,int xmax,int ymax)
{
	    float dx,dy;
	    float steps,x=x1,y=y1;
	    int i=0;
	    dx=x2-x1;
	    dy=y2-y1;
	    if(abs(dx)>=abs(dy))
			steps=abs(dx);
	    else
			steps=abs(dy);
	    dx=dx/steps;
	    dy=dy/steps;
	    while(i++<=steps)
	    {
	    if(x>=xmin && x<=xmax && y>=ymin && y<=ymax)
	    {
			line(x,y,x2,y2);
			return;
	    }
			x=x+dx;
			y=y+dy;
	    }
}
void main()
{
	    int n,gd,gm,x1,x2,y1,y2,xRec,yRec,b1,b2,b3,b4,l,b,yMin,yMax,xMin,xMax;
	    float m;
	    int a[10][4],i,j, flag=0;
	    gd=DETECT;
	    gm=DETECT;
	    initgraph(&gm,&gd,"C:\\TC\\BGI");

	    cout<<"Enter the length and breadth of the clipping window:\n";
	    cin>>l>>b;

	    cout<<"Enter the starting co-ord of the rectangle\n";
	    cin>>xRec>>yRec;
	    clearviewport();

	    rectangle(xRec,yRec,xRec+l,yRec+b);
	    getch();
	    clearviewport();


	    cout<<"Enter the no of lines\n";
	    cin>>n;

	    for(i=0;i<n;i++)
	    {
			cout<<"Enter the co-ord of line \n"<<i+1;
			for(j=0;j<2;j++)
			{
				    cin>>a[i][j];
			}
			a[i][2]=a[0][0];
			a[i][3]=a[0][1];
			if(i!=0)
			{
			       a[i-1][2]=a[i][0];
			       a[i-1][3]=a[i][1];
			}
	    }
	    clearviewport();
	    rectangle(xRec,yRec,xRec+l,yRec+b);
	    for(i=0;i<n;i++)
	    {
			line(a[i][0],a[i][1],a[i][2],a[i][3]);
	    }
	    getch();
	    clearviewport();
	    rectangle(xRec,yRec,xRec+l,yRec+b);

	    xMin=xRec;
	    yMin=yRec;
	    xMax=xRec+l;
	    yMax=yRec+b;

	    for(i=0;i<n;i++)
	    {
			flag=0;
			x1=a[i][0];
			x2=a[i][2];
			y1=a[i][1];
			y2=a[i][3];

			if(x1>=xMin && x1<=xMax && y1>=yMin && y1<=yMax)
				    flag++;
			if(x2>=xMin && x2<=xMax && y2>=yMin && y2<=yMax)
				    flag++;


			switch(flag)
			{
				    case 0:
						break;

case 1:
if(x2>=xMin && x2<=xMax && y2>=yMin &&y2<=yMax)
{
	dda(x1,y1,x2,y2,xMin,yMin,xMax,yMax);
}
else
{
	dda(x2,y2,x1,y1,xMin,yMin,xMax,yMax);
}
break;
case 2:
	line(x1,y1,x2,y2);
	break;
}
}
   getch();
  closegraph();
}