// Beautfiful Arrays
#include <stdio.h>
#include <stdlib.h>

int compare(const void *a,const void *b) {
    return *(int *)a - *(int *)b;
}

int main() {
    int T,N;
    int i,j,k,l,flag,key;
    int a[100000];

    scanf("%d",&T);
    for(i=0;i<T;i++) {
        flag = 1;
        scanf("%d",&N);
        for(j=0;j<N;j++)
            scanf("%d",a+j);
        //Sorting the array using qsort
        qsort(a,N,sizeof(int),compare);
        /*
        for(l=0;l<N;l++)
            printf("%d",a[l]);
        printf("\n");
        */
    outer:for(l=0;l<N;l++) {
            if(!flag)
                break;
            for(k=l+1;k<N;k++) {
                key = a[l] * a[k];
                if( bsearch(&key,a,N,sizeof(int),compare)
                        == NULL ){
                    flag = 0;
                    break ;
                }
            }
        }

        flag==1?puts("yes"):puts("no");

    }
    return 0;

}


