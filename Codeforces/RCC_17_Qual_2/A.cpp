#include <iostream>
#include <algorithm>

using namespace std;

int A[21][21];

int main() {
  int T; cin >> T;

  while(T--) {
    int N, M; cin >> N >> M;

    int curr = N * M;
    for(int i_ = 1; i_ <= N; i_++) {
      int i = i_, j = 1;
      while(i >= 1 && j <= M) {
        A[i][j] = curr--;
        i--; j++;
      }
    }
    for(int j_ = 2; j_ <= M; j_++) {
      int i = N, j = j_;
      while(i >= 1 && j <= M) {

        A[i][j] = curr--;
        i--; j++;
      }
    }

    for(int i = 1; i <= N; i++) {
      for(int j = 1; j <= M; j++) {
        cout << A[i][j] << " ";
      }
      cout << endl;
    }
  }
}
