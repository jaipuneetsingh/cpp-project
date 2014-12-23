#include<iostream.h>
#include<conio.h>
#include<graphics.h>
void bre_line(int,int,int,int);
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
	cout<<"Enter the Co-ordinates";
	cin>>x1>>y1;
	cout<<"Enter the co-ordinates";
	cin>>x2>>y2;
	bre_line(x1,y1,x2,y2);

}
void bre_line(int x1,int y1,int x2,int y2)
{

	  int dx=x2-x1,dy=y2-y1;
	  int p=2*dy-dx,i=dx;
	  while(i>0)
	  {
	       putpixel(x1,y1,WHITE);
	       if(p<0)
	       {
		   x1=x1+1;
		   p=p+2*dy;
	       }
	       else
	       {
		   x1=x1+1;
		   y1=y1+1;
		   p=p+2*dy-2*dx;
	       }
	       i--;
	  }
	  getch();
	  closegraph();
}

