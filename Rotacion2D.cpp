#include <iostream>
#include <math.h>
#include <GL/glut.h>

using namespace std;

bool dato = false;
int xi, yi, xf, yf;
int xaux = 0, yaux = 0;
float puntos[5][2] = {{-150,100},{-100,-100},{100,-100},{150,100},{0,150}};
int angulo = 1;
int pi = 3.1416;

void dibujar()
{
	glFlush();
}

void pintar(int x, int y, float R, float G, float B)
{
	glPointSize(3);
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

void CoorBasic()
{
	pintar(0, 0, 1, 0, 0);
	pintar(-4, 0, 1, 0, 0);
	pintar(0, 4, 1, 0, 0);
	pintar(0, -4, 1, 0, 0);
	pintar(4, 0, 1, 0, 0);
}

void linea(float r, float g, float b){
	float m=0, dx = 0, dy = 0, B = 0, v = 0; // valor de la funcion.
	dx = xf - xi;
	dy = yf - yi;
	if(dx != 0){
		m = dy / dx;  //CALCULO DE LA PENDIENTE
		B = yi - (m*xi);  //FORMULA PARA "Y"
		if(dy == 0){ //si es una linea horizontal
			if(xi > xf){
				for(int i = xf; i < xi; i++){
					pintar(i, yi, r, g, b);
				}
			}else{
				for(int i = xi; i < xf; i++){
					pintar(i, yi, r, g, b);
				}
			}
		}else{
			if(m > 0){ //si tiene pendiente positiva
				if(fabs(dx) > fabs(dy)){
					if(xi > xf){
						for(int i = xf; i < xi; i++){
							v = m * i + B; //FORMULA PARA QUE SUBA LA Y
							pintar(i, v, r, g, b);
						}
					}else{
						for(int i = xi; i < xf; i++){
							v = m * i + B;
							pintar(i, v, r, g, b);
						}
					}	
				}else {
					if(yi > yf){
						for(int i = yf; i < yi; i++){
							v = (i - B) / m;
							pintar(v, i, r, g, b);
						}
					}else{
						for(int i = yi; i < yf; i++){
							v = (i - B) / m;
							pintar(v, i, r, g, b);
						}
					}
				}
			}else{ //si tiene pendiente negativa
				if(fabs(dx) > fabs(dy)){
					if(xi > xf){
						for(int i = xf; i < xi; i++){
							v = m * i + B;
							pintar(i, v, r, g, b);
						}
					}else{
						for(int i = xi; i < xf; i++){
							v = m * i + B;
							pintar(i, v, r, g, b);
						}
					}	
				}else {
					if(yi > yf){
						for(int i = yf; i < yi; i++){
							v = (i - B) / m;
							pintar(v, i, r, g, b);
						}
					}else{
						for(int i = yi; i < yf; i++){
							v = (i - B) / m;
							pintar(v, i, r, g, b);
						}
					}	
				}
			}
			
		}
	}else{ //Cuando sea una vertical
			if(yi > yf){
				for(int i = yf; i < yi; i++){
					pintar(xi, i, r, g, b);
				}
			}
			else{
				for(int i = yi; i < yf; i++){
					pintar(xi, i, r, g, b);
				}
			}
	}
}

void poligono()
{
	
		xaux = puntos[0][0];
		yaux = puntos[0][1];
	for(int x = 0; x < 5; x++){
			
		if(x == 0){
			xi = xaux;
			yi = yaux;
		}else{
			xf = puntos[x][0];
			yf = puntos[x][1];
			linea(1, 1, 0);
			xi = puntos[x][0];
			yi = puntos[x][1];
		}
	}
	xi = xaux;
	yi = yaux;
	linea(1, 0, 0);
}

void ArrowKey(int key, int x, int y){
	
	switch(key){
		case GLUT_KEY_RIGHT:
			for(int rote = 0; rote <20; rote++){
				for(int x = 0; x < 5; x++){
				puntos[x][0] = (puntos[x][0] * (cos(((angulo * 3.1416) / 180)))) - (puntos[x][1] * (sin(((angulo * 3.1416) / 180))));
				puntos[x][1] = puntos[x][0] * (sin((angulo * 3.1416) / 180)) + puntos[x][1] * (cos((angulo * 3.1416) / 180));
				//cout<<"x:"<<puntos[x][0]<<" y:"<<puntos[x][1]<<endl;
				round(puntos[x][0]);
				round(puntos[x][0]);
				}
				
			}
			
			cout<<endl;
			glClear(GL_COLOR_BUFFER_BIT);
			CoorBasic();
			poligono();
			break;
		case GLUT_KEY_LEFT:
			for(int rote = 0; rote <20; rote++){
				for(int x = 0; x < 5; x++){
				puntos[x][0] = (puntos[x][0] * (cos(((-angulo * 3.1416) / 180)))) - (puntos[x][1] * (sin(((-angulo * 3.1416) / 180))));
				puntos[x][1] = puntos[x][0] * (sin((-angulo * 3.1416) / 180)) + puntos[x][1] * (cos((-angulo * 3.1416) / 180));
				round(puntos[x][0]);
				round(puntos[x][0]);
				}
			}
			
			cout<<endl;
			glClear(GL_COLOR_BUFFER_BIT);
			CoorBasic();
			poligono();
			break;
		case GLUT_KEY_UP:
			for(int x = 0; x < 5; x++){
				puntos[x][1] = puntos[x][1] + 20;
			}
			glClear(GL_COLOR_BUFFER_BIT);
			CoorBasic();
			poligono();
			break;
		case GLUT_KEY_DOWN:
			for(int x = 0; x < 5; x++){
				puntos[x][1] = puntos[x][1] - 20;
			}
			glClear(GL_COLOR_BUFFER_BIT);
			CoorBasic();
			poligono();
			break;
	}
}

int main(int argc, char* args[])
{
	
	glutInit(&argc, args); //iniciamos Glut	
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);	
	glutInitWindowSize(800,600);
	glutInitWindowPosition(400,50);	
	glutCreateWindow("Traslacion");	
	gluOrtho2D(-400, 400, -300, 300);
	glutDisplayFunc(dibujar);	
	//glutMouseFunc(mouse);
	//coordenadas();
	poligono();
	glutSpecialFunc(ArrowKey);
	glutMainLoop();
	
	return 0;
}
