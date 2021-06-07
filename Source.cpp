#include <GL/glut.h>

void init2D(float r, float g, float b)
{
	glClearColor(r, g, b, 0.0);
	glMatrixMode(GL_PROJECTION);//matrix mode
	gluOrtho2D(0.0, 500.0, 0.0, 500.0);//2D orthogonal projection
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 1.0, 1.0);

	//drawing multiple points
	glBegin(GL_POINTS);
	float y, x;
	for (x = -80; x < 80; x += 0.01f) {
		y = 0.5f * (x * x);
		glVertex2i(x + 50, y + 50);
	}
	glEnd();
	glFlush();//flushing
}

void main(int argc, char* argv[])
{
	glutInit(&argc, argv);//initialize GLUT
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);//display mode
	glutInitWindowSize(500, 500);//window size
	glutInitWindowPosition(100, 100);//window position
	glutCreateWindow("Quadratics Grapher in OpenGL using GL_POINTS");//creating window
	init2D(0.0, 0.0, 0.0);//Projections
	glutDisplayFunc(display);//register display callback
	glutMainLoop();//routine
}