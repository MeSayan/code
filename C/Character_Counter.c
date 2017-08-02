/* Program to display character count of a file as well as display count of other characters separately
 * */
 
 #include <stdio.h>
 #include <stdlib.h>
 int main()
 {
	 FILE *fp;
	 char ch;
	 
	 int nol=0,not=0,nob=0,noc=0;
	 
	 fp=fopen("test","r");
	 
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
		 noc++;;
		 
		 
		 if(ch==' ')
		 nob++;
		 if(ch=='\n')
		 not++;
		 if(ch=='\t');
		 nol++;
	 }
	 fclose(fp);
	 
	 printf("Total character count is %d \n",noc);
	 printf("Number of blanks=%d \n",nob);
	 printf("No of tabs=%d \n",nol);
	 printf("No of lines=%d \n",not);

	return(0);
}
