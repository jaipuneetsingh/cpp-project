#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
DDALine(int x1,int x2,int y1,int y2,int color);
void main()
{
	char ch;
	int gd=DETECT,gm,errorcode,x1,y1,x2,y2,color;
	detectgraph(&gd,&gm);
	errorcode=graphresult();
	initgraph(&gd,&gm,"C:\\tc\\bgi");
	if(errorcode!=grOk)
	{
		cout<<"Graphics not installed";
		return;
	}
	cout<<"Enter the x-coordinate";
	cin>>x1>>x2;
	cout<<"Enter the y-coordinate";
	cin>>y1>>y2;
	color=15;
	DDALine(x1,y1,x2,y2,color);
	getch();
}
int DDALine(int x1,int y1,int x2,int y2,int iColor)
{
    float dX,dY,iSteps;
    float xInc,yInc,iCount,x,y;

    dX = x1 - x2;
    dY = y1 - y2;

    if (fabs(dX) > fabs(dY))
    {
	iSteps = fabs(dX);
    }
    else
    {
	iSteps = fabs(dY);
    }

    xInc = dX/iSteps;
    yInc = dY/iSteps;


    x = x1;
    y = y1;

    for (iCount=1; iCount<=iSteps; iCount++)
    {
	putpixel(floor(x),floor(y),iColor);
	x -= xInc;
	y -= yInc;
    }
   return 0;
}