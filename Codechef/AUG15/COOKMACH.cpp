// Cooking Machine

#include <iostream>
#include <algorithm>

using namespace std;

bool is_power2(int a) {
  return (__builtin_popcount(a) == 1);
}

int main() {
  int T; cin >> T;

  while(T--) {
    int A, B; cin >> A >> B;

    int count = 0;
    if(A > B) {
      while(A > B || !is_power2(A)) {
        if(A & 1) A = (A - 1)/2;
        else A /= 2;

        count++;
      }

      while(A != B) A *= 2, count++;
    }
    else if (A < B){
      while(!is_power2(A)) {
        if(A & 1) A = (A - 1)/2;
        else A /= 2;

        count++;
      }

      while(A != B) A *= 2, count++;
    }

    cout << count << endl;
  }
}
