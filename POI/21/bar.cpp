#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

string str;
int A[1000002];
int A2[1000002];

int front[1000002];
int back[1000002];

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int N; cin >> N;
  cin >> str;

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

  int ans = 0;

  for(int i = 1; i <= N; i++) {
    for(int j = front[i]; j >= i; j--) {
      if(i >= back[j]) {
        ans = max(ans, j - i + 1);
      }
      if(j - i + 1 <= ans) break;
    }
  }

  cout << ans << endl;
}
