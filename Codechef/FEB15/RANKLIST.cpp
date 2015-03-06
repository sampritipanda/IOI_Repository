// Let us play with rank list

#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
  int T; cin >> T;

  while(T--){
    long long N, S; cin >> N >> S;
    long long final_sum = (N * (N + 1))/2;

    if(S == final_sum) cout << 0 << endl;
    else {
      int count = 0;
      for(long long i = final_sum - 1; i >= S; i -= (N - count)){
        count++;
      }
      cout << count << endl;
    }
  }
}
