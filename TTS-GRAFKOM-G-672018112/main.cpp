#include <iostream>
#include <GL/freeglut.h>

void Render() {

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