// Hyperspace paths

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

int main() {
  int k; cin >> k;
  long long start[k], end[k], d[k];
  for(int i = 0; i < k; i++) cin >> start[i];
  for(int i = 0; i < k; i++) cin >> end[i];
  for(int i = 0; i < k; i++) cin >> d[i];

  bool possible = true;
  int even = 0, odd = 0, no_steps = 0;
  for(int i = 0; i < k; i++){
    if(end[i] == start[i] && d[i] == 0) {
      no_steps++;
      continue;
    }
    else if(d[i] == 0 && end[i] != start[i]){
      possible = false;
      break;
    }
    else if(d[i] != 0 && (abs(end[i] - start[i]) % d[i]) != 0){
      possible = false;
      break;
    }
    else {
      if((abs(end[i] - start[i]))/d[i] & 1) odd++;
      else even++;
    }
  }

  if(odd != (k - no_steps) && even != (k - no_steps)) possible = false;

  if(possible){
    cout << 1 << endl;
    long long shortest_path = 0;
    for(int i = 0; i < k; i++){
      if(d[i] != 0) shortest_path = max(shortest_path, abs(end[i] - start[i])/d[i]);
    }
    cout << shortest_path << endl;
    long long sanity = 0;
    for(int i = 0; i < k; i++){
      if(d[i] == 0) {
        sanity += start[i] * (shortest_path + 1);
        continue;
      }
      long long curr_sanity = LLONG_MIN;
      for(int j = 0; j <= shortest_path; j++){
        if((start[i] + j*d[i] - (shortest_path - j)*d[i]) == end[i]){
          long long sum = 0;
          long long curr_end = start[i] + j * d[i];
          sum += ((j + 1) * (start[i] + curr_end))/2;
          sum += ((shortest_path - j + 1) * (curr_end + end[i]))/2 - curr_end;
          curr_sanity = max(curr_sanity, sum);
        }
      }
      sanity += curr_sanity;
    }
    cout << sanity << endl;
  }
  else {
    cout << 0 << endl;
  }
}
