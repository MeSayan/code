#include<stdio.h>

int main()
{
		printf("In c programing language the character data type always take up 1 byte \nbut other variable like int ,float, double may take up different valued from system to system.");
		printf("\n lets find out the sizes for each data type using sizeof(operand) function.\n");
		
		printf("The size of char is %d bytes. \n",sizeof(char));
		printf("The size of int variables is %d bytes. \n",sizeof(int));
		printf("The size of float variables is %d bytes. \n",sizeof(float));
		printf("The size of double variable is %d bytes. \n",sizeof(double));
		
		return 1;
}
