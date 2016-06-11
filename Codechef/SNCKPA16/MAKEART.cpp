#include <iostream>

using namespace std;

int A[100001];

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int T; cin >> T;

  while(T--) {
    int N; cin >> N;

    for(int i = 1; i <= N; i++) cin >> A[i];

    bool pos = false;
    for(int i = 1; i <= N - 2; i++) {
      if(A[i] == A[i + 1] && A[i + 1] == A[i + 2]) pos = true;
    }
    if(pos) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
}
