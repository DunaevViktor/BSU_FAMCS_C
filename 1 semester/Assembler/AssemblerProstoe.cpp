#include <iostream>
using namespace std;
void main() 
{

int x,d;
int res;
cout<<"input x";
cin>>x;
_asm
{
	cmp x,1
	jne else1
if1:mov res,0
	jmp endif1
else1:cmp x,2
	  jne else2
if2:mov res,1
	jmp endif2
else2:mov ebx,x
//	  and ebx,1
	  test ebx,1
	  jne else3
if3:mov res,0
	jmp endif3
else3:mov ecx,3
w1:   mov eax,ecx
	  imul ecx
	  cmp eax,ebx
	  jg endw1
	  mov eax,ebx
	  cdq
	  idiv ecx
	  cmp edx,0
	  jne incd2
	  mov res,0
	  jmp endw1
incd2:add ecx,2
	  jmp w1
endw1:mov eax,edx
	  cdq
	  idiv ecx
if4:cmp edx,0
	je endif4
	mov res,1
    endif4:
	endif3:
	endif2:
	endif1:

}
if(res==0)
cout<<"ne prostoe";
else
cout<<"prostoe";
}