#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int A[1001];

int main() {
  int N, S; cin >> N >> S;

  for(int i = 0; i <= S; i++) {
    A[i] = 0;
  }

  for(int i = 0; i < N; i++) {
    int f, s; cin >> f >> s;
    A[f] = max(A[f], s);
  }

  int time = A[S];
  for(int i = S - 1; i >= 0; i--) {
    time++;
    time = max(time, A[i]);
  }
  cout << time << endl;
}
