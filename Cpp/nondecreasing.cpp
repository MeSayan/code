#include <stdio.h>
#include <stdlib.h>

#define MAX_DIGITS 10000

// Function to compute and return M

void getM(int digits[], int count) {

   int i, j;

   for ( i = 0; i < count-1; i++) {
      if( digits[i] > digits[i+1]) {
        // Decrease the digit by 1
        digits[i] = digits[i] - 1;
      break;
    }
   }

   //Make remaining digits 9
   for ( j = i+1; j < count; j++) {
      digits[j] = 9;
  }

}


// Driver Program

int main() {

  int  j;

  // Used to input very large numbers
  int digits[] = {1,0,0,0}; // N = 45671035


  getM(digits, sizeof(digits)/sizeof(int));

   for( j = 0; j < sizeof(digits) / sizeof(int) ; j++) {
    printf("%d", digits[j]);
   }

   printf("\n");
   return 0;

}
