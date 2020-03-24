#include <iostream>
using namespace std;
int main()
{
	int a,b;
	long long c;
	cin>>a>>b;
	_asm
	{
		mov eax,a
			imul dword ptr b // edx:eax<-a*b
			mov dword ptr c,eax
			mov dword ptr c+4,edx
	}
	cout<<c<<endl;
}
