#include <iostream>
#include <algorithm>

using namespace std;

int A[100001];

int main() {
  int N, K; cin >> N >> K;
  for(int i = 1; i <= N; i++) cin >> A[i];

  int min_el = *min_element(A + 1, A + N + 1);

  bool pos = true;
  long long ans = 0;
  for(int i = 1; i <= N; i++) {
    if((A[i] - min_el) % K == 0) {
      ans += (A[i] - min_el)/K;
    }
    else {
      pos = false;
      break;
    }
  }
  if(!pos) ans = -1;
  cout << ans << endl;
}

