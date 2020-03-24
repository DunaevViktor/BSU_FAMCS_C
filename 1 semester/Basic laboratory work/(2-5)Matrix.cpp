
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int Find_Min (int**y, int i, int my);
int Find_Max (int**y, int j, int ny);

int main()
{
	int	**a;
	int n; 
	int m; 
	int i, j,v;



printf("vvedite razmernost\n ");
	scanf("%d%d", &n, &m);

	
	a =  (int**)malloc(n * sizeof(int*));
	
	if (!a)
	{
		printf("oshibka\n");
		return 0;
	}
	
	for (i = 0; i < n; ++i)
	{
		a[i] = (int*)malloc(m * sizeof(int)); // videlyaem pamat
		
		if (!a[i])
		{
			for (j = 0; j < i; ++j)
				free(a[j]);
			free(a);
			printf("oshibka\n");

			return 1;
		}
	}


	printf("vvedite elem matrici:\n");
	for (i = 0; i < n; ++i)
		for (j = 0; j < m; ++j)
			scanf("%d", &a[i][j]); // vvod matrici

	printf("vasha matrica:\n");
	for (i = 0; i < n; ++i)      // vivod matrici
	{
		for (j = 0; j < m; ++j)
			printf("%d ", a[i][j]);
		printf("\n");
	}
	                                                                                                                                                                             
	for (i=0;i<n;i++)
	{
		int mmin=a[i][0];
		int p=0;
		for(int z=0;z<m;z++)
			if(mmin>a[i][z])
			{	mmin=a[i][z] ;
				p=z;
			}
		
		for( v=0;v<n;v++)
		{
			if(a[v][p]>a[i][p])
				break;
		}
			if(v==n)
				printf("a[%d][%d]=%d\n",i,p,a[i][p]);
	}	



	
	for (i = 0; i < n; ++i) // osvobozdaem pamat
		free(a[i]);
	free(a);

	return 0;
}

