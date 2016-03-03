#include <iostream>
#include <vector>

using namespace std;

long long count(long long n) {
    long long count = 0;

    for (long long i=5; n/i>=1; i *= 5) count += n/i;

    return count;
}

int main() {
  int M; cin >> M;

  vector<int> ans;
  ans.clear();

  for(int i = 0; i <= 1000000; i++) {
    if(count(i) == M) ans.push_back(i);
  }
  cout << ans.size() << endl;
  for(auto it: ans) cout << it << " "; cout << endl;
}
