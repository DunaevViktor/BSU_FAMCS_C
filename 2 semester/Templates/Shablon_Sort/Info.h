#pragma once
#include <iostream>
#include<fstream>
#include<cstring>
#include"Book.h"
using namespace std;

template <class T>
struct Info
{
	int key;
	T info;
	Info()
	{
		key=0;
		T temp;
		info=temp;
	}
	Info(int k,T i)
	{
		key=k;
		info=i;
	}
	Info(int k)
	{
		key=k;
		T temp;
		info=temp;
	}
	Info& operator = (Info&k)
	{
		if(this!=&k)
		{
		key=k.key;
		info=k.info;
		}
		return *this;
	}
	void Cprint()
	{
		cout<<key<<" "<<info<<endl;
	}
	void print (ostream&out)
	{
		out<<key<<" "<<info<<endl;
	}
	bool operator <(Info&a)
	{
		if(key<a->key)return true;
		else return false;
	}
};