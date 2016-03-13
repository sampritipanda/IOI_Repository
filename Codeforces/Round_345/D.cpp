#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string X;
int A[500001];  // 1 = Vertical, 2 = Horizontal
long long P[500001];
long long S[500002];

int main() {
  int N; long long a, b, T; cin >> N >> a >> b >> T;

  cin >> X;
  for(int i = 0; i < N; i++) {
    if(X[i] == 'w') A[i + 1] = 2;
    else A[i + 1] = 1;
  }

  P[1] = 0;
  for(int i = 2; i <= N; i++) {
    P[i] = P[i - 1] + a;
    if(A[i] == 2) P[i] += b;
    P[i] += 1;
  }

  S[N + 1] = 0;
  for(int i = N; i >= 2; i--) {
    S[i] = S[i + 1] + a;
    if(A[i] == 2) S[i] += b;
    S[i] += 1;
  }

  int ans = 0;
  int first = (A[1] == 1 ? 0 : b) + 1;

  T -= first;
  if(T >= 0) ans++;

  int curr = 0;
  for(int i = N + 1; i >= 2; i--) {
    if(T < S[i]) break;

    int curr2 = 0;
    curr2 += (N + 1 - i);
    int curr_time = T - S[i];
    curr_time -= (N + 1 - i) * a;
    curr2 += max(0, (int)(upper_bound(P + 1, P + i, curr_time) - (P + 1) - 1));

    curr = max(curr, curr2);
  }

  reverse(S + 1, S + N + 2);

  for(int i = 1; i <= N; i++) {
    if(T < P[i]) break;

    int curr2 = 0;
    curr2 += (i - 1);
    int curr_time = T - P[i];
    curr_time -= (i - 1) * a;
    curr2 += max(0, (int)(upper_bound(S + 1, S + (N + 1 - i), curr_time) - (S + 1) - 1));

    curr = max(curr, curr2);
  }


  cout << ans + curr << endl;
}

