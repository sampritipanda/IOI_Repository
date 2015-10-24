// Count Subarrays 

#include <iostream>
#include <algorithm>

using namespace std;

int A[100000];

int main() {
  int T; cin >> T;

  while(T--) {
    int N; cin >> N;
    for(int i = 0; i < N; i++) cin >> A[i];

    long long ans = 0;
    long long i = 0, curr_length = 1;
    while(i < N) {
      if(i < N - 1 && A[i] <= A[i + 1]) {
        curr_length++;
      }
      else {
        ans += ((curr_length + 1) * curr_length)/2;
        curr_length = 1;
      }
      i++;
    }
    cout << ans << endl;
  }
}
