#include<iostream>
#include<cmath>
using namespace std;

class point2D
{
protected:
	double x;
	double y;
public:
	point2D()
	{
		x=0;
		y=0;
	}
	point2D(double x1,double y1)
	{
		x=x1;
		y=y1;
	}
	point2D(const point2D &p)
	{
		x=p.x;
		y=p.x;
	}
	virtual ~point2D()
	{
	}
	friend ostream &operator <<(ostream &out,point2D &p);
	virtual double Len(const point2D &p)
	{
		return sqrt((x-p.x)*(x-p.x)+(y-p.y)*(y-p.y));
	}
};
ostream &operator <<(ostream &out,point2D &p)
{
out<<" x= "<<p.x<<" y= "<<p.y<<endl;
return out;
}

class point3D:public point2D
{
protected:
	double z;
public:
	point3D():point2D()
	{
		z=0;
	}
	point3D(double x1,double y1,double z1):point2D(x1,y1)
	{
		z=z1;
	}
	point3D(const point3D &p):point2D(p)
	{
		z=p.z;
	}
	virtual~point3D()
	{
	}
	friend ostream &operator <<(ostream &out,point3D &p);
	virtual double Len(const point2D &p)
	{
		point3D *p3=/***/(point3D*)&p;
		return sqrt((x-p3->x)*(x-p3->x)+(y-p3->y)*(y-p3->y)+(z-p3->z)*(z-p3->z));
	}
};
ostream &operator <<(ostream &out,point3D &p)
{
	out<<"x= "<<p.x<<" y= "<<p.y<<" z= "<<p.z<<endl;
	return out;
}

int main()
{
	setlocale(LC_ALL,".1251");
	double x,y,z;

    cout<<"Введите первую точку(2D):"<<endl;
	cin>>x>>y;
	point2D a(x,y);
	cout<<"Первая точка-"<<a<<endl;
	cout<<"Введите вторую точку(2D):"<<endl;
	cin>>x>>y;
    point2D b(x,y);
    cout<<"Вторая точка-"<<b<<endl;
    double res;
	point2D*f;
	f=&a;
    res=f->Len(b);
	cout<<"Расстояние: "<<res<<endl;

	
	cout<<"Введите первую точку(3D):"<<endl;
	cin>>x>>y>>z;
	point3D c(x,y,z);
	cout<<"Первая точка-"<<c<<endl;

	cout<<"Введите вторую точку(3D):"<<endl;
	cin>>x>>y>>z;
	point3D d(x,y,z);
	cout<<"Вторая точка-"<<d<<endl;
	f=&c;
	res=f->Len(d);
	cout<<"Расстояние: "<<res<<endl;

	return 0;
}

