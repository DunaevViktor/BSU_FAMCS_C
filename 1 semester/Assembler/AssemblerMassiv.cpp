#include<iostream>
#include<stdlib.h>
using namespace std;
int maxA(int *A,int n,int &imax) // ����������� ������
{
	int res;
	_asm
	{
		mov ecx,n
		dec ecx // n-1->ecx
		mov esi,A // ����� ������ ������� � esi
		mov eax,0 // ��� ������� �������� ������ 0,��������(��������)
		mov edi,edx // ��� ��������������� �������
		mov eax,[esi] // ����� �������� � 0
for1:
		add esi,4 // ������� � ���������� ��������
	    inc edx
		cmp eax,[esi] // ������� �������� ������������ �� ���������
		cmovl eax,[esi] // ������ ������� ��������
		cmovl edi,edx // � edi �������� edx
			loop for1 // ���������� 1, � �����������, ���� 0,
			          // �� ��������� � �����
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



