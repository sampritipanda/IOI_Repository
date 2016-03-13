#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int N; cin >> N;

  int ans_1 = 0, ans_2 = 0;

  for(int i = 0; i < N; i++) {
    int x; cin >> x;
    ans_1 |= x;
  }

  for(int i = 0; i < N; i++) {
    int x; cin >> x;
    ans_2 |= x;
  }

  cout << ans_1 + ans_2 << endl;
}
