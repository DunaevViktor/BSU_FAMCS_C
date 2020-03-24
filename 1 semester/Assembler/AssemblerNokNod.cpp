#include <iostream>
#include<stdlib.h>
using namespace std;
 int AsmNod(int f,int e)
 {
	 int r;
	 _asm
	 {
		 mov ecx,e
		 mov ebx,f
repeat:
if_:
		 cmp ecx,ebx
		 jng else_ // esli vtoroe,to na else_
		 mov eax,ecx // ostatok ot deleniya
		 mov edx,0
		 div ebx
		 mov ecx,edx // ostatok
		 jmp end_else
else_:
		 mov eax,ebx
		 cdq
		 idiv ecx
		 mov ebx,edx // ostatok
end_else:
		 mov eax,ecx
		 imul ebx
until:
		 test eax,eax // poluchaetsya li 0?
		 jnz repeat
		 mov r,ebx
		 add r,ecx
	 }
	 return r;
 }
 int main()
 {
	 int nok;
	 int u;
	 int a;
     int b;
	 cout<<"Input dva chisla: ";
	 cin>>a>>b;
	u=AsmNod(a,b);
	cout<<"NoD = "<<u<<endl;
    nok=(a*b)/u;
    cout<<"NoK = "<<nok<<endl;
 }

