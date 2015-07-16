// Strange operations

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  ios::sync_with_stdio(false);

  int T; cin >> T;

  while(T--) {
    int N, K; cin >> N >> K;

    int sum = 0;
    for(int i = 0; i < N; i++) {
      int a; cin >> a;
      sum += a;
      sum %= 2;
    }

    K--;
    while(K--) {
      sum += sum + 1;
      sum %= 2;
    }

    if((sum + 1) % 2 == 0) cout << "even" << endl;
    else cout << "odd" << endl;
  }
}
