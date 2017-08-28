#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;
int main() {

  int N,  i, j;
  int max = 0, sum;
  
  scanf("%d", &N);
  
  int A[N+1];
  int P[N+1];
  vector< int > isparent(N+1, 0);
  queue<int> Q;
  
  
  for (i  = 1; i <= N; i++) {
    scanf("%d", A+i);
  }
    
  for (i = 1 ; i <= N; i++ ) {
    scanf("%d", P+i);
  }
  
  for (i = 1; i <= N; i++) {
    if(P[i] == -1) {
      isparent[i] = 1;
    }
    else {
      isparent[P[i]] = 1;
    }
  }
  
  // Scan for leaf nodes and add them to queue
  for( i = 1; i <= N; i++) {
    if(isparent[i] != 1) {
      Q.push(i);
    }
  }
 
  /*
  while( !Q.empty() ) {
    int i = Q.front();
    Q.pop();
    cout << i << "  ";
  }
  */
  
  while( !Q.empty() ) {
    
    int v = Q.front();
    Q.pop();
    sum = 0;
    
    while( P[v] != -1) {
      if( (A[P[v]] - A[v]) > 0 ) {
        sum += A[P[v]] - A[v];
      }   
      v = P[v];
    }
    
    if( sum > max) 
      max = sum;
  }
     
  cout << max << endl;
  
  return 0;
}
