#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int K, S;
vector<int> T[3001];
int dir_par[3001], dir_len[3001];
int sieve[1000001];
int val_cnt[1000001];
int D[3001];
set<int> D_set;
int file_par[3001], file_len[3001];
bool ans[3001];
vector<int> files_by_dir[3001];

void dfs_dist(int i, int d) {
  d += dir_len[i];
  D[i] = d;

  for(int u: T[i]) {
    dfs_dist(u, d);
  }
}

void add(int i, int d) {
  int len = d + S;
  if(len > 1000000) return;
  val_cnt[len]++;
  if(val_cnt[len] == 1) {
    for(int j = len; j <= 1000000; j += len) {
      sieve[j]++;
    }
  }
  for(int u: T[i]) {
    add(u, d + dir_len[u]);
  }
}

void remove(int i, int d) {
  for(int u: T[i]) {
    remove(u, d + dir_len[u]);
  }

  int len = d + S;
  if(len > 1000000) return;
  if(val_cnt[len] == 1) {
    for(int j = len; j <= 1000000; j += len) {
      sieve[j]--;
    }
  }
  val_cnt[len]--;
}

void dfs_solve_loop(int i) {
  add(i, 0);

  for(int q: files_by_dir[i]) {
    int req = K - file_len[q] - D[file_par[q]];
    if(req > 0 && sieve[req]) {
      ans[q] = true;
    }
  }

  for(int u: T[i]) {
    dfs_solve_loop(u);
  }

  remove(i, 0);
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int N, M; cin >> N >> M >> K;
  cin >> S; S++;

  dir_par[0] = -1; dir_len[0] = 1;
  for(int i = 1; i <= N; i++) {
    cin >> dir_par[i] >> dir_len[i];
    dir_len[i]++;
    T[dir_par[i]].push_back(i);
  }

  for(int i = 1; i <= M; i++) {
    cin >> file_par[i] >> file_len[i];
  }

  dfs_dist(0, 0);
  for(int i = 0; i <= N; i++) D_set.insert(D[i]);

  for(int i = 1; i <= M; i++) {
    int req = K - file_len[i];

    if(D[file_par[i]] == req) {
      ans[i] = true;
      continue;
    }

    int j = file_par[i], len = 0;
    while(j != -1) {
      if(D_set.count(req - len - S)) {
        ans[i] = true;
        break;
      }
      len += dir_len[j];
      j = dir_par[j];
    }
  }

  for(int i = 1; i <= M; i++) {
    files_by_dir[file_par[i]].push_back(i);
  }

  dfs_solve_loop(0);

  for(int i = 1; i <= M; i++) {
    if(ans[i]) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
}
