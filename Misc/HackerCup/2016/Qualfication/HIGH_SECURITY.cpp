// High Security

#include <iostream>
#include <algorithm>
#include <string>
#include <cassert>

using namespace std;

char G[1000][2];
int N;

void fill(int i, int j) {
  for(int k = i; k < N; k++) {
    if(G[k][j] == 'X') break;
    G[k][j] = '*';
  }
  for(int k = i - 1; k >= 0; k--) {
    if(G[k][j] == 'X') break;
    G[k][j] = '*';
  }
}

int solve() {
  if(N == 1) {
    if(G[0][0] == 'X' && G[0][1] == 'X') return 0;
    else return 1;
  }

  int ans = 0;

  for(int j = 0; j < 2; j++) {
    for(int i = 0; i < N; i++) {
      if(G[i][j] == '.') {
        if((i == 0 && G[i + 1][j] == 'X') || (i == N - 1 && G[i - 1][j] == 'X') || (i > 0 && i < N - 1 && G[i - 1][j] == 'X' && G[i + 1][j] == 'X')) {
          ans++;
          if(G[i][j^1] != 'X') fill(i, j^1);
          G[i][j] = '*';
        }
      }
    }
  }

  for(int j = 0; j < 2; j++) {
    for(int i = 0; i < N; i++) {
      if(G[i][j] == '.') {
        ans++;
        fill(i, j);
      }
    }
  }

  bool done = true;
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < 2; j++) {
      if(G[i][j] == '.') {
        done = false;
      }
    }
  }
  assert(done);

  return ans;
}

int main() {
  int T; cin >> T;

  for(int t = 1; t <= T; t++) {
    cin >> N;
    for(int j = 0; j < 2; j++) {
      for(int i = 0; i < N; i++) {
        cin >> G[i][j];
      }
    }

    cout << "Case #" << t << ": " << solve() << endl;
  }
}
