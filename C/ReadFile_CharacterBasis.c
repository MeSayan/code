/*This is a program to open a file in read only mode and print its contents
 * character by character
 * 
 * */
 
 #include <stdio.h>
 #include <stdlib.h>
 int main()
 {
	  FILE *fp;
	  char ch;
	  
	  fp=fopen("/home/sayan/test","r");
	  
	  //Checking to see if we have succesfully opened the file
	  
	  if(fp==NULL)
	  {
		  puts("Cannot open file");
		  exit(1);
	  }
	  
	  while(1)
	  {
		ch=fgetc(fp);
		if(ch==EOF)
		break;
		printf("%c",ch);
	  }


printf("\n");
fclose(fp);

return 0;
}
