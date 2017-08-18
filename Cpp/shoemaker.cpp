#include <iostream>
#include <algorithm>
#include <vector>
#define all(c) c.begin(), c.end()          
#define tr(container, it) \
               for( typeof(container.begin()) it = container.begin(); it != container.end(); it++)
            

using namespace std;

// compare function is given so that we can specify how to compare two pairs.compare

bool cmp_pair(pair<int, pair<int, int> >a, pair<int, pair<int, int> > b) {
  return (a.second.first * b.second.second) > (b.second.first * a.second.second);
}



int main() {
  
  int N, i,t, s;
  vector< pair<int, pair<int, int> > > list;
  list.reserve(1000000);
  
  cin >> N;
  
  for(i = 0; i < N; i++) {
    cin >> t >> s;
    list.push_back(make_pair(i+1, make_pair(s,t)));
  }
  
  stable_sort(all(list), cmp_pair);
  
  /*
  for(i = 0; i < (int)list.size(); i++) {
    cout << list[i].first << list[i].second << endl;
  
  }
  */
  
  // traverse the list and print
  tr(list, it) {
    cout << it->first << endl;
  }
  
  return 0;
  
}