#include <stdio.h>

int main() {
    int T,N,flag=1;
    int x,nx,i,j,r;
    
    scanf("%d",&T);

    for(i=0;i<T;i++) {
        
        flag = 1;
        //Get no of Students
        scanf("%d",&N);
        // Get Hostel Id of students check if all are same
        scanf("%d",&x);
        for(j=1;j<N;j++){
            scanf("%d",&nx);
            if( nx != x ){
                flag = 0;
            }
        }
        //Get ranks of all students ,see if they are less than 15
        for(j=0;j<N;j++) {
            scanf(" %d",&r);
            if( r < 15 ) {
                flag = 0;
            }
        }

        if(flag)
            puts("Party");
        else
            puts("No Party");
    }
}
