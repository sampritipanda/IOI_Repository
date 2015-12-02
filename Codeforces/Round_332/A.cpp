#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  long long a, b, c; cin >> a >> b >> c;

  vector<long long> ans;
  ans.push_back(a + b + c);
  ans.push_back(a + a + b + b);
  ans.push_back(a + c + c + a);
  ans.push_back(b + c + c + b);

  sort(ans.begin(), ans.end());
  cout << ans[0] << endl;
}


