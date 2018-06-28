#include<stdio.h>

int main(void) 
{
	char input[100];						//Initializing the string
	gets(input);							//Inputting the string


	int count=0;							//Variable denoting the length of the string, initially set to 0
	for(int i=0; input[i]!='\0'; i++)		//Loop for calculating the length. Though we can use the strlen() function by including the string.h library.
	{
		count++;
	}
	

	int flag=0;								
	for(int j=0; j<(count/2); j++)			//Looping over half of the string, and comparing the ith and size-ith element and checking whether same
	{
		if(input[j]!=input[count-j-1])		//If they are different, clearly the string is not a palindrome, so break out from the loop and display NO
		{
			flag=1;
			break;
		}
	}										//Else the loops runs till completion and finally the flag value remains 0, so print YES
	
	if(flag==1)
		printf("No");
	else
		printf("Yes");
	
	return 0;
}