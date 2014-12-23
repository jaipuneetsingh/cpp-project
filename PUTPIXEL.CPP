#include<iostream.h>
#include<conio.h>
#include<graphics.h>
void main()
{
	char ch;
	int gd=DETECT,gm,errorcode,x,y,color;
	detectgraph(&gd,&gm);
	errorcode=graphresult();
	initgraph(&gd,&gm,"C:\\tc\\bgi");
	if(errorcode!=grOk)
	{
		cout<<"Graphics not installed";
		return;
	}
	cout<<"Enter the x-coordinate";
	cin>>x;
	cout<<"Enter the y-coordinate";
	cin>>y;
	color=15;
	putpixel(x,y,color);
	getch();
}