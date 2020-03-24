#include <stdio.h>
#include <stdlib.h>
void Find_Min_Max(int *mas,int b,int * x,int *y);
int main()
{
	int c,d;
	/* ukazatel na massiv,razmer massiva */
	int	*a, n;
	/* index */
	int i;

	printf("Input size of an array:\n ");
	scanf("%d", &n);

	/* videlyaem pamat */
	a =  (int*)malloc(n * sizeof(int));
	/* esli eror to vihod */
	if (!a)
	{
		printf("Error\n");
		return 0;
	}

	/* vvod elementov massiva */
	printf("Input elements \n");
	for (i = 0; i < n; ++i)
				scanf("%d", &a[i]);


	Find_Min_Max(a,n,&c,&d);

	printf("Min element of array %d\n",c);
	printf("Max element of array %d\n",d);
	return 0;
}

//funkcuia nahozdeniay min i max v massive mas i razmernosti b
//x-min and y-max
	void Find_Min_Max(int *mas,int b,int * x,int *y)
	{
		*x=mas[0];
		*y=mas[0];
		for(int i=1;i<b;i++)
		{
			if(mas[i]<*x)
				*x=mas[i];
			if(mas[i]>*y)
				*y=mas[i];
		}
	}
