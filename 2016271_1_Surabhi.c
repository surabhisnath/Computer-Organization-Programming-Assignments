#include <stdio.h>

int main(void) 
{
	int x;
	scanf("%d",&x);     //Take input for n (number of numbers to sum)
	int sum=0;          //Initialize sum to 0
	
	int val;
	for(int i=0; i<x; i++)      //Run loop to take input and add numbers
	{
		scanf("%d", &val);      //Take in number
		sum+=val;	            //Add it to sum
	}
	
	printf("%d",sum);           //Print sum

	return 0;
}
