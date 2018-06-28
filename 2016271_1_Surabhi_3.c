#include <stdio.h>
 
 
 
int heap[50];                       //Initialize the heap
int size=0;
 
 
 
void heapifydown(int index)         //Heapifies the heap by making comparisons with the children and swapping accordingly with the larger child's value
{
 
	int i=index;
 
	while(i<=((size/2)-1))
	{
 
		if(2*i+1<size && 2*i+2<size)
		{
			if(  (heap[i]<heap[2*i+1]) || (heap[i]<heap[2*i+2])  )
			{
				int temp=heap[i];
				if(heap[2*i+1]<heap[2*i+2])
				{
					heap[i]=heap[2*i+2];
					heap[2*i+2]=temp;
					i=(i*2+2);
				}
 
				else
				{
					heap[i]=heap[2*i+1];
					heap[2*i+1]=temp;
					i=(i*2+1);
				}
			}
 
			else
			{
				break;
			}
 
		}
 
		else if((2*i+1)<size)
		{
			if(heap[i]<heap[2*i+1])
			{
				int temp=heap[i];
				heap[i]=heap[2*i+1];
				heap[2*i+1]=temp;
				i=(i*2+1);
			}
 
			else
			{
				break;
			}
		}
 
 
		else
		{
			break;
		}
	}
}
 
 
 
void extractmax()               //Removes the max element from the heap
{
    if(size>=0)
    {
	    if(size==1)
	    {
		    size--;
	    }
	
	    else
	    {
        	heap[0]=heap[size-1];
		    size--;
		    heapifydown(0);
	    }
    }
 
}
 
void heapifyup(int index)       //Heapifies the heap by making comparisons with parent ans swaps accordingly
{
		int i=index;
		while(i>0 && (heap[(i-1)/2]<heap[i]))
		{
			int temp=heap[(i-1)/2];
			heap[(i-1)/2]=heap[i];
			heap[i]=temp;
			i=(i-1)/2;
		}
}
 
 
void insert(int e)          //Inserts new element in the heap
{
		if(size==0)
			heap[0]=e;
		else
		{
			heap[size]=e;
			heapifyup(size);
		}
 
		size++;
}
 
 
void display()
{
	for(int q=0; q<size; q++)
	{
		printf("%d",heap[q]);
		printf(" ");
	}
}
 
 
void displaysorted()        //Performs heap sort by successive extract max options and prints sorted
{
	int arr[size];
	int copy[size];
	for(int z=0; z<size; z++)
	{
		copy[z]=heap[z];
	}
	
	
	int temp=size;
	for( int k=0; k<temp; k++)
	{
		arr[k]=heap[0];
		extractmax();
		
	}
	
 
	for(int h=temp-1; h>=0; h--)
	{
		printf("%d",arr[h]);
		printf(" ");
	}
 
	for(int z=0; z<temp; z++)
	{
		insert(copy[z]);
	}
}
 
 
int main(void) 
{
	int N;
	scanf("%d",&N);
 
	for(int i=0; i<N; i++)      //Form the heap
	{
		int toins;
		scanf("%d",&toins);
		insert(toins);
	}
 
	int T;
	scanf("%d",&T);
 
	for(int j=0; j<T; j++)      //Run this loop T times where T is number of testcases
	{
		//("0 - Print the max-heap\n");
		//("1 - Heapsort, then print the sorted array\n");
		//("2 [element] - Insert element into max-heap, then print the heap\n");
		//("3 - Remove/extract maximum element in max-heap, then print the heap\n");
		//("4 - Print maximum element of max-heap\n");
 
		int choice;             
 
		scanf("%d",&choice);    //Input user's choice
 
 
		if(choice==0)           //If choice is 0, display the heap
		{
			display();
			printf("\n");
		}
 
		else if(choice==1)      //If choice is 1, perform heap sort and print sorted array
		{
			displaysorted();
			printf("\n");
		}
 
 
		if(choice==2)           //If choice is 2, ask for another input to be inserted into heap and then display the heap
		{
			int elem;
			scanf("%d",&elem);
			insert(elem);
			display();
			printf("\n");
		}
 
		else if(choice==3)      //If choice is 3, remove the max element from the heap and display
		{
			extractmax();
			display();
			printf("\n");
		}
 
		else if(choice==4)      //If choice is 4, print the max element in the heap
		{
			printf("%d",heap[0]);
			printf("\n");
		}
 
	}
 
	return 0;
}




