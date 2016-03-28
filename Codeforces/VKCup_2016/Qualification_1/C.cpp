#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<string> A;

int main() {
  int N; cin >> N;
  A.resize(N);
  for(int i = 0; i < N; i++) {
    cin >> A[i];
  }

  int ans = 6;
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      if(i == j) continue;

      int cnt = 0;
      for(int k = 0; k < 6; k++)
        if(A[i][k] != A[j][k]) cnt++;

      ans = min(ans, (cnt + 1)/2 - 1);
    }
  }
  cout << ans << endl;
}
