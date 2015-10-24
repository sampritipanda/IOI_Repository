// Hamro and array

#include <iostream>
#include <algorithm>

using namespace std;

long long A[100001];
long long prefix_1[100001], prefix_2[100001];
int sign_1[100001], sign_2[100001];

int main() {
  int N, Q; cin >> N >> Q;
  for(int i = 1; i <= N; i++) cin >> A[i];

  prefix_1[0] = sign_1[0] = 0;
  for(int i = 1; i <= N; i++) {
    sign_1[i] = (i & 1 ? 1 : -1);
    prefix_1[i] = prefix_1[i - 1] + sign_1[i] * A[i];
  }

  prefix_2[0] = sign_2[0] = 0;
  for(int i = 1; i <= N; i++) {
    sign_2[i] = (i & 1 ? -1 : 1);
    prefix_2[i] = prefix_2[i - 1] + sign_2[i] * A[i];
  }

  while(Q--) {
    int L, R; cin >> L >> R;
    if(sign_1[L] == 1) {
      cout << prefix_1[R] - prefix_1[L - 1] << endl;
    }
    else {
      cout << prefix_2[R] - prefix_2[L - 1] << endl;
    }
  }
}
