// Carol and Skrulls

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define MOD 1000000007

vector<int> negative;
vector<int> positive;

int main() {
  ios::sync_with_stdio(false);

  int T; cin >> T;

  while(T--) {
    positive.clear();
    negative.clear();
    bool zero = false;

    int N; cin >> N;
    for(int i = 0; i < N; i++) {
      int a; cin >> a;
      if(a > 0) positive.push_back(a);
      else if(a < 0) negative.push_back(a);
      else zero = true;
    }

    sort(negative.begin(), negative.end());

    long long ans = 1;
    for(auto a: positive) ans = (ans * a) % MOD;
    if(positive.size() == 0 && negative.size() == 1) {
      if(zero) ans = 0;
      else ans = ((*negative.begin()) + MOD) % MOD;
    }
    else if(positive.size() == 0 && negative.size() == 0) {
      ans = 0;
    }
    else {
      if(negative.size() % 2 == 1) negative.pop_back();
      for(auto a: negative) {
        ans = (ans * (-a)) % MOD;
      }
    }

    cout << ans << endl;
  }
}
