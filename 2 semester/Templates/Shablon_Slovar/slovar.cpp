#include <iostream>
#include<fstream>
#include "book.h"
#include "Class.h"
using namespace std;
//сущ класс работы с бинарном файлом преврaтить в шблонный класс работы со структурами + добавить
//оператор []
//объединение, пересечение
int main()
{
	//char* xx = new char[30];
	//strcpy(xx,"ABC");
	//char* yy = new char[30];
	//strcpy(yy, "DES");
	//SF <char*> S1("ABC", yy);
	//cout << S1.first << " " << S1.second << endl;
	//S1.output();
	//cout << endl;
	setlocale (LC_ALL,".1251");
	ifstream IN("in.txt");
	book x("MA", "Levakov", 2014);
	book y("GA", "Bazilev", 2000);
	book z("DM", "Volchkova", 2007);
	SF<book>  B1("1", x);
	SF<book>  B2("2", y);
	SF<book>  B3("3", z);
	SF<book>* mas;
	mas = new SF<book>[3];
	mas[0] = B3;
	mas[1] = B1;
	mas[2] = B2;
	binary<book> c(mas, 3);
	//c.Writec();
	c.Sortfirst();
	//c.Writec();

	/*SF<book> B4;
	B4.input(IN);
	B4.output();*/

	/*book a;
	IN >> a;
	cout << a;*/

	binary<book> d(3);
	d.Read(IN);
	cout << "Проверка работы Read и Write "<<endl;
	d.Writec();
	cout << endl;
	d.Sortfirst();
	cout << "Проверка работы Sort по Key " << endl;
	d.Writec();

	/*B1 = B2;
	B1.output();*/
}