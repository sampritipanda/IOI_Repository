#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct seg {
  int L, R, i;
};

bool compare(seg A, seg B) {
  return (A.R - A.L) < (B.R - B.L);
}

vector<seg> A;

int dp[501];
int best[501];   //  -1 = Ends here, >= 0 = Next ID

int solve(int i) {
  if(i == A.size()) return 0;
  if(dp[i] != -1) return dp[i];

  int ans = 1; best[i] = -1;
  for(int j = i + 1; j < A.size(); j++) {
    if(A[j].L < A[i].L && A[j].R > A[i].R) {
      if(1 + solve(j) > ans) {
        ans = 1 + solve(j);
        best[i] = j;
      }
    }
  }
  return dp[i] = ans;
}

int main() {
  for(int i = 0; i <= 500; i++) dp[i] = -1;

  int N; cin >> N;
  for(int i = 1; i <= N; i++) {
    seg curr; curr.i = i;
    cin >> curr.L >> curr.R;
    A.push_back(curr);
  }

  sort(A.begin(), A.end(), compare);

  int curr = -1, m = 0;
  for(int i = 0; i < A.size(); i++) {
    if(solve(i) > m) {
      m = solve(i);
      curr = i;
    }
  }

  cout << m << endl;

  vector<int> ans;
  while(curr < N) {
    if(best[curr] == -2) curr++;
    else {
      ans.push_back(A[curr].i);
      if(best[curr] == -1) break;
      else curr = best[curr];
    }
  }
  for(int i = 0; i < ans.size(); i++) {
    if(i > 0) cout << " ";
    cout << ans[i];
  }
  cout << endl;
}
