#include<stdio.h>
#include <iostream>
#include<GL/gl.h>
#include <GL/glut.h>
#include<math.h>
using namespace std;

int cx,cy;
int r;


int p0 = 1 - r;

void plot(int cx,int cy){
	glClear (GL_COLOR_BUFFER_BIT);
	glColor3f (1.0, 0.0, 0.0);
	glPointSize(1.0);
	glBegin(GL_POINTS);
	glVertex2i(cx,cy);

	}


void myDisplay(void){
    int x = 0;
    int y = r;
    plot(cx+x,cy+y);
    plot(cx+y,cy+x);
    plot(cx+x,cy-y);
    plot(cx-y,cy+x);
    for(int i=0; i<y; i++){
	if(p0<0){

		x = x + 1;
		plot(cx+x,cy+y);
		plot(cx+y,cy+x);
		plot(cx+y,cy-x);
		plot(cx+x,cy-y);

        plot(cx-x,cy+y);
		plot(cx-y,cy+x);
		plot(cx-y,cy-x);
        plot(cx-x,cy-y);


		cout<<cx+x<<" "<<cy+y<<" "<<endl;
		p0 = p0 + 2*(x-1) + 3;
        cout<<p0<<" ";

		}
	else {

		x = x+1;
		y = y-1;
		plot(cx+x,cy+y);
		plot(cx+y,cy+x);
		plot(cx+y,cy-x);
        plot(cx+x,cy-y);

        plot(cx-x,cy+y);
		plot(cx-y,cy+x);
		plot(cx-y,cy-x);
        plot(cx-x,cy-y);


		cout<<cx+x<<" "<<cy+y<<" "<<endl;
		p0 = p0 + 2*(x-1-y-1)+ 5;
		cout<<p0<<" ";

		}


    }

    //cout<<x<<" "<<y<<endl;
    glEnd();
	glFlush();

}

void myInit (void)
{
glClearColor(1.0, 1.0, 1.0, 0.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}

int main(int argc, char** argv)
{

cout<<"Enter the x-point for the center:"<<endl;
cin>>cx;
cout<<"Enter the y-point for the center:"<<endl;
cin>>cy;
cout<<"Now enter the radius:"<<endl;
cin>>r;
p0 = 1 -r;
cout<<"Now look at the window"<<endl;

glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize (640, 480);
glutInitWindowPosition (300, 200);
glutCreateWindow ("");
glutDisplayFunc(myDisplay);
myInit ();
glutMainLoop();

}
