/*	vivesti na konsole vse chisla mersena iz intervala*/


#include <stdio.h>
#include <stdlib.h>
#include < math.h > 
bool prime_number(int y);
int main()
{
	//krainie znacheniya intervala
	int c,d,k;

	printf("Input interval:\n ");
	scanf("%d%d", &c,&d);
	
	//for(k=c;k<d+1;k++)
	//{
	 bool flag=false;
	 bool rez ;
		 // Proveryaem Mersena
		 for(int n=1;n<=30;n++) //?????
		 {
			 unsigned int mers= (1<<n)-1;
				 //      pow(2,(double)n)-1;
			 k=mers;
			 rez = prime_number(k);
			 bool rez2=prime_number(n);
			 if (rez==true && rez2==true)
			{
			   if (mers<c || mers>d) continue;		
			 
				 printf("digit %d is Mersenne prime\n",k);
			  flag=true;
			 }
		 }

		 
//	  }
	
	 if (flag==false)
	printf("this interval has not got Mersenne prime\n");
}	
//funkcia dlya proverki prostoe li chislo
//kod vozvrata false-neprostoe ,true-prostoe
	bool prime_number(int y1)
	{
		 int y=y1;
		if (y==2) return true;
		if (y==3) return true;
			if(y%2==0)
				return false;
		for( int i=3; i*i<=y; i+=2)
		{
			if(y%i==0)
				return false;
		}
		return true;
	}