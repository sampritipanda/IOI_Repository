#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int F[1000000];
int N;

void add(int L, int R) {
  F[L]++;
  if(R < N - 1) F[R + 1]--;
}

bool check(vector<int>& A, int len) {
  for(int i = 0; i < N; i++) F[i] = 0;

  for(int i = 0; i < N; i++) {
    int valid_L = A[i] - 1 - len, valid_R = A[i] - 1 + len;
    if(valid_L < 0) valid_L += N;
    if(valid_R >= N) valid_R -= N;

    int qL, qR;
    if(valid_L >= i) qL = valid_L - i;
    else qL = N - i + valid_L;

    if(valid_R >= i) qR = valid_R - i;
    else qR = N - i + valid_R;

    if(qL <= qR) add(qL, qR);
    else {
      add(qL, N - 1);
      add(0, qR);
    }
  }

  for(int i = 1; i < N; i++) F[i] += F[i - 1];

  for(int i = 0; i < N; i++) {
    if(F[i] == N) return true;
  }
  return false;
}

int solve(vector<int> A) {
  int L = 0, R = N/2;
  while(L < R) {
    int mid = (L + R)/2;
    if(check(A, mid)) {
      R = mid;
    }
    else {
      L = mid + 1;
    }
  }
  return L;
}

int main() {
  cin >> N;
  vector<int> A(N);
  for(int i = 0; i < N; i++) cin >> A[i];

  int ans = solve(A);
  if(A.size() > 1) reverse(A.begin() + 1, A.end());
  ans = min(ans, solve(A));
  cout << ans << endl;
}
