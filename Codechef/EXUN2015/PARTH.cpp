#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> A;

int find(int i) {
  if(A[i] == i) return i;
  else return A[i] = find(A[i]);
}

void merge(int i, int j) {
  i = find(i), j = find(j);
  A[i] = j;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N = 30000;
  A.resize(N + 1);
  for(int i = 0; i <= N; i++) A[i] = i;

  int T; cin >> T;

  while(T--) {
    char c; cin >> c;
    int i, j; cin >> c;

    if(c == 'M') {
      merge(i, j);
    }
    else {
    }
  }
}
