#include <iostream>
#include <algorithm>
#include <cstring>
#include <climits>
#include <cmath>

using namespace std;

int main() {
  int N; cin >> N;
  int A[N];

  for(int i = 0; i < N; i++) {
    cin >> A[i];
  }

  sort(A, A + N);
  int ans = 0;
  for(int i = 0; i < N; i++) {
    if(A[i] != (i + 1)) ans++;
  }
  cout << ans << endl;
}
