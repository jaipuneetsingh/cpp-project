#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
void main()
{
	int gdriver=DETECT,gmode;
	int x1,x2,y1,y2,xmin,xmax,ymin,ymax,t1;
	float m;
	initgraph(&gdriver,&gmode,"c:\\tc\\bgi");
	cout<<"\nEnter the clip window cootdinates : ";
	cin>>xmin>>ymin>>xmax>>ymax;
	cout<<"\nEnter the line end points : ";
	cin>>x1>>y1>>x2>>y2;
	m=(float(y2-y1))/(float(x2-x1));
	cout<<"\nBefore clip clip window and line : ";
	rectangle(xmin,ymin,xmax,ymax);
	line(x1,y1,x2,y2);
	delay(700);
	clrscr();
	if(x1<xmin)
	{
		y1=y1+(xmin-x1)*m;
		x1=xmin;
	}
	if(x2>xmax)
	{
		y2=y2-(x2-xmax)*m;
		x2=xmax;
	}
	if(y2>ymax)
	{
		x2=x2-float((y2-ymax)/m);
		y2=ymax;
	}
	if(y1<ymin)
	{
		x1=x1+(ymin-y1)/m;
		y1=ymin;
	}
	if(x2<xmin)
	{
		y2=y2+(xmin-x2)*m;
		x2=xmin;
	}
	if(x1>xmax)
	{
		y1=y1-(x1-xmax)*m;
		x1=xmax;
	}
	if(y2<ymin)
	{
		x2=x2+float((ymin-y2)/m);
		y2=ymin;
	}
	if(y1>ymax)
	{
		x1=x1-float((y1-ymax)/m);
		y1=ymax;
	}
	rectangle(xmin,ymin,xmax,ymax);
	line(x1,y1,x2,y2);
	getch();
}
