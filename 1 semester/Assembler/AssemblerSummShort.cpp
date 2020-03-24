#include<iostream>
using namespace std;
int main()
{
	signed short a1,b1;
	int c1;
	cin>>a1>>b1;
	_asm
	{
		mov ax,a1
			cwde //eax<-a1(ax)
			mov c1,eax
			mov ax,b1
			cwde // eax<-b1(ax)
			add c1,eax
	}
	cout<<c1<<endl;
}