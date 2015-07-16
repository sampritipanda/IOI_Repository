#include <iostream>
#include <set>

using namespace std;

int main() {
  int T; cin >> T;

  while(T--) {
    int N; cin >> N;
    set<int> days;
    for(int i = 0; i < N; i++) {
      int d; cin >> d;
      days.insert(d);
    }
    cout << days.size() << endl;
  }
}
