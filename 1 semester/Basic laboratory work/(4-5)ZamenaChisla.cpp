#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <iostream>
using namespace std;


void zamenachisla(const char *str1, int chto1, int na_chto1,const char *res)
{
	 char *x;
	 char * str;
     char *res2;
     str=(char *)str1;
     res2=(char *)res;

	char* chto = new char[225];                //sozdaem stroki s budushimi chiframi
	char* na_chto = new char[225];

    sprintf(chto, "%d", chto1);                    //perevodim pervor chislo v stroku
    sprintf(na_chto, "%d", na_chto1);              //perevodim vtoroe chislo v stroku

	x =(char * )strstr(str, chto);
	while (x != NULL)
	{
		int n = x - str;
		strncpy(res2, str, n);         // kopiruem vse simvoli do pervogo vhozdeniya
		res2[n] = '\0';
        strcat(res2, na_chto);          //copy zadannoe na mesto iskomogo
		str=x+strlen(chto);
		res2=res2+n+strlen(na_chto);
		x=strstr(str,chto);
		strcat(res2, str);              //copy ostatok stroki
	}
delete[]chto;                           //osvobozdaem pamat pod sozdanie stroki
delete[]na_chto;
}

int main()
{
	char str1[100],  res[200];
	int chto, na_chto;
	cin.getline(str1, 99, '\n');
	scanf("%d%d",&chto,&na_chto);
	strcpy(res, " ");
	zamenachisla(str1, chto, na_chto, res);            
	cout << res << endl;
	return 0;
}