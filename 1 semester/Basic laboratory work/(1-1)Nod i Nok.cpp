// Найти НОД и НОК двух заданных натуральных чисел, используя алгоритм Евклида.

#include <iostream>
using namespace std;

int main()
{
	int a, b, nod;
	long long nok;
	cout << "input numbers "<< endl;
	cin >> a >> b;
	nok = (long long)a*b;
	while (a != b)
	{
		if (a<b)
			b = b - a;
		if (b<a)
			a = a - b;
	}
	nod = a;
	nok = nok / nod;
		cout << "NOD = " << nod << endl;
	    cout << "NOK = " << nok << endl;
		return 0;
}