#include <iostream>
#include <algorithm>

using namespace std;

bool prime[100002];

int main() {
  for(int i = 2; i <= 100001; i++) prime[i] = true;

  for(int i = 2; i <= 100001; i++) {
    if(!prime[i]) continue;
    for(int j = i + i; j <= 100001; j += i) {
      prime[j] = false;
    }
  }

  int N; cin >> N;

  if(N <= 2) cout << 1 << endl;
  else cout << 2 << endl;
  for(int i = 2; i <= N + 1; i++) cout << (prime[i] ? 1 : 2) << " ";
  cout << endl;
}
