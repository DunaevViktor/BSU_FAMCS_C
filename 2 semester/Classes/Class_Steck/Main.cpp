#include "stack.h"
#include <fstream>
#include<iostream>
#include<string>
using namespace std;
int main()
{
	ifstream in("ex1.txt");
	stack textline;
	string line;
	while(getline(in,line))
//��������� ���� ������ �� �����,���� �����,�� ����� �� �����.
	{
		textline.push(new string(line));
//������� ����� ������ �� ������ ������
//������� ����� ������������ ����������� ��� ���� string
	}
	string *s;
	while(!(textline.isEmpty() ))
	{
		s=(string*)textline.pop();
		cout<< *s <<endl;
		delete s;
	}
	return 0;
}