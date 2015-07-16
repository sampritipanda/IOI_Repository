// Stamps

#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

int main() {
  bool map[26]; for(int i = 0; i < 26; i++) map[i] = false;

  int K; cin >> K;
  int N; cin >> N;
  string S; cin >> S;
  vector<string> stamps;
  set<int> indexes[15][26];
  for(int i = 0; i < K; i++){
    int len; string M; cin >> len >> M;
    for(int j = 0; j < len; j++){
      map[M[j] - 'a'] = true;
      indexes[i][M[j] - 'a'].insert(j);
    }
    stamps.push_back(M);
  }

  bool possible = true;
  for(auto c: S){
    if(!map[c - 'a']){
      possible = false;
      break;
    }
  }

  if(possible) {
    int count = 0;
    int i = 0;
    while(i < N){
      count++;
      int max_i = i;
      for(int x = 0; x < K; x++){
        int j = i;
        int start_pos = -1;
        while(j < N){
          auto next = indexes[x][S[j] - 'a'].upper_bound(start_pos);
          if(next == indexes[x][S[j] - 'a'].end()) break;
          else {
            j++;
            start_pos = *next;
          }
        }
        max_i = max(max_i, j);
      }
      i = max_i;
    }
    cout << count << endl;
  }
  else {
    cout << -1 << endl;
  }
}
