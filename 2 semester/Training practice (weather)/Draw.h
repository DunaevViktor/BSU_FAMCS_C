#pragma once
#include <iostream>
#include"Lagrange.h"
#include <Windows.h>
#include <GL/glut.h>
using namespace std;

void Draw() //������� ���������
{
	double x; //������������� ����������

	glClear(GL_COLOR_BUFFER_BIT); //������� ����� �����
	glColor3f(0.0, 0.0, 255.0);   //���� ���� ���������

	glBegin(GL_LINES);  //�����
	glVertex2d(-50, 0); //����� ������� ��
	glVertex2d(50, 0);  //������ ������� ��
	glVertex2d(0, -50); //������ ������� ��
	glVertex2d(0, 50);  //������� ������� ��

	glVertex2d(50, 0);  //������� ������ ������� ��
	glVertex2d(47, 2);  //������ � ������ ������ ������� ��
	glVertex2d(50, 0);  //������� ������� ������� ��
	glVertex2d(47, -2); //������ � ������ ������� ������� ��

	glVertex2d(0, 50);  //������� ����� ������� ��
	glVertex2d(-2, 47); //������ � ������ ����� ������� ��
	glVertex2d(0, 50);  //������� ������ ������� ��
	glVertex2d(2, 47);  //������ � ������ ������ ������� ��
	glEnd();

	glColor3f(0, 255, 0); //���� �������
	glPointSize(2.0); //������ �����
	//������ �����
	glBegin(GL_POINTS);//�����
	for (x = 0; x < 11; x += 0.0001) //���� ��� �����
	{
		glVertex2d(x, Lagrange(x)); //�������� ����� � ������������ � � �������������� ��������� �,
		//���������� � ������� ������������ ��������
	}
	glEnd();

	glFlush();
}