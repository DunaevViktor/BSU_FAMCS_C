#include<iostream>
using namespace std;
int main()
{
	long long int a, a1, d, i, cifra = 0, ocifra = 0, ccifra;
	int A[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	cout << "vvedite celoe chislo" << endl;     /* vvod*/
	cin >> a;
	a1 = a;
	while (a1>0)
	{
		d = a1 % 10;
		a1 /= 10;
		A[d]++;
		cifra++;
	}
	cout << endl;
	for (int i = 0; i<10; i++)                         //proverka cifri na necetnoe raz
	if (A[i] % 2 != 0)
	{
		ocifra++;
		ccifra = i;
	}
	if (ocifra>1)
	{
		cout << endl << "net polindroma" << endl;
		return 0;
	}
	if (ocifra == 0)                
           //esli net nechetnoi cifri
	{
		for (i = 9; i >= 0; i--)
		{
			for (int b = A[i] / 2; b > 0; b--)
			{
				cout << i;
			}
		}
		for (i = 0; i <10; i++)
		{
			for (int b = A[i] / 2; b > 0; b--)
			{
				cout << i;
			}
		}
		cout << endl << " - palindrom" << endl;
	}

	if (ocifra == 1)                    //cifra vstrecausayacya nechetnoe kol raz
	{
		for (i = 9; i >= 0; i--)
		{
			for (int b = A[i] / 2; b > 0; b--)
			{
				cout << i;
			}
		}
		cout << ccifra;
		for (i = 0; i <10; i++)
		{
			for (int b = A[i] / 2; b > 0; b--)
			{
				cout << i;
			}
		}
		cout << " - palindrom" << endl;
	}
	return 0;
}