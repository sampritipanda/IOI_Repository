#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int main() {
  int N; cin >> N;

  vector<int> A;
  map<int, int> F;
  A.resize(N);

  for(int i = 0; i < N; i++) {
    cin >> A[i];
    F[A[i]]++;
  }

  int ans = 0;
  while(true) {
    int sum = 0;
    for(auto it: F) sum += it.second;

    if(sum == 0) break;

    int cnt = 0;
    for(auto it: F) {
      if(it.second > 0) {
        cnt++;
        F[it.first]--;
      }
    }
    ans += cnt - 1;
  }

  cout << ans << endl;
}
