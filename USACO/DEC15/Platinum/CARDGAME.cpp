#include <iostream>
#include <fstream>
#include <set>
#include <algorithm>

using namespace std;

#define in cin
#define out cout

int main() {
  ifstream in("cardgame.in");
  ofstream out("cardgame.out");

  int N; in >> N;
  vector<int> V(N);
  for(int i = 0; i < N; i++) in >> V[i];

  int final_ans = 0;
  for(int brk = N; brk >= 0; brk--) {
    set<int> A, B, X;
    for(int i = 1; i <= 2*N; i++) B.insert(i);
    for(auto i: V) B.erase(i);
    X = B;

    for(int i = 0; i < brk; i++) A.insert(V[i]);

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
    for(int i = brk; i < N; i++) A.insert(V[i]);

    auto x = A.begin(), y = B.begin();
    while(x != A.end() && y != B.end()) {
      if(*y < *x) {
        ans++;
        y++;
      }
      x++;
    }

    final_ans = max(final_ans, ans);
    if(final_ans == N) break;
  }
  out << final_ans << endl;
}
