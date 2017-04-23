#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

multiset<long long> S;

int main() {
  int T; cin >> T;

  for(int t = 1; t <= T; t++) {
    long long N; cin >> N;
    int K; cin >> K; K--;

    S.clear();
    S.insert(N);

    while(K--) {
      long long curr = *S.rbegin();
      S.erase(S.find(curr));

      if(curr % 2 == 1) {
        S.insert(curr/2);
        S.insert(curr/2);
      }
      else {
        S.insert(curr/2);
        S.insert(curr/2 - 1);
      }
    }

    long long fin = 0;
    if(S.size() > 0) fin = *S.rbegin();
    if(fin % 2 == 0) {
      cout << "Case #" << t << ": " << fin/2 << " " << (fin/2 - 1) << endl;
    }
    else {
      cout << "Case #" << t << ": " << fin/2 << " " << fin/2 << endl;
    }
  }
}
