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
//Прочитать одну строку из файла,если конец,то выйти из цикла.
	{
		textline.push(new string(line));
//Создать новую строку на основе старой
//Неявный вызов конструктора копирования для типа string
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