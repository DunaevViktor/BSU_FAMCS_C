#include <iostream>
#include <math.h>
using namespace std;


int main()
{
	cout << "enter number\n";
	int a, b, x1 = 0, x2 = 0, s = 0;
	double sum = 0;
	cin >> a >> b;
	for (a; a < b; a++)
	{
		x1 = a;
		x2 = a;
		while (x1 > 0)
		{
			x1 = x1 / 10;
			s++;
		}
		while (x2 > 0)
		{
			x1 = x2 % 10;
			sum += pow((double)x1, s);
			x2 = x2 / 10;
		}
		if (sum == a) cout << a << " ";
		s = 0;
		sum = 0;
	}
	system("pause");

	return 0;
}