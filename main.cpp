#include <string.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
/* GLUT callback Handlers */
float a,b,c,d,e,f,x,y, oldX, oldY;
int it = 0;
void resize(int width, int height)
{
    if(width<=height)
        glViewport(0,(GLsizei) (height-width)/2,(GLsizei) width,(GLsizei) width);

    else
        glViewport((GLsizei) (width-height)/2 ,0 ,(GLsizei) height,(GLsizei) height);
}

void init()
{
 glMatrixMode(GL_PROJECTION);
 glLoadIdentity();
 oldX = 1.0;
 oldY = 1.0;
 glOrtho(-2.5,2.75,0,10.5, -1.0, 1.0); // adjusted for suitable viewport

}

void display(void)
{
  glClear (GL_COLOR_BUFFER_BIT);        // clear display screen

  for(int i=0; i<200000; i++){          // Maping the pixels using glVertex3f(x, y, 0) for n = 200000)
    it = rand()%100+1;                  //rand no.
    if(it<=7){

        a= -0.15; b =0.26; c =0.28; d =0.24; e =0; f=0.44;
        }
    else if(it <=14){
            a= 0.2; b =0.23; c =-0.26; d =0.22; e =0; f=1.6;


    }
    else if(it <=99){
        a= 0.85; b = -0.04; c =0.04; d =0.85; e =0; f=1.6;
    }
    else {
        a= 0; b =0; c =0; d =0.16; e =0; f=0;
    }

    x = a*oldX + c*oldY + e;            // transformations
    y = b*oldX + d*oldY + f;


    glBegin(GL_POINTS);

    glVertex3f(x, y, 0);

    glEnd();

    oldX = x ; oldY = y;
  }
  glFlush ();                           // clear buffer
}


void key(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 27 :                       // esc key to exit
        case 'q':
            exit(0);
            break;
    }

    glutPostRedisplay();
}


/* Program entry point */

int main(int argc, char *argv[])
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
   glutInitWindowSize (600, 800);                //window screen
   glutInitWindowPosition (100, 100);            //window position
   glutCreateWindow ("Program1");                //program title
   init();
   glutDisplayFunc(display);                     //callback function for display
   glutReshapeFunc(resize);                      //callback for reshape
   glutKeyboardFunc(key);                        //callback function for keyboard
   glutMainLoop();                               //loop

    return EXIT_SUCCESS;
}
