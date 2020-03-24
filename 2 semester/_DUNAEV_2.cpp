#include <fstream>
#include <string>
#include<cmath>
#include<iostream>
using namespace std;

void MinMax(int **ma,int k, int * x,int *y) //поиск наибольшей и наименьшей суммы выигрыша
	{
		*x=ma[0][2];
		*y=ma[0][2];
		for(int i=1;i<k;i++)
		{
			if(ma[i][2]<*x)
				*x=ma[i][2];
			if(ma[i][2]>*y)
				*y=ma[i][2];
		}
	}


void numlitle(int **ma,int k,int*mas,int &kol,&symMin)
{
kol=0;
int symMin=0;
	int min,max;
	MinMax(ma, k, &min, &max);
    cout << "Numbers with naimenshii viigrish: " << endl;
	for (int i = 0; i < k; i++) 
		if (ma[i][2] == min)
		{
			symMin = symMin + ma[i][2];//сумма всех наименьших
			//cout << ma[i][1] << "   ";
			mas[kol]=ma[i][1];
			kol++;
		}
		
	cout<<kol<< endl;
}

void sort(int** ma, int k) //сортировка строк матрицы 
//по элеметам втрого столбца(суммы выигрышей)
//метод пузырька
{
for (int i = 0; i < k-1; i++) 
	for (int j = i; j < k; j++)
		if (ma[i][2] < ma[j][2])
			for (int c = 0; c < 3; c++)
			{
				int t = ma[i][c];
				ma[i][c] = ma[j][c];
				ma[j][c] = t;
			}

}

int comp(const void* e1, const void* e2)
{
return*(int*)e1 - *(int *)e2;
}


int ReversNumbers(int x) // переворачивание числа
{
int rev = 0;
while (x)
{
rev = rev * 10 + (x % 10);
x = x / 10;
}
return rev;
}

void Ost(int r, int* c, int* d) //разбиение числа на номер билета и сумму выйгрыша
{
	*c = r % 10000;
	*d = r / 10000;
}

void func(int** ma, int k)
{
	for (int i = 0; i < k; i++)
	{
		int a, b;
		int rev = ReversNumbers(ma[i][0]); //переворачиваем число, чтобы последними цифрами был номер билета
		Ost(rev, &a, &b);//получаем перевернутые номер билета и сумму выигрыша
		ma[i][1] = ReversNumbers(a); // значения заносим в соответствующие столбцы матрицы
		ma[i][2] = ReversNumbers(b); // в a-номер билет , в b-сумма выигрыша
	}
}

int main()
{
	ifstream in;
	ofstream outMS, out;
	in.open("Input.txt");
	outMS.open("OutputMS.txt");
	out.open("Output.txt");
	int ** ma = new int*[20];//создаем матрицу, каждая строка - информация о номере билета  и выигрыше
	for (int i = 0; i < 20; i++)
		ma[i] = new int[3];// первый столбец - число из файла
	                       // второй - номер билета
	                       // третий - сумма выйгрыша 

	int k = 0;
	while (!in.eof())//пока не конец файла
	{
		in >> ma[k][0]; //заполняем первый столбец матрицы числами из файла
		k++;//считаем кол-во трок матрицы
	}

	func(ma, k);
	sort(ma, k);
	for (int i = 0; i < k; i++)
		outMS << ma[i][1] << "   " << ma[i][2] << endl;
	//qsort(ma[i][2],8,sizeof(int),comp);

	int min, max;
	MinMax(ma, k, &min, &max);
	out << "Наибольшая сумма выигрыша: " << max << endl;
	out << "Наименьшая сумма выигрыша: " << min << endl;

	int symMax = 0, symMin = 0;
	int sym = 0;

	out << "Номера билетов с наибольшим выигрышем: " << endl;
	for (int i = 0; i < k; i++) // вывод с наименьшим
		if (ma[i][2] == max)
		{
			symMax = symMax + ma[i][2]; //сумма всех наибольших
			out << ma[i][1] << "   ";
		}
	out << endl;
	// Место дня номеров билетов с наименьшим выйгрышем

	int *mas = new int[20];
	int u;
	numlitle(ma,ma[k][2],mas,u,symMin);
      for(int i=0;i<u;i++)
        {
		   //symMin = symMin + ma[i][2];
           cout << ma[i][1] << "   ";
        }

	out << "Номера билетов остальных: " << endl;
	for (int i = 0; i < k; i++) //вывод без наибольшего и без наименьшего
		if (ma[i][2] != min && ma[i][2] != max)
		{
			sym = sym + ma[i][2]; //сумма остальных
			out << ma[i][1] << "   ";
		}
	out<< endl;

	
	//for (int i = 0; i < k; i++)
	//{
	//	if (ma[i][2] == max)
	//		symMax = symMax + ma[i][2]; //сумма всех наибольших
	//	if (ma[i][2] == min)
	//		symMin = symMin + ma[i][2];//сумма всех наименьших
	//	else
	//		sym = sym + ma[i][2]; //сумма остальных
	//}

	out << "Сумма наибольших выигрышей: " << symMax << endl;
	out << "Сумма наименьших выигрышей: " << symMin << endl;
	out << "Сумма остальных выигрышей: " << sym << endl;
}