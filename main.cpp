#include<cstdio>
#include<cmath>

#include<GL/glut.h>
#include<GL/glu.h>

#include"world.h"
#include"fish.h"


#define _WIDTH 1400
#define _HEIGTH 900


using namespace std;
world* myWorld;

float WidthHeigth_Scaling;
bool fl_stopped = false; //flag to stop animation
int WinID;

void keyboard_callback(unsigned char cKey, int i1, int i2)
{
	if(cKey == 'a')
	{
		glViewport(5,5,0.5,0.5);
	}
	else if(cKey == 'd')
	{
		glTranslatef(0,0,-0.1);
	}
	else if(cKey == 'w')
	{
		glTranslatef(0,0.1,0);
	}
	else if(cKey == 's')
	{
		glTranslatef(0,-0.1,0);
	}
	else if(cKey =='r')
	{
		glLoadIdentity();
		glOrtho(-1.0*WidthHeigth_Scaling, 1.0*WidthHeigth_Scaling, -1.0, 1.0, -5.0, 5.0);
	}
	else if(cKey =='p')
		glScalef(0.9,0.9,0.9);
	else if(cKey =='o')
		glScalef(1.1,1.1,1.1);
	else if(cKey =='b')
	{
		if(fl_stopped)
		{
			fl_stopped = false;
			cout<<"animation continued..."<<endl;
		}else{
			fl_stopped = true;
			cout<<"animation stopped"<<endl;
		}
	}
	else if(cKey =='q')
		glutDestroyWindow( WinID );

}

void DrawWorld(world *w)
{

	for(auto o: *(w->getObjects()))
	{

		glColor3f(1, 1, 1 );

		glPushMatrix();
		glTranslatef(o->getPos().getX(),
			   o->getPos().getY(),
			   o->getPos().getZ());
		glutWireSphere(0.015,10,10);
		glPopMatrix();

		/*glBegin( GL_LINE_STRIP );
		glVertex3d(gIt->lv_Position.X*_SCALE_SPACE,
			   gIt->lv_Position.Y*_SCALE_SPACE,
			   gIt->lv_Position.Z*_SCALE_SPACE);

		glEnd();*/
	}
}

void display( void )
{


	myWorld -> update();
    DrawWorld(myWorld);
	glFlush();
	glutSwapBuffers();
	glClear( GL_COLOR_BUFFER_BIT );
    //glRotatef(_ROTATE_VEL, _ROTATE_X, _ROTATE_Y, _ROTATE_Z);
//	sleep(1);
}

int main(int argc, char **argv)
{

    glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA );
	glutInitWindowSize(_WIDTH,_HEIGTH);
	glutInitWindowPosition(0,0);
	WinID = glutCreateWindow("swarm3d");

	glClearColor(0.0,0.0,0.0,0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glLineWidth(3);

	WidthHeigth_Scaling = (float)_WIDTH/_HEIGTH;
	glMatrixMode( GL_PROJECTION );
	glLoadIdentity();
	glOrtho(-1.0*WidthHeigth_Scaling, 1.0*WidthHeigth_Scaling, -1.0, 1.0, -5.0, 5.0);
	glutDisplayFunc( display );
	glutIdleFunc( display );
	glutKeyboardFunc( keyboard_callback );

    myWorld = new world;
    myWorld->spawn(30);

	glutMainLoop();


    return 0;
}


