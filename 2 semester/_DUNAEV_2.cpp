#include <fstream>
#include <string>
#include<cmath>
#include<iostream>
using namespace std;

void MinMax(int **ma,int k, int * x,int *y) //����� ���������� � ���������� ����� ��������
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
			symMin = symMin + ma[i][2];//����� ���� ����������
			//cout << ma[i][1] << "   ";
			mas[kol]=ma[i][1];
			kol++;
		}
		
	cout<<kol<< endl;
}

void sort(int** ma, int k) //���������� ����� ������� 
//�� �������� ������ �������(����� ���������)
//����� ��������
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


int ReversNumbers(int x) // ��������������� �����
{
int rev = 0;
while (x)
{
rev = rev * 10 + (x % 10);
x = x / 10;
}
return rev;
}

void Ost(int r, int* c, int* d) //��������� ����� �� ����� ������ � ����� ��������
{
	*c = r % 10000;
	*d = r / 10000;
}

void func(int** ma, int k)
{
	for (int i = 0; i < k; i++)
	{
		int a, b;
		int rev = ReversNumbers(ma[i][0]); //�������������� �����, ����� ���������� ������� ��� ����� ������
		Ost(rev, &a, &b);//�������� ������������ ����� ������ � ����� ��������
		ma[i][1] = ReversNumbers(a); // �������� ������� � ��������������� ������� �������
		ma[i][2] = ReversNumbers(b); // � a-����� ����� , � b-����� ��������
	}
}

int main()
{
	ifstream in;
	ofstream outMS, out;
	in.open("Input.txt");
	outMS.open("OutputMS.txt");
	out.open("Output.txt");
	int ** ma = new int*[20];//������� �������, ������ ������ - ���������� � ������ ������  � ��������
	for (int i = 0; i < 20; i++)
		ma[i] = new int[3];// ������ ������� - ����� �� �����
	                       // ������ - ����� ������
	                       // ������ - ����� �������� 

	int k = 0;
	while (!in.eof())//���� �� ����� �����
	{
		in >> ma[k][0]; //��������� ������ ������� ������� ������� �� �����
		k++;//������� ���-�� ���� �������
	}

	func(ma, k);
	sort(ma, k);
	for (int i = 0; i < k; i++)
		outMS << ma[i][1] << "   " << ma[i][2] << endl;
	//qsort(ma[i][2],8,sizeof(int),comp);

	int min, max;
	MinMax(ma, k, &min, &max);
	out << "���������� ����� ��������: " << max << endl;
	out << "���������� ����� ��������: " << min << endl;

	int symMax = 0, symMin = 0;
	int sym = 0;

	out << "������ ������� � ���������� ���������: " << endl;
	for (int i = 0; i < k; i++) // ����� � ����������
		if (ma[i][2] == max)
		{
			symMax = symMax + ma[i][2]; //����� ���� ����������
			out << ma[i][1] << "   ";
		}
	out << endl;
	// ����� ��� ������� ������� � ���������� ���������

	int *mas = new int[20];
	int u;
	numlitle(ma,ma[k][2],mas,u,symMin);
      for(int i=0;i<u;i++)
        {
		   //symMin = symMin + ma[i][2];
           cout << ma[i][1] << "   ";
        }

	out << "������ ������� ���������: " << endl;
	for (int i = 0; i < k; i++) //����� ��� ����������� � ��� �����������
		if (ma[i][2] != min && ma[i][2] != max)
		{
			sym = sym + ma[i][2]; //����� ���������
			out << ma[i][1] << "   ";
		}
	out<< endl;

	
	//for (int i = 0; i < k; i++)
	//{
	//	if (ma[i][2] == max)
	//		symMax = symMax + ma[i][2]; //����� ���� ����������
	//	if (ma[i][2] == min)
	//		symMin = symMin + ma[i][2];//����� ���� ����������
	//	else
	//		sym = sym + ma[i][2]; //����� ���������
	//}

	out << "����� ���������� ���������: " << symMax << endl;
	out << "����� ���������� ���������: " << symMin << endl;
	out << "����� ��������� ���������: " << sym << endl;
}