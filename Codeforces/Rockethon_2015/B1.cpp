// Permutations

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int calculateSum(vector<int>& permutation, int N){
  int sum = 0;
  for(int i = 0; i < N; i++){
    for(int j = i; j < N; j++){
      int min_elem = permutation[i];
      for(int k = i + 1; k <= j; k++){
        min_elem = min(min_elem, permutation[k]);
      }
      sum += min_elem;
    }
  }
  return sum;
}

int main() {
  int N, M; cin >> N >> M;
  vector<int> permutation;
  for(int i = 1; i <= N; i++) permutation.push_back(i);

  int max_sum = calculateSum(permutation, N);
  while(next_permutation(permutation.begin(), permutation.end())){
    max_sum = max(max_sum, calculateSum(permutation, N));
  }

  permutation.clear();
  for(int i = 1; i <= N; i++) permutation.push_back(i);
  int count = 0;
  while(true){
    if(calculateSum(permutation, N) == max_sum) count++;
    if(count == M) break;
    next_permutation(permutation.begin(), permutation.end());
  }
  for(int i = 0; i < N; i++) cout << permutation[i] << " \n"[i == N - 1];
}
