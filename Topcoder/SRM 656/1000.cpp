#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

class PermutationCountsDiv2 {
  public:
  int countPermutations(int N, vector <int> pos) {
    bool greater_than_next[N];
    for(int i = 0; i < N; i++) greater_than_next[i] = true;
    greater_than_next[N - 1] = false;
    for(auto it: pos){
      greater_than_next[it - 1] = false;
    }
    int inversions = 0;
    for(int i = 0; i < (N - 1); i++){
      for(int j = i + 1; j < N; j++){
      }
    }
  }
};

