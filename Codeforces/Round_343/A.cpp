#include <iostream>
#include <algorithm>

using namespace std;

bool A[101][101];

int main() {
  int N; cin >> N;

  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= N; j++) {
      char ch; cin >> ch;

      if(ch == 'C') A[i][j] = true;
    }
  }

  long long ans = 0;
  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= N; j++) {
      for(int k = j + 1; k <= N; k++) {
        if(A[i][j] && A[i][k]) ans++;
      }
    }
  }

  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= N; j++) {
      for(int k = j + 1; k <= N; k++) {
        if(A[j][i] && A[k][i]) ans++;
      }
    }
  }

  cout << ans << endl;
}
