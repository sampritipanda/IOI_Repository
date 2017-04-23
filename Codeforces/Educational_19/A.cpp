#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
  int N, K; cin >> N >> K;
  vector<int> ans;

  while(N > 1) {
    bool done = false;
    for(int i = 2; i * i <= N; i++) {
      if(N % i == 0) {
        done = true;
        ans.push_back(i);
        N /= i;
        break;
      }
    }
    if(!done) {
      ans.push_back(N);
      break;
    }
  }

  if(ans.size() < K) {
    cout << -1 << endl;
  }
  else {
    while(ans.size() > K) {
      int tmp = ans.back(); ans.pop_back();
      tmp *= ans.back(); ans.pop_back();
      ans.push_back(tmp);
    }

    for(int i = 0; i < K; i++) cout << ans[i] << " ";
    cout << endl;
  }
}
