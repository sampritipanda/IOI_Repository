// Presents

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int N; cin >> N;
  int A[N + 1];
  for(int i = 1; i <= N; i++) {
    int p; cin >> p;
    A[p] = i;
  }

  for(int i = 1; i <= N; i++) cout << A[i] << " ";
  cout << endl;
}
