#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

vector<int> A;
int L[100001], R[100001], V[100001];
bool is_root[100001];
set<int> reachable;
int N;

void solve(int i, int qL, int qR) {
  if(i == -1) return;
  if(qL > qR) return;
  if(A[qL] <= V[i] && V[i] <= A[qR]) reachable.insert(V[i]);

  int t_r = (lower_bound(A.begin(), A.end(), V[i]) - A.begin()) - 1;
  int t_l = (upper_bound(A.begin(), A.end(), V[i]) - A.begin());

  solve(L[i], qL, min(t_r, qR));
  solve(R[i], max(t_l, qL), qR);
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int N; cin >> N;
  for(int i = 1; i <= N; i++) is_root[i] = true;


  for(int i = 1; i <= N; i++) {
    cin >> V[i] >> L[i] >> R[i];
    if(L[i] != -1) is_root[L[i]] = false;
    if(R[i] != -1) is_root[R[i]] = false;
    A.push_back(V[i]);
  }

  sort(A.begin(), A.end());
  A.resize(unique(A.begin(), A.end()) - A.begin());

  int root = -1;
  for(int i = 1; i <= N; i++) {
    if(is_root[i]) {
      root = i;
      break;
    }
  }

  solve(root, 0, A.size() - 1);
  int ans = 0;
  for(int i = 1; i <= N; i++) {
    if(reachable.count(V[i]) == 0) ans++;
  }
  cout << ans << endl;
}
