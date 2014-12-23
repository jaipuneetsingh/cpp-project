#include<iostream.h>
#include<conio.h>
#include<graphics.h>
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
}
void ellipse(int xc,int yc,int rx,int ry)
{
	int x=0,y=ry;
	int p=(ry*ry)-(rx*rx*ry)+((rx*rx)/4);
	while((2*x*ry*ry)<(2*y*rx*rx))
	{
	putpixel(xc+x,yc-y,WHITE);
	       putpixel(xc-x,yc+y,WHITE);
	       putpixel(xc+x,yc+y,WHITE);
	       putpixel(xc-x,yc-y,WHITE);

	       if(p<0)
	       {
		   x=x+1;
		   p=p+(2*ry*ry*x)+(ry*ry);
	       }
	       else
	       {
		   x=x+1;
		   y=y-1;
		   p=p+(2*ry*ry*x+ry*ry)-(2*rx*rx*y);
	       }
	  }
	  p=((float)x+0.5)*((float)x+0.5)*ry*ry+(y-1)*(y-1)*rx*rx-rx*rx*ry*ry;

while(y>=0)
	  {
	       putpixel(xc+x,yc-y,WHITE);
	       putpixel(xc-x,yc+y,WHITE);
	       putpixel(xc+x,yc+y,WHITE);
	       putpixel(xc-x,yc-y,WHITE);

	       if(p>0)
	       {
		   y=y-1;
		   p=p-(2*rx*rx*y)+(rx*rx);

	       }
	       else
	       {
		   y=y-1;
		   x=x+1;
		   p=p+(2*ry*ry*x)-(2*rx*rx*y)-(rx*rx);
	       }
	  }
	  getch();

 }