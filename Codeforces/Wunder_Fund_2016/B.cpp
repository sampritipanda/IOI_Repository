#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int A[50][50];
int ans[50];

int main() {
  int N; cin >> N;
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      cin >> A[i][j];
    }
  }

  int cnt = 0;
  for(int i = 0; i < N; i++) {
    map<int, int> F;
    for(int j = 0; j < N; j++) {
      if(i == j) continue;
      F[A[i][j]]++;
    }

    int val = 0;
    for(auto it: F) {
      if(it.second > 1) {
        val = it.first;
        break;
      }
    }

    if(val != 0) ans[i] = val;
    else {
      if(cnt == 0) ans[i] = N - 1;
      else ans[i] = N;

      cnt++;
    }
  }

  for(int i = 0; i < N; i++) cout << ans[i] << " "; cout << endl;
}
