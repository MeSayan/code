#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;

int A[100000];
int P[100000];
vector< int > isleaf(100000, 1);
vector< vector<int> > G(100000, vector< int> (1,0));


int dfs(int vertex,int N) {

  int sum = 0, max = 0;
  
  if(isleaf[vertex] == 1) {
    if ((A[P[vertex]] - A[vertex]) > 0) 
      return A[P[vertex]] - A[vertex];
    return 0;
  }
  else {
  
  for( int i = 0; i < (int) G[vertex].size(); i++) {
    if( i != 0 ) {
    sum = dfs(G[vertex][i], N);
    }
    //cout << sum << " ";
    if (sum > max) {
      max = sum;
    }
  }
  return max;
  }
}



int main() {

  int N,  i, j, boss;
  int max = 0;
  
  scanf("%d", &N);
  
  for (i  = 1; i <= N; i++) {
    scanf("%d", A+i);
  }
    
  for (i = 1 ; i <= N; i++ ) {
    scanf("%d", P+i);
  }
  
  
  
  for (i = 1; i <= N; i++) {
    if(P[i] == -1) {
      isleaf[i] = 0;
      boss = i;
    }
    else {
      isleaf[P[i]] = 0;
      G[P[i]].push_back(i);
    }
  }
      
  max = dfs(boss, N);
     
  cout << max << endl;
  
  return 0;
}
