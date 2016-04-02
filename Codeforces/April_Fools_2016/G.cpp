#include <iostream>
#include <algorithm>

using namespace std;

char A[10][10];
int cnt[10];

int main() {
  int F, I, T; cin >> F >> I >> T;

  for(int i = 0; i < F; i++) {
    for(int j = 0; j < I; j++) {
      cin >> A[i][j];
      if(A[i][j] == 'Y') {
        cnt[j]++;
      }
    }
  }

  int ans = 0;
  for(int i = 0; i < I; i++) {
    if(cnt[i] >= T) ans++;
  }
  cout << ans << endl;

  // xxxxxxx
}
