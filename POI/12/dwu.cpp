// Same Side => (u | v) & (!u | !v)
// Different => (u | !v) & (!u | v)

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cassert>
#include <vector>
#include <map>
#include <set>
#include <climits>

using namespace std;

const int MAX_M = 100000;

int A[50000];
int B[50000];
vector<int> I_A[MAX_M + 1];
vector<int> I_B[MAX_M + 1];

vector<int> G[100000];
int ans[50000];

void add(int u, int v) {
  // (u | v) === (!u => v) === (!v => u)
  G[u ^ 1].push_back(v);
  G[v ^ 1].push_back(u);
}

void dfs(int i, int p, int s, vector<int>& curr) {
  if(i == s && p != -1) return;

  curr.push_back(i);

  for(int j = 0; j < G[i].size(); j++) {
    if(G[i][j] == p) continue;
    dfs(G[i][j], i, s, curr);
  }
}

int main() {
  int N; scanf("%d", &N);

  for(int i = 0; i < N; i++) {
    scanf("%d", &A[i]);
    I_A[A[i]].push_back(i);
  }
  for(int i = 0; i < N; i++) {
    scanf("%d", &B[i]);
    I_B[B[i]].push_back(i);
  }

  for(int i = 1; i <= MAX_M; i++) {
    if(I_A[i].size() == 2) {
      int u = I_A[i][0] * 2, v = I_A[i][1] * 2;
      add(u, v); add(u ^ 1, v ^ 1);
    }
    else if(I_B[i].size() == 2) {
      int u = I_B[i][0] * 2, v = I_B[i][1] * 2;
      add(u, v); add(u ^ 1, v ^ 1);
    }
    else if(I_A[i].size() == 1 && I_B[i].size() == 1) {
      int u = I_A[i][0] * 2, v = I_B[i][0] * 2;
      add(u, v ^ 1); add(u ^ 1, v);
    }
  }

  set<int> temp;
  for(int i = 0; i < 2 * N; i++) {
    if(G[i].size() == 1) temp.insert(i);
  }

  for(int i = 0; i < 2 * N; i++) {
    assert(G[i].size() <= 2);
  }

  for(int i = 0; i < N; i++) ans[i] = -1;

  for(int i = 0; i < 2 * N; i++) {
    if(ans[i/2] != -1 || G[i].size() == 0) continue;

    vector<int> curr;
    dfs(i, -1, i, curr);

    int type_1 = 0, type_2 = 0;
    // Set False
    for(int j = 0; j < curr.size(); j++) {
      if(curr[j] % 2 == 1) type_1++;
    }
    // Set True
    for(int j = 0; j < curr.size(); j++) {
      if(curr[j] % 2 == 0) type_2++;
    }

    if(type_1 <= type_2) {
      for(int j = 0; j < curr.size(); j++) {
        if(curr[j] % 2 == 1) {
          ans[curr[j]/2] = 1;
        }
        else {
          ans[curr[j]/2] = 0;
        }
      }
    }
    else {
      for(int j = 0; j < curr.size(); j++) {
        if(curr[j] % 2 == 0) {
          ans[curr[j]/2] = 1;
        }
        else {
          ans[curr[j]/2] = 0;
        }
      }
    }
  }

  int cnt = 0;
  for(int i = 0; i < N; i++) {
    if(ans[i] == 1) cnt++;
  }
  printf("%d\n", cnt);

  // DEBUG
  for(int i = 0; i < N; i++) {
    if(ans[i] == 1) cerr << i + 1 << " ";
  }
  cerr << endl << endl;

  for(int i = 0; i < 2 * N; i++) {
    if(i % 2 == 0)
      cerr << i/2 << ": ";
    else
      cerr << "!" << i/2 << ": ";
    for(int x: G[i]) {
      if(x % 2 == 0)
        cerr << x/2 << " ";
      else
        cerr << "!" << x/2 << " ";

    }
    cerr << endl;
  }
  // DEBUG - END
}
