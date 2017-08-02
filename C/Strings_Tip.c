/*This is a program to displa utility of sscanf() and sprintf() functions
 * which work just like their cousins except they use a prespecied char buffer for I/O
 * */
 
 #include <stdio.h>
 int main()
 {
	 int i=10;
	 char ch='A';
	 char str[20];
	 float a=3.14;
	 printf("%d %c %f \n",i,ch,a);
	 sprintf(str,"%d %c %f \n",i,ch,a);
	 printf("%s \n",str);
	 
	 
	 //Now demonstrating utitlity  of sscanf();
	 int d=9;
	 char e='B';
	 float f=6.0;
	 
	 printf("Before reading values from string str we have %d %c %f \n",d,e,f);
	 sscanf(str,"%d %c %f",&d,&e,&f);
	 //In scanf punctuation marks between two format specifier is  ignored
	 
	 printf("After reading values from string we have %d %c %f \n",d,e,f);
	
	 return 0;		
 }
	 
 
