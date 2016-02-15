#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int N; cin >> N;
  vector<int> A(N);
  for(int i = 0; i < N; i++) cin >> A[i];

  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      if(i == j) cout << 0;
      else cout << min(A[i], A[j]);

      cout << " ";
    }
    cout << endl;
  }
}
