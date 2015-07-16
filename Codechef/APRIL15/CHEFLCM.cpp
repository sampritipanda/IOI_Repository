// Chef and Interview

#include <iostream>
#include <set>

using namespace std;

int main() {
  int T; cin >> T;

  while(T--){
    int N; cin >> N;
    long long sum = 0;
    for(int i = 1; i*i <= N; i++){
      if(N % i != 0) continue;
      sum += i;
      if(i != N/i) sum += N/i;
    }
    cout << sum << endl;
  }
}
