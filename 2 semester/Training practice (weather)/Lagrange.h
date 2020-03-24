#pragma once
#include <iostream>
#include <Windows.h>
#include <GL/glut.h>
using namespace std;

double Lagrange(double var)//Получает Х
{
	double s, L; //Инициализация
	double x1[12] = { 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0, 12.0 };
	double y1[12] = { -1.28, -1.13, 4.04, 7.25, 12.65, 17.61, 18.66, 21.24, 14.49, 5.36, 3.78, 1.60 };
	L = 0;
	//Вычисление коэффициентов L в формуле Лагранжа
	//Вычисление суммы L т.е. значения многочлена Лагранжа для Х
	for (int i = 0; i < 12; i++)
	{
		s = 1.0;
		for (int j = 0; j < 12; j++)
		if (j != i)
			s *= ((var - x1[j]) / (x1[i] - x1[j]));
		L += y1[i] * s;
	}
	return L;
}