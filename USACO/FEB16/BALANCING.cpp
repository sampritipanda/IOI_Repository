#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

#define MAX_N 1000000

vector<pair<int, int> > P;
int X[MAX_N + 1];
int Y[MAX_N + 1];
int T[MAX_N + 1];

int main() {
  freopen("balancing.in", "r", stdin);
  freopen("balancing.out", "w", stdout);

  ios::sync_with_stdio(false); cin.tie(0);

  int N; cin >> N;
  for(int i = 0; i < N; i++) {
    int x, y; cin >> x >> y;
    X[x]++; Y[y]++;
    P.push_back({x, y});
  }

  sort(P.begin(), P.end());

  for(int i = 1; i <= MAX_N; i++) {
    X[i] = X[i - 1] + X[i];
    Y[i] = Y[i - 1] + Y[i];
  }

  int ans = INT_MAX;
  {
    int a = -1, best = INT_MAX;
    for(int i = 0; i <= MAX_N; i += 2) {
      int curr = max(X[i], X[MAX_N] - X[i]);
      if(curr < best) {
        best = curr; a = i;
      }
    }

    for(int i = 0; i <= MAX_N; i++) T[i] = 0;
    for(auto it: P) {
      if(it.first <= a) T[it.second]++;
    }
    for(int i = 1; i <= MAX_N; i++) T[i] += T[i - 1];

    for(int b = 0; b <= MAX_N; b += 2) {
      int bottom_left = T[b];
      int bottom_right = Y[b] - bottom_left;
      int top_left = X[a] - bottom_left;
      int top_right = (Y[MAX_N] - Y[b]) - top_left;

      ans = min(ans, max(max(top_left, top_right), max(bottom_left, bottom_right)));
    }
  }

  {
    int b = -1, best = INT_MAX;
    for(int i = 0; i <= MAX_N; i += 2) {
      int curr = max(Y[i], Y[MAX_N] - Y[i]);
      if(curr < best) {
        best = curr; b = i;
      }
    }

    for(int i = 0; i <= MAX_N; i++) T[i] = 0;
    for(auto it: P) {
      if(it.second <= b) T[it.first]++;
    }
    for(int i = 1; i <= MAX_N; i++) T[i] += T[i - 1];

    for(int a = 0; a <= MAX_N; a += 2) {
      int bottom_left = T[a];
      int bottom_right = Y[b] - bottom_left;
      int top_left = X[a] - bottom_left;
      int top_right = (Y[MAX_N] - Y[b]) - top_left;

      ans = min(ans, max(max(top_left, top_right), max(bottom_left, bottom_right)));
    }
  }

  cout << ans << endl;
}

