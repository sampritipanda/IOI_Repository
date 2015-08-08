// Greedy puppy

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int T; cin >> T;

  while(T--) {
    int N, K; cin >> N >> K;
    int max_possible = -1;

    for(int i = 1; i <= K; i++) {
      max_possible = max(max_possible, N % i);
    }

    cout << max_possible << endl;
  }
}
