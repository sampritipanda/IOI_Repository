// Age of Ultron

#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
  int T; cin >> T;

  while(T--) {
    int N; cin >> N;

    int count = 0;

    while(N % 2 == 0) {
      count++;
      N /= 2;
    }

    for(int i = 3; i <= sqrt(N); i += 2) {
      while(N % i == 0) {
        count++;
        N /= i;
      }
    }

    if(N > 2) count++;

    cout << count << endl;
  }
}
