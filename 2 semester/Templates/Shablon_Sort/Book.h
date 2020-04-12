#pragma once
#include <iostream>
#include<fstream>
#include<cstring>
using namespace std;

struct book
{
	char name[30];
	int year;
	book()
	{
		strcpy(name,"Пустая книга");
		year=0;
	}
	book(char* name1,int year1)
	{
		strcpy(name,name1);
		year=year1;
	}
	friend ostream& operator <<(ostream&out, book&b);
	
};
ostream& operator <<(ostream&out, book&b)
	{
		out<<b.name<<" "<<b.year;
		return out;
	};
