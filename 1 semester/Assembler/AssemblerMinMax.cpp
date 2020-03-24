#include <iostream>
#include <stdlib.h>
using namespace std;
void minmax(int x,int y,int *min,int *max)
	// Х и У копии аргументов , хранятся в стеке
{
	_asm
	{
		mov esi,min // адрес поля записывается в esi
		mov edi,max // адрес поля записывается в edi
		mov eax,x // x->eax
		mov eax,eax
		mov ebx,y // y->ebx
		cmp eax,ebx
		cmove edx,y // максимум,в eax - остался минимум
		cmovg eax,y // большее в edx, меньшее в eax
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










