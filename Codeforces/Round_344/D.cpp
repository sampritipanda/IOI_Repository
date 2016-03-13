#include <iostream>
#include <algorithm>
#include <cassert>

using namespace std;

vector<pair<char, long long> > A, B, S;
int Z[500001];

pair<char, long long> input() {
  string S; cin >> S;

  int N = S.length();
  char c = S[N - 1];
  S.pop_back(); S.pop_back();
  N -= 2;
  assert(N == int(S.length()));

  long long num = 0;
  for(int i = 0; i < N; i++) {
    num = (num * 10) + (S[i] - '0');
  }

  return {c, num};
}

bool equal_pair(pair<char, long long> A, pair<char, long long> B, int pos) {
  bool cnd1 = (A.first == B.first);
  bool cnd2 = false;
  if(pos == 0) cnd2 = (A.second <= B.second);
  else cnd2 = (A.second == B.second);

  return cnd1 && cnd2;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int N, M; cin >> N >> M;
  A.push_back({'$', 0}); B.push_back({'$', 0});

  A[0] = input();
  for(int i = 1; i < N; i++) {
    pair<char, long long> curr = input();
    if(curr.first == A.back().first) {
      A.back().second += curr.second;
    }
    else {
      A.push_back(curr);
    }
  }
  N = A.size();

  B[0] = input();
  for(int i = 1; i < M; i++) {
    pair<char, long long> curr = input();
    if(curr.first == B.back().first) {
      B.back().second += curr.second;
    }
    else {
      B.push_back(curr);
    }
  }
  M = B.size();

  for(auto it: B) S.push_back(it);
  S.push_back({'$', 0});
  for(auto it: A) S.push_back(it);

  int len = S.size();

  Z[0] = -1;
  int L = 0, R = 0;
  for(int i = 1; i < len; i++) {
    if(i > R) {
      L = R = i;
      int cnt = 0;
      while(R < len && equal_pair(S[R-L], S[R], cnt++)) R++;
      Z[i] = R-L; R--;
    }
    else {
      int k = i-L;
      if(Z[k] < R-i+1) Z[i] = Z[k];
      else {
        L = i;
        int cnt = Z[k];
        while(R < len && equal_pair(S[R-L], S[R], cnt++)) R++;
        Z[i] = R-L; R--;
      }
    }
  }

  long long ans = 0;
  // S[M - 1] = last of substring, S[M] = seperator ( '$' )
  for(int i = M + 1; i < len; i++) {
    if(M == 1) {
      if(Z[i] <= 1 && B[0].first == S[i].first) ans += max(S[i].second - B[0].second + 1, 0LL);
    }
    else {
      if(Z[i] == M) ans++;
      else if(Z[i] == M - 1) {
        if(equal_pair(B[M - 1], S[i + Z[i]], 0)) ans++;
      }
    }
  }

  cout << ans << endl;
}
