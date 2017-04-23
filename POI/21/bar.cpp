#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <set>

using namespace std;

char str[1000002];
int A[1000002];
int A2[1000002];

int front[1000002];
int back[1000002];
set<int> ids;
set<pair<int, int> > back_set;

int main() {
  int N;
  scanf("%d %s", &N, str);

  for(int i = 1; i <= N; i++) {
    A[i] = A[i - 1];

    if(str[i - 1] == 'j') A[i]--;
    else A[i]++;
  }

  for(int i = N; i >= 1; i--) {
    A2[i] = A2[i + 1];
    if(str[i - 1] == 'j') A2[i]--;
    else A2[i]++;
  }

  stack<int> S;
  for(int i = N; i >= 1; i--) {
    S.push(i);

    front[i] = N;
    while(!S.empty() && A[i - 1] <= A[S.top()]) {
      S.pop();
    }
    if(!S.empty()) front[i] = S.top() - 1;
  }

  while(!S.empty()) S.pop();

  for(int i = 1; i <= N; i++) {
    S.push(i);

    back[i] = 1;
    while(!S.empty() && A2[i + 1] <= A2[S.top()]) {
      S.pop();
    }
    if(!S.empty()) back[i] = S.top() + 1;
  }

  int ans_brute = 0;
  bool brute_pos = true;
  int cnt = 0;

  for(int i = 1; i <= N; i++) {
    if(cnt > 2 * N) {
      brute_pos = false;
      break;
    }
    for(int j = front[i]; j >= i; j--) {
      cnt++;
      if(i >= back[j]) {
        ans_brute = max(ans_brute, j - i + 1);
      }
      if(j - i + 1 <= ans_brute) break;
    }
  }

  if(brute_pos) {
    printf("%d\n", ans_brute);
    return 0;
  }

  int ans = 0;

  for(int i = N; i >= 1; i--) {
    while(!back_set.empty() && -back_set.begin()->first > i) {
      ids.erase(back_set.begin()->second);
      back_set.erase(back_set.begin());
    }
    if(front[i] < i) continue;
    back_set.insert(make_pair(-back[i], i)); ids.insert(i);

    set<int>::iterator it = ids.upper_bound(front[i]);
    if(it != ids.begin()) {
      it--;
      ans = max(ans, *it - i + 1);
    }
  }

  printf("%d\n", ans);
}
