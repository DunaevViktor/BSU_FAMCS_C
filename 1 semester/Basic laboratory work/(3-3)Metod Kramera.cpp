#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	float  a00,a01,a10,a11,c0,c1,b,x,y,x1,y1;
	cout << "vvedite koefficienti 1 uravneniya : " << endl;
	cin >> a00 >> a01 >> c0;
	cout << "vvedite koefficienti 2 uravneniya : " << endl;
	cin >> a10 >> a11 >> c1;
    b = (a00*a11)- (a01*a10);
	x1 = (c0*a11)-(a01*c1);
    y1 = (c1*a00)-(c0*a10);
	if (b!=0)
	{
		x = x1/b;
	    y = y1/b;
		cout << "x - " << x << endl;
	    cout << "y - " << y << endl;

		return 0;
	}
	if (b == 0 && y1 == 0 && x1 == 0)
	   {
		cout<< endl <<"resheniya "<< endl;
	    }
	else
		cout<< endl <<"net resheniy "<< endl;

}