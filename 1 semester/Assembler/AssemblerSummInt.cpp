#include <iostream>
using namespace std;
int main()
{
	signed int a,b;
	long long c;
	cin>>a>>b;
	_asm
	{
		mov eax,a
			cdq // edx(starshi):eax(mladshi)<-a
			mov dword ptr c,eax
			mov dword ptr c+4,edx
			mov eax,b
			cdq // edx:eax<-b
			add dword ptr c,eax
			adc dword ptr c+4,edx
	}
	cout<<c<<endl;
}