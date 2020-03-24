#include <iostream>
#include"Lagrange.h"
#include"Draw.h"
#include"Initialize.h"
#include <Windows.h>
#include <GL/glut.h>
using namespace std;

void main(int argc, char**argv)
{
	setlocale(LC_ALL, ".1251");
	cout << "Среднегодовые температуры за 2015 в Беларуси: " << endl;
	cout << "{ 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0, 12.0 }" << endl;
	cout << "{ -1.28, -1.13, 4.04, 7.25, 12.65, 17.61, 18.66, 21.24, 14.49, 5.36, 3.78, 1.60 }" << endl;

	/*double x1[12];
	double y1[12];
	for (int h = 0; h < 12; h++)
	{
		cin >> x1[h] >> y1[h];
		cout << endl;
	}*/

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(700, 600);
	glutCreateWindow("Grafik");
	glutDisplayFunc(Draw);
	Initialize();
	glutMainLoop();
}