#include <iomanip>
#include <iostream>
#include <cmath>
using namespace std;
int main()

{
	double e, k, c, d, sum;
	int k1;
	cout << "Input amount of digits" << endl;
	cin >> k1;
	k = k1;
	e = 1.0 / pow(10.0, k + 1.0);
	sum = 0.0;
	c = -1.0;
	d = 1.0;
	do
	{
		sum += c / (d*d);
		c = -c;
		d += 2;
	} 
	while (fabs(c / (d*d)) >= e);
	cout << setprecision(k1) << sum << endl;
}