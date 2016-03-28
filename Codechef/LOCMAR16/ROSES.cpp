#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

vector<int> even, odd;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int T; cin >> T;

  while(T--) {
    odd.clear(); even.clear();

    int N; cin >> N;
    string S; cin >> S;

    for(int i = 0; i < N; i++) {
      int x; cin >> x;
      if(x % 2 == 0) even.push_back(x);
      else odd.push_back(x);
    }

    sort(odd.begin(), odd.end());
    sort(even.begin(), even.end());

    int odd_sz = odd.size(), even_sz = even.size();

    // Maximize Odd Sum
    if(S == "Happy") {
      long long even_sum = 0;
      for(auto it: even) even_sum += it;
      long long odd_sum = 0;
      for(int i = odd_sz - 1; i >= (odd_sz % 2 == 1 ? 0 : 1); i--) odd_sum += odd[i];

      long long sum = odd_sum + even_sum;
      if(sum % 2 == 0) cout << "Sad" << endl;
      else cout << sum << endl;
    }
    // Maximize Even Sum
    else {
      long long even_sum = 0;
      for(auto it: even) even_sum += it;
      long long odd_sum = 0;
      for(int i = odd_sz - 1; i >= (odd_sz % 2 == 0 ? 0 : 1); i--) odd_sum += odd[i];

      long long sum = odd_sum + even_sum;
      if(sum % 2 == 1 || sum == 0) cout << "Sad" << endl;
      else cout << sum << endl;
    }
  }
}
