#include <iostream>
#include <algorithm>
#include <set>
#include <queue>

using namespace std;

int N;
int S, F, R; 
int shortest_path = -1;
int D_R[100001];
vector<int> G[100001];
queue<pair<int, int> > Q; // {vertex, distance}
bool visited[100001];
bool selected[100001];

// whether answer is >= d
bool check(int d) {
  for(int i = 0; i <= N; i++) {
    visited[i] = false;
    selected[i] = true;
  }

  // remove all nodes at a distance < d from R
  for(int i = 1; i <= N; i++) {
    if(D_R[i] < d) selected[i] = false;
  }

  int new_shortest = -1;
  while(!Q.empty()) Q.pop();
  if(selected[S]) Q.push({S, 0});

  while(!Q.empty()) {
    int u = Q.front().first, d = Q.front().second; Q.pop();

    if(visited[u]) continue;
    visited[u] = true;

    if(u == F) {
      new_shortest = d;
      break;
    }

    for(auto v: G[u]) {
      if(selected[v]) {
        Q.push({v, d + 1});
      }
    }
  }

  return new_shortest == shortest_path;
}

int main() {
  int M; cin >> N >> M;

  while(M--) {
    int a, b; cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  cin >> S >> F >> R;

  for(int i = 0; i <= N; i++) visited[i] = false;
  while(!Q.empty()) Q.pop();
  Q.push({S, 0});
  while(!Q.empty()) {
    int u = Q.front().first, d = Q.front().second; Q.pop();

    if(visited[u]) continue;
    visited[u] = true;

    if(u == F) {
      shortest_path = d;
      break;
    }

    for(auto v: G[u]) {
      Q.push({v, d + 1});
    }
  }

  for(int i = 0; i <= N; i++) visited[i] = false;
  while(!Q.empty()) Q.pop();
  Q.push({R, 0});
  while(!Q.empty()) {
    int u = Q.front().first, d = Q.front().second; Q.pop();

    if(visited[u]) continue;
    visited[u] = true;

    D_R[u] = d;

    for(auto v: G[u]) {
      Q.push({v, d + 1});
    }
  }

  int L = 0, R = N;
  while(L < R) {
    int mid = (L + R + 1)/2;

    // ans >= mid
    if(check(mid)) {
      L = mid;
    }
    else {
      R = mid - 1;
    }
  }

  cout << L << endl;
}
