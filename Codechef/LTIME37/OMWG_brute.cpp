#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int N, M;
map<vector<vector<int>>, int> memo;

int solve(vector<vector<int> > A) {
  if(memo.count(A) > 0) return memo[A];
  // cout << memo.size() << endl;

  int ans = 0;
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < M; j++) {
      if(A[i][j]) continue;
      vector<vector<int> > T = A;
      T[i][j] = 1;
      int curr = 0;
      if(i - 1 >= 0) curr += A[i - 1][j];
      if(i + 1 < N) curr += A[i + 1][j];
      if(j - 1 >= 0) curr += A[i][j - 1];
      if(j + 1 < M) curr += A[i][j + 1];
      ans = max(ans, solve(T) + curr);
    }
  }
  memo[A] = ans;
  return ans;
}

int main() {
  cin >> N >> M;

  vector<vector<int> > A(N, vector<int>(M));

  cout << solve(A) << endl;
}
