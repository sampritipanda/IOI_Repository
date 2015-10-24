#include <bits/stdc++.h>

using namespace std;

int check(int n) {
  for(int i = 2; i*i <= n; i++) {
    if(n % i == 0) return 0;
  }
  return 1;
}

int main() {
  int N; cin >> N;

  if(check(N)) cout << 1 << endl << N << endl;
  else if(check(N - 2)) cout << "2\n2 " << N - 2 << endl;
  else if(check(N - 3)) cout << "2\n3 " << N - 3 << endl;
  else {
    cout << 3 << endl;
    N -= 3;
    for(int i = 2; i <= 100000; i++) {
      if(check(i) && check(N - i)) {
        cout << 3 << " " << i << " " << N - i << endl;
        break;
      }
    }
  }
}
