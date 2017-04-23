#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>

using namespace std;

vector<int> A, P;
vector<vector<int> > ans;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int N, K; cin >> N >> K;
  string S; cin >> S;

  A.push_back(0);
  P.push_back(0);

  for(int i = 1; i <= N; i++) {
    A.push_back(i);
    P.push_back(P.back() + (S[i - 1] == 'b' ? 1 : -K));

    if((P.size() - 1) >= (K + 1) && (P.back() - *(P.rbegin() + (K + 1))) == 0) {
      ans.push_back(vector<int>());
      for(int j = 0; j < (K + 1); j++) {
        ans.back().push_back(A.back());
        A.pop_back();
        P.pop_back();
      }
    }
  }

  for(int i = ans.size() - 1; i >= 0; i--) {
    for(int j = ans[i].size() - 1; j >= 0; j--) {
      cout << ans[i][j] << " ";
    }
    cout << endl;
  }
}
