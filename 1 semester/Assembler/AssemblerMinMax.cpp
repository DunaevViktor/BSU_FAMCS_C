#include <iostream>
#include <stdlib.h>
using namespace std;
void minmax(int x,int y,int *min,int *max)
	// � � � ����� ���������� , �������� � �����
{
	_asm
	{
		mov esi,min // ����� ���� ������������ � esi
		mov edi,max // ����� ���� ������������ � edi
		mov eax,x // x->eax
		mov eax,eax
		mov ebx,y // y->ebx
		cmp eax,ebx
		cmove edx,y // ��������,� eax - ������� �������
		cmovg eax,y // ������� � edx, ������� � eax
		mov [esi],eax
		mov [edi],edx
	}
}
int main()
{
	int x1,x2,imin,imax;
	printf("Input x1 and x2: ");
	cin>>x1>>x2;
	minmax(x1,x2,&imin,&imax);
		printf("Otvet: min and max\n");
	cout<<imin<<" "<<imax<<endl;
}










