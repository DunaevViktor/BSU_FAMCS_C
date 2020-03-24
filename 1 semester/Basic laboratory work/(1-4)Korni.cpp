//Нахождение действительных корней квадратного уравнения 


#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	setlocale(LC_ALL, ".1251");
	float a, b, c, x1, x2;
	cout << "Введите коэффиценты квадратного уравнения" << endl;
	cin >> a >> b >> c;
	if (a == 0)
	{
		if (b == 0)
			cout << "коэффиценты введены некорректно" << endl;
		else
		{
			x1 = (-c) / b;
			cout << "Единственный корень уравнения: " << x1 << endl;
			return 0;
		}
	}
	else
		if (((b*b) - (4 * a*c))<0)
		cout << "Уравнение не имеет действительных корней" << endl;
		else
		{
			x1 = (-b + sqrt((b*b) - (4 * a*c)))/ (2 * a);
			x2 = (-b - sqrt((b*b) - (4 * a*c))) / (2 * a);
			cout << "Первый корень уравнения  " << x1 << endl;
			cout << "Второй корень уравнения  " << x2 << endl;
			return 0;
		}
	return 0;
}
