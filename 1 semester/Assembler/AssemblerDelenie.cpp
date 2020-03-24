#include <iostream>
using namespace std;
int main()
{
	short a,b,c,d;
	int x,y;
	cin>>a>>b>>c>>d;
	_asm
	{
		mov ax,a
			cwde // eax<-a
			mov ebx,eax
			mov ax,d
			cwde
			imul ebx; // Resultat edx:eax
		mov x,edx;
		mov ax,b
			cwde
			mov ebx,eax
			mov ax,c
			cwde
			imul ebx; // Resultat edx:eax
		add x,eax

			mov ax,b
			cwde
			mov ebx,eax
			mov ax,d
			cwde
			imul ebx // Resultat edx:eax
			mov y,eax
	}
	cout<<x<<y<<endl;
}

