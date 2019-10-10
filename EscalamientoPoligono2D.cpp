#include <iostream>
#include <math.h>
#include <GL/glut.h>

using namespace std;

bool dato = false;
int xi, yi, xf, yf;
int xaux = 0, yaux = 0;
float puntos[5][2] = {{-150,100},{-100,-100},{100,-100},{150,100},{0,150}};

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
					pintar(i, yi, 1, 1, 0);
				}
			}else{
				for(int i = xi; i < xf; i++){
					pintar(i, yi, 1, 1, 0);
				}
			}
		}else{
			if(m > 0){ //si tiene pendiente positiva
				if(fabs(dx) > fabs(dy)){
					if(xi > xf){
						for(int i = xf; i < xi; i++){
							v = m * i + b; //FORMULA PARA QUE SUBA LA Y
							pintar(i, v, 1, 1, 0);
						}
					}else{
						for(int i = xi; i < xf; i++){
							v = m * i + b;
							pintar(i, v, 1, 1, 0);
						}
					}	
				}else {
					if(yi > yf){
						for(int i = yf; i < yi; i++){
							v = (i - b) / m;
							pintar(v, i, 1, 1, 0);
						}
					}else{
						for(int i = yi; i < yf; i++){
							v = (i - b) / m;
							pintar(v, i, 1, 1, 0);
						}
					}
				}
			}else{ //si tiene pendiente negativa
				if(fabs(dx) > fabs(dy)){
					if(xi > xf){
						for(int i = xf; i < xi; i++){
							v = m * i + b;
							pintar(i, v, 1, 1, 0);
						}
					}else{
						for(int i = xi; i < xf; i++){
							v = m * i + b;
							pintar(i, v, 1, 1, 0);
						}
					}	
				}else {
					if(yi > yf){
						for(int i = yf; i < yi; i++){
							v = (i - b) / m;
							pintar(v, i, 1, 1, 0);
						}
					}else{
						for(int i = yi; i < yf; i++){
							v = (i - b) / m;
							pintar(v, i, 1, 1, 0);
						}
					}	
				}
			}
			
		}
	}else{ //Cuando sea una vertical
			if(yi > yf){
				for(int i = yf; i < yi; i++){
					pintar(xi, i, 0.6, 0, 0.5);
				}
			}
			else{
				for(int i = yi; i < yf; i++){
					pintar(xi, i, 0.6, 0, 0.5);
				}
			}
	}
}

void polilinea()
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
			linea();
			xi = puntos[x][0];
			yi = puntos[x][1];
		}
	}
	xi = xaux;
	yi = yaux;
	linea();
}

void ArrowKey(int key, int x, int y){
	switch(key){
		case GLUT_KEY_RIGHT:
			for(int x = 0; x < 5; x++){
				puntos[x][0] = puntos[x][0] + 20;
			}
			glClear(GL_COLOR_BUFFER_BIT);
			CoorBasic();
			polilinea();
			break;
		case GLUT_KEY_LEFT:
			for(int x = 0; x < 5; x++){
				puntos[x][0] = puntos[x][0] - 20;
			}
			glClear(GL_COLOR_BUFFER_BIT);
			CoorBasic();
			polilinea();
			break;
		case GLUT_KEY_UP:
			for(int x = 0; x < 5; x++){
				puntos[x][0] = puntos[x][0] * 1.1;
				puntos[x][1] = puntos[x][1] * 1.1;
			}
			glClear(GL_COLOR_BUFFER_BIT);
			CoorBasic();
			polilinea();
			break;
		case GLUT_KEY_DOWN:
			for(int x = 0; x < 5; x++){
				puntos[x][0] = puntos[x][0] * 0.9;
				puntos[x][1] = puntos[x][1] * 0.9;
			}
			glClear(GL_COLOR_BUFFER_BIT);
			CoorBasic();
			polilinea();
			break;
	}
}

int main(int argc, char* args[])
{
	
cout<<"-----------INSTRUCCIONES---------------"<<endl<<endl;
cout<<"Use las teclas de ARRIBA Y ABAJO para"<<endl;
cout<<"aumentar y disminuir de tamaño respectivamente";
	
	glutInit(&argc, args); //iniciamos Glut	
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);	
	glutInitWindowSize(800,600);
	glutInitWindowPosition(400,50);	
	glutCreateWindow("Traslacion");	
	gluOrtho2D(-400, 400, -300, 300);
	glutDisplayFunc(dibujar);	
	//glutMouseFunc(mouse);
	//coordenadas();
	polilinea();
	glutSpecialFunc(ArrowKey);
	glutMainLoop();
	
	return 0;
}
