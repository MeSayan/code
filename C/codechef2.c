#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct post {
    int f,p;
    int special ;
    char str[100];
};

int compare(const void *a,const void *b) {
    struct post *p1 = (struct post *)a;
    struct post *p2 = (struct post *)b;
    
    if( p1->special == p2->special) {
        return p2->p - p1->p ;
    }
    else {
        return p2->special - p1->special;
    }
}

void sortList(struct post list[],int size) {
    struct post temp;
    int i,j; 

    for(i=0;i<size;i++) {
        for(j = 0;j<size;j++) {
           // Special - Non Special 
            if( list[j].special < list[j+1].special ){
                temp =  list[j];
                list[j] = list[j+1];
                list[j+1] = temp;
            }
            // Special - Special and Non-Special and Non-Special
            else if( list[j].special == list[j+1].special ){
                if( list[j].p < list[j+1].p){
                    temp = list[j];
                    list[j] = list[j+1];
                    list[j+1] = temp;
                }
            }
        }
    }
}

void printList(struct post list[],int size){     
   //Print All the posts
   int i;
       for(i=0;i<size;i++){
            printf("%s\n",list[i].str);
        }
   }

int main() {
    int M,N,i,j;

    // Get M and N
    scanf("%d %d",&N,&M);

    struct post postList[M];
    int frndList[N];

    for(i=0;i<N;i++) {
        scanf("%d",frndList+i);
    }
    

    for(i=0;i<M;i++){
        scanf("%d %d %s",&(postList[i].f),&(postList[i].p),postList[i].str);
        postList[i].special = 0;
     
        for(j=0;j<N;j++) {
            if(postList[i].f == frndList[j])
                    postList[i].special = 1;
        }
    
    }
    qsort(postList,M,sizeof(struct post),compare);
    //sortList(postList,M);
    printList(postList,M);
   return 0;
}

    


    
