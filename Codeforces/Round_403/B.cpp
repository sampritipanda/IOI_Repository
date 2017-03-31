#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <string>

using namespace std;

string A[1001], B[1001];
map<string, vector<int> > group;
set<string> used;
bool vis[1001];
string ans[1001];

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int N; cin >> N;

  for(int i = 1; i <= N; i++) {
    string X, Y; cin >> X >> Y;
    A[i] = X.substr(0, 3);
    B[i] = X.substr(0, 2) + Y.substr(0, 1);
  }

  bool pos = true;
  for(int i = 1; i <= N; i++) {
    for(int j = i + 1; j <= N; j++) {
      if(A[i] == A[j] && B[i] == B[j]) {
        pos = false;
        break;
      }
    }
    if(!pos) break;
  }

  if(pos) {
    for(int i = 1; i <= N; i++) {
      group[A[i]].push_back(i);
    }

    for(auto it: group) {
      if(it.second.size() > 1) {
        for(int i: it.second) {
          vis[i] = true;
          ans[i] = B[i];
          used.insert(B[i]);
        }
      }
    }

    stack<int> Q;
    for(int i = 1; i <= N; i++) {
      if(vis[i]) continue;
      if(used.count(A[i]) > 0 || used.count(B[i]) > 0) Q.push(i);
    }
    for(int i = 1; i <= N; i++) {
      if(vis[i]) continue;
      if(used.count(A[i]) == 0 && used.count(B[i]) == 0) Q.push(i);
    }

    while(!Q.empty()) {
      int i = Q.top(); Q.pop();
      if(vis[i]) continue;
      vis[i] = true;
      if(used.count(A[i]) > 0 && used.count(B[i]) > 0) {
        pos = false;
        break;
      }
      else if(used.count(A[i]) > 0) {
        ans[i] = B[i];
        used.insert(B[i]);
      }
      else if(used.count(B[i]) > 0) {
        ans[i] = A[i];
        used.insert(A[i]);
      }
      else {
        ans[i] = A[i];
        used.insert(A[i]);
      }

      for(int j = 1; j <= N; j++) {
        if(vis[j]) continue;
        if(A[j] == ans[i] || B[j] == ans[i]) Q.push(j);
      }
    }

    for(int i = 1; i <= N; i++) {
      if(!pos) break;
      for(int j = i + 1; j <= N; j++) {
        if(ans[i] == ans[j]) {
          pos = false;
          break;
        }
      }
    }

    if(pos) {
      cout << "YES" << endl;
      for(int i = 1; i <= N; i++) cout << ans[i] << endl;
    }
    else {
      cout << "NO" << endl;
    }
  }
  else {
    cout << "NO" << endl;
  }
}
