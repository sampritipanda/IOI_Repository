#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int F[100001];
int G[100001];
int H[100001];
int H_R[100001];

int main() {
  set<int> X;

  int N; cin >> N;
  for(int i = 1; i <= N; i++) {
    cin >> F[i];
    X.insert(F[i]);
  }

  int M = X.size();
  auto it = X.begin();
  for(int i = 1; i <= M; i++) {
    H[i] = *it;
    H_R[*it] = i;
    it++;
  }

  for(int i = 1; i <= N; i++) {
    G[i] = H_R[F[i]];
  }

  bool pos = true;
  for(int i = 1; i <= M; i++) {
    if(G[H[i]] != i) pos = false;
  }

  for(int i = 1; i <= N; i++) {
    if(H[G[i]] != F[i]) pos = false;
  }

  if(pos) {
    cout << M << endl;
    for(int i = 1; i <= N; i++) cout << G[i] << " "; cout << endl;
    for(int i = 1; i <= M; i++) cout << H[i] << " "; cout << endl;
  }
  else cout << -1 << endl;
}
