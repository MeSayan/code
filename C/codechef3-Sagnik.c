#include <stdio.h>

int main(void) {
    	int i,j,t,n,c=1;
	    int rank[1000], hostel_id[10];
    	scanf("%d",&t);
    	for(i=1;i<=t;i++)
    	{
    		scanf("%d",&n);
     		for(j=0;j<n;j++)
    			scanf("%d",&hostel_id[j]);
                for(j=0;j<n;j++)
    			scanf("%d",&rank[j]);
                
    		for(j=0;j<n;j++)
    		{
    			if(hostel_id[j]!=hostel_id[0])
    			{
    				c=0;
    				break;
    			}
    			if(rank[j]<15)
    			{
    				c=0;
    				break;
    			}
    		}
    		if(c==0)
    			printf("No Party\n");
    		else
    			printf("Party\n");
    		c=1;
    	} 	   

	return 0;
}
