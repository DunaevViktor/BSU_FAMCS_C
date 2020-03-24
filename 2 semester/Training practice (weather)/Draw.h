#pragma once
#include <iostream>
#include"Lagrange.h"
#include <Windows.h>
#include <GL/glut.h>
using namespace std;

void Draw() //Функция рисования
{
	double x; //Инициализация переменных

	glClear(GL_COLOR_BUFFER_BIT); //Выбрать буфер цвета
	glColor3f(0.0, 0.0, 255.0);   //Цвет осей координат

	glBegin(GL_LINES);  //Линии
	glVertex2d(-50, 0); //Левая граница Ох
	glVertex2d(50, 0);  //Правая граница Ох
	glVertex2d(0, -50); //Нижняя граница Оу
	glVertex2d(0, 50);  //Верхняя граница Оу

	glVertex2d(50, 0);  //Поворот нижней стрелки Ох
	glVertex2d(47, 2);  //Размер и наклон нижней стрелки Ох
	glVertex2d(50, 0);  //Поворот верхней стрелки Ох
	glVertex2d(47, -2); //Размер и наклон верхней стрелки Ох

	glVertex2d(0, 50);  //Поворот левой стрелки Оу
	glVertex2d(-2, 47); //Размер и наклон левой стрелки Оу
	glVertex2d(0, 50);  //Поворот правой стрелки Оу
	glVertex2d(2, 47);  //Размер и наклон правой стрелки Оу
	glEnd();

	glColor3f(0, 255, 0); //Цвет графика
	glPointSize(2.0); //Размер точек
	//Рисуем точки
	glBegin(GL_POINTS);//Точки
	for (x = 0; x < 11; x += 0.0001) //Цикл для точек
	{
		glVertex2d(x, Lagrange(x)); //Рисовать точку с координатами Х и соответсвующим значением У,
		//посчитаным с помощью инторполяции Лагранжа
	}
	glEnd();

	glFlush();
}