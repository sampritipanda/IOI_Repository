#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int T; cin >> T;

  while(T--) {
    int N; cin >> N;

    for(int i = 0; i < N; i++) cout << char('a' + (i % 26));
    cout << endl;
  }
}
