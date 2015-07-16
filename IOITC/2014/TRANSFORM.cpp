// Transform

#include <iostream>

using namespace std;

int main() {
  int N; cin >> N;
  int A[N]; for(int i = 0; i < N; i++) cin >> A[i];

  int positive_numbers = 0, negative_numbers= 0, zero = 0;
  for(int i = 0; i < N; i++){
    if(A[i] < 0) negative_numbers++;
    else if(A[i] > 0) positive_numbers++;
    else zero++;
  }

  if(zero == (N - 1)) cout << 1 << endl;
  else if(zero == N || positive_numbers == 0 || negative_numbers == 0) cout << 0 << endl;
  else cout << 1 << endl;
}
