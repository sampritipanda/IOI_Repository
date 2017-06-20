#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
vector<int> A;
int rev_A[2000001];
int jmp[2000001];
int vis[2000001];

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  cin >> N >> M;

  A.push_back(0);
  for(int i = 0; i < N; i++) {
    int L, R; cin >> L >> R;
    A.push_back(L);
    A.push_back(R);
    jmp[L] = R;
    jmp[R] = L;
  }
  sort(A.begin(), A.end());
  for(int i = 0; i < A.size(); i++) {
    rev_A[A[i]] = i;
  }

  long long ans = 0;
  int curr = 0;
  while(curr != A.size() - 1) {
    vis[curr] = 1;
    curr = rev_A[jmp[A[curr + 1]]];
    ans++;
  }

  vector<int> cands;
  for(int i = 0; i < A.size() - 1; i++) {
    if(vis[i]) continue;

    int curr = i, cnt = 0;
    while(!vis[curr]) {
      vis[curr] = 1;
      curr = rev_A[jmp[A[curr + 1]]];
      cnt++;
    }

    cands.push_back(cnt);
  }

  sort(cands.begin(), cands.end());

  while(M > 0 && !cands.empty()) {
    ans += cands.back() + 2;
    cands.pop_back();
    M--;
  }

  ans += M/2 * 4;
  if(M % 2) ans++;

  cout << ans << endl;
}
