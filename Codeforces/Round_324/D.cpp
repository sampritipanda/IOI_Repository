#include <iostream>
#include <algorithm>

using namespace std;

inline bool is_prime(int N) {
  for(int i = 2; i*i <= N; i++) {
    if(N % i == 0) return false;
  }
  return true;
}

int main() {
  vector<int> ans;
  int N; cin >> N;
  for(int i = N; i >= 2; i--) {
    if(i == N - 1) continue;
    if(is_prime(i)) {
      N -= i;
      ans.push_back(i);
      break;
    }
  }

  if(N > 0) {
    if(is_prime(N)) ans.push_back(N);
    else {
      for(int i = 2; i <= N - 2; i++) {
        if(is_prime(i) && is_prime(N - i)) {
          ans.push_back(i); ans.push_back(N - i);
          break;
        }
      }
    }
  }

  cout << ans.size() << endl;
  for(auto it: ans) cout << it << " ";
  cout << endl;
}
