#include<iostream>
using namespace std;
struct NotinRange
{
};
class Myvect
{
	int size;
	int *p;
public:
	Myvect()
	{
		size=10;
		p=new int[10];
	}
	Myvect(const Myvect &r)
	{
		size=r.size;
		p=new int[r.size];
		for (int i=0;i<size;i++)
			p[i]=r.p[i];
	}
	Myvect(int n)
	{
		size=n;
		p=new int[n];
	}
	int &operator [](int index)
	{
		if (index>=0&&index<size)
			return p[index];
		else
			throw NotinRange();
	}
};
int main()
{
	Myvect r;
	try
	{
		r[5]=7;
		//r[10]=r[5];
		cout<<r[5]<<endl;
	}
	catch (NotinRange)
	{
		cout<<"Error 404"<<endl;
	}
}
