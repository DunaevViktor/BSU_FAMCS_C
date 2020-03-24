#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdarg.h>
using namespace std;

int  print(int n, ...)
{
	va_list	a;
	int sum = 0, pro = 1;
	if (n < 1)
	{
		cout<<"There are no numbers."<<endl;
		return 0;
	}
	cout<<"kolichestvo parametrov - "<<n<<endl;


	va_start(a, n);

	while (n)
	{
		int x;


		x = va_arg(a, int);
		printf("%d ", x);
		sum = sum + x; // summa
		pro = pro*x; // proiz
		--n;
	}
	cout<<"viberete operaciu 1 - summa 2 - proizvedenie"<<endl;
	int o;
	cin>>o;
	if (o == 1) return sum;
	if (o == 2)  return pro;

	va_end(a);

	return  -1;
}


int main()
{
	int a,b;
	a = print(4, 5, 2, -7,-2);
	if (a == -1)
	{
		cout<<"nepravelno vibrana operaciya"<<endl; // esli oshibka
		return 0;
	}
	cout<<"otvet - "<<a<<endl;
		a = print(3, 5, 2, -7);
	if (a == -1)
	{
		cout<<"nepravelno vibrana operaciya"<<endl; // esli oshibka
		return 0;
	}
	cout<<"otvet - "<<a<<endl;
}