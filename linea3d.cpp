#include <GL/glut.h>

GLint winWidth = 600, winHeight = 600; // Tama�o inicial ventana de visualizaci�n.
GLfloat x0 = 100.0, y0 = 50.0, z0 = 50.0; // Origen coordenadas de visualizaci�n. 
GLfloat xref = 50.0, yref = 50.0, zref = 0.0; // Punto observado. 
GLfloat Vx = 0.0, Vy = 1.0, Vz = 0.0; // Vector vertical.
/* Establecer l�mites de coordenadas para ventana de recorte: */ 
GLfloat xwMin = -40.0, ywMin = -60.0, xwMax = 40.0, ywMax = 60.0;
/* Establecer posici�n de los planos de recorte pr�ximo y lejano: */ 
GLfloat dnear = 25.0, dfar = 125.0;
void init (void) 
{ 
glClearColor (1.0, 1.0, 1.0, 0.0);

glMatrixMode (GL_MODELVIEW); 
gluLookAt (x0, y0, z0, xref, yref, zref, Vx, Vy, Vz);
glMatrixMode (GL_PROJECTION); 
glFrustum (xwMin, xwMax, ywMin, ywMax, dnear, dfar);
}
void displayFcn (void) 
{ 
glClear (GL_COLOR_BUFFER_BIT);
/* Establecer par�metros para un �rea de relleno cuadrada. */ 
glColor3f (0.0, 1.0, 0.0); // Seleccionar color de relleno verde. 
glPolygonMode (GL_FRONT, GL_FILL); 
glPolygonMode (GL_BACK, GL_LINE); // Cara posterior al�mbrica. 
glBegin (GL_LINES); 
	glVertex3f (0.0, 0.0, 0.0); 
	glVertex3f (80.0, 0.0, 0.0); 
	glVertex3f (0.0, 0.0, 0.0); 
	glVertex3f (0.0, 80.0, 00); 
	glVertex3f (0.0, 0.0, 0.0); 
	glVertex3f (0.0, 0.0, 70.0);
glEnd ( ); 
glFlush ( );
}
void reshapeFcn (GLint newWidth, GLint newHeight) 
{ 
	glViewport (0, 0, newWidth, newHeight);
	winWidth = newWidth; winHeight = newHeight;
} 
main (int argc, char** argv) 
{ 
glutInit (&argc, argv); glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB); 
glutInitWindowPosition (50, 50); 
glutInitWindowSize (winWidth, winHeight); 
glutCreateWindow ("Perspective View of A Square");
init ( ); 
glutDisplayFunc (displayFcn); 
glutReshapeFunc (reshapeFcn); 
glutMainLoop ( );
}

