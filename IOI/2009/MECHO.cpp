#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <climits>

using namespace std;

int R[800][800];  // min time for bees to spread here
char A[800][800];
bool vis[800][800];
int N, S;

bool check(int i, int j) {
  if(i < 0 || i >= N) return false;
  if(j < 0 || j >= N) return false;
  if(vis[i][j] || A[i][j] == 'T') return false;
  return true;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  cin >> N >> S;

  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      cin >> A[i][j];
    }
  }

  queue<vector<int> > Q;

  int s_i, s_j, d_i, d_j;

  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      R[i][j] = INT_MAX/2;

      if(A[i][j] == 'M') {
        s_i = i; s_j = j;
      }
      else if(A[i][j] == 'D') {
        d_i = i; d_j = j;
      }
      else if(A[i][j] == 'H') {
        Q.push({i, j, 0});
      }
    }
  }

  while(!Q.empty()) {
    int i = Q.front()[0], j = Q.front()[1], t = Q.front()[2];
    Q.pop();

    if(R[i][j] != INT_MAX/2 || A[i][j] == 'T' || A[i][j] == 'D') continue;
    R[i][j] = t;

    if(i > 0) Q.push({i - 1, j, t + 1});
    if(i < N - 1) Q.push({i + 1, j, t + 1});
    if(j > 0) Q.push({i, j - 1, t + 1});
    if(j < N - 1) Q.push({i, j + 1, t + 1});
  }

  int left = -1, right = N * N;

  while(left < right) {
    int mid = (left + right + 1)/2;

    for(int i = 0; i < N; i++) {
      for(int j = 0; j < N; j++) {
        vis[i][j] = false;
      }
    }
    while(!Q.empty()) Q.pop();

    int min_time = INT_MAX/2;
    Q.push({s_i, s_j, mid * S});

    while(!Q.empty()) {
      int i = Q.front()[0], j = Q.front()[1], t = Q.front()[2];
      Q.pop();

      if(i == d_i && j == d_j) {
        min_time = t;
        break;
      }

      if(vis[i][j] || A[i][j] == 'T' || R[i][j] * S <= t) continue;
      vis[i][j] = true;

      if(check(i - 1, j)) Q.push({i - 1, j, t + 1});
      if(check(i + 1, j)) Q.push({i + 1, j, t + 1});
      if(check(i, j - 1)) Q.push({i, j - 1, t + 1});
      if(check(i, j + 1)) Q.push({i, j + 1, t + 1});
    }

    if(min_time != INT_MAX/2) {
      left = mid;
    }
    else {
      right = mid - 1;
    }
  }

  cout << left << endl;
}
