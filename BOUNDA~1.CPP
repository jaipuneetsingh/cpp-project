#include<conio.h>
#include<iostream.h>
#include<graphics.h>
#include<dos.h>       
#include<stdlib.h>
void boundaryfill(int ,int,int,int);
void main()
{
	int gdriver=DETECT,gmode,col1;
	int col,x1,x2,y1,y2,ch,red;
	initgraph(&gdriver,&gmode,"C:\\TC\\BGI");
	cout<<"\nEnter 1 to draw and fill rectangle";
	cout<<"\nEnter 2 to draw and fill circle";
	cout<<"\nEnter choice : ";
	cin>>ch;
	switch(ch)
	{
	case 1:
		cout<<"\nEnter the rectangle coordinates as leftmostupper and rightmostlower    coordinates :";
	        cin>>x1>>y1>>x2>>y2;
		cout<<"\nEnter the color value betwen 0 and 15 of rectangle and boundary color";
		cin>>col>>col1;
		clearviewport();
		setcolor(col1);
		rectangle(x1,y1,x2,y2);
		boundaryfill((int)(x1+x2)/2,(int)(y1+y2)/2,col,col1);
		break;
	case 2:
              	cout<<"\nEnter the center coordinates of the circle and radius : ";
              	cin>>x1>>y1>>red;
		cout<<"\nEnter the color value betwen 0 and 15 of circle and also the boundary   color";
	        cin>>col>>col1;
		clearviewport();
		setcolor(col1);
		circle(x1,y1,col1);
		boundaryfill(x1,y1,col,col1);
		break;
	default:
		cout<<"\nInvalid choice : ";
	}
	getch();
	closegraph();
}
void boundaryfill(int x,int y,int col,int col1)
{
	if(getpixel(x,y)==7 && getpixel(x,y)!=col1)
	{
		putpixel(x,y,col);
		boundaryfill(x,y+1,col,col1);
		boundaryfill(x+1,y,col,col1);
		boundaryfill(x,y-1,col,col1);
		boundaryfill(x-1,y,col,col1);
	}
}
