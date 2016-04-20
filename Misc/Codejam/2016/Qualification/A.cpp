#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
  int T; cin >> T;

  for(int t = 1; t <= T; t++) {
    long long N; cin >> N;
    bool freq[10];
    for(int i = 0; i < 10; i++) freq[i] = false;

    bool done = false;

    for(int i = 1; i <= 100000; i++) {
      long long X = N * i;
      if(X == 0) freq[0] = true;
      while(X > 0) {
        int d = X % 10;
        freq[d] = true;
        X /= 10;
      }

      bool all = true;
      for(int i = 0; i < 10; i++)
        if(!freq[i]) all = false;

      if(all) {
        done = true;
        cout << "Case #" << t << ": " << (N * i) << endl;
        break;
      }
    }

    if(!done) {
      cout << "Case #" << t << ": INSOMNIA" << endl;
    }
  }
}
