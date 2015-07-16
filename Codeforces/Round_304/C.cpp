#include <iostream>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

map<pair<queue<int>, queue<int> >, bool> visited;

pair<long long, int> dfs(queue<int> A, queue<int> B, long long fights){
  if(A.size() == 0) {
    return {fights, 2};
  }
  else if(B.size() == 0) {
    return {fights, 1};
  }
  else if(visited.find({A, B}) != visited.end()){
    return {fights, -1};
  }
  else {
    visited[{A, B}] = true;
    if(A.front() > B.front()){
      A.push(B.front());
      A.push(A.front());
      A.pop();
      B.pop();
    }
    else {
      B.push(A.front());
      B.push(B.front());
      B.pop();
      A.pop();
    }
    return dfs(A, B, fights + 1);
  }
}

int main() {
  int N; cin >> N;
  queue<int> A, B;

  int a_n; cin >> a_n;
  for(int i = 0; i < a_n; i++) {
    int a; cin >> a;
    A.push(a);
  }
  int b_n; cin >> b_n;
  for(int i = 0; i < b_n; i++) {
    int b; cin >> b;
    B.push(b);
  }

  pair<int, int> ans = dfs(A, B, 0);
  if(ans.second == -1) cout << -1 << endl;
  else cout << ans.first << " " << ans.second << endl;
}
