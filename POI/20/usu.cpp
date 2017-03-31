#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int A[1000000];
int P_0[1000000];
int P_1[1000000];
int N, K;

int count_pref(int j, int L, int R) {
  if(j == 0) {
    if(L == 0) return P_0[R];
    return P_0[R] - P_0[L - 1];
  }
  else {
    if(L == 0) return P_1[R];
    return P_1[R] - P_1[R - 1];
  }
}

void solve(int L, int R) {
  if(L > R) return;

  if(R - L == K) {
    for(int i = L; i <= R; i++) cout << i << " "; cout << endl;
    return;
  }

  for(int i = L + (K + 1); i <= R; i += (K + 1)) {
    if(count_pref(0, L, i) % K == 0 && count_pref(0, L, i)/K == count_pref(1, L, i)) {
      solve(L, i);
      solve(i + 1, R);
      return;
    }
  }

  int i = L, j = R;
  int cnt_0 = 0, cnt_1 = 0;
  while(i < j) {
    if(A[i] == 0 && cnt_0 < K) {
      cnt_0++;
      i++;
    }
    else if(A[i] == 1 && cnt_1 == 0) {
      cnt_1++;
      i++;
    }
    else if(A[j] == 0 && cnt_0 < K) {
      cnt_0++;
      j--;
    }
    else if(A[j] == 1 && cnt_1 == 0) {
      cnt_1++;
      j--;
    }

    if(cnt_0 == K && cnt_1 == 1) {
      for(int k = L; k < i; k++) cout << k << " ";
      for(int k = j + 1; k <= R; k++) cout << k << " ";
      cout << endl;

      solve(i, j);
      return;
    }
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  cin >> N >> K;
  string S; cin >> S;

  for(int i = 0; i < N; i++) {
    if(S[i] == 'b') A[i] = 1;
    else A[i] = 0;
  }
  P_0[0] = (A[0] == 0 ? 1 : 0);
  for(int i = 1; i < N; i++) {
    P_0[i] = P_0[i - 1] + (A[i] == 0 ? 1 : 0);
  }
  P_1[0] = (A[0] == 1 ? 1 : 0);
  for(int i = 1; i < N; i++) {
    P_1[i] = P_1[i - 1] + (A[i] == 1 ? 1 : 0);
  }

  solve(0, N - 1);
}
