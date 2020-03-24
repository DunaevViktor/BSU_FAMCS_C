#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<locale.h>

int cmpS(const void *a1,const void *a2)
{
	char **a=(char **)a1;
	char **b=(char **)a2;
	return strcmp(*a,*b);	
}

int main()
{
	char* MS[3];
	int n=3;
	int i;
	
	printf("Input string: ");
	
	for(i=0; i<n; i++)
	{
		char* str = new char[100];
		gets(str);
		MS[i]=str;
	}

	qsort(MS,n,sizeof(char*),cmpS);

	for (int i=0; i<n; i++)
		printf("%s\n",MS[i]);

}