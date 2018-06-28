#include <stdio.h>

int main(void) 
{
	int a=0;        //First value in fibonacci series is 0
	int b=1;        //Second value in fibonacci series is 1
	
	int n;          
	scanf("%d",&n);     //Take input for n, where we want nth fibonacci number
	
	if(n==1)
		printf("%d",a);
	else if(n==2)
		printf("%d",b);
	
	else
	{
		int x;
	
		for(int i=2; i<n; i++)          //Loop to find fibonacci numbers
		{
			x=a+b;
			a=b;
			b=x;
		}
	
		if(n>7)                         //Reverse the fibonacci number (if its 2 digits or larger)
		{
			int val=0;                  
			while(x>=1)                 //Use continuous divide by 10, modulo 10 operations to get answer
			{
				val=val*10+(x%10);
				x/=10;
			}
			
			x=val;
		}
		
		printf("%d",x);                 //Print the answer (nth fibonacci number in reverse)
	}
	

	return 0;
}