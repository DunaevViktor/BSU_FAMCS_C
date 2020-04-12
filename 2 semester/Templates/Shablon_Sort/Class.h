#include <iostream>
#include<fstream>
#include<cstring>
#include"Book.h"
#include"Info.h"
using namespace std;

template <class T>
int Firstcmp(const void* a1,const void* b1)
{
	Info<T>*a=(Info<T>*)a1;
	Info<T>*b=(Info<T>*)b1;
	return (a->key)-(b->key);
}

template <class T>
class Class
{
public:
	Info<T>* Mass;
	int n;//количество элментов
	Class()
	{
		n=1;
		Mass=new Info<T>[1];
	}
	Class(int n1)
	{
		n=n1;
		Mass=new Info<T>[n1];
	}
	Class(int n1,Info<T>* Mass1)//количество элементов и массив структур
	{
		n=n1;
		Mass=new Info<T>[n];
		for(int i=0;i<n;i++)
		{
			Mass[i]=Mass1[i];
		}
	}
	void sortmass()
	{
		
		qsort(Mass,n,sizeof(Info<T>),Firstcmp<T>);
	}
	T search (int key1)
	{
		Info<T> Look(key1);
		Info<T>*res=(Info<T>*)bsearch(&Look,Mass,n,sizeof(Info<T>),Firstcmp<T>);
	    Info<T> temp;
		if(res!=0)
		{
			temp=*res;
		}
		return temp.info;
	}
	void printing(ostream& out)
	{
		for(int i=0;i<n;i++)
		{
			Mass[i].print(out);
		}
	}
	void Cprinting()
	{
		for(int i=0;i<n;i++)
		{
			Mass[i].Cprint();
		}
	}
};