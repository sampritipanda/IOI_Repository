#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int vis[1 << 25];
int timer = 0;

inline int encode(int i, int j) {
  return i * N + j;
}

void print(int mask) {
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      if(mask & (1 << encode(i, j))) cout << 'R';
      else cout << 'W';
    }
    cout << endl;
  }
}

void dfs(int mask) {
  if(vis[mask]) return;
  vis[mask] = timer;

  for(int i = 0; i < N; i++) {
    if(i + 2 > N) break;
    for(int j = 0; j < N; j++) {
      if(j + 2 > N) break;
      int new_mask = mask;
      new_mask ^= (1 << encode(i, j));
      new_mask ^= (1 << encode(i + 1, j));
      new_mask ^= (1 << encode(i, j + 1));
      new_mask ^= (1 << encode(i + 1, j + 1));
      dfs(new_mask);
    }
  }
}

int main() {
  cin >> N;

  for(int i = 0; i < (1 << (N * N)); i++) {
    if(vis[i]) continue;

    ++timer;
    dfs(i);
  }

  for(int j = 1; j <= timer; j++) {
    cout << "\n" << j << "\n=========\n";

    for(int i = 0; i < (1 << (N * N)); i++) {
      if(vis[i] == j) {
        print(i);
        cout << endl;
      }
    }
  }
}
