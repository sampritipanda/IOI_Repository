// Jimma and Chingam 

#include <iostream>
#include <algorithm>

using namespace std;

int N;
vector<int> A;
int dp[101][101][2][2];
vector<int> freq[101][101][2][2];

int query(vector<int>& bit, int i) {
  int res = 0;
  while(i > 0) {
    res += bit[i];
    i += i & -i;
  }
  return res;
}

void update(vector<int>& bit, int i) {
  while(i <= 1001) {
    bit[i] += 1;
    i += i & -i;
  }
}

int solve(int L, int R, int i, int j) {
  if(L > R) return 0;

  vector<pair<int, vector<int> > > sort_arr;
  if(i == 0) {
    if(j == 0) {
    }
    else {
    }
  }
  else {
    if(j == 0) {
    }
    else {
    }
  }
}

int main() {
  int T; cin >> T;

  while(T--) {
    cin >> N;
    A.resize(N);
    for(int i = 0; i < N; i++) cin >> A[i];
    for(int i = 0; i < N; i++) A[i]++;

    cout << min(min(solve(0, N - 1, 0, 0), solve(0, N - 1, 0, 1)), min(solve(0, N - 1, 1, 0), solve(0, N - 1, 1, 1))) << endl;
  }
}
