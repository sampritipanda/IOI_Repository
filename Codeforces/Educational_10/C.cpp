#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int A[300001];
int I[300001];
int start[300002];

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int N, M; cin >> N >> M;

  for(int i = 1; i <= N; i++) {
    cin >> A[i];
    I[A[i]] = i;
  }

  memset(start, -1, sizeof start);

  while(M--) {
    int a, b; cin >> a >> b;
    a = I[a], b = I[b];
    if(a > b) swap(a, b);
    start[b] = max(start[b], a);
  }

  vector<int> S;
  S.push_back(N + 1);
  for(int i = N; i >= 1; i--) {
    if(start[i] != -1) S.push_back(i);
  }

  long long ans = 0;
  for(int i = 1; i <= N; i++) {
    while(start[S.back()] != -1 && i > start[S.back()]) S.pop_back();
    int nex = S.back();
    ans += nex - i;
    if(i == start[nex]) S.pop_back();
  }
  cout << ans << endl;
}
