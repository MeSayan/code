#include<stdio.h>

int main()
{
		printf("In C the long keyword is used to increase the byte size of integer and floating point varibles.\n");
		printf("Thus using the keyword long int the the variable we can increase range of values supported by variable\n");
		
		int a;
		long int b;
		long long int c;
		
		/* For GCC long long long and more longs is not allowed
		 
		 long long long int d;
		
		*/
		
		printf("sizeof(int)=%d bytes.\n",sizeof(a));
		printf("sizeof(long int)=%d bytes. \n",sizeof(b));
		printf("sizeof(long long int)=%d bytes. \n",sizeof(c));
		
		//printf("sizeof(long long long int)=%d bytes. \n",sizeof(d));

		return 1;
}
