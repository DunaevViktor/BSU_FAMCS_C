#pragma once
#include <iostream>
#include<fstream>
using namespace std;

struct book
{
	char name[50];
	char author[50];
	int year;
	char temp[10];
	book()
	{
		strcpy(name, "Empty");
	}
	book(char* n, char* a, int y)
	{
		strcpy(name, n);
		strcpy(author, a);
		year = y;
	}
	friend ostream& operator <<(ostream &out, book &b);
	friend istream& operator >>(istream &in, book &b);
};
ostream& operator <<(ostream &out, book &b)
{
	out << b.name << " " << b.author << " " << b.year << endl;
	return out;
}
istream& operator >>(istream &in, book &b)
{
	in.getline(b.name, 49, '|');
	in.getline(b.author, 49, '|');
	in.getline(b.temp, 9, '\n');
	b.year = atoi(b.temp);
	return in;
}