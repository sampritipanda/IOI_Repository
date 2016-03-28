#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int A[100001];
vector<int> ans;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int T; cin >> T;

  while(T--) {
    int N; cin >> N;
    for(int i = 1; i <= N; i++) cin >> A[i];

    ans.clear();

    int j = N;
    ans.push_back(1);
    for(int i = N - 1; i >= 1; i--) {
      int x = A[i], y = A[i + 1];
      if(x/abs(x) == y/abs(y)) {
        j = i;
      }
      ans.push_back(j - i + 1);
    }
    reverse(ans.begin(), ans.end());
    for(auto it: ans) cout << it << " "; cout << endl;
  }
}
