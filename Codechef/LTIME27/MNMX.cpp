#include <iostream>
#include <algorithm>

using namespace std;

int A[50000];

int main() {
  int T; cin >> T;

  while(T--) {
    int N; cin >> N;
    for(int i = 0; i < N; i++) {
      cin >> A[i];
    }
    cout << ((long long)(*min_element(A, A + N))) * (N - 1) << endl;
  }
}
