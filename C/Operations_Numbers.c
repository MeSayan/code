#include <stdio.h>
#include <math.h>

int num_of_digits(int no);

int reverse(int no);

void reverse_original(int  * no);// Used to reverse the entered no itself.

int ispallindrome(int no);

int no_of_digits(int no)
{
	int c=0;
	while(no>0)
	{
		no=no/10;
		c++;
	}
	return c;
}

int reverse(int no)
{
	int rev=0;
	
	while(no>0)
	{
		int r=no%10;
		rev=rev*10+r;
		no=no/10;
	}
	//printf("%d",rev);
	return rev;
}

void reverse_original(int * no)
{   
	int num=*no;
	int rev=reverse(num);
	* no=rev;
}
 
int isPalindrome(int no)
{
		int x=reverse(no);
		if(x==no)
		printf("The number entered (%d) is pallindrome \n",no);
		else
		printf("The number entered (%d) is not pallindrome \n",no);
		
		return 0;
}

int main()
{	int choice,no;
	int i=1;
	while(i==1)
	{
		puts("\nEnter a number:");
		scanf("%d",&no);
		puts("Enter 1 to print the no of digits,2 to reverse the no using pass by value,3 to reverse no using pass by reference and 4 to check if entered no is pallindrome or not");
		puts("Enter a menu indice:");
		scanf("%d",&choice);
	
	
		switch(choice)
		{
			case 1:printf("The no of digits in %d is %d \n",no,no_of_digits(no));
				break;
			case 2:{
					printf("The original no is: %d \n",no);		
					printf("The reversed no is %d",reverse(no));
					break;
					}
			case 3:{	
					printf("The original no is %d \n",no);
					reverse_original(&no);
					printf("The reversed no is %d",no);
					break;
					}
			case 0: {
					puts("Program terminates");
					i=2;
					break;
					}
			case 4:isPalindrome(no);break;
					
			default:puts("Im sorry I dont understand you:");break;
		}
	}
	return 0;
}
