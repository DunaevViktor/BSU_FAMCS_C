#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

class mymatrix
{
	int n, m; //m - stroki, n - stolbci
	int **A;
	int *V;
public:
	mymatrix() //konstruktor po umolchaniu
	{
		m = 3; n = 3;
		A = new int*[m];
		for (int i = 0; i<m; i++)
			A[i] = new int[n];
		V = new int[n];
		for (int i = 0; i<n; i++)
			V[i] = 1;
	}

	mymatrix(int m1, int n1)//konstruktor with int
	{
		m = m1; n = n1;
		A = new int*[m];
		for (int i = 0; i<m; i++)
			A[i] = new int[n];
		V = new int[n];
		for (int i = 0; i<n; i++)
			V[i] = 1;
	}

	mymatrix(const mymatrix& p1)//konstruktor kopirovaniya
	{
		m = p1.m; n = p1.n;
		A = new int*[m];
		for (int i = 0; i<m; i++)
			A[i] = new int[n];
		for (int i = 0; i<m; i++)
		for (int j = 0; j<n; j++)
			A[i][j] = p1.A[i][j];
		V = new int[n];
		for (int i = 0; i < n; i++) V[i] = 1;
	}

	mymatrix& operator=(const mymatrix & t)//operator =
	{
		if (this != &t)
		{
			for (int i = 0; i<m; i++)
				delete[]A[i];
			delete[]A;
			delete[]V;
			m = t.m; n = t.n;
			A = new int*[m];
			for (int i = 0; i<m; i++)
				A[i] = new int[n];
			for (int i = 0; i<m; i++)
			for (int j = 0; j<n; j++)
				A[i][j] = t.A[i][j];
			V = new int[n];
			for (int i = 0; i < n; i++) V[i] = 1;
		}
		return *this;
	}

	void input(istream &in)//function vvoda
	{
		int m1, n1;
		in >> m1 >> n1;
		if (m != m1 || n != n1)
		{
			for (int i = 0; i<m; i++)
				delete[]A[i];
			delete[]A;
			delete[]V;
			m = m1; n = n1;
			A = new int*[m1];
			for (int i = 0; i<m1; i++)
				A[i] = new int[n1];
			V = new int[n1];
			for (int i = 0; i < n1; i++) 
				V[i] = 1;
		}
		for (int i = 0; i<m1; i++)
		for (int j = 0; j<n1; j++)
			in >> A[i][j];
	}

	void output(ostream & out) //function vivoda
	{
		out << m << " " << n << endl;
		for (int i = 0; i<m; i++)
		{
			for (int j = 0; j<n; j++)
				out << A[i][j] << " ";
			out << endl;
		}
	}


	mymatrix sum(const mymatrix & t) //summa matrix
	{
		mymatrix res(t);
		if (m == t.m && n == t.n)
		{
			for (int i = 0; i<m; i++)
			for (int j = 0; j<n; j++)
				res.A[i][j] += A[i][j];
		}
		else
		{
			cout<<"No Summ";
			return res;
		}
		for (int i = 0; i<m; i++)
		{
			for (int j = 0; j<n; j++)
				cout << res.A[i][j] << " ";
			cout << endl;
		}
		return res;
	}

	mymatrix multiint(const mymatrix & t)//umnozenie na chislo
	{
		mymatrix res(t);
		int x;
		cin >> x;
		for (int i = 0; i<m; i++)
		for (int j = 0; j<n; j++)
			res.A[i][j] = x*A[i][j];
		for (int i = 0; i<m; i++)
		{
			for (int j = 0; j<n; j++)
				cout << res.A[i][j] << " ";
			cout << endl;
		}
		return res;
	}


	mymatrix multi(const mymatrix & t) //umnozenie matrix
	{
		mymatrix res(m, t.n);
		cout << m << " " << t.n << endl;
		for (int i = 0; i<res.m; i++)
		for (int j = 0; j<res.n; j++)
			res.A[i][j] = 0;
		for (int i = 0; i<m; i++)
		for (int j = 0; j<t.n; j++)
		for (int k = 0; k < n; k++)
		{
				res.A[i][j] += (A[i][k] * t.A[k][j]);
		}
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<t.n;j++)
					cout<<res.A[i][j]<<" ";
			cout<<endl;
		}
		return res;
	}


	int detL(int x)  //podschet opredelitelya
	{
		if(m!=n)
		{
			cout<<" ERROR m!=n"<<endl;
			return -1;
		}
		int sum = 0;
		int sign = 1;
		if (x == n - 1)
			for (int i = 0; i<n; i++)
				if (V[i] == 1) 
				{
					return A[x][i];
				}
		for (int i = 0; i<n; i++)
		{
			if (V[i] != 1) continue;
			else
			{
				V[i] = 0;
				sum += (A[x][i] * sign * detL(x + 1));
				V[i] = 1;
				sign = -sign;
			}
		}
		return sum;
	}

	virtual ~mymatrix() //destruktor
	{
		for (int i = 0; i<m; i++)
			delete[]A[i];
		delete[]A;
		delete[]V;
	}
};


int main()
{
	ifstream in1("in.txt");
	mymatrix m1(3,2);
	mymatrix m2(2,3);
	m1.input(in1);
	m1.output(cout);
	cout << endl;
	m2.input(in1);
	m2.output(cout);
	cout << endl<<"Sum"<<endl;
	m1.sum(m2);
	cout << endl<<"Multiply on constant"<<endl<<"Enter constant"<<endl;
	m1.multiint(m1);
	cout << endl<<"Multiply on matrix"<<endl;
	m1.multi(m2);
	cout<<endl<<"determinant";
	int det = m1.detL(0);
	cout << endl << "det = " << det << endl;

	return 0;
}
