#include <iostream>
using namespace std;
int main()
{
	signed char a,b;
	short c;
	cin>>a>>b;
	_asm
	{
		// Заносим 1-байтовые поля 
		// Расширяем первое
		// Сохраняем перед расширением второго
		// Те же операции для второго
		// Складываем 
		mov al,a
			cbw // ax<-a
			mov c,ax // c<-a
			mov al,b
			cbw // ax<-b
			add c,ax // Resultat v C
	}
	cout<<c<<endl;
}






