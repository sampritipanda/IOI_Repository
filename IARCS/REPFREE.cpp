// Repetition-free Numbers

#include <iostream>
#include <string>
#include <sstream>

#define SSTR( x ) dynamic_cast< std::ostringstream & >( \
            ( std::ostringstream() << std::dec << x ) ).str()

using namespace std;

bool repeated(int N){
  if(N == 0) return true;
  int used[10]; for(int i = 0; i <= 9; i++) used[i] = 0;

  while (N > 0) {
    if (N % 10 == 0 || used[N % 10]) return true;
    used[N % 10] = 1;
    N /= 10;
  }

  if(used[0]) return true;
  return false;
}

int main(){
  int N; cin >> N;
  // string S = SSTR(N);
  // cout << S.length() << endl;

  if(N >= 987654321) {
    cout << 0 << endl;
    return 0;
  }

  N++;
  while(repeated(N)){
    N++;
  }
  cout << N << endl;
}
