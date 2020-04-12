#include <iostream>
#include<fstream>
#include<cstring>
#include"Book.h"
#include"Info.h"
#include"Class.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, ".1251");
	book B1("Геометрия и алгебра",2015);
	book B2("Математический анализ",2007);
	book B3("Дискретная математика",2013);

	Info<book> Book1(23,B1);
	Info<book> Book2(8,B2);
	Info<book> Book3(15,B3);

	Info<book>* Mas;

	Mas=new Info<book>[3];
	Mas[0]=Book1;
	Mas[1]=Book2;
	Mas[2]=Book3;

	Class<book> C(3,Mas);
	cout<<"Начальный: "<<endl;
	C.Cprinting();
	cout<<endl<<"Отсортированные: ";
	C.sortmass();
	cout<<endl;
	C.Cprinting();
	cout<<endl;

	int l;
	cout<<"Введите ключ, по которому будем искать: "<<endl;
	cin>>l;
	book h;
	h=C.search(l);
	cout<<h<<endl;

	return 0;
}