#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

#define MOD 1000000007

int start_time[10001];
int end_time[10001];
bool visited[10001];
int timer = 0;

vector<int> tree[10001];
long long segtree[40004];

unordered_map<long long,long long> Fib;
 
long long fib(long long n)
{
    if(n<2) return 1;
    if(Fib.find(n) != Fib.end()) return Fib[n];
    Fib[n] = (fib((n+1) / 2)*fib(n/2) + fib((n-1) / 2)*fib((n-2) / 2)) % 100000;
    return Fib[n];
}

void dfs(int i) {
  if(visited[i]) return;

  visited[i] = true;
  start_time[i] = ++timer;

  for(auto v: tree[i]) {
    dfs(v);
  }

  end_time[i] = timer;
}

void init_tree(int L, int R, int i) {
  if(L == R) {
    segtree[i] = 1;
    return;
  }

  int mid = L + (R - L)/2;
  init_tree(L, mid, 2*i + 1);
  init_tree(mid + 1, R, 2*i + 2);
  segtree[i] = (segtree[2*i + 1] + segtree[2*i + 2]) % MOD;
}

long long query(int L, int R, int i, int qS, int qE) {
  if(qS > R || qE < L) return 0;

  if(qS <= L && R <= qE) {
    return segtree[i];
  }

  int mid = L + (R - L)/2;
  return (query(L, mid, 2*i + 1, qS, qE) + query(mid + 1, R, 2*i + 2, qS, qE)) % MOD;
}

void update(int L, int R, int i, int pos, int val) {
  if(pos > R || pos < L) return;
  segtree[i] = (segtree[i] + val) % MOD;

  if(L != R) {
    int mid = L + (R - L)/2;
    update(L, mid, 2*i + 1, pos, val);
    update(mid + 1, R, 2*i + 2, pos, val);
  }
}

int main() {
  int N, Q; cin >> N >> Q;
  for(int i = 1; i <= N; i++) {
    tree[i].clear();
    visited[i] = false;
  }

  for(int i = 0; i < N - 1; i++) {
    int u, v; cin >> u >> v;
    tree[u].push_back(v);
    tree[v].push_back(u);
  }

  dfs(1);
  init_tree(1, N, 0);

  while(Q--) {
    int type; cin >> type;

    if(type == 0) {
      int v, m; cin >> v >> m;
      if(m & 1) continue;
      else {
        long long add = (m * fib(m/2)) % MOD;
        update(1, N, 0, start_time[v], add);
      }
    }
    else {
      int v; cin >> v;
      cout << query(1, N, 0, start_time[v], end_time[v]) << endl;
    }
  }
}
