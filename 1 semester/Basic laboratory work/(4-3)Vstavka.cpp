#include<iostream>
#include<string>

void Zamena(const char*s1, const char*chto, const char*na_chto, const char*rez)
{
	char*x; char*str; char*rez2;
	str = (char*)s1; rez2 = (char*)rez;
	x = strstr(str, chto);
	while (x != 0)
	{
		int y = strlen(chto);
		int m = x - str;
		int n = m + y;
		strncpy(rez2, str, n);
		rez2[n] = '\0';
		strcat(rez2, na_chto);
		str = x + y;
		rez2 = rez2 + n + strlen(na_chto);
		x = strstr(str, chto);
	}
strcpy(rez2,str);
}
using namespace std;
void main()
{
	char s1[100], chto[20], na_chto[30], rez[200];
	cin.getline(s1, 99, '\n');
	cin.getline(chto, 19, '\n');
	cin.getline(na_chto, 29, '\n');
	strcpy(rez, " ");
	Zamena(s1, chto, na_chto, rez);
	cout << rez << endl;
	return;
}