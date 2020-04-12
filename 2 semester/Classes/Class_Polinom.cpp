#include<iostream>
#include<cmath>
using namespace std;
struct ODN
{
double k;
int st;
};
class polinom
{
int n; //Количество одночленов в полиноме
ODN *mas; //Массив k и st(* - так как память выделяется динамически)
public:
	void Sokr();
	polinom (int m)
	{
		n=m;
mas=new ODN[m];
for (int i=0;i<m;i++)
{
mas[i].k=0;
mas[i].st=0;
}
	}

polinom(); //Создание вырожденного полинома (0;0)
           //Конструктор по умолчанию
polinom(polinom &p); //Оператор копирования
friend istream &operator >>(istream &in, polinom &p);
friend ostream &operator <<(ostream &out, polinom &p);
friend polinom operator +(polinom &p1, polinom &p2);
polinom &operator +=(polinom &p);
polinom &operator =(polinom &p)
{
delete []mas;
n=p.n;
mas=new ODN[n];
for (int i=0;i<n;i++)
{
	mas[i]=p.mas[i];
}
return *this;
}
~polinom()
{
delete[]mas;
}
void print()
{
	for(int i=0;i<n;i++)
	{
		cout<<mas[i].k<<"x^"<<mas[i].st<<" ";
	}
}
};
polinom::polinom()
{
n=1;
mas=new ODN[n];
mas[0].k=0;
mas[0].st=0;
}
polinom::polinom(polinom &p)
{
n=p.n;
mas=new ODN[n];
for(int i=0;i<n;i++)
{
mas[i]=p.mas[i];
}
}
istream &operator >>(istream &in, polinom &p)
{
in>>p.n;
delete[]p.mas;
p.mas=new ODN[p.n];
for(int i=0;i<p.n;i++)
{
in>>p.mas[i].k;
in>>p.mas[i].st;
}
return in;
}
ostream &operator <<(ostream &out, polinom &p)
{
	if((p.n==1) && (fabs(p.mas[0].k)<=0.00001))
	{
		out<<0<<endl;
		return out;
	}
	else 
	{
	int i=0;
for( int i1=0;i1<p.n;i1++)
{  i=i1;
	out<<p.mas[i].k<<"x^";
	out<<p.mas[i].st;
	if (i<p.n-1)
		cout<<"+";
}
return out;
	}
}
void polinom::Sokr()
{
int count=0;  // кол нулей
ODN *mas2;
	for(int i=0;i<n;i++)
	{
		if(fabs(mas[i].k)<=0.00001)
		{
			count++;
		}
	}
	if(count==0)
		return;
	if(count!=n)  // не все нулевые
	{
		mas2=new ODN[n-count];
		int count2=0;
		for(int i=0;i<n;i++)
		{
			if(fabs(mas[i].k)>=0.00001)
			{
				mas2[count2]=mas[i];
				count2++;
			}
		}
		n=count2;
	}
	else   // все нулевые
	{
		mas2=new ODN[1];
		n=1;
		mas2[0].k=0;
		mas2[0].st=0;
	}
	delete[]mas;	
	mas=mas2;


}


polinom operator +(polinom &A, polinom &B)
{
       int i=0,j=0,l=0;
	   polinom C(A.n+B.n);
	while(i<A.n && j<B.n)
	{
		if(A.mas[i].st>B.mas[j].st)
		{
			C.mas[l]=B.mas[j];
			j++;
			l++;
		}
        if(A.mas[i].st==B.mas[j].st)
		{
			C.mas[l].k=B.mas[j].k+A.mas[i].k;
			C.mas[l].st=B.mas[j].st;
			j++;
			i++;
			l++;
		}
        if(A.mas[i].st<B.mas[j].st)
		{
			C.mas[l]=A.mas[i];
			i++;
			l++;
		}
	}
	while(i<A.n)
	{
		C.mas[l]=A.mas[i];
		i++;
		l++;
	}
	while(j<B.n)
	{
		C.mas[l]=B.mas[j];
		j++;
		l++;
	}
	
	C.n=l;
	C.Sokr();
	return C;
}


int main()
{
polinom p1;
cout<<"Vvedite kolychestvo odnochlenov?"<<endl;
cout<<"Vvedite koefficienti odnochlenov?(kol,stepen)"<<endl;
cin>>p1;
cout<<"Polinom1: "<<p1<<endl;
p1.Sokr();
cout<<"Sokr: "<<p1<<endl;

polinom p2;
cout<<"Vvedite kolychestvo odnochlenov?"<<endl;
cout<<"Vvedite koefficienti odnochlenov?(kol,stepen)"<<endl;
cin>>p2;
cout<<"Polinom1: "<<p2<<endl;
p2.Sokr();
cout<<"Sokr: "<<p2<<endl;

polinom p3;
p3=p1+p2;
cout<<"Summa = ";
cout<<p3;
cout<<endl;
return 0;
}



















