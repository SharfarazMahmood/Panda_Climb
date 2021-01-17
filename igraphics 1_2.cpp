#include "iGraphics.h"
double x=50.0;
double y=100.0;

void animateBall()
{

}

void iDraw()
{
	//place your drawing codes here
	/**iSetColor(0,255,0);
	iFilledRectangle(50,150,800,240);
	iSetColor(255,0,0);
	iFilledCircle(230,270,80);**/
	
	iSetColor(255,255,255);
	iLine(30,500,670,500);
	iSetColor(255,255,255);
	iLine(30,500,350,600);
	iSetColor(255,255,255);
	iLine(350,600,670,500);
	
	iSetColor(0,102,102);//house
	iFilledRectangle(50,100,600,400);
	iSetColor(255,255,255);//door
	iFilledRectangle(275,100,150,300);
	iSetColor(255,255,255);//floor
	iFilledRectangle(20,70,670,30);
	iSetColor(255,255,255);//window
	iFilledRectangle(85,320,155,155);

}

void iMouseMove(int mx, int my)
{
	//place your codes here
}

void iMouse(int button, int state, int mx, int my)
{
	//place your codes here
	printf("mouse cliked at: %d %d\n",mx,my);
}

void iKeyboard(unsigned char key)
{
	//place your codes here
}
void iSpecialKeyboard(unsigned char key)
{
	//place your codes for other keys here
}
int main()
{
	//place your own initialization codes here.
	iInitialize(1000, 650,"Hello iGraphics");
return 0;
}