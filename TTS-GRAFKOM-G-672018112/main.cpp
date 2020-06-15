#include <iostream>
#include <GL/freeglut.h>

int x = 0;
int y = 0;

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
	;	y = 100;
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

	glFlush();
}

int main(int argc, char** argv) {
	//Inisialisasi Program
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Sean Alessandro Pattirane - 672018112");
	glutDisplayFunc(Render);
	gluOrtho2D(0, 500, 500, 0);
	//Selesai Inisialisasi
	glutMainLoop();
}