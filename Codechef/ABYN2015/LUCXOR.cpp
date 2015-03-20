#include <iostream>

using namespace std;

int main() {
  int T; cin >> T;

  while(T--){
    int N; cin >> N;
    if(N % 2 == 0) cout << 0 << endl;
    else {
      long long result = 0;
      for(int i = 1; i <= N; i++){
        if(i % 2 == 1) result ^= i;
      }
      cout << result << endl;
    }
  }
}
