#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;
int Sort1(double*Mas, int a);
struct full
{};

class Myset
{
	double *Mas;
	int n, size;
public:
	Myset()
	{
		size = 2;
		n = 0;
		Mas = new double[2];
	}
	Myset(int _size)
	{
		size = _size;
		n = 0;
		Mas = new double[size];
	}
	Myset(Myset &p)
	{
		size = p.size;
		n = p.n;
		Mas = new double[size];
		for (int i = 0; i<n; i++)
			Mas[i] = p.Mas[i];
	}
	virtual ~Myset()
	{
		delete[]Mas;
	}
	Myset& operator=(const Myset &p)
	{
		if (this == &p) return *this;
		size = p.size;
		n = p.n;
		delete[]Mas;
		Mas = new double[size];
		for (int i = 0; i<n; i++)
			Mas[i] = p.Mas[i];
		return *this;
	}
	Myset Union(Myset&p);
	Myset &operator =(Myset&p);
	void Add(double k);
	Myset InterSection(Myset &p);
	friend ostream& operator<<(ostream &out, const Myset&p);
	friend istream & operator >> (istream &in, Myset &p);
};
istream & operator >> (istream &in, Myset &p)
{
	int y;
	in >> y;
	if (p.size<y)
	{
		delete[]p.Mas;
		p.Mas = new double[y];
		p.size = y;
	}
	p.n = y;
	for (int i = 0; i<p.n; i++)
	{
		in >> p.Mas[i];
	}
	p.n = Sort1(p.Mas, p.n);
	return in;
}
ostream& operator<<(ostream &out, const Myset&p)
{
	for (int i = 0; i<p.n; i++)
	{
		out << p.Mas[i] << " ";
	}
	return out;
}
Myset Myset::Union(Myset &p)
{
	Myset res(size + p.size);
	int k = 0, i = 0, j = 0;
	while (i < n && j < p.n)
	{
		if (fabs(Mas[i] - p.Mas[j]) <= 1.0E-7)
		{
			res.Mas[k++] = Mas[i++];
			j++;
		}
		else
		if (Mas[i] < Mas[j])
			res.Mas[k++] = Mas[i++];
		else
			res.Mas[k++] = p.Mas[j++];
	}
	while (i < n)
		res.Mas[k++] = Mas[i++];
	while (j < p.n)
		res.Mas[k++] = p.Mas[j++];
	res.n = k;
	res.n = Sort1(res.Mas, res.n);
	return res;
}

Myset Myset::InterSection(Myset &p)
{
	Myset res(size + p.size);
	int k = 0, i = 0, j = 0;
	while (i < n && j < p.n)
	{
		if (fabs(Mas[i] - p.Mas[j]) <= 1.0E-7)
		{
			res.Mas[k++] = Mas[i++];
			j++;
		}
		else
		if (Mas[i] < Mas[j])
			i++;
		else
			j++;
	}
	res.n = k;
	res.n = Sort1(res.Mas, res.n);
	return res;
}

int cmpdouble(const void*a, const void * b)
{
	double *a1 = (double*)a;
	double *b1 = (double*)b;
	if (fabs(*a1 - *b1) <= 1.0E-7)
		return 0;
	else
	if (*a1 < *b1)
		return -1;
	else
		return 1;
}
int Sort1(double*Mas, int a)
{
	qsort(Mas, a, sizeof(double), cmpdouble);
	for (int i = 0; i<a; i++)
	{
		if (Mas[i] == Mas[i + 1])
		{
			for (int j = i + 1; j<a - 1; j++)
				Mas[j] = Mas[j + 1];
			a--;
			i--;
		}
	}
	return a;
}
Myset& Myset::operator =(Myset&p)
{
	if (this != &p)
	{
		delete[]Mas;
		n = p.n;
		Mas = new double[n];
		for (int i = 0; i<p.n; i++)
		{
			Mas[i] = p.Mas[i];
		}
	}
	return *this;
}
void Myset::Add(double k)
{
	double* d = (double*)bsearch(&k, Mas, n, sizeof(double), cmpdouble);
	if (d != NULL)
		return;
	if (n == size)
		throw full();
	for (int i = n - 1; i >= 0; i--)
	{
		if (Mas[i] < k)
		{
			Mas[++i] = k;
			n++;
			return;
		}
		else
			Mas[i + 1] = Mas[i];
	}
	Mas[0] = k;
	n++;
}
int main()
{
	ifstream in1("in.txt");
	Myset A;
	in1 >> A;
	cout <<"Mnozestvo pervoe : "<< A << endl;
	ifstream in2("in1.txt");
	Myset B;
	in2 >> B;
	cout <<"Mnozestvo vtoroe : "<<B << endl;
	Myset C = A.InterSection(B);
	cout <<"Peresechenie mnozestv : "<<C<<endl;
	Myset D = A.Union(B);
	cout <<"Union mnozestv : "<<D<<endl;
	double k;
	cout<<"Dobavit element v Pereshechenie? Kakoi?"<<endl;
	cin >> k;
	C.Add(k);
	cout <<"Peresechenie s dobavleniem : "<<C;
}