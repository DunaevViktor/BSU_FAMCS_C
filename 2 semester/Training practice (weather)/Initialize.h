#pragma once
#include <iostream>
#include"Lagrange.h"
#include"Draw.h"
#include <Windows.h>
#include <GL/glut.h>
using namespace std;

void Initialize()//Инициализация окна
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-50, 50, -50, 50);//Размер рабочей области
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
