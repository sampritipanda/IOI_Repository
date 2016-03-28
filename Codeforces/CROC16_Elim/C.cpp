#include <iostream>
#include <algorithm>
#include <deque>
#include <climits>

using namespace std;

string S;
deque<int> A;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int N, K; cin >> N >> K; K++;
  cin >> S;

  int i;
  for(i = 0; i < N; i++) {
    if(S[i] == '0') A.push_back(i);
    if(A.size() == K) break;
  }
  A.pop_back();

  int ans = INT_MAX;
  while(i < N) {
    if(S[i] == '1') {
      i++;
      continue;
    }
    A.push_back(i);

    int first = A.front(), last = A.back();
    int mid = (first + last)/2;

    auto it = lower_bound(A.begin(), A.end(), mid);
    int val1 = *it;
    if(it != A.begin()) it--;
    int val2 = *it;

    ans = min(ans, max(val1 - first, last - val1));
    ans = min(ans, max(val2 - first, last - val2));

    A.pop_front();
    i++;
  }

  cout << ans << endl;
}
