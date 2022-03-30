/*
 * GLUT Shapes Demo
 *
 * Written by Nigel Stewart November 2003
 *
 * This program is test harness for the sphere, cone
 * and torus shapes in GLUT.
 *
 * Spinning wireframe and smooth shaded shapes are
 * displayed until the ESC or q key is pressed.  The
 * number of geometry stacks and slices can be adjusted
 * using the + and - keys.
 */
#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>

#include <stdlib.h>
#include <math.h>

static GLfloat spin = 0.0;
static float	tx	=  0.0;
static float	ty	=  0.0;

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);


    glColor3f(0.0,0.9, 0.0); glRectf( -10.0,-25.0,10.0,-90.0);
    //glColor3f(2.0, 0.5, 1.0); glRectf( -30.0,30.0,30.0,-30.0);
    glColor3f(0.0, 0.5, 0.5); glRectf( -25.0,-85.0,25.0,-100.0);

	glPushMatrix();

           glColor3f(2.0, 0.5, 1.0); glRectf( -30.0,30.0,30.0,-30.0);


	glRotatef(spin, 0.0, 0.0, 1.0);
	glColor3f(0.0, 0.5, 1.0);


	glTranslatef(tx,ty,0); glRectf(-90.0, 15.0, -45.0,-15.0);


	glTranslatef(tx,ty,0);  glRectf(45.0, 15.0, 90.0, -15.0);



	glTranslatef(tx,ty,0); glColor3f(0.0,1.0, 1.0);glRectf( -50.0,5.0,-10.0,-5.0);
    glTranslatef(tx,ty,0); glColor3f(0.0, 1.0, 1.0); glRectf( 10.0,5.0,50.0,-5.0);

	glPopMatrix();

        glColor3f(2.0, 0.5, 1.0); glRectf( -30.0,30.0,30.0,-30.0);



	glFlush();

}


void spinDisplay_left(void)
{
   spin = spin + 1;
   if (spin > 360.0)
      spin = spin - 360.0;
   glutPostRedisplay();
}

void spinDisplay_right(void)
{
   spin = spin - 1;
   if (spin > 360.0)
      spin = spin - 360.0;
   glutPostRedisplay();
}


void init(void)
{
	glClearColor (0.0, 0.0, 0.0, 0.0);
	glOrtho(-100.0, 100.0, -100.0, 100.0, -1.0, 1.0);
}


void my_keyboard(unsigned char key, int x, int y)
{

	switch (key) {

		case 'l':
			spinDisplay_left();
			break;

		case 'r':
			spinDisplay_right();
			break;


		case 's':
			 glutIdleFunc(NULL);
			 break;

	  default:
			break;
	}
}

void spe_key(int key, int x, int y)
{

	switch (key) {

		case GLUT_KEY_LEFT:
				tx -=5;
				glutPostRedisplay();
				break;

			//spinDisplay_left();
			//break;

		case GLUT_KEY_RIGHT:
				tx +=5;
				glutPostRedisplay();
				break;

			//spinDisplay_right();
			//break;

		case GLUT_KEY_DOWN:
				ty -=5;
				glutPostRedisplay();
				break;

			//spinDisplay_left();
			//break;

		case GLUT_KEY_UP:
				ty +=5;
				glutPostRedisplay();
				break;

	  default:
			break;
	}
}


void my_mouse(int button, int state, int x, int y)
{
   switch (button) {
      case GLUT_LEFT_BUTTON:
         if (state == GLUT_DOWN)
            glutIdleFunc(spinDisplay_left);
         break;
      case GLUT_MIDDLE_BUTTON:
      case GLUT_RIGHT_BUTTON:
         if (state == GLUT_DOWN)
			glutIdleFunc(spinDisplay_right);
          //glutIdleFunc(NULL); // make idle function inactive
         break;
      default:
         break;
   }
}





int main()
{
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (500, 500);
	glutInitWindowPosition (100, 100);
	glutCreateWindow (" Farhina 172-15-9705");
	init();

	glutDisplayFunc(display);
	glutKeyboardFunc(my_keyboard);
	glutSpecialFunc(spe_key);

	glutMouseFunc(my_mouse);
	glutMainLoop();
	return 0;
}

