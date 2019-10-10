#include <GL/glut.h>


void dibujar()
{
	glFlush();
}

void pintar(int x, int y, float R, float G, float B)
{
	glPointSize(5);
	glColor3f(R, G, B);
	glBegin(GL_POINTS);
	glVertex2f(x, y);
	glEnd();
	glutSwapBuffers();
}

void coordenadas()
{
	for(int x = -400; x<400; x++){
		pintar(x, 0, 1, 1, 0.0);
	}
	for(int y = -300; y < 300; y++){
		pintar(0, y, 1, 1, 0);
	}
	pintar(0, 0, 0, 0, 0);
}

void mouse(int btn, int state, int x, int y)
{
	x = x - 400;
	y = 300 - y;
	
	if(btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
		pintar(x, y, 1, 0, 0);
	}
}

int main(int argc, char* args[])
{
	glutInit(&argc, args); //iniciamos Glut	
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);	
	glutInitWindowSize(800,600);
	glutInitWindowPosition(50,50);	
	glutCreateWindow("Ventanita");	
	gluOrtho2D(-400, 400, -300, 300);
	glutDisplayFunc(dibujar);	
	glutMouseFunc(mouse);
	coordenadas();
	glutMainLoop();
	
	return 0;
}
