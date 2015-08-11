// Chef and insomnia

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int A[1000];
bool bad[1000][1000];

int main() {
  memset(bad, false, sizeof bad);

  int N, K; cin >> N >> K;
  for(int i = 0; i < N; i++) cin >> A[i];

  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      if(i < j && A[i] % A[j] == K) bad[i][j] = true;
    }
  }

  long long ans = 0;
  for(int i = 0; i < N; i++) {
    int j = i + 1;
    for(; j < N; j++) {
      if(i < j && A[i] % A[j] == K) break;
    }
    cout << i << " " << j << endl;
    ans += j - i;
  }

  cout << ans << endl;
}
