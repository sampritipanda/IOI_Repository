#include <iostream>
#include <set>

using namespace std;

int main() {
  int N; cin >> N;

  for(int i = 1; i <= N; i += 2) {
    cout << i << " ";
  }
  for(int i = (N & 1 ? N - 2 : N - 1); i >= 1; i -= 2) {
    cout << i << " ";
  }

  for(int i = 2; i <= N; i += 2) {
    cout << i << " ";
  }
  for(int i = (N & 1 ? N - 1 : N - 2); i >= 2; i -= 2) {
    cout << i << " ";
  }

  cout << N << endl;
}
