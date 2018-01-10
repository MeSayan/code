#include <stdio.h>

void func() {
    //Do nothing;
}


int m3() {
    int i;

    for( i = 1;  i <= 10; i++) {
        func();
        printf("%d \n",i);
    }

    return 0;

}
