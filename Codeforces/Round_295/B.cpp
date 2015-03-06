#include <iostream>
#include <climits>
#include <queue>

using namespace std;

bool visited[20001];

int main() {
  int N, M; cin >> N >> M;
  for(int i = 0; i <= 20000; i++) {
    visited[i] = false;
  }

  if(N >= M) cout << N - M << endl;
  else {
    int ans = 0;
    queue<pair<int, int> > Q;
    Q.push({N, 0});

    while(!Q.empty()){
      auto curr = Q.front();
      Q.pop();

      if(curr.first == M){
        ans = curr.second;
        break;
      }
      if(curr.first == 0 || curr.first >= (M*2)) continue;

      if(visited[curr.first]) continue;
      visited[curr.first] = true;

      if(curr.first > 1) Q.push({curr.first - 1, curr.second + 1});
      if(curr.first < M) Q.push({curr.first * 2, curr.second + 1});
    }

    cout << ans << endl;
  }
}
