// Vasya and Petya's Game

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool is_prime(int N) {
  if(N == 1) return false;
  for(int i = 2; i*i <= N; i++) {
    if(N % i == 0) return false;
  }
  return true;
}

int main() {
  vector<int> ans;
  int N; cin >> N;

  for(int i = 2; i <= N; i++) {
    if(!is_prime(i)) continue;

    int k = i;
    while(k <= N) {
      ans.push_back(k);
      k *= i;
    }
  }

  cout << ans.size() << endl;
  for(auto it: ans) cout << it << " ";
  cout << endl;
}
