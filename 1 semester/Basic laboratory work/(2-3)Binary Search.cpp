/*Задача 3.Используя бинарный поиск, найти элементы в отсортированном целочисленном масиве. 
Размерность, элементы и искомый элемент массива вводятся с консоли.*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
void vibor(int *, int);


void MySort(int*x, int k)
{
	int min, imin = 0;
	for (int i = 1; i<k; i++)
	{
		imin = i - 1;
		for (int j = 1; j<k; j++)
		if (x[j]<x[imin])
			imin = j;
		min = x[imin];
		x[imin] = x[i - 1];
		x[i - 1] = min;
	}
}

int BinSearch(int*A, int n, int x)
{
	int  middle, left = 0, right = n - 1;
	while (left <= right)
	{
		middle = (left + right) / 2;
		if (x == A[middle])
			return middle;
		if (x > A[middle])
			left = middle + 1;
		else
			right = middle - 1;
	}
	return -1;
}

int main(void)
{
	setlocale(LC_ALL, ".1251");
	int *a, n, x, index;
	printf("Введите кол-во элементов массива:  ");
	scanf_s("%d", &n);
	a = (int*)malloc(n * sizeof(int));
	if (!a)
	{
		printf("Error: there is no memory.\n");
		return 0;
	}
	printf("Введите массив:\n");
	for (int i = 0; i < n; ++i)
		scanf_s("%d", &a[i]);
	MySort(a, n);
	for (int i = 0; i < n; ++i)
		printf("%d ", a[i]);
	cout << "Введите искомое число:  ";
	cin >> x;
	index = BinSearch(a, n, x);
	if (index == -1)
		cout << "Искомое число не найдено" << endl;
	else
		cout << "Индекс искомого числа -  " << index << endl;
	free(a);
	system("pause");
}