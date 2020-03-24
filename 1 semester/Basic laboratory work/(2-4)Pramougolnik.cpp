#include <iostream>
#include <fstream>
using namespace std;

void MyInput(istream& in, int**A, int&m, int &n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			in >> A[i][j];

		cout<<endl;
	}
}
void MyOutput(ostream&out, int**A, int m, int n)
{
	out << m << n << endl;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			out << A[i][j] << " ";
		out<<endl;
	}
	out << endl;
}
void MySort (int*x,int k)
{
int min,imin=0;
for (int i=1;i<k;i++)
{
   imin=i-1;
	for (int j=i;j<k;j++)
		if (x[j]<x[imin])
			imin=j;
	min=x[imin];
	x[imin]=x[i-1];
	x[i-1]=min;
}
}
void MyInput1(istream& in, int*A, int m)
{
	for (int i = 0; i < m; i++)
			in >> A[i];
}
int main()
{
	ifstream in ("in.txt");
    ofstream out ("out.txt");
	int m,n;
	in >> m >>n;
	int **A;
	A=(int**)malloc(m*sizeof(int*));
	for (int i=0;i<m;i++)
		A[i]=(int*)malloc(n*sizeof(int));

	int A1[4],A2[4];
	MyInput(in,A,m,n);
    MyInput1(in,A1,4);//ввести 4 заданные числа в массив А1
	MyOutput(cout,A,m,n);

	MySort(A1,4);//отсортировать А1
for (int i1=0;i1<5;i1++) // сформировать 4ку в углах прямоугольника
for (int i2=i1+1;i2<5;i2++)
for (int j1=0;j1<5;j1++)
for (int j2=j1+1;j2<5;j2++) 
{

	A2[0]=A[i1][j1];//А2 вторая четверка
	A2[1]=A[i1][j2];
	A2[2]=A[i2][j1];
	A2[3]=A[i2][j2];
	MySort (A2,4); //посортировать А2

	bool flag=true;
	for (int k=0;k<4;k++)
		if(A1[k]!=A2[k]) flag=false;//сравниваем поэлементно А1 и А2
	if (flag == true)
	{
		cout << "("<<i1<<","<<j1<<")";
		cout << "("<<i2<<","<<j2<<")"<<endl;//если совпали все - ввыодим координаты (i1,j1) (i2,j2)
    for (int i=0;i<m;i++)
      free (A[i]);
    free (A);
		return 0;
	}
}
cout<<"Не найден прямоугольник"<<endl;
    for (int i=0;i<m;i++)
      free (A[i]);
    free (A);
return 0;

}
