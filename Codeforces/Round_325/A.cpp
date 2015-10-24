#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int N; cin >> N;
  int A[N];
  int count = 0;
  for(int i = 0; i < N; i++) {
    cin >> A[i];
    if(A[i]) count++;
  }
  if(count == 0) {
    cout << 0 << endl;
    return 0;
  }

  int first = -1, last = -1;
  for(first = 0; first < N; first++)
    if(A[first] == 1) break;
  for(last = N - 1; last >= 0; last--)
    if(A[last] == 1) break;

  int ans = 0;
  int i = first;
  bool at = false;
  while(i <= last) {
    if(A[i]) at = true;
    if(at) {
      ans++;
      if(i < N - 2 && A[i + 1] == 0 && A[i + 2] == 0) at = false;
    }
    i++;
  }
  cout << ans << endl;
}
