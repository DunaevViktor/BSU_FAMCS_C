#include<iostream>
#include<stdlib.h>
using namespace std;
int maxA(int *A,int n,int &imax) // статический массив
{
	int res;
	_asm
	{
		mov ecx,n
		dec ecx // n-1->ecx
		mov esi,A // адрес начала массива в esi
		mov eax,0 // для индекса значение равное 0,максимум(значение)
		mov edi,edx // для результирующего индекса
		mov eax,[esi] // занос элемента с 0
for1:
		add esi,4 // перейти к следующему элементу
	    inc edx
		cmp eax,[esi] // текущий максимум сравнивается со следующим
		cmovl eax,[esi] // меняет текущий максимум
		cmovl edi,edx // в edi помещаем edx
			loop for1 // вычетается 1, и проверяется, если 0,
			          // то переходит в конец
			mov edx,imax
			mov [edx],edi
			mov res,eax
	}
	return res;
}
int main()
{
	int *A;
	int otv,ind,n;

	printf("Input a size of an array: ");
	scanf_s("%d", &n);

	A=(int*)malloc(n * sizeof(int));

	if (!A)
	{
		printf("Error: there is no memory.\n");
		return 0;
	}

	printf("Input elements of the array: ");
	for (int i = 0; i < n; ++i)
	scanf_s("%d", A[i]);

	otv=maxA(A,10,ind);
    printf("Otvet: chislo and index");
    cout<<otv<<endl;
    cout<<ind<<endl;
}



