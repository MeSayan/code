#include <stdio.h>
#include <stdlib.h>
//#include <conio.h>

int month,year;
char *days[]={" ","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};
int months[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
char *monthsw[]={" ","January","February","March","April","May","June","July","August","September","October","November","December"};


	int isleap(int year)
	{
			if(year%100==0 && year%400==0)
			return 1;
			else if(year%100!=0 && year%4==0)
			return 1;
			
			
			return 0;
	}
	
	void display_calender(int count,int m,int y)
		{	
			char pattern[10]="----------";
			printf("%10s%10s%10s%10s%10s%10s%10s\n",pattern,pattern,pattern,pattern,pattern,pattern,pattern);
			printf("%30s,%d\n",monthsw[m],y);
			printf("%10s%10s%10s%10s%10s%10s%10s\n",pattern,pattern,pattern,pattern,pattern,pattern,pattern);
			for(int i=1;i<=7;i++)
			printf("%-10s",days[i]);
			puts("");
			printf("%10s%10s%10s%10s%10s%10s%10s\n",pattern,pattern,pattern,pattern,pattern,pattern,pattern);
			
			for(int i=1;i<count;i++)
			printf("%10s","");
			
			int perline=7-count+1;
			
			for(int i=1;i<=months[m];i++)
			{
				 printf("%-10d",i);
				 count++;
				 perline--;
				 
				 if(count>7)
				 count-=7;
				 if(perline==0)
				 {
					 
				  puts("");
				  perline=7;
			
			     }
		    }
		    printf("\n%10s%10s%10s%10s%10s%10s%10s\n",pattern,pattern,pattern,pattern,pattern,pattern,pattern);
		    
		}

int  compute(int m,int y)
	{
			int count=1;//According to gregorian calender
		for(int i=1;i<y;i++)
		{
			
			if(isleap(i))
			count+=2;
			else
			count++;
			
			if(count>7)
			count-=7;
		}
		
		for(int i=1;i<m;i++)
		{
			if(isleap(y))
			months[2]=29;
			else
			months[2]=28;
			
			count+=months[i]-28;
			if(count>7)
			count-=7;
		}
		

		//printf("\nThe day  of week of 1st %s of the year %d is: %s",monthsw[m],y,days[count]);
		display_calender(count,m,y);
		
		return 0;
	}
		
		
			
		
		
	int main()
	{
		int month,year;
		/*
		printf("%d",isleap(1600));
		printf("%d",isleap(1700));
		printf("%d",isleap(1800));
		printf("%d",isleap(1900));
		printf("%d",isleap(2000));
		*/
	
	 {
		system("clear");
		puts("Enter the month and year in order");
		scanf("%i %i",&month,&year);
		compute(month,year);
	}
	
	
	return 0;
}
		
		
	
