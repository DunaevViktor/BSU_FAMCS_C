#pragma once
#include <iostream>
#include<fstream>
#include "book.h"
using namespace std;

template <class T>
struct SF
{
	char first[30];
	T second;
public:
	void FC(char*f, T s)
	{
		strcpy(first, f);
		memcpy((char*)&second, (char*)&s, sizeof(T));
	}
	SF(char*f, T&s)
	{
		FC(f, s);
	}
	SF()
	{
		T c;
		FC("Empty", c);
	}
	SF(SF&node)
	{
		FC(node.first, node.second);
	}
	friend bool operator<(SF&A, SF&B)
	{
		if (strcmp(A->first, B->first) < 0)
			return true;
		else return false;
	}
	friend bool operator==(SF&A, SF&B)
	{
		if (strcmp(A->first, B->first) == 0)
			return true;
		else return false;
	}
	SF& operator=(SF&A)
	{
		if (this != &A)
			FC(A.first, A.second);
		return *this;
	}
	void output()
	{
		cout << first << " " << second;
	}
	void input(istream &in)
	{
		in.getline(first, 29, '|');
		in >> second;
	}

};
template <class T>
int firstcmp(const void*a1, const void*b1)
{
	SF<T> *a = (SF<T>*)a1;
	SF<T> *b = (SF<T>*)b1;
	int a2 = atoi(a->first);
	int b2 = atoi(b->first);
	return a2 - b2; //b2-a2
}
template<class T2>
class binary
{
	SF<T2>* mas;//массив структур у которых темплейт это т2
	int n;
public:
	binary()
	{
		n = 1;
		mas = new SF<T2>[1];
	}
	binary(SF<T2>* a, int n1)
	{
		n = n1;
		mas = new SF<T2>[n1];
		for (int i = 0; i < n1; i++)
		{
			mas[i] = a[i];
		}
	}
	binary(int n1)
	{
		n = n1;
		mas = new SF<T2>[n1];
	}
	void Read(istream &in)
	{
		int s = 0;
		while (!in.eof() && (s<n))
		{
			mas[s].input(in);
			s++;
			if (in.bad())
				break;
		}
		n = s;
	}
	void Sortfirst()
	{
		qsort(mas, n, sizeof(SF<T2>), firstcmp<T2>);//??
	}
	void Write(char* filename)
	{
		ofstream out;
		out.open(filename, ios::binary);
		for (int i = 0; i < n; i++)
		{
			out.write((char*)&mas[i], sizeof(SF));
		}
		out.close();
	}
	void Writec()
	{
		for (int i = 0; i < n; i++)
		{
			cout <<" люч: "<< mas[i].first <<" "<< " нига: " << mas[i].second;
		}
	}
	~binary()
	{
		delete[]mas;
	}
};
template<>
void SF<char*>::FC(char*f, char*s)
{
	strcpy(first, f);
	second = new char[30];
	strcpy(second, s);
}
