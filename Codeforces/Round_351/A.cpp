#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int A[5001];
int ans[5001];
int F[5001];

int main() {
  int N; cin >> N;

  for(int i = 1; i <= N; i++) cin >> A[i];

  for(int i = 1; i <= N; i++) {
    memset(F, 0, sizeof F);
    int el = -1, freq = 0;
    for(int j = i; j <= N; j++) {
      F[A[j]]++;
      if(F[A[j]] > freq || (F[A[j]] == freq && A[j] < el)) {
        freq = F[A[j]];
        el = A[j];
      }
      ans[el]++;
    }
  }

  for(int i = 1; i <= N; i++) cout << ans[i] << " ";
  cout << endl;
}
