#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int N, M;
long long K;
long long A[1001][1001];
long long B[1001][1001];
bool vis[1001][1001];
set<long long> divisors;
long long done = 0;

void dfs(int i, int j) {
  if(i < 1 || i > N || j < 1 || j > M) return;
  if(B[i][j] == 0) return;
  if(vis[i][j]) return;

  vis[i][j] = true;
  done += B[i][j];

  dfs(i + 1, j);
  dfs(i - 1, j);
  dfs(i, j + 1);
  dfs(i, j - 1);
}

void removeExtra(int i, int j) {
  if(i < 1 || i > N || j < 1 || j > M) return;
  if(B[i][j] == 0) return;

  if(vis[i][j]) return;
  if(done == K) {
    return;
  }

  vis[i][j] = true;

  done += B[i][j];

  removeExtra(i + 1, j);
  removeExtra(i - 1, j);
  removeExtra(i, j + 1);
  removeExtra(i, j - 1);
}


int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  cin >> N >> M >> K;
  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= M; j++) {
      cin >> A[i][j];

      if(K % A[i][j] == 0) divisors.insert(A[i][j]);
    }
  }

  bool pos = false;

  for(auto X: divisors) {
    for(int i = 1; i <= N; i++) {
      for(int j = 1; j <= M; j++) {
        if(A[i][j] < X) B[i][j] = 0;
        else B[i][j] = X;
        vis[i][j] = false;
      }
    }

    int start_i = -1, start_j = -1;
    for(int i = 1; i <= N; i++) {
      for(int j = 1; j <= M; j++) {
        if(vis[i][j]) continue;

        if(B[i][j] == X && A[i][j] == X) {
          done = 0;
          dfs(i, j);

          if(done >= K) {
            start_i = i, start_j = j;
            goto dfs_over;
          }
        }
      }
    }

dfs_over:
    bool valid = true;
    if(start_i == -1) valid = false;

    if(valid) {
      for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
          vis[i][j] = false;
        }
      }

      done = 0;
      removeExtra(start_i, start_j);

      pos = true;
      cout << "YES" << endl;
      for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
          if(!vis[i][j]) B[i][j] = 0;

          cout << B[i][j] << " ";
        }
        cout << endl;
      }
      break;
    }
  }

  if(!pos) cout << "NO" << endl;
}
