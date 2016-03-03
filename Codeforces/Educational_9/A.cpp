#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
  vector<string> ops;
  int N, p; cin >> N >> p;
  for(int i = 0; i < N; i++) {
    string S; cin >> S;
    ops.push_back(S);
  }
  reverse(ops.begin(), ops.end());

  long long cnt = 0;
  long long ans = 0;
  for(auto S: ops) {
    if(S == "halfplus") {
      cnt = (cnt * 2) + 1;
    }
    else if(S == "half") {
      cnt *= 2;
    }

    ans += (cnt * p)/2;
  }

  cout << ans << endl;
}
