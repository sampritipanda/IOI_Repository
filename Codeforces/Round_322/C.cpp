#include <iostream>
#include <algorithm>

using namespace std;

int N , K;
long long A[100001];

bool cmp(int x, int y) {
  return (x % 10) > (y % 10);
}

int main() {
  cin >> N >> K;
  for(int i = 1; i <= N; i++) cin >> A[i];

  sort(A + 1, A + 1 + N, cmp);

  while(1){
    bool ok = true;
    bool ok2= true;
    for( int i = 1 ; i <= N ; i++ ){
      int nxt = 10 - (A[i] % 10);
      if( A[i] != 100 ) ok = false;
      if( A[i] == 100 ) continue;
      if( K < nxt ) continue;
      ok2= false;
      K -= nxt;
      A[i] += nxt;
    }

    if( ok or ok2 ) break;
  }

  long long ans = 0;
  for(int i = 1; i <= N; i++) ans += A[i]/10;

  cout << ans << endl;
}
