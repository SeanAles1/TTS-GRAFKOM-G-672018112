#define _USE_MATH_DEFINES
#include <iostream>
#include <GL/freeglut.h>
#include <math.h>

int x = 0;
int y = 0;
int xLingkaran = 35;
int yLingkaran = 12;

void Pola1() {
	glColor3ub(255, 238, 204);
	glBegin(GL_POLYGON);
	//Kotak Putih
	glVertex2f(51 + x, 121 + y);
	glVertex2f(86 + x, 51 + y);
	glVertex2f(151 + x, 86 + y);
	glVertex2f(116 + x, 151 + y);
	glEnd();

	//Kotak - Hitam
	glColor3ub(0, 0, 0);
	glBegin(GL_POLYGON);

	glVertex2f(86 + x, 85 + y);
	glVertex2f(86 + x, 121 + y);
	glVertex2f(116 + x, 121 + y);
	glVertex2f(116 + x, 85 + y);
	glEnd();

	//Garis
	glColor3ub(0, 0, 0);
	glBegin(GL_LINES);
	//1
	glVertex2f(86 + x, 121 + y);
	glVertex2f(51 + x, 121 + y);
	//2
	glVertex2f(87 + x, 51 + y);
	glVertex2f(87 + x, 85 + y);
	//3
	glVertex2f(151 + x, 86 + y);
	glVertex2f(116 + x, 86 + y);
	//4
	glVertex2f(116 + x, 151 + y);
	glVertex2f(116 + x, 121 + y);

	glEnd();
}

void Pola2() {
	glColor3ub(255, 238, 204);
	glBegin(GL_POLYGON);

	//Kotak Putih
	glVertex2f(151 + x, 86 + y);
	glVertex2f(216 + x, 51 + y);
	glVertex2f(251 + x, 121 + y);
	glVertex2f(186 + x, 151 + y);

	glEnd();

	//Kotak - Hitam
	glColor3ub(0, 0, 0);
	glBegin(GL_POLYGON);

	glVertex2f(186 + x, 85 + y);
	glVertex2f(186 + x, 121 + y);
	glVertex2f(216 + x, 121 + y);
	glVertex2f(216 + x, 85 + y);
	glEnd();

	//Garis
	glColor3ub(0, 0, 0);
	glBegin(GL_LINES);

	//1
	glVertex2f(151 + x, 86 + y);
	glVertex2f(186 + x, 86 + y);
	//2
	glVertex2f(216 + x, 51 + y);
	glVertex2f(216 + x, 85 + y);
	//3
	glVertex2f(251 + x, 121 + y);
	glVertex2f(216 + x, 121 + y);
	//4
	glVertex2f(187 + x, 151 + y);
	glVertex2f(187 + x, 121 + y);

	glEnd();
}

void Pola3() {
	glColor3ub(255, 238, 204);
	glPointSize(2);
	glBegin(GL_POLYGON);

	//Kotak Putih
	glVertex2f(1 + x, 11.5 + y);
	glVertex2f(20.5 + x, 1 + y);
	glVertex2f(30 + x, 22 + y);
	glVertex2f(10.5 + x, 30 + y);

	glEnd();

	//Kotak - Hitam
	glColor3ub(0, 0, 0);
	glBegin(GL_POLYGON);

	glVertex2f(10.5 + x, 11.5 + y);
	glVertex2f(10.5 + x, 22 + y);
	glVertex2f(20.5 + x, 22 + y);
	glVertex2f(20.5 + x, 11.5 + y);
	
	glEnd();

	//Garis
	glColor3ub(0, 0, 0);
	glBegin(GL_LINES);

	//1
	glVertex2f(1 + x, 11.5 + y);
	glVertex2f(10.5 + x, 11.5 + y);
	//2
	glVertex2f(19.5 + x, 1 + y);
	glVertex2f(19.5 + x, 11.5 + y);
	//3
	glVertex2f(30 + x, 22 + y);
	glVertex2f(19.5 + x, 22 + y);
	//4
	glVertex2f(10.5 + x, 30 + y);
	glVertex2f(10.5+ x, 20.5 + y);

	glEnd();
}

void Pola4() {
	glColor3ub(255, 238, 204);
	glPointSize(0.000001f);
	glBegin(GL_POINTS);

	//Kotak Putih
	for (int i = 1; i <= 30; i++) {
		glVertex2f(0 + x, 12.5 + y);
		x += 30;
	}
	x = 0;
	y = 0;
	glEnd();
}

void Pola5(double r, int vertex) {
	double ngon = (double)vertex;
	//Algoritma Orbit
	glBegin(GL_LINE_LOOP);
	glColor3ub(103, 103, 103);
	for (int i = 0; i < vertex; i++) {
		double a = r * cos(2 * M_PI * i / vertex);
		double b = r * sin(2 * M_PI * i / vertex);
		glVertex2d(a + xLingkaran, b + yLingkaran);
	}
	glEnd();
}

void Render() {
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	//Layer 1
	Pola1();
	Pola2();
	x += 200;
	Pola1();
	Pola2();

	x = 0;
	//Layer 2
	y = 100;
	x -= 100;
	Pola2();
	x += 200;
	Pola1();
	Pola2();
	x += 200;
	Pola1();

	x = 0;
	y = 0;
	//Layer 3
	y = 200;
	Pola1();
	Pola2();
	x += 200;
	Pola1();
	Pola2();

	x = 0;
	y = 0;
	//Layer 4
	y = 300;
	x -= 100;
	Pola2();
	x += 200;
	Pola1();
	Pola2();
	x += 200;
	Pola1();

	x = 0;
	y = 0;

	//kotak pojok - 1
	Pola3();
	//kotak pojok - 2
	x += 470;
	Pola3();
	
	x = 0;
	y = 0;
	//kotak pojok - 3
	x = 0;
	y += 470;
	Pola3();

	x = 0;
	y = 0;
	//kotak pojok - 4
	x += 470;
	y += 470;
	Pola3();

	x = 0;
	y = 0;

	//Titik
	for (int j = 1; j <= 60 ; j += 2) {
		Pola4();
		y = y + 10*j;
	}
	
	x = 0;
	y = 0;
	
	//Design Backround
	for (int k = 1; k <= 15; k++) {
		Pola5(7, 300);
		xLingkaran += 30;
	}
	xLingkaran = 52;
	//Design Backround
	yLingkaran += 14;
	for (int k = 1; k <= 14; k++) {
		Pola5(7, 300);
		xLingkaran += 30;
	}
	xLingkaran = 8;
	yLingkaran += 14;
	for (int k = 1; k <= 17; k++) {
		Pola5(7, 300);
		xLingkaran += 30;
	}
	xLingkaran = 22;
	yLingkaran += 14;
	for (int k = 1; k <= 16; k++) {
		if (k >= 1 && k <=2 || k >= 4 && k <= 6 || k >= 8 && k <= 9 || k > 10 && k <= 13 || k >= 15 && k <= 16) {
			Pola5(7, 300);
		}
		xLingkaran += 30;
	}
	xLingkaran = 8;
	yLingkaran += 14;
	for (int k = 1; k <= 17; k++) {
		if (k >= 1 && k <= 3 || k >= 6 && k <= 6 || k == 9 || k >= 12 && k <= 13  ||k >= 16 && k <= 17) {
			Pola5(7, 300);
		}
		xLingkaran += 30;
	}
	xLingkaran = 22;
	yLingkaran += 14;
	for (int k = 1; k <= 17; k++) {
		if (k >= 1 && k <= 2 || k == 9 || k >= 15 && k <= 16) {
			Pola5(7, 300);
		}
		xLingkaran += 30;
	}
	xLingkaran = 8;
	yLingkaran += 14;
	for (int k = 1; k <= 17; k++) {
		if (k >= 1 && k <= 2 || k == 9 || k >= 16 && k <= 17) {
			Pola5(7, 300);
		}
		xLingkaran += 30;
	}
	xLingkaran = 35;
	yLingkaran = 12;
	glFlush();
}

int main(int argc, char** argv) {
	//Inisialisasi Program
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Sean Alessandro Pattirane - 672018112");
	glutDisplayFunc(Render);
	glEnable(GL_POINT_SMOOTH);
	gluOrtho2D(0, 500, 500, 0);
	//Selesai Inisialisasi
	glutMainLoop();
}