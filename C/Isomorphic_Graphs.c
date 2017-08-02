#include <stdio.h>
#include <stdio_ext.h>
#define nrow 6
#define ncol 5

void display(int a[nrow][ncol])
{	int i,j;
	for(i=0;i<nrow;i++)
	{
		for(j=0;j<ncol;j++)
		printf("%d\t",a[i][j]);
		printf("\n");
	}
}
int isequal(int a[nrow][ncol],int b[nrow][ncol])
{
	int i,j;
	for(i=0;i<nrow;i++)
	{
		for(j=0;j<ncol;j++)
		{
			if(a[i][j]!=b[i][j])
			return 0;
		}
	}
	return 1;
}

int main()
{	 
	 int i,j,k,t;
	 int a[nrow][ncol];
	 int b[nrow][ncol];		
     
     
     while(1)
    { 	puts("Enter the elements of Incidence Matrix of the Graph(G)");
		for(i=0;i<nrow;i++)
		{	
			for(j=0;j<ncol;j++)
			{
			 scanf("%d",&a[i][j]);
			}
		}
		puts("Enter the elements of Incidence Matrix of the Graph(G1)");
		for(i=0;i<nrow;i++)
		{
			for(j=0;j<ncol;j++)
			{
				scanf("%d",&b[i][j]);
			}
		}
	 
		puts("Graph G\n----------");
		display(a);
		puts("Graph G1\n-----------");
		display(b);
		printf("Okay(y/n)?");
		
		//__fpurge(stdin);
		while(getchar()!='\n');
		/*
		 * fflush(stdin) wont work because it is designed for output streams
		 * only.
		 * __fpurge(stdin) works only on  linux and clears the input buffer
		 * of unwanted characters like '\n'
		 * To clear unwanted characters and mantain code universality/portability
		 * use while(getchar()!='\n')
		 * */
		char c;
		scanf("%c",&c);
		if(c=='y')
		break;
	}
	 
	 
	 for(i=0;i<nrow;i++)
	 {
		 for(j=0;j<nrow;j++)
		 {
			 if(j==i)
			 continue;
			 else
			 {
				 for(k=0;k<ncol;k++)
				 {
					 t=a[i][k];
					 a[i][k]=a[j][k];
					 a[j][k]=t;
				 }
				 //printf("After Interchange:\n--------------------\n");
				 //display(b);
				 
				 if(isequal(a,b))
				{	 
				 puts("The Graphs (G) and (G1) are isomorphic!");
				 return 0;
				}
			}
		}
	}
	puts("As of now the graphs are not yet proved to be isomorphic. Please confirm with other sources"); 
	 
	 return 0;
 }
 
	
