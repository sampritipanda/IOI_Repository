#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

map<string, int> S_M;
int U[100001];
int C[100001];

int find(int i) {
  if(U[i] == i) return i;
  return U[i] = find(U[i]);
}

void merge(int a, int b) {
  a = find(a), b = find(b);
  if(a != b) {
    U[a] = b;
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int N, M, Q; cin >> N >> M >> Q;

  for(int i = 1; i <= N; i++) {
    string S; cin >> S;
    S_M[S] = i;
    U[i] = i;
    C[i] = 0;
  }

  while(M--) {
    int t; string s_x, s_y; cin >> t >> s_x >> s_y;
    int x = S_M[s_x], y = S_M[s_y];

    if(t == 1) {
      if(C[x] != 0 && C[y] != 0 && ) 
    }
  }
}
