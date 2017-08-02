/*WAP a program to find the ASCII Value of an entered character
*/

#include <stdio.h>

int main()
{
		int num;
		char c;
		
		//Getting input
		printf("Enter the character that you want to find ASCII value of:");
		scanf("%c,",&c);
		
		num=(int)c;
		
		/* We could have directly used 
		 * printf("%d",c); to print the integer value of the character
		 * */
		
		printf("The character you have entered: %c \n",c);
		printf("The ASCII value is: %d",num);
		return 1;// To check for code completion
}
