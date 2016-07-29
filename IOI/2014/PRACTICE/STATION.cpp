#include <iostream>
#include <algorithm>

using namespace std;

vector<int> I;

int solve(int N, int K) {
  int i = 0;
  int ans = 0;
  while(i != N - 1) {
    auto it = upper_bound(I.begin(), I.end(), i + K);
    it--;
    if(*it <= i) return -1;
    i = *it;
    ans++;
  }
  return ans;
}

int main() {
  int N, K; cin >> N >> K;
  for(int i = 0; i < N; i++) {
    int x; cin >> x;
    if(x) I.push_back(i);
  }

  cout << solve(N, K) << endl;
}
