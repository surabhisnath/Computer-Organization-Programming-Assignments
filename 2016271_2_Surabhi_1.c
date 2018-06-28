#include <stdio.h>

int dim;			//Global variable indicating dimension of matrices

void findinv(float mat1[dim][dim], float mat2[dim][dim])        //Function for calculating inverse
{
	float frac;
    
    for(int i=0; i<dim; i++)
    {
    	    
        if(mat1[i][i]==0)                       //If mat1[i][i] is 0, need to swap rows to get a row h having non 0 mat1[h][i]
        {
            for(int h=i+1; h<dim; h++)
        	{
        	    if(mat1[h][i]!=0.00)
        		{
        	        for(int n=0; n<dim; n++)
        	        {
        	            float temp1=mat1[i][n];
    		            mat1[i][n]=mat1[h][n];
    		            mat1[h][n]=temp1;
        		        float temp2=mat2[i][n];     //Do same swap in mat2 as well
        		        mat2[i][n]=mat2[h][n];
        		        mat2[h][n]=temp2;
        		    }
        		    
        		    break;
        	    }
        		       
        	}
        }
        	
        	
    	    
    	    
        for(int j=0; j<dim; j++)
    	{
        	
            if(i!=j)
        	{
                frac=mat1[j][i]/mat1[i][i];                     //Using replacement operations, gets 0s in the column

                for(int k=0; k<dim; k++)
            	{
                    mat2[j][k]-=frac*mat2[i][k];
                }
             
                for(int k=0; k<dim; k++)
                {
                    mat1[j][k]-=frac*mat1[i][k];
                }
                
            }
        }
    }
    
    for(int m=0; m<dim; m++)                        //Scale the diagonal elements to 1
	{
        for(int n=0; n<dim; n++)
    	{
            mat2[m][n]/=mat1[m][m];
        }
        
        for(int o=0; o<dim; o++)
    	{
            mat1[m][o]/=mat1[m][m];
        }
    }
		
}




int main(void) 
{
    scanf("%d", &dim);                  //Take input for variable dim
    
    float mat1[dim][dim], mat2[dim][dim];       //Initialize 2 matrices, mat1 and mat2. Mat1 is input matrix, mat2 is initially identity matrix. When mat1 becomes identity matrix, mat2 becomes mat1's inverse matrix
 
    for(int i=0; i<dim; i++)            //input for matrix 1
    {
        for(int j=0; j<dim; j++)
        {
            scanf("%f", &mat1[i][j]);
        }
    }
   	
   	for(int k=0; k<dim; k++)        //Initialize mat2 (identity matrix)
    {
        for(int l=0; l<dim; l++)
    	{
            if(k==l)
               	mat2[k][l] = 1.00;
        	else
            	mat2[k][l] = 0.00;
    	}
    }
    
    
    
    //Inverse calculation (we know that it exists (given))
    
    findinv(mat1, mat2);
    	
    
    for(int i=0; i<dim; i++)                        //Display the inverse matrix
    {
        for(int j=0; j<dim; j++)
    	{
            printf("%f", mat2[i][j]);
        	printf(" ");
        }
    	printf("\n");
    }
   	

	return 0;
}
