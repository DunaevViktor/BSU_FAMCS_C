#include <iostream>
using namespace std;
int main()
{
	signed char a,b;
	short c;
	cin>>a>>b;
	_asm
	{
		// ������� 1-�������� ���� 
		// ��������� ������
		// ��������� ����� ����������� �������
		// �� �� �������� ��� �������
		// ���������� 
		mov al,a
			cbw // ax<-a
			mov c,ax // c<-a
			mov al,b
			cbw // ax<-b
			add c,ax // Resultat v C
	}
	cout<<c<<endl;
}






