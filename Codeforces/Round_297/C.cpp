#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  map<int, int> sticks;
  int N; cin >> N;

  for(int i = 0; i < N; i++){
    int l; cin >> l; sticks[l]++;
  }

  vector<int> lengths;
  long long total_area = 0;

  for(auto it: sticks) {
    if(it.second > 0) lengths.push_back(it.first);
  }

  for(int i = lengths.size() - 1; i > 0; i--){
    int l = lengths[i];
    if(sticks[l] % 2 == 1){
      if(sticks.count(l - 1) > 0) {
        sticks[l]--; sticks[l - 1]++;
      }
      else {
        sticks[l]--;
      }
    }
  }

  for(auto l: lengths){
    if(sticks[l] < 2){
      sticks.erase(l);
    }
  }

  lengths.clear();
  for(auto it: sticks) {
    lengths.push_back(it.first);
  }

  while(!lengths.empty()) {
    long long curr_area = 1;
    int l = lengths.back();
    curr_area *= l;
    curr_area *= l;
    curr_area *= sticks[l]/4;
    sticks[l] %= 4;
    total_area += curr_area;
    if(lengths.size() > 1) {
      curr_area = 1;
      curr_area *= l;
      int l2 = lengths[lengths.size() - 2];
      int j = min(sticks[l], sticks[l2])/2;
      curr_area *= l2;
      curr_area *= j;
      total_area += curr_area;
      sticks[l] -= 2*j;
      sticks[l2] -= 2*j;
    }
    else {
      break;
    }

    if(sticks[l] < 2) lengths.pop_back();
  }

  cout << total_area << endl;
}
