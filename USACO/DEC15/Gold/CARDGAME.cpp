#include <iostream>
#include <fstream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

// #define in cin
// #define out cout

int main() {
  ifstream in("cardgame.in");
  ofstream out("cardgame.out");

  int N; in >> N;
  vector<int> V(N);
  for(int i = 0; i < N; i++) in >> V[i];

  set<int> A, B, X;
  for(int i = 1; i <= 2*N; i++) B.insert(i);
  for(auto i: V) B.erase(i);
  X = B;

  for(int i = 0; i < N/2; i++) A.insert(V[i]);

  int ans = 0;
  auto i = A.rbegin(), j = B.rbegin();
  while(i != A.rend() && j != B.rend()) {
    if(*j > *i) {
      ans++;
      X.erase(*j);
      j++;
    }
    i++;
  }

  B = X;
  A.clear();
  for(int i = N/2; i < N; i++) A.insert(V[i]);

  auto x = A.begin(), y = B.begin();
  while(x != A.end() && y != B.end()) {
    if(*y < *x) {
      ans++;
      y++;
    }
    x++;
  }

  out << ans << endl;
}
