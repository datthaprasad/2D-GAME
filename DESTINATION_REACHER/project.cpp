//comment 
#include<stdio.h>
#include<stdlib.h>
#include<GL/glut.h>
#include<math.h>
using namespace std;
#include<mmsystem.h>
#define degtorad 3.14/180

double a=1000,count=0,flag=0,s=200.0,com=200,theta,down=0,downcount=0,downflag=0,ly=200,rhandmov=200,ry=200;
double rlegmov=200,stoprlegmov=0,rlegmovcount=0,upflag=0,llegmov=200,stopllegmov=0,lhandmov=200,buildmove=150;
int k,glitch=0,stoplhandmov=0,stoprhandmov=0,roll=0,showf=0,score=0,n=10,num[20],numlen=0,shift=0,mainpage=1,level,done=0,lost=0;
int i,j,instruct=0,game=0;

void move(void);

void circle_draw(int size)
//To draw a circle
{
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
	for(i=0;i<360;i++)
	glVertex2f(25*cos(i*degtorad)*size,25*sin(i*degtorad)*size);
	glEnd();

}

void drwcl(int xc,int yc,int radius,int angle1,int angle2)         //To draw a cloud
{
    int a;
    glBegin(GL_POLYGON);
	for(a=angle1;a<=angle2;a=a+5)
	{
		float angle_radians=a*(22/7)/(float)180;
		float x=xc+radius*(float)cos(angle_radians);
		float y=yc+radius*(float)sin(angle_radians);
    		glVertex2f(x,y);
	}
    glEnd();
}

void trees()							//To draw a tree in level 1
{
	if(level==1)
	{
	glPushMatrix();
	glTranslated(-100,0,0);

	glBegin(GL_POLYGON);				//tree1
		glColor3f(0.3,0.1,0.0);
		glVertex2f(a+500,200);
		glVertex2f(a+500,360);
		glVertex2f(a+530,360);
		glColor3f(0.0,0.0,0.0);
		glVertex2f(a+530,200);
		glEnd();

		glBegin(GL_POLYGON);
		glColor3f(0.4,0.6,0.0);
		glVertex2f(a+450,360);
		glVertex2f(a+515,700);
		glVertex2f(a+515,350);
		glEnd();

	    glBegin(GL_POLYGON);
		glColor3f(0.5,0.5,0.0);
		glVertex2f(a+580,360);
		glVertex2f(a+515,700);
		glVertex2f(a+515,350);
		glEnd();	glPopMatrix();

	glPushMatrix();
	glTranslated(-720,0,0);

	glBegin(GL_POLYGON);				//tree2
	glColor3f(0.3,0.1,0.0);
	glVertex2f(a+500,200);
	glVertex2f(a+530,450);
	glVertex2f(a+550,450);
	glColor3f(0.0,0.0,0.0);
	glVertex2f(a+530,200);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.3,0.1,0.0);
	glVertex2f(a+535,450);
	glVertex2f(a+565,500);
	glVertex2f(a+578,500);
	glVertex2f(a+550,450);
	glEnd();

	glLineWidth(10.0);
	glBegin(GL_LINES);
	glColor3f(0.3,0.1,0.0);
	glVertex2f(a+535,440);
	glVertex2f(a+485,555);
	glVertex2f(a+570,500);
	glVertex2f(a+535,585);
	glVertex2f(a+575,500);
	glVertex2f(a+595,565);
	glEnd();

	glLineWidth(6.0);
	glBegin(GL_LINES);
	glColor3f(0.3,0.1,0.0);
	glVertex2f(a+514,490);
	glVertex2f(a+535,555);
	glEnd();

	glLineWidth(5.0);
	glBegin(GL_LINES);
	glColor3f(0.3,0.1,0.0);
	glVertex2f(a+548,555);
	glVertex2f(a+570,590);
	glVertex2f(a+578,515);
	glVertex2f(a+635,580);
	glEnd();

	glLineWidth(3.0);
	glBegin(GL_LINES);
	glColor3f(0.3,0.1,0.0);
	glVertex2f(a+500,515);
	glVertex2f(a+520,565);
	glEnd();
 	glColor3f(0.4,0.6,0.0);
      	drwcl(a+514,510,50,0,360);			//leaf
      	drwcl(a+585,520,50,0,360);
      	drwcl(a+515,565,40,0,360);
      	drwcl(a+584,580,40,0,360);
      	drwcl(a+534,610,30,0,360);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-400,0,0);

	glBegin(GL_POLYGON);				//tree3
	glColor3f(0.3,0.1,0.0);
	glVertex2f(a+500,200);
	glVertex2f(a+530,450);
	glVertex2f(a+550,450);
	glColor3f(0.0,0.0,0.0);
	glVertex2f(a+530,200);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.3,0.1,0.0);
	glVertex2f(a+535,450);
	glVertex2f(a+565,500);
	glVertex2f(a+578,500);
	glVertex2f(a+550,450);
	glEnd();

	glLineWidth(10.0);
	glBegin(GL_LINES);
	glColor3f(0.3,0.1,0.0);
	glVertex2f(a+535,440);
	glVertex2f(a+485,555);
	glVertex2f(a+570,500);
	glVertex2f(a+535,585);
	glVertex2f(a+575,500);
	glVertex2f(a+595,565);
	glEnd();

	glLineWidth(6.0);
	glBegin(GL_LINES);
	glColor3f(0.3,0.1,0.0);
	glVertex2f(a+514,490);
	glVertex2f(a+535,555);
	glEnd();

	glLineWidth(5.0);
	glBegin(GL_LINES);
	glColor3f(0.3,0.1,0.0);
	glVertex2f(a+548,555);
	glVertex2f(a+570,590);
	glVertex2f(a+578,515);
	glVertex2f(a+635,580);
	glEnd();

	glLineWidth(3.0);
	glBegin(GL_LINES);
	glColor3f(0.3,0.1,0.0);
	glVertex2f(a+500,515);
	glVertex2f(a+520,565);
	glEnd();
 	glColor3f(0.4,0.6,0.0);
      	drwcl(a+514,510,50,0,360);			//leaf
      	drwcl(a+585,520,50,0,360);
      	drwcl(a+515,565,40,0,360);
      	drwcl(a+584,580,40,0,360);
      	drwcl(a+534,610,30,0,360);
	glPopMatrix();


	glPushMatrix();
	glTranslated(1000,0,0);

	glBegin(GL_POLYGON);				//tree1
		glColor3f(0.3,0.1,0.0);
		glVertex2f(a+500,200);
		glVertex2f(a+500,360);
		glVertex2f(a+530,360);
		glColor3f(0.0,0.0,0.0);
		glVertex2f(a+530,200);
		glEnd();

		glBegin(GL_POLYGON);
		glColor3f(0.4,0.6,0.0);
		glVertex2f(a+450,360);
		glVertex2f(a+515,700);
		glVertex2f(a+515,350);
		glEnd();

	    glBegin(GL_POLYGON);
		glColor3f(0.5,0.5,0.0);
		glVertex2f(a+580,360);
		glVertex2f(a+515,700);
		glVertex2f(a+515,350);
		glEnd();	glPopMatrix();

	glPushMatrix();
	glTranslated(1590,0,0);

	glBegin(GL_POLYGON);				//tree5
	glColor3f(0.3,0.1,0.0);
	glVertex2f(a+500,200);
	glVertex2f(a+530,450);
	glVertex2f(a+550,450);
	glColor3f(0.0,0.0,0.0);
	glVertex2f(a+530,200);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.3,0.1,0.0);
	glVertex2f(a+535,450);
	glVertex2f(a+565,500);
	glVertex2f(a+578,500);
	glVertex2f(a+550,450);
	glEnd();

	glLineWidth(10.0);
	glBegin(GL_LINES);
	glColor3f(0.3,0.1,0.0);
	glVertex2f(a+535,440);
	glVertex2f(a+485,555);
	glVertex2f(a+570,500);
	glVertex2f(a+535,585);
	glVertex2f(a+575,500);
	glVertex2f(a+595,565);
	glEnd();

	glLineWidth(6.0);
	glBegin(GL_LINES);
	glColor3f(0.3,0.1,0.0);
	glVertex2f(a+514,490);
	glVertex2f(a+535,555);
	glEnd();

	glLineWidth(5.0);
	glBegin(GL_LINES);
	glColor3f(0.3,0.1,0.0);
	glVertex2f(a+548,555);
	glVertex2f(a+570,590);
	glVertex2f(a+578,515);
	glVertex2f(a+635,580);
	glEnd();

	glLineWidth(3.0);
	glBegin(GL_LINES);
	glColor3f(0.3,0.1,0.0);
	glVertex2f(a+500,515);
	glVertex2f(a+520,565);
	glEnd();

 	glColor3f(0.4,0.6,0.0);
      	drwcl(a+514,510,50,0,360);			//leaf
      	drwcl(a+585,520,50,0,360);
      	drwcl(a+515,565,40,0,360);
      	drwcl(a+584,580,40,0,360);
      	drwcl(a+534,610,30,0,360);
	glPopMatrix();
	}
}

void trees1()						//to draw a tree in level 2
{
	if(level==2)
	{

		glPushMatrix();
			glTranslated(-150,0,0);

			glBegin(GL_POLYGON);				//tree1
				glColor3f(0.3,0.1,0.0);
				glVertex2f(a+500,200);
				glVertex2f(a+500,360);
				glVertex2f(a+530,360);
				glColor3f(0.0,0.0,0.0);
				glVertex2f(a+530,200);
				glEnd();

				glBegin(GL_POLYGON);
				glColor3f(0.4,0.6,0.0);
				glVertex2f(a+450,360);
				glVertex2f(a+515,700);
				glVertex2f(a+515,350);
				glEnd();

			    glBegin(GL_POLYGON);
				glColor3f(0.5,0.5,0.0);
				glVertex2f(a+580,360);
				glVertex2f(a+515,700);
				glVertex2f(a+515,350);
				glEnd();	glPopMatrix();


	glPushMatrix();
	glTranslated(150,0,0);

	glBegin(GL_POLYGON);
	glColor3f(0.3,0.1,0.0);				//tree1
	glVertex2f(a+500,200);
	glVertex2f(a+530,450);
	glVertex2f(a+550,450);
	glColor3f(0.0,0.0,0.0);
	glVertex2f(a+530,200);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.3,0.1,0.0);
	glVertex2f(a+535,450);
	glVertex2f(a+565,500);
	glVertex2f(a+578,500);
	glVertex2f(a+550,450);
	glEnd();

	glLineWidth(10.0);
	glBegin(GL_LINES);
	glColor3f(0.3,0.1,0.0);
	glVertex2f(a+535,440);
	glVertex2f(a+485,555);
	glVertex2f(a+570,500);
	glVertex2f(a+535,585);
	glVertex2f(a+575,500);
	glVertex2f(a+595,565);
	glEnd();

	glLineWidth(6.0);
	glBegin(GL_LINES);
	glColor3f(0.3,0.1,0.0);
	glVertex2f(a+514,490);
	glVertex2f(a+535,555);
	glEnd();

	glLineWidth(5.0);
	glBegin(GL_LINES);
	glColor3f(0.3,0.1,0.0);
	glVertex2f(a+548,555);
	glVertex2f(a+570,590);
	glVertex2f(a+578,515);
	glVertex2f(a+635,580);
	glEnd();

	glLineWidth(3.0);
	glBegin(GL_LINES);
	glColor3f(0.3,0.1,0.0);
	glVertex2f(a+500,515);
	glVertex2f(a+520,565);
	glEnd();

 	glColor3f(0.4,0.6,0.0);
      	drwcl(a+514,510,50,0,360);			//leaf
      	drwcl(a+585,520,50,0,360);
      	drwcl(a+515,565,40,0,360);
      	drwcl(a+584,580,40,0,360);
      	drwcl(a+534,610,30,0,360);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-350,0,0);

	glBegin(GL_POLYGON);				//tree2
	glColor3f(0.3,0.1,0.0);
	glVertex2f(a+500,200);
	glVertex2f(a+530,450);
	glVertex2f(a+550,450);
	glColor3f(0.0,0.0,0.0);
	glVertex2f(a+530,200);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.3,0.1,0.0);
	glVertex2f(a+535,450);
	glVertex2f(a+565,500);
	glVertex2f(a+578,500);
	glVertex2f(a+550,450);
	glEnd();

	glLineWidth(10.0);
	glBegin(GL_LINES);
	glColor3f(0.3,0.1,0.0);
	glVertex2f(a+535,440);
	glVertex2f(a+485,555);
	glVertex2f(a+570,500);
	glVertex2f(a+535,585);
	glVertex2f(a+575,500);
	glVertex2f(a+595,565);
	glEnd();

	glLineWidth(6.0);
	glBegin(GL_LINES);
	glColor3f(0.3,0.1,0.0);
	glVertex2f(a+514,490);
	glVertex2f(a+535,555);
	glEnd();

	glLineWidth(5.0);
	glBegin(GL_LINES);
	glColor3f(0.3,0.1,0.0);
	glVertex2f(a+548,555);
	glVertex2f(a+570,590);
	glVertex2f(a+578,515);
	glVertex2f(a+635,580);
	glEnd();

	glLineWidth(3.0);
	glBegin(GL_LINES);
	glColor3f(0.3,0.1,0.0);
	glVertex2f(a+500,515);
	glVertex2f(a+520,565);
	glEnd();

 	glColor3f(0.4,0.6,0.0);
      	drwcl(a+514,510,50,0,360);			//leaf
      	drwcl(a+585,520,50,0,360);
      	drwcl(a+515,565,40,0,360);
      	drwcl(a+584,580,40,0,360);
      	drwcl(a+534,610,30,0,360);
	glPopMatrix();
	}
}


void backbuild()					//to draw a buildings in level1
{
	if(level==1)
	{
	glPushMatrix();
	glTranslated(-250,0,0);

	glColor3f(0.25,0.0,0.25);
	glBegin(GL_POLYGON);				//build 1
	glVertex2f(buildmove,150);
	glVertex2f(buildmove,700);
	glVertex2f(buildmove+245,700);
	glVertex2f(buildmove+245,150);
	glEnd();

	glColor3f(0.45,0.16,0.40);
	glBegin(GL_POLYGON);
	glVertex2f(buildmove+245,150);
	glVertex2f(buildmove+245,700);
	glVertex2f(buildmove+265,720);
	glVertex2f(buildmove+265,180);
	glEnd();

	glColor3f(0.35,0.16,0.75);
	glBegin(GL_POLYGON);
	glVertex2f(buildmove,700);
	glVertex2f(buildmove+20,720);
	glVertex2f(buildmove+265,720);
	glVertex2f(buildmove+245,700);
	glEnd();

	glColor3f(0.34,0.50,0.1);
	glBegin(GL_POLYGON);
	glVertex2f(buildmove-3,470);
	glVertex2f(buildmove-3,500);
	glVertex2f(buildmove+248,500);
	glVertex2f(buildmove+248,470);
	glEnd();

	glColor3f(0.1,0.0,0.07);
	glBegin(GL_POLYGON);
	glVertex2f(buildmove+90,150);
	glVertex2f(buildmove+90,370);
	glVertex2f(buildmove+135,370);
	glVertex2f(buildmove+135,150);
	glEnd();

	glColor3f(0.24,0.50,0.9);
	glBegin(GL_POLYGON);
	glVertex2f(buildmove+1,501);
	glVertex2f(buildmove+1,698);
	glVertex2f(buildmove+40,698);
	glVertex2f(buildmove+40,501);
	glEnd();

	glColor3f(0.24,0.50,0.9);
	glBegin(GL_POLYGON);
	glVertex2f(buildmove+42,501);
	glVertex2f(buildmove+42,698);
	glVertex2f(buildmove+81,698);
	glVertex2f(buildmove+81,501);
	glEnd();

	glColor3f(0.24,0.50,0.9);
	glBegin(GL_POLYGON);
	glVertex2f(buildmove+83,501);
	glVertex2f(buildmove+83,698);
	glVertex2f(buildmove+122,698);
	glVertex2f(buildmove+122,501);
	glEnd();

	glColor3f(0.24,0.50,0.9);
	glBegin(GL_POLYGON);
	glVertex2f(buildmove+124,501);
	glVertex2f(buildmove+124,698);
	glVertex2f(buildmove+163,698);
	glVertex2f(buildmove+163,501);
	glEnd();

	glColor3f(0.24,0.50,0.9);
	glBegin(GL_POLYGON);
	glVertex2f(buildmove+165,501);
	glVertex2f(buildmove+165,698);
	glVertex2f(buildmove+204,698);
	glVertex2f(buildmove+204,501);
	glEnd();

	glColor3f(0.24,0.50,0.9);
	glBegin(GL_POLYGON);
	glVertex2f(buildmove+206,501);
	glVertex2f(buildmove+206,698);
	glVertex2f(buildmove+244,698);
	glVertex2f(buildmove+244,501);
	glEnd();


	glColor3f(0.35,0.16,0.14);				//build 2
	glBegin(GL_POLYGON);
	glVertex2f(buildmove+500,150);
	glVertex2f(buildmove+500,700);
	glVertex2f(buildmove+750,700);
	glVertex2f(buildmove+750,150);
	glEnd();

	glColor3f(0.25,0.16,0.04);				//build 2
	glBegin(GL_POLYGON);
	glVertex2f(buildmove+500,700);
	glVertex2f(buildmove+520,720);
	glVertex2f(buildmove+770,720);
	glVertex2f(buildmove+750,700);
	glEnd();

	glColor3f(0.15,0.16,0.07);				//build 2
	glBegin(GL_POLYGON);
	glVertex2f(buildmove+750,150);
	glVertex2f(buildmove+750,700);
	glVertex2f(buildmove+770,720);
	glVertex2f(buildmove+770,170);
	glEnd();

	glColor3f(0.24,0.50,0.0);
	glBegin(GL_POLYGON);
	glVertex2f(buildmove+550,600);
	glVertex2f(buildmove+550,650);
	glVertex2f(buildmove+600,650);
	glVertex2f(buildmove+600,600);
	glEnd();

	glColor3f(0.24,0.50,0.0);
	glBegin(GL_POLYGON);
	glVertex2f(buildmove+650,600);
	glVertex2f(buildmove+650,650);
	glVertex2f(buildmove+700,650);
	glVertex2f(buildmove+700,600);
	glEnd();

	glColor3f(0.24,0.50,0.0);
	glBegin(GL_POLYGON);
	glVertex2f(buildmove+550,500);
	glVertex2f(buildmove+550,550);
	glVertex2f(buildmove+600,550);
	glVertex2f(buildmove+600,500);
	glEnd();

	glColor3f(0.24,0.50,0.0);
	glBegin(GL_POLYGON);
	glVertex2f(buildmove+650,500);
	glVertex2f(buildmove+650,550);
	glVertex2f(buildmove+700,550);
	glVertex2f(buildmove+700,500);
	glEnd();

	glColor3f(1.0,0.0,0.0);
	glBegin(GL_POLYGON);
	glVertex2f(buildmove+600,150);
	glVertex2f(buildmove+600,350);
	glVertex2f(buildmove+650,350);
	glVertex2f(buildmove+650,150);
	glEnd();
	glPopMatrix();
	}

	if(level==2)						//to draw a building in level2
	{
	glPushMatrix();
	glTranslated(-290,0,0);

	glColor3f(0.15,0.0,0.15);
	glBegin(GL_POLYGON);				//build 1
	glVertex2f(buildmove,150);
	glVertex2f(buildmove,700);
	glVertex2f(buildmove+245,700);
	glVertex2f(buildmove+245,150);
	glEnd();

	glColor3f(0.35,0.06,0.30);
	glBegin(GL_POLYGON);
	glVertex2f(buildmove+245,150);
	glVertex2f(buildmove+245,700);
	glVertex2f(buildmove+265,720);
	glVertex2f(buildmove+265,180);
	glEnd();

	glColor3f(0.25,0.06,0.65);
	glBegin(GL_POLYGON);
	glVertex2f(buildmove,700);
	glVertex2f(buildmove+20,720);
	glVertex2f(buildmove+265,720);
	glVertex2f(buildmove+245,700);
	glEnd();

	glColor3f(0.24,0.30,0.05);
	glBegin(GL_POLYGON);
	glVertex2f(buildmove-3,470);
	glVertex2f(buildmove-3,500);
	glVertex2f(buildmove+248,500);
	glVertex2f(buildmove+248,470);
	glEnd();

	glColor3f(0.1,0.0,0.07);
	glBegin(GL_POLYGON);
	glVertex2f(buildmove+90,150);
	glVertex2f(buildmove+90,370);
	glVertex2f(buildmove+135,370);
	glVertex2f(buildmove+135,150);
	glEnd();

	glColor3f(0.20,0.50,0.85);
	glBegin(GL_POLYGON);
	glVertex2f(buildmove+1,501);
	glVertex2f(buildmove+1,698);
	glVertex2f(buildmove+40,698);
	glVertex2f(buildmove+40,501);
	glEnd();

	glColor3f(0.20,0.50,0.85);
	glBegin(GL_POLYGON);
	glVertex2f(buildmove+42,501);
	glVertex2f(buildmove+42,698);
	glVertex2f(buildmove+81,698);
	glVertex2f(buildmove+81,501);
	glEnd();

	glColor3f(0.20,0.50,0.85);
	glBegin(GL_POLYGON);
	glVertex2f(buildmove+83,501);
	glVertex2f(buildmove+83,698);
	glVertex2f(buildmove+122,698);
	glVertex2f(buildmove+122,501);
	glEnd();

	glColor3f(0.20,0.50,0.85);
	glBegin(GL_POLYGON);
	glVertex2f(buildmove+124,501);
	glVertex2f(buildmove+124,698);
	glVertex2f(buildmove+163,698);
	glVertex2f(buildmove+163,501);
	glEnd();

	glColor3f(0.20,0.50,0.85);
	glBegin(GL_POLYGON);
	glVertex2f(buildmove+165,501);
	glVertex2f(buildmove+165,698);
	glVertex2f(buildmove+204,698);
	glVertex2f(buildmove+204,501);
	glEnd();

	glColor3f(0.20,0.50,0.85);
	glBegin(GL_POLYGON);
	glVertex2f(buildmove+206,501);
	glVertex2f(buildmove+206,698);
	glVertex2f(buildmove+244,698);
	glVertex2f(buildmove+244,501);
	glEnd();


	glColor3f(0.35,0.36,0.04);				//build 2
	glBegin(GL_POLYGON);
	glVertex2f(buildmove+500,150);
	glVertex2f(buildmove+500,700);
	glVertex2f(buildmove+750,700);
	glVertex2f(buildmove+750,150);
	glEnd();

	glColor3f(0.15,0.06,0.06);				//build 2
	glBegin(GL_POLYGON);
	glVertex2f(buildmove+500,700);
	glVertex2f(buildmove+520,720);
	glVertex2f(buildmove+770,720);
	glVertex2f(buildmove+750,700);
	glEnd();

	glColor3f(0.21,0.20,0.09);				//build 2
	glBegin(GL_POLYGON);
	glVertex2f(buildmove+750,150);
	glVertex2f(buildmove+750,700);
	glVertex2f(buildmove+770,720);
	glVertex2f(buildmove+770,170);
	glEnd();

	glColor3f(0.34,0.50,0.0);
	glBegin(GL_POLYGON);
	glVertex2f(buildmove+550,600);
	glVertex2f(buildmove+550,650);
	glVertex2f(buildmove+600,650);
	glVertex2f(buildmove+600,600);
	glEnd();

	glColor3f(0.34,0.50,0.0);
	glBegin(GL_POLYGON);
	glVertex2f(buildmove+650,600);
	glVertex2f(buildmove+650,650);
	glVertex2f(buildmove+700,650);
	glVertex2f(buildmove+700,600);
	glEnd();

	glColor3f(0.34,0.50,0.0);
	glBegin(GL_POLYGON);
	glVertex2f(buildmove+550,500);
	glVertex2f(buildmove+550,550);
	glVertex2f(buildmove+600,550);
	glVertex2f(buildmove+600,500);
	glEnd();

	glColor3f(0.34,0.50,0.0);
	glBegin(GL_POLYGON);
	glVertex2f(buildmove+650,500);
	glVertex2f(buildmove+650,550);
	glVertex2f(buildmove+700,550);
	glVertex2f(buildmove+700,500);
	glEnd();

	glColor3f(0.0,0.0,1.0);
	glBegin(GL_POLYGON);
	glVertex2f(buildmove+600,150);
	glVertex2f(buildmove+600,350);
	glVertex2f(buildmove+650,350);
	glVertex2f(buildmove+650,150);
	glEnd();
	glPopMatrix();
	}
}
void mplatform()
{
	glColor3f(0.0,0.0,0.0);				//main platform
	glBegin(GL_POLYGON);
	glVertex2f(0,0);
	glVertex2f(0,200);
	glVertex2f(1000,200);
	glVertex2f(1000,0);
	glEnd();
}

void mainblock()					//main block
{
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
	glVertex2f(400,200);
	glVertex2f(400,250);
	glVertex2f(450,250);
	glVertex2f(450,200);
	glEnd();
}

void arrow()						//arrows
{
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_LINES);
	glVertex2f(218,390);
	glVertex2f(218,325);
	glVertex2f(210,380);
	glVertex2f(218,390);
	glVertex2f(218,390);
	glVertex2f(226,380);
	glEnd();
}

void mstickmanj()					//instruction page stickman
{
	glColor3f(0.0,0.0,0.0);
	glLineWidth(10);
	glBegin(GL_POLYGON);				//head
	glColor3f(0.0,0.0,0.0);
	float theta;
		glBegin(GL_POLYGON);
		for(int z=0;z<360;z++){
	        theta=z*3.14/180;
	        glVertex2f(220+15*cos(theta),500+15*sin(theta));
		}
	glEnd();

	glBegin(GL_LINES);				//body
	glColor3f(0.0,0.0,0.0);
    	glVertex2f(220,500);
	glVertex2f(215,440);
	glVertex2f(215,441);
	glVertex2f(200,408);
	glVertex2f(201,409);
	glVertex2f(188,414);
	glVertex2f(215,440);
	glVertex2f(225,415);
	glVertex2f(225,416);
	glVertex2f(218,400);
	glVertex2f(218,465);
	glVertex2f(228,468);
	glVertex2f(227,467);
	glVertex2f(235,480);
	glVertex2f(218,473);
	glVertex2f(201,462);
	glVertex2f(202,463);
	glVertex2f(208,445);
	glEnd();
}

void arrow2()						//arrow 2
{
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_LINES);
	glVertex2f(250,227);
	glVertex2f(400,227);
	glVertex2f(380,239);
	glVertex2f(400,227);
	glVertex2f(400,227);
	glVertex2f(380,215);
	glEnd();

}

void mstickman()					//mainpage stickman
{
	glColor3f(0.0,0.0,0.0);
	glLineWidth(10);
	glBegin(GL_POLYGON);
	glColor3f(0.0,0.0,0.0);
	float theta;
		glBegin(GL_POLYGON);
		for(int z=0;z<360;z++){
	        theta=z*3.14/180;
	        glVertex2f(220+15*cos(theta),300+15*sin(theta));
		}
	glEnd();
	glBegin(GL_LINES);
	glColor3f(0.0,0.0,0.0);
    	glVertex2f(220,300);
	glVertex2f(215,240);
	glVertex2f(215,241);
	glVertex2f(200,208);
	glVertex2f(201,209);
	glVertex2f(188,214);
	glVertex2f(215,240);
	glVertex2f(225,215);
	glVertex2f(225,216);
	glVertex2f(218,200);
	glVertex2f(218,265);
	glVertex2f(228,268);
	glVertex2f(227,267);
	glVertex2f(235,280);
	glVertex2f(218,273);
	glVertex2f(201,262);
	glVertex2f(202,263);
	glVertex2f(208,245);
	glEnd();
}


void cloud()						//To draw a cloud
{

  	glPushMatrix();
	glTranslated(500.0,250.0,0);
   	glColor3f(0.3,0.9,1);
   	glColor3f(0.8,0.9,1);
   	glColor3f(0.7,0.9,1);
   	drwcl(240,600,25,0,360);
   	drwcl(270,620,35,0,360);
   	drwcl(280,590,35,0,360);
   	drwcl(310,640,30,0,360);
   	drwcl(240,615,35,0,360);
   	drwcl(310,590,35,0,360);
	circle_draw(0);
   	glPopMatrix();
}


void platform()						//To draw a platform
{
	glLineWidth(2);
	if(level==1)
	glColor3f(0.0,0.0,0.0);
	else
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
	glVertex2f(0,0);
	glVertex2f(0,200);
	glVertex2f(1000,200);
	glVertex2f(1000,0);
	glEnd();
}

void stickman()						//To draw a stickman
{

	glLineWidth(10);
	if(level==1)
	glColor3f(0.0,0.0,0.0);
	else
	glColor3f(0.0,0.0,0.0);
	float theta;
		glBegin(GL_POLYGON);
		for(int z=0;z<360;z++){
	        theta=z*3.14/180;
	        glVertex2f(com+20+15*cos(theta),s+100+15*sin(theta));
		}
	glEnd();

	glBegin(GL_LINES);
	if(level==1)
	glColor3f(0.0,0.0,0.0);
	else
	glColor3f(0.0,0.0,0.0);
    	glVertex2f(com+20,s+100);
	glVertex2f(com+15,s+40);
	glVertex2f(com+15,s+41);
	glVertex2f(llegmov,s+8);
	glVertex2f(llegmov+1,s+9);
	glVertex2f(llegmov-12,s+14);
	glVertex2f(com+15,s+40);
	glVertex2f(rlegmov+25,s+15);
	glVertex2f(rlegmov+25,s+16);
	glVertex2f(rlegmov+18,s);
	glVertex2f(com+18,s+65);
	glVertex2f(rhandmov+28,ry+68);
	glVertex2f(rhandmov+27,ry+67);
	glVertex2f(rhandmov+35,ry+80);
	glVertex2f(com+18,s+73);
	glVertex2f(lhandmov+1,s+62);
	glVertex2f(lhandmov+2,s+63);
	glVertex2f(lhandmov+8,s+45);
	glEnd();
}

void println(float x,float y,char *number)			//To print the statements
{
	char *p;
	glRasterPos2f(x,y);
	for(p=number;*p!='\0';p++)
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,*p);
}

void move3(void)						//Move function
{

	if(s>=200.0)
	{
		if(level==1)
		{
			if(((a+300<225)&&s<250&&(a+300>218))||(s<=250&&(a+300>162)&&(a+350<230)))
			{
				lost=1;
         			glutIdleFunc(NULL);
	        		showf=1;
				glutPostRedisplay();
			}
			if(((a+500<225)&&s<250&&(a+500>218))||(s<=250&&(a+500>162)&&(a+550<230)))
			{
                		lost=1;
		    		glutIdleFunc(NULL);
	        		showf=1;
				glutPostRedisplay();
			}
			if(((a+750<225)&&s<250&&(a+750>218))||(s<=250&&(a+750>162)&&(a+800<230)))
			{
                		lost=1;
		    		glutIdleFunc(NULL);
	        		showf=1;
				glutPostRedisplay();
			}
			if(((a+1100<225)&&s>200&&(a+1100>208))||(s>=200&&(a+1100>162)&&(a+1100<230))&&!roll)
			{
				lost=1;
		    		glutIdleFunc(NULL);
	        		showf=1;
				glutPostRedisplay();
			}
			if(((a+1450<225)&&s>200&&(a+1450>208))||(s>=200&&(a+1450>162)&&(a+1450<230))&&!roll)
			{
				lost=1;
		    		glutIdleFunc(NULL);
	        		showf=1;
				glutPostRedisplay();
			}
			if(((a+1700<225)&&s<250&&(a+1700>218))||(s<=250&&(a+1700>162)&&(a+1750<230)))
			{
               			lost=1;
		    		glutIdleFunc(NULL);
	        		showf=1;
				glutPostRedisplay();
			}
			if(((a+1950<225)&&s>200&&(a+1950>208))||(s>=200&&(a+1950>162)&&(a+1950<230))&&!roll)
			{
				lost=1;
		    		glutIdleFunc(NULL);
	        		showf=1;
				glutPostRedisplay();
			}
			if(((a+2200<225)&&s<250&&(a+2200>218))||(s<=250&&(a+2200>162)&&(a+2250<230)))
			{
                 		lost=1;
		    		glutIdleFunc(NULL);
	        		showf=1;
				glutPostRedisplay();
			}
			a-=0.7;
			buildmove-=0.7;

		}
		if(level==2)
		{
			if(((a+300<225)&&s<250&&(a+300>208))||(s<=250&&(a+300>162)&&(a+350<230)))
			{
				lost=1;
		    		glutIdleFunc(NULL);
	        		showf=1;
				glutPostRedisplay();
			}
			if(((a+358<225)&&s<250&&(a+358>208))||(s<=250&&(a+358>162)&&(a+408<230)))
			{
				lost=1;
		    		glutIdleFunc(NULL);
	        		showf=1;
				glutPostRedisplay();
			}
			if(((a+515<225)&&s<250&&(a+515>208))||(s<=250&&(a+515>162)&&(a+565<230)))
			{
				lost=1;
		    		glutIdleFunc(NULL);
	        		showf=1;
				glutPostRedisplay();
			}
			if(((a+725<225)&&s>200&&(a+725>208))||(s>=200&&(a+725>162)&&(a+725<230))&&!roll)
			{
				lost=1;
		    		glutIdleFunc(NULL);
	        		showf=1;
				glutPostRedisplay();
			}
			if(((a+935<225)&&s<250&&(a+935>208))||(s<=250&&(a+935>162)&&(a+985<230)))
			{
				lost=1;
		    		glutIdleFunc(NULL);
	        		showf=1;
				glutPostRedisplay();
			}
			if(((a+1015<225)&&s<250&&(a+1015>208))||(s<=250&&(a+1015>162)&&(a+1065<230)))
			{
				lost=1;
		    		glutIdleFunc(NULL);
	        		showf=1;
				glutPostRedisplay();
			}
			if(((a+1155<225)&&s>200&&(a+1155>208))||(s>=200&&(a+1155>162)&&(a+1155<230))&&!roll)
			{
				lost=1;
		    		glutIdleFunc(NULL);
	        		showf=1;
				glutPostRedisplay();
			}
			if(((a+1305<225)&&s>200&&(a+1305>208))||(s>=200&&(a+1305>162)&&(a+1305<230))&&!roll)
			{
				lost=1;
		    		glutIdleFunc(NULL);
	        		showf=1;
				glutPostRedisplay();
			}
			if(((a+1475<225)&&s<250&&(a+1475>208))||(s<=250&&(a+1475>162)&&(a+1525<230)))
			{
				lost=1;
		    		glutIdleFunc(NULL);
	        		showf=1;
				glutPostRedisplay();
			}
			a-=0.86;
			buildmove-=0.86;

		}

			s-=1.5;
			ry-=1.5;
			score+=1;

	}

	else
	{
		ry=200;
		downflag=0;
		flag=0;
		s=200;
		glutIdleFunc(move);
	}
glutPostRedisplay();
}


void move(void)
{
	score+=1;
	count++;
	glitch++;
	if(!upflag||!downflag)
	{
		if(glitch==40)
		{
			glitch=0;
			llegmov=200;
			rlegmov=200;
		}
		if(rhandmov+33>219&&stoprhandmov==0)
		{
			if(ry+73>250)
				ry-=0.25;
			if(ry+73<=263)
			{
				rhandmov-=0.25;
				if(rhandmov+33<=220)
				{
					rhandmov=185;
					stoprhandmov=1;
				}
			}
		}
	else if(rhandmov+33<234&&stoprhandmov==1)
	{
		rhandmov+=0.35;
		if(rhandmov+33>=233)
		{
			rhandmov=200;
			if(ry+73<274)
				ry+=0.35;
			if(ry+73>=273)
				stoprhandmov=0;
		}
	}
	if(lhandmov+1<219&&stoplhandmov==0)
	{
		lhandmov+=0.35;
		if(lhandmov+1>=218)
		{
			lhandmov=218;
			stoplhandmov=1;
		}
	}
	else if(lhandmov+1>200&&stoplhandmov==1)
	{
		lhandmov-=0.35;
		if(lhandmov+1<=201)
		{
			lhandmov=200;
			stoplhandmov=0;
		}
	}

	if((llegmov<220)&&stopllegmov==0)
	{

		llegmov+=0.5;
		if(llegmov>=219)
		{
			llegmov=220;
			stopllegmov=1;
		}
	}
	else if(llegmov>199&&stopllegmov==1)
	{

		llegmov-=0.5;
		if(llegmov<=200)
		{

			llegmov=200.0;
			stopllegmov=0;
		}
	}
	if((rlegmov+25)>208.0&&stoprlegmov==0)
	{
		rlegmov-=0.5;
		if(rlegmov+25<=209.0)
		{
			rlegmov=184.0;
			stoprlegmov=1;
		}

	}
	else if((rlegmov+25)<226.0&&stoprlegmov==1)
	{
		rlegmov+=0.5;
		if(rlegmov+25>=225.0)
		{
			rlegmov=200.0;
			stoprlegmov=0;
		}
	}
	}
	if(level==1)
	{
		if(((a+300<225)&&s<250&&(a+300>218))||(s<=250&&(a+300>162)&&(a+350<230)))
		{
          		lost=1;
		    	glutIdleFunc(NULL);
	        	showf=1;
			glutPostRedisplay();
		}
		if(((a+500<225)&&s<250&&(a+500>218))||(s<=250&&(a+500>162)&&(a+550<230)))
		{
                  	lost=1;
		    	glutIdleFunc(NULL);
	        	showf=1;
			glutPostRedisplay();
		}
		if(((a+750<225)&&s<250&&(a+750>218))||(s<=250&&(a+750>162)&&(a+800<230)))
		{
                	lost=1;
		    	glutIdleFunc(NULL);
	        	showf=1;
			glutPostRedisplay();
		}
		if(((a+1100<225)&&s>200&&(a+1100>208))||(s>=200&&(a+1100>162)&&(a+1100<230))&&!roll)
		{
			lost=1;
		    	glutIdleFunc(NULL);
	        	showf=1;
			glutPostRedisplay();
		}
		if(((a+1450<225)&&s>200&&(a+1450>208))||(s>=200&&(a+1450>162)&&(a+1450<230))&&!roll)
		{
			lost=1;
		    	glutIdleFunc(NULL);
	        	showf=1;
			glutPostRedisplay();
		}
		if(((a+1700<225)&&s<250&&(a+1700>218))||(s<=250&&(a+1700>162)&&(a+1750<230)))
		{
                  	lost=1;
		    	glutIdleFunc(NULL);
	        	showf=1;
			glutPostRedisplay();
		}
		if(((a+1950<225)&&s>200&&(a+1950>208))||(s>=200&&(a+1950>162)&&(a+1950<230))&&!roll)
		{
			lost=1;
		    	glutIdleFunc(NULL);
	        	showf=1;
			glutPostRedisplay();
		}
		if(((a+2200<225)&&s<250&&(a+2200>218))||(s<=250&&(a+2200>162)&&(a+2250<230)))
		{
               		lost=1;
		    	glutIdleFunc(NULL);
	        	showf=1;
			glutPostRedisplay();
		}
				a-=0.7;
				buildmove-=0.7;
	}

	if(level==2)
	{
		if(((a+300<225)&&s<250&&(a+300>208))||(s<=250&&(a+300>162)&&(a+350<230)))
		{
			lost=1;
			glutIdleFunc(NULL);
	        	showf=1;
			glutPostRedisplay();
		}
    		if(((a+358<225)&&s<250&&(a+358>208))||(s<=250&&(a+358>162)&&(a+408<230)))
		{
			lost=1;
		    	glutIdleFunc(NULL);
	        	showf=1;
			glutPostRedisplay();
		}
		if(((a+515<225)&&s<250&&(a+515>208))||(s<=250&&(a+515>162)&&(a+565<230)))
		{
	            	lost=1;
		    	glutIdleFunc(NULL);
	        	showf=1;
			glutPostRedisplay();
		}
		if(((a+725<225)&&s>200&&(a+725>208))||(s>=200&&(a+725>162)&&(a+725<230))&&!roll)
		{
                 	lost=1;
		    	glutIdleFunc(NULL);
	        	showf=1;
			glutPostRedisplay();
		}
		if(((a+935<225)&&s<250&&(a+935>208))||(s<=250&&(a+935>162)&&(a+985<230)))
		{
			lost=1;
		    	glutIdleFunc(NULL);
	        	showf=1;
			glutPostRedisplay();
		}
		if(((a+1015<225)&&s<250&&(a+1015>208))||(s<=250&&(a+1015>162)&&(a+1065<230)))
		{
			lost=1;
		    	glutIdleFunc(NULL);
	        	showf=1;
			glutPostRedisplay();
		}
		if(((a+1155<225)&&s>200&&(a+1155>208))||(s>=200&&(a+1155>162)&&(a+1155<230))&&!roll)
		{
			lost=1;
		    	glutIdleFunc(NULL);
	        	showf=1;
			glutPostRedisplay();
		}
		if(((a+1305<225)&&s>200&&(a+1305>208))||(s>=200&&(a+1305>162)&&(a+1305<230))&&!roll)
		{
			lost=1;
		    	glutIdleFunc(NULL);
	        	showf=1;
			glutPostRedisplay();
		}
		if(((a+1475<225)&&s<250&&(a+1475>208))||(s<=250&&(a+1475>162)&&(a+1525<230)))
		{
			lost=1;
		    	glutIdleFunc(NULL);
	        	showf=1;
			glutPostRedisplay();
		}
		a-=0.86;
		buildmove-=0.86;
	}
		if((s-50.0)==300.0&&count==35)
		glutIdleFunc(move3);
glutPostRedisplay();
}


void move2(void)

{

	 //mciSendString("pause pirate", NULL, 0, NULL);
	//			 mciSendString("play pirate", NULL, 0, NULL);

	downflag=1;
	if(level==1)
	{

		if(((a+300<225)&&s<250&&(a+300>218))||(s<=250&&(a+300>162)&&(a+350<230)))
		{
                	lost=1;
		    	glutIdleFunc(NULL);
	        	showf=1;
			glutPostRedisplay();
		}
		if(((a+500<225)&&s<250&&(a+500>218))||(s<=250&&(a+500>162)&&(a+550<230)))
		{
                	lost=1;
		    	glutIdleFunc(NULL);
	        	showf=1;
			glutPostRedisplay();
		}
		if(((a+750<225)&&s<250&&(a+750>218))||(s<=250&&(a+750>162)&&(a+800<230)))
		{
               		lost=1;
		    	glutIdleFunc(NULL);
	        	showf=1;
			glutPostRedisplay();
		}
		if(((a+1100<225)&&s>200&&(a+1100>208))||(s>=200&&(a+1100>162)&&(a+1100<230))&&!roll)
		{
			lost=1;
		    	glutIdleFunc(NULL);
	        	showf=1;
			glutPostRedisplay();
		}
		if(((a+1450<225)&&s>200&&(a+1450>208))||(s>=200&&(a+1450>162)&&(a+1450<230))&&!roll)
		{
			lost=1;
		    	glutIdleFunc(NULL);
	        	showf=1;
			glutPostRedisplay();
		}
		if(((a+1700<225)&&s<250&&(a+1700>218))||(s<=250&&(a+1700>162)&&(a+1750<230)))
		{
			lost=1;
		    	glutIdleFunc(NULL);
	        	showf=1;
			glutPostRedisplay();
		}
		if(((a+1950<225)&&s>200&&(a+1950>208))||(s>=200&&(a+1950>162)&&(a+1950<230))&&!roll)
		{
			lost=1;
		    	glutIdleFunc(NULL);
	        	showf=1;
			glutPostRedisplay();
		}
		if(((a+2200<225)&&s<250&&(a+2200>218))||(s<=250&&(a+2200>162)&&(a+2250<230)))
		{
			lost=1;
		    	glutIdleFunc(NULL);
	        	showf=1;
			glutPostRedisplay();
		}
	}

	if(level==2)
	{
		if(((a+300<225)&&s<250&&(a+300>218))||(s<=250&&(a+300>162)&&(a+350<230)))
		{
			lost=1;
		    	glutIdleFunc(NULL);
	        	showf=1;
			glutPostRedisplay();
		}
		if(((a+358<225)&&s<250&&(a+358>208))||(s<=250&&(a+358>162)&&(a+408<230)))
		{
			lost=1;
		    	glutIdleFunc(NULL);
	        	showf=1;
			glutPostRedisplay();
		}
		if(((a+515<225)&&s<250&&(a+515>208))||(s<=250&&(a+515>162)&&(a+565<230)))
		{
			lost=1;
		    	glutIdleFunc(NULL);
	        	showf=1;
			glutPostRedisplay();
		}
		if(((a+725<225)&&s>200&&(a+725>208))||(s>=200&&(a+725>162)&&(a+725<230))&&!roll)
		{
			lost=1;
		    	glutIdleFunc(NULL);
	        	showf=1;
			glutPostRedisplay();
		}
		if(((a+935<225)&&s<250&&(a+935>208))||(s<=250&&(a+935>162)&&(a+985<230)))
		{
			lost=1;
		    	glutIdleFunc(NULL);
	        	showf=1;
			glutPostRedisplay();
		}
		if(((a+1015<225)&&s<250&&(a+1015>208))||(s<=250&&(a+1015>162)&&(a+1065<230)))
		{
			lost=1;
		    	glutIdleFunc(NULL);
	        	showf=1;
			glutPostRedisplay();
		}
		if(((a+1155<225)&&s>200&&(a+1155>208))||(s>=200&&(a+1155>162)&&(a+1155<230))&&!roll)
		{
			lost=1;
		    	glutIdleFunc(NULL);
	        	showf=1;
			glutPostRedisplay();
		}
		if(((a+1305<225)&&s>200&&(a+1305>208))||(s>=200&&(a+1305>162)&&(a+1305<230))&&!roll)
		{
			lost=1;
		    	glutIdleFunc(NULL);
	        	showf=1;
			glutPostRedisplay();
		}
		if(((a+1475<225)&&s<250&&(a+1475>208))||(s<=250&&(a+1475>162)&&(a+1525<230)))
		{
			lost=1;
		    	glutIdleFunc(NULL);
	        	showf=1;
			glutPostRedisplay();
		}
	}
	if((s-50.0)<=300.0)
	{
		score+=1 ;
		ry+=1.5;
		s+=1.5;
		if(level==1)
		{

			a-=0.7;
			buildmove-=0.7;
		}
		if(level==2)
		{
			a-=0.86;
			buildmove-=0.86;
		}
		count=0;
	}
	else
	{
		ry=350;
		flag=1;
		s=350;
		glutIdleFunc(move);
	}
glutPostRedisplay();
}

void blocklevel1()				//To draw a blocks in level 1
{
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON); 			//block 1
	glVertex2f(a+300,200);
	glVertex2f(a+300,250);
	glVertex2f(a+350,250);
	glVertex2f(a+350,200);
	glEnd();

	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON); 			//block 2
	glVertex2f(a+500,200);
	glVertex2f(a+500,250);
	glVertex2f(a+550,250);
	glVertex2f(a+550,200);
	glEnd();

	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);			//block3
	glVertex2f(a+750,200);
	glVertex2f(a+750,250);
	glVertex2f(a+800,200);
	glEnd();

	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);			//block 4
	glVertex2f(a+1100,270);
	glVertex2f(a+1100,320);
	glVertex2f(a+1150,320);
	glVertex2f(a+1150,270);
	glEnd();

	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);			//block 5
	glVertex2f(a+1450,270);
	glVertex2f(a+1450,320);
	glVertex2f(a+1500,320);
	glVertex2f(a+1500,270);
	glEnd();

	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);			//block 6
	glVertex2f(a+1700,250);
	glVertex2f(a+1750,250);
	glVertex2f(a+1750,200);
	glEnd();

	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON); 			//block 7
	glVertex2f(a+1950,270);
	glVertex2f(a+1950,320);
	glVertex2f(a+2000,320);
	glVertex2f(a+2000,270);
	glEnd();

	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);			//block 8
	glVertex2f(a+2200,200);
	glVertex2f(a+2200,250);
	glVertex2f(a+2250,250);
	glVertex2f(a+2250,200);
	glEnd();
}

void blocklevel2()				//To draw a blocks in level 2
{
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);			//block 1
	glVertex2f(a+300,200);
	glVertex2f(a+300,250);
	glVertex2f(a+350,250);
	glVertex2f(a+350,200);
	glEnd();

	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);			//block 2
	glVertex2f(a+358,200);
	glVertex2f(a+358,250);
	glVertex2f(a+408,250);
	glVertex2f(a+408,200);
	glEnd();

	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);			//block 3
	glVertex2f(a+515,200);
	glVertex2f(a+515,250);
	glVertex2f(a+565,200);
	glEnd();

	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);			//block 4
	glVertex2f(a+725,270);
	glVertex2f(a+725,320);
	glVertex2f(a+775,320);
	glVertex2f(a+775,270);
	glEnd();

	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);			//block 5
	glVertex2f(a+935,200);
	glVertex2f(a+935,250);
	glVertex2f(a+985,250);
	glVertex2f(a+985,200);
	glEnd();

	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);			//block 6
	glVertex2f(a+1015,200);
	glVertex2f(a+1015,250);
	glVertex2f(a+1065,250);
	glVertex2f(a+1065,200);
	glEnd();

	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);			//block 7
	glVertex2f(a+1155,270);
	glVertex2f(a+1155,320);
	glVertex2f(a+1205,320);
	glVertex2f(a+1205,270);
	glEnd();

	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);			//block 8
	glVertex2f(a+1305,270);
	glVertex2f(a+1305,320);
	glVertex2f(a+1355,320);
	glVertex2f(a+1355,270);
	glEnd();

	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);			//block 9
	glVertex2f(a+1475,200);
	glVertex2f(a+1475,250);
	glVertex2f(a+1525,250);
	glVertex2f(a+1525,200);
	glEnd();
}

void show()
{
	if(level==1)
	{
		blocklevel1();
	}
	else if(level==2)
	{
		glColor3f(0.0,0.0,0.0);
		println(a+-600,800,"****** LEVEL 1 COMPLETED ******");
	}
}

void instructfunc()				//To view the instruction
{
	glColor3f(1.0,1.0,0.0);
	println(450,900,"Instructions");
	glColor3f(1.0,1.0,1.0);
	println(155,540,"Press LEFT for Jump");
	glColor3f(1.0,1.0,1.0);
	println(250,250,"Press RIGHT to Roll");
	glColor3f(1.0,1.0,1.0);
	println(600,400,"Press R to Restart Game");
	mstickman();
	mstickmanj();
	mplatform();
	arrow();
 	arrow2();
	glPushMatrix();
	glColor3f(1.0,1.0,1.0);
	glTranslatef(450.0,225.0,0);
	glColor3f(0.0,0.0,0.0);
	circle_draw(1);
	glPopMatrix();
}

void display(void)				//To display
{
		if(instruct==1)
	{
		glClear(GL_COLOR_BUFFER_BIT);
		glClearColor(0.1,0.2,0.3,0.4);
		instructfunc();
	}
    	else if(mainpage==0)
	{

     		//// mciSendString("pause kgf", NULL, 0, NULL);
    	////	 mciSendString("play pirate repeat", NULL, 0, NULL);
		glClear(GL_COLOR_BUFFER_BIT);
		if(level==1)
		glClearColor(0.2,0.3,0.7,0.9);
		else
		glClearColor(0.2,0.3,0.7,0.9);
		backbuild();
		platform();
		cloud();
		trees();
		trees1();

	if(showf)
	{
		if(level==1)
		glColor3f(1.0,1.0,1.0);
		else
		glColor3f(1.0,1.0,1.0);
		mciSendString("pause kgf", NULL, 0, NULL);
		mciSendString("open \"fail_opengl.wav\" type mpegvideo alias f", NULL, 0, NULL);
		 mciSendString("play f ", NULL, 0, NULL);

		 glColor3f(1.0,1.0,0.0);
		println(500,500,"Game Over");
		println(500,450,"Score:");
		for(i=0;i<=n;i++)
		{
			num[i]=score%10;
			score=score/10;
			if(score==0)
			break;
			numlen++;
		}
		for(i=numlen;i>=0;i--)
		{
			shift+=10;
			if(num[i]==1)
				println(550+shift,450,"1");
			else if(num[i]==2)
				println(550+shift,450,"2");
			else if(num[i]==3)
				println(550+shift,450,"3");
			else if(num[i]==4)
				println(550+shift,450,"4");
			else if(num[i]==5)
				println(550+shift,450,"5");
			else if(num[i]==6)
				println(550+shift,450,"6");
			else if(num[i]==7)
				println(550+shift,450,"7");
            		else if(num[i]==8)
				println(550+shift,450,"8");
            		else if(num[i]==9)
				println(550+shift,450,"9");
			else if(num[i]==0)
				println(550+shift,450,"0");
		}


	}

	if(down==0)
	stickman();
	else
	{
		rlegmov=200;
		llegmov=200;
		downcount+=2;
		glPushMatrix();
		if(level==1)
		glColor3f(0.0,0.0,0.0);
		else
		glColor3f(0.0,0.0,0.0);
		glTranslatef(225.0,225.0,0);
		circle_draw(1);
		glPopMatrix();
		if(downcount==350)
		{
			roll=0;
			upflag=0;
			down=0;
			downcount=0;
		}
	}
	if(a+1475<=(-5)&&level==2)
	{
		done=0;
		level=3;
		glutIdleFunc(NULL);
		glColor3f(1.0,1.0,1.0);
		println(350,900,"Level 2 completed");
		lost=1;
	}
	if(buildmove+750<=(-5))
		buildmove=1000;
	if(a+2250<=0&&level==1)
	{
		done=0;level=2;
	}
	if(level==2&&done==0)
	{
		done=1;

		a=1000;
	}
if(level==1)
	blocklevel1();
	show();
if(level==2)
	blocklevel2();

	}
	else
	{
	    mciSendString("close f ", NULL, 0, NULL);
        mciSendString("play kgf repeat", NULL, 0, 0);
		glClear(GL_COLOR_BUFFER_BIT);
		glClearColor(0.3,0.2,0.3,0.4);
        glColor3f(0.0,0.0,0.0);
		println(360,920,"SRINIVAS INSTITUTE OF TECHNOLOGY");
		glColor3f(1.0,1.0,0.0);
		println(359,920,"SRINIVAS INSTITUTE OF TECHNOLOGY");
        glColor3f(1.0,1.0,1.0);
		println(280,860,"DEPARTMENT OF COMPUTER SCIENCE AND ENGINEERING");
		glColor3f(1.0,1.0,1.0);
		println(355,800,"COMPUTER GRAPHICS AND VISUALIZATION");
        glColor3f(1.0,1.0,1.0);
		println(460,740,"A mini project on");
		glColor3f(0.0,0.0,0.0);

		println(409,680,"DESTINATION REACHER");
		glColor3f(1.0,1.0,1.0);
		println(409,680,"DESTINATION REACHER");
		glColor3f(1.0,0.0,0.0);
		println(410,680,"DESTINATION REACHER");

		glColor3f(1.0,1.0,1.0);
		println(500,630,"By");
		glColor3f(1.0,1.0,1.0);
		println(340,570,"Dattha Prasad");
		glColor3f(1.0,1.0,1.0);
		println(570,570,"4SN17CS019");
		glColor3f(1.0,1.0,1.0);
		println(340,520,"Harinandan");
		glColor3f(1.0,1.0,1.0);
		println(570,520,"4SN17CS028");
		glColor3f(0.0,0.5,1.0);
		println(720,350,"* Press UP to start the game");
		glColor3f(0.0,0.5,1.0);
		println(720,290,"* Press DOWN for Instructions");
		glColor3f(0.0,0.5,1.0);
		println(720,230,"* Press q to QUIT");
		mplatform();}
	glFlush();
}

void keyboard(unsigned char key,int x,int y)
{


	if(key=='r'|key=='R')
		if(lost==1||instruct==1)
		{
			// mciSendString("play kgf", NULL, 0, NULL);

			lost=0;
			numlen=0;
			for(i=0;i<n;i++)
			num[i]=0;
			instruct=0;
			buildmove=150;
			instruct=0;
			game=0;
 			shift=0;
 			mainpage=1;
 			done=0;
			glClearColor(0.1,0.2,0.3,0.4);
			ly=200,glitch=0,stoplhandmov=0,stoprhandmov=0,roll=0,showf=0,rhandmov=200,ry=200,score=0;
			a=1000,count=0,flag=0,s=200.0,com=200,down=0,downcount=0,downflag=0,rlegmov=200,stoprlegmov=0;
			rlegmovcount=0,upflag=0,llegmov=200,stopllegmov=0,lhandmov=200;
			glutPostRedisplay();
		}
		if(key=='q'|key=='Q')
		{
			if(mainpage==1)
				exit(0);
		}


}

void myinit()
{
	glClearColor(1.0,1.0,1.0,1.0);
	glColor3f(1.0,1.0,1.0);
	glPointSize(1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,999.0,0.0,999.0);
}

void special(int key, int x,int y)
{
	switch(key)
	{
	case (GLUT_KEY_RIGHT):
			if(downflag!=1&&!showf)
			{

				if(mainpage==0&&instruct==0){
					mciSendString("close s", NULL, 0, NULL);
					mciSendString("open \"spin_opengl.wav\" type mpegvideo alias s", NULL, 0, NULL);
					mciSendString("play s", NULL, 0, NULL);

				}
				roll=1;
				llegmov=200;
				rlegmov=200;
				upflag=1;
				down=1;
				display();
			}
			break;
	case (GLUT_KEY_LEFT):
				if(flag!=1&&upflag!=1&&!showf)
				{
					if(mainpage==0&&instruct==0){
						mciSendString("close j", NULL, 0, NULL);
						mciSendString("open \"jump_opengl.wav\" type mpegvideo alias j", NULL, 0, NULL);
						mciSendString("play j", NULL, 0, NULL);

					}

					rlegmov=200;
					llegmov=200;
					glutIdleFunc(move2);
				}
			break;
	case (GLUT_KEY_UP):
		if(game!=1)
		{
			mainpage=0;
         		score=0;
			level=1;
			game=1;
			//mciSendString("play pirate", NULL, 0, NULL);

			glutIdleFunc(move);
			display();
		}
		break;
	case (GLUT_KEY_DOWN):mainpage=0;
		if(game!=0)
		break;
		instruct=1;
		display();
	}
}


  time_t t1, t2, previous_pause_time=0;

  //open the audio file


int main(int argc,char **argv)
{
    	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(1500,1500);
	glutInitWindowPosition(0,0);
	glutCreateWindow("DESTINATION REACHER");
	glutDisplayFunc(display);
	myinit();
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(special);
	glutIdleFunc(move);

	//sndPlaySound(TEXT("song.wav"),SND_ASYNC | SND_LOOP);
	// mciSendString("open \"song.wav\" type mpegvideo alias mp3", NULL, 0, NULL);
	//sndPlaySound(TEXT("vathi.wav"),SND_ASYNC);
	 mciSendString("open \"pirates_opengl.wav\" type mpegvideo alias kgf", NULL, 0, NULL);
	// mciSendString("open \"dp2.wav\" type mpegvideo alias kgf", NULL, 0, NULL);
	 mciSendString("open \"spin_opengl.wav\" type mpegvideo alias s", NULL, 0, NULL);
	 mciSendString("open \"jump_opengl.wav\" type mpegvideo alias j", NULL, 0, NULL);


	glutMainLoop();
}




