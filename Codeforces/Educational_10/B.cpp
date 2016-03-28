#include <iostream>
#include <deque>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
  int N; cin >> N;
  vector<int> A(N);
  for(int i = 0; i < N; i++) {
    cin >> A[i];
  }
  sort(A.begin(), A.end());

  deque<int> Q;
  for(auto it: A) Q.push_back(it);

  vector<int> ans;

  int last = Q.front(); Q.pop_front();
  ans.push_back(last);

  for(int i = 2; i <= N; i++) {
    if(i % 2 == 0) {
      int curr = Q.back();
      Q.pop_back();
      if(curr < last) break;
      ans.push_back(curr);
      last = curr;
    }
    else {
      int curr = Q.front();
      Q.pop_front();
      if(curr > last) break;
      ans.push_back(curr);
      last = curr;
    }
  }

  if(ans.size() == N) {
    for(auto it: ans) cout << it << " "; cout << endl;
  }
  else cout << -1 << endl;
}
