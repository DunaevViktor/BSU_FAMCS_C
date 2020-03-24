#include<iostream>
#include<string>

void Zamena( const char*s1, const char*chto, const char*rez)
{
	char*x; char*str; char*rez2;
	str = (char*)s1; rez2 =(char*) rez;
	x = strstr(str, chto);
	while (x != 0)
	{
		int n = x - str;
		strncpy(rez2, str, n);
		rez2[n] = '\0';
		
		str = x + strlen(chto);
		rez2 = rez2 + n;
		x = strstr(str, chto);
	}
	strcpy(rez2,str);

}
using namespace std;
void main()
{
	char s1[100], chto[20], rez[200];
	cin.getline(s1, 99, '\n');
	cin.getline(chto, 19, '\n');

	strcpy(rez, " ");
	Zamena(s1, chto, rez);
	cout << rez << endl;
	return;
}