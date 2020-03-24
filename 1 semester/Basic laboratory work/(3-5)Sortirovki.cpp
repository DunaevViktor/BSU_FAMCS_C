#include <iostream>
#include <stdio.h>
using namespace std;

int Greater_int(const void*a1, const void*b1)
{
	int *a = (int*)a1;
	int *b = (int*)b1;
	return *a - *b;
}
int Less_int(const void*a1, const void*b1)
{
	int *a = (int*)a1;
	int *b = (int*)b1;
	return *b - *a;
}
int Greater_double(const void*a1, const void*b1)
{
	double *a = (double*)a1;
	double *b = (double*)b1;
	if (*a<*b)
		return -1;
	if (*a>*b)
		return 1;
	else
		return 0;
}
int Less_double(const void*a1, const void*b1)
{
	double *a = (double*)a1;
	double *b = (double*)b1;
	if (*a>*b)
		return -1;
	if (*a<*b)
		return 1;
	else
		return 0;
}
int main()
{
	int i, n, a[100];
	double x[100];
	printf("razmernost massiva: ");
	scanf_s("%d", &n);
	printf("elementi: ");              /* vvod massiva */
	for (i = 0; i < n; ++i)
	{
		scanf_s("%d", &a[i]);
		x[i] = a[i];
	}
	printf("neotsortirovanni massiv: ");  /* vivod massiva */
	for (i = 0; i < n; ++i)
		printf("%d ", a[i]);
	printf("\n");

	qsort(a, n, sizeof(int), Greater_int);/* sort massiva */
	printf("sort po vozrastaniu: ");  /* vivod*/
	for (i = 0; i < n; ++i)
		printf("%d ", a[i]);
	printf("\n");
	
	qsort(a, n, sizeof(int), Less_int);/* sort massiv */
	printf("sort po ubivaniu: ");  /* vivod massiva */
	for (i = 0; i < n; ++i)
		printf("%d ", a[i]);
	printf("\n");
	
	qsort(x, n, sizeof(double), Greater_double);/* sort masasiv */
	printf("sort po vozrastaniu: ");  /* vivod massiva*/
	for (i = 0; i < n; ++i)
		printf("%5.1f ", x[i]);
	printf("\n");
	
	qsort(x, n, sizeof(double), Less_double);/* sort */
	printf("sort po ubivaniu: ");  /* vivod massiva*/
	for (i = 0; i < n; ++i)
		printf("%5.1f ", x[i]);
	printf("\n");
}