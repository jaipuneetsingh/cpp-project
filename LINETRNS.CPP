//Program to Translate a Line
#include<iostream.h>
#include<conio.h>
#include<graphics.h>
void main()
{
	char ch;
	int gd=DETECT,gm,errorcode,x1,x2,y1,y2,x3,y3;
	detectgraph(&gd,&gm);
	errorcode=graphresult();
	initgraph(&gd,&gm,"C:\\tc\\bgi");
	if(errorcode!=grOk)
	{
		cout<<"Sorry Your Graphics is not loaded";
		return;
	}
	cout<<"Enter the P(x,y) Co-ordinate";
	cin>>x1>>y1;
	cout<<"Enter the Q(x,y) Co-ordinate";
	cin>>x2>>y2;
	clearviewport();
	outtextxy(x1,y1,"P(x,y)");
	line(x1,y1,x2,y2);
	outtextxy(x2,y2,"Q(x,y)");
	cout<<"Enter the co-ordinate tp Translate R(x,y)";
	cin>>x3>>y3;
	outtextxy(x1,y1,"P(x,y)");
	line(x1+x3,y1+y3,x2+x3,y2+y3);
	outtextxy(x1,y1,"Q(x,y)");
	getch();
}