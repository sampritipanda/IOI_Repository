#include <iostream>

using namespace std;

int main() {
  string S; cin >> S;
  int A[5];
  for(int i = 0; i < 5; i++) A[i] = S[i] - '0';

  long long num = A[0] * 10000 + A[2] * 1000 + A[4] * 100 + A[3] * 10 + A[1];
  long long res = 1;
  for(int i = 0; i < 5; i++) res = (res * num) % 100000LL;
  long long res2 = res/10;

  int dig = 1;
  while(res2 > 0) {
    res2 /= 10;
    dig++;
  }
  for(int i = 0; i < 5 - dig; i++) cout << 0;
  cout << res << endl;
}
