// Petersen Graph

#include <iostream>
#include <string>
#include <vector>
#include <utility>

using namespace std;

vector<pair<int, char> > A[10];
char chars[100];
string str;
int dfs[100001];

bool search(int u, int t, int p){
    if (p==str.length() - 1 && u == t){
        dfs[p + 1] = u;
        return true;
    }
    for(int i = 0; i < A[i].size(); i++){
        int v = A[u][i].first;
        char c = A[u][i].second;
        if (c == str[p + 1]){
            dfs[p + 1] = u;
            return search(v, t, p + 1);
        }
    }
}

int main(){
  int T; cin >> T;

  for(int i = 0; i <= 4; i++){
    A[i].push_back(make_pair((i + 1) % 5, 'A' + (i + 1) % 5));
    A[(i+1) % 5].push_back(make_pair(i, 'A' + i));
    A[i].push_back(make_pair(i + 5, 'A' + i));
    A[i+5].push_back(make_pair(i, 'A' + i));
  }

  for(int i = 5; i <= 6; i++){
    A[i].push_back(make_pair(i + 2, 62 + i));
    A[i + 2].push_back(make_pair(i, 60 + i));
    A[i].push_back(make_pair(i + 3, 63 + i));
    A[i + 3].push_back(make_pair(i, 60 + i));
  }
  A[7].push_back(make_pair(9, 'E')); A[9].push_back(make_pair(7, 'C'));
  for(int i = 0; i < 10; i++) chars[i] = 'A' + i % 5;


  while(T--){
    bool found = false;
    cin >> str;
    int N = str.length();

    for(int i = 0; i < 10; i++){
      for(int j = 0; j < 10; j++)
        if (str[0] == chars[i] && str[N - 1] == chars[j]){
          found = search(i, j, 0);
          if (found) {
            for(int k = 1; k <= N; k++) cout << dfs[k];
            break;
          }
        }
      if (found) break;
    }
    if (!found) cout << -1;
    cout << endl;
  }
}
