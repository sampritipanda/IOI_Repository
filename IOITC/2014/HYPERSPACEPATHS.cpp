// Hyperspace paths

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
  int k; cin >> k;
  int start[k], end[k], d[k];
  for(int i = 0; i < k; i++) cin >> start[i];
  for(int i = 0; i < k; i++) cin >> end[i];
  for(int i = 0; i < k; i++) cin >> d[i];

  bool possible = true;
  for(int i = 0; i < k; i++){
    if(((end[i] - start[i]) != 0 && d == 0) || abs(end[i] - start[i]) % d[i] != 0){
      possible = false;
      break;
    }
  }

  if(possible){
    cout << 1 << endl;
    int shortest_path = 0;
    for(int i = 0; i < k; i++){
      shortest_path = max(shortest_path, abs(end[i] - start[i])/d[i]);
    }
    cout << shortest_path << endl;
    long long sanity = 0;
    for(int i = 0; i < k; i++){
      int x = (-start[i] + end[i] + 2*d[i])/(shortest_path * d[i]);
      int y = (start[i] - end[i] + 2*d[i])/(shortest_path * d[i]);

      if(x > 0) sanity += (x * (2 * (start[i] + d[i]) + (x - 1) * d[i]))/2;
      if(y > 0) sanity += (y * (2 * ((start[i] + d[i] + (x - 1) * d[i]) - d[i]) - (y - 1) * d[i]))/2;
      int test = 0;
    }
    cout << sanity << endl;
  }
  else {
    cout << 0 << endl;
  }
}
