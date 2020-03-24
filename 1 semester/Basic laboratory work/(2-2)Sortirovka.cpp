//	������ 2.���������� �������������� ������� �������� �������, ������� ��� ������.
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
void obmen(int *a, int n)
{
	for (int i = 0; i<n; i++)
	for (int j = i + 1; j<n; j++)
	if (a[i]>a[j])
	{
		int tmp = a[i];
		a[i] = a[j];
		a[j] = tmp;
	}
}
void vibor(int*x, int k)
{
	int min, imin = 0;
	for (int i = 1; i < k; i++)
	{
		imin = i - 1;
		for (int j = i; j < k; j++)
		if (x[j] < x[imin]) // ���� �������� ���� ,�� �������� � ���������� �� �����������
			imin = j;
		min = x[imin];
		x[imin] = x[i - 1];
		x[i - 1] = min;
	}
}
void vstavka(int *a, int n)
{
	long i, j;
	for (i = 1; i < n; i++)
	{  // ���� ��������, i - ����� �������
		int x = a[i];// ����� ����� �������� � ������� 		������������������ 
		for (j = i - 1; j >= 0 && a[j] > x; j--)
		{
			a[j + 1] = a[j];// �������� ������� �������
	     }
		    a[j + 1] = x; // ������� ��������
	}
}

int main(void)
{
	setlocale(LC_ALL, ".1251");
	int *a, n, i, k;
	printf("������� ���-�� ��������� �������:  ");
	scanf_s("%d", &n);
	a = (int*)malloc(n * sizeof(int));
	if (!a)
	{
		printf("Error: there is no memory.\n");
		return 0;
	}
	printf("������� ������:\n");
	for (int i = 0; i < n; ++i)
		scanf_s("%d", &a[i]);
	printf("������������ ������ ������� �������(1), �������(2) � ������(3)\n");
	scanf_s("%d", &k);
	if (k == 1)
		vstavka(a, n);
	if (k == 2)
		vibor(a, n);
	if (k == 3)
		obmen(a, n);
	for (i = 0; i<n; ++i)
		printf("%d ", a[i]);
	printf("\n");
	free(a);
	system("pause");
}