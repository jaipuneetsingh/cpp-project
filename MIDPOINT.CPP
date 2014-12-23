#include<iostream.h>
#include<conio.h>
#include<graphics.h>
void plotpoint(int,int,int,int);
void main()
{
	char ch;
	int gd=DETECT,gm,errorcode,xc,yc,r,x,y,Pk;
	detectgraph(&gd,&gm);
	errorcode=graphresult();
	initgraph(&gd,&gm,"C:\\tc\\bgi");
	if(errorcode!=grOk)
	{
		cout<<"Graphics not installed";
		return;
	}
	cout<<"Enter the xc:";
	cin>>xc;
	cout<<"Enter the yc:";
	cin>>yc;
	cout<<"Enter the Radius";
	cin>>r;
	x=0;
	y=r;
	Pk=1-r;
	plotpoint(xc,yc,x,y);
	while(x<y)
	{
		if(Pk<0)
		{
			x=x+1;
			Pk=Pk+(2*x)+1;
		}
		else
		{
			x=x+1;
			y=y-1;
			Pk=Pk+(2*x)-(2*y)+1;
		}
		plotpoint(xc,yc,x,y);
	  }
	  getch();
	  closegraph();

}
void plotpoint(int xc,int yc,int x,int y)
 {
	  putpixel(xc+x,yc+y,WHITE);
	  putpixel(xc+y,yc+x,WHITE);
	  putpixel(xc-y,yc+x,WHITE);
	  putpixel(xc-x,yc+y,WHITE);
	  putpixel(xc-x,yc-y,WHITE);
	  putpixel(xc-y,yc-x,WHITE);
	  putpixel(xc+y,yc-x,WHITE);
	  putpixel(xc+x,yc-y,WHITE);
 }