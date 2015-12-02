#include <iostream>

using namespace std;

int main() {
  int N = 200000;
  cout << N << endl;
  for(int i = 1; i <= N; i++) {
    if(i % 2 == 1) cout << int(1e9);
    else cout << -int(1e9);

    if(i < N) cout << " ";
  }
  cout << endl;
}
