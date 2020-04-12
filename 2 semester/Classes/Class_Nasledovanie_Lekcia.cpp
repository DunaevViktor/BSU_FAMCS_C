#include<iostream>
using namespace std;
class base
{
public:
	base()
	{
        cout<<"Konstruktor base"<<endl;
	}
	virtual~base()
	{
		cout<<"Destruktor base"<<endl;
	}
};
class derived:public base
{
public:
	derived(void)
	{
		cout<<"Konstruktor proizvodnoi"<<endl;
	}
	virtual~derived()
	{
		cout<<"Destruktor proizvodnoi"<<endl;
	}
};
int main()
{
	derived A;
	return 0;
}
/*
class Tc1
{
public:
	int a;
};
class Tc2
{
public:
		float a;
};
class Tc3: public Tc1 public Tc2
{
};
int main()
{
	Tc3 c3;
	count<<c3.Tc2::a;
}
*/
/*
class derived:public base
{
	cls obj1;
public:
	derived(void);
	derived(const derived &d);
	virtual~derived();
	derived &operator =(const derived &d)
};
derived::derived(void):base()
{
	obj1=value;
}
derived::derived(const derived &d):base(d)
{
	obj1=d.obj1;
}
derived &derived::operator =(const derived &d)
{
	if(this!&d)
	{
		*((base*)this)=d;
		obj1=d.obj1;
	}
	return *this;
}
*/

