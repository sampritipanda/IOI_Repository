// Xor Queries

#include <stdio.h>
#include <vector>
#include <map>

using namespace std;

int sort_query(vector<int>& arr, int L, int R, int x, int type){
  map<int, int> count_map;
  for(int i = L; i <= R; i++){
    count_map[arr[i]]++;
  }

  if(type == 3){
    int count = 0;
    for(auto it: count_map){
      if(it.first <= x) count += it.second;
    }
    return count;
  }
  else {
    int curr = 0;
    for(auto it: count_map){
      if(curr + it.second >= x) return it.first;
      else curr += it.second;
    }
  }
}

int main() {
  int M; scanf("%d", &M);
  vector<int> arr;

  for(int i = 0; i < M; i++){
    int type; scanf("%d", &type);

    if(type == 0){
      int x; scanf("%d", &x);
      arr.push_back(x);
    }
    else if(type == 1){
      int L, R, x; scanf("%d %d %d", &L, &R, &x);
      L--; R--;

      int max = x ^ arr[L], max_elem = arr[L];
      for(int i = L + 1; i <= R; i++){
        if((x ^ arr[i]) > max) {
          max = x ^ arr[i];
          max_elem = arr[i];
        }
      }
      printf("%d\n", max_elem);
    }
    else if(type == 2){
      int k; scanf("%d", &k);
      arr.resize(arr.size() - k);
    }
    else {
      int L, R, x; scanf("%d %d %d", &L, &R, &x);
      L--; R--;

      printf("%d\n", sort_query(arr, L, R, x, type));
    }
  }
}
