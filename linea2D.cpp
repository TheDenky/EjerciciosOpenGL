#include <math.h>
#include <GL/glut.h>

int w=800, h=600;
int xi=0, yi=0, xf = 0, yf=0;
bool dato = false;

void pixel(int x, int y, float r, float g, float b)
{
	glPointSize(4);
	glColor3f(r, g, b);
	glBegin(GL_POINTS);
	glVertex2f(x, y);
	glEnd();
	glutSwapBuffers();
}

void plano()
{
	for(int i = -w / 2 ; i < w / 2; i++){
		pixel(i, 0, 1, 1, 1);
	}
	for(int i = -h / 2; i < h / 2; i++){
		pixel(0, i, 1, 1, 1);
	}
	pixel(0, 0, 0, 0, 0);
}

void display()
{
	
}

void linea(){
	float m=0, dx = 0, dy = 0, b = 0, v = 0; // valor de la funcion.
	dx = xf - xi;
	dy = yf - yi;
	if(dx != 0){
		m = dy / dx;  //CALCULO DE LA PENDIENTE
		b = yi - (m*xi);  //FORMULA PARA "Y"
		if(dy == 0){ //si es una linea horizontal
			if(xi > xf){
				for(int i = xf; i < xi; i++){
					pixel(i, yi, 0.6, 0, 0.5);
				}
			}else{
				for(int i = xi; i < xf; i++){
					pixel(i, yi, 0.6, 0, 0.5);
				}
			}
		}else{
			if(m > 0){ //si tiene pendiente positiva
				if(fabs(dx) > fabs(dy)){
					if(xi > xf){
						for(int i = xf; i < xi; i++){
							v = m * i + b; //FORMULA PARA QUE SUBA LA Y
							pixel(i, v, 0.6, 0, 0.5);
						}
					}else{
						for(int i = xi; i < xf; i++){
							v = m * i + b;
							pixel(i, v, 0.6, 0, 0.5);
						}
					}	
				}else {
					if(yi > yf){
						for(int i = yf; i < yi; i++){
							v = (i - b) / m;
							pixel(v, i, 0.6, 0, 0.5);
						}
					}else{
						for(int i = yi; i < yf; i++){
							v = (i - b) / m;
							pixel(v, i, 0.6, 0, 0.5);
						}
					}
				}
			}else{ //si tiene pendiente negativa
				if(fabs(dx) > fabs(dy)){
					if(xi > xf){
						for(int i = xf; i < xi; i++){
							v = m * i + b;
							pixel(i, v, 0.6, 0, 0.5);
						}
					}else{
						for(int i = xi; i < xf; i++){
							v = m * i + b;
							pixel(i, v, 0.6, 0, 0.5);
						}
					}	
				}else {
					if(yi > yf){
						for(int i = yf; i < yi; i++){
							v = (i - b) / m;
							pixel(v, i, 0.6, 0, 0.5);
						}
					}else{
						for(int i = yi; i < yf; i++){
							v = (i - b) / m;
							pixel(v, i, 0.6, 0, 0.5);
						}
					}	
				}
			}
			
		}
	}else{ //Cuando sea una vertica
			if(yi > yf){
				for(int i = yf; i < yi; i++){
					pixel(xi, i, 0.6, 0, 0.5);
				}
			}
			else{
				for(int i = yi; i < yf; i++){
					pixel(xi, i, 0.6, 0, 0.5);
				}
			}
	}
}

void mouse(int btn, int state, int x, int y)
{
	y = (h / 2) - y;
	x = x - (w / 2);
	if(dato == false){
		if(btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
			xi = x;
			yi = y;
			pixel(xi, yi, 0.6, 0.4, 0.7);
			dato = true;
		}
	}
	else {
		if(btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
			xf = x;
			yf = y;
			pixel(xf, yf, 0, 0, 0.4);
			dato = false;
			linea();
		}
	}
}

int main(int argc, char * argv[]){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(w, h);
	glutInitWindowPosition(200, 100);
	glutCreateWindow("Linea");
	gluOrtho2D( -w / 2, w / 2, -h / 2, h / 2);
	glutMouseFunc(mouse);
	glutDisplayFunc(display);
	plano();
	glutMainLoop();
	return 0;
}
