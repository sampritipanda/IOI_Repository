// Error Correct System

#include <iostream>
#include <string>
#include <set>
#include <map>

using namespace std;

int main() {
  int N; cin >> N;
  string S, T; cin >> S >> T;
  map<pair<char, char>, int> dict;
  set<int> error_indexes;
  set<int> errors_by_char[26];
  int distance = 0;

  for(int i = 0; i < N; i++){
    if(S[i] != T[i]){
      distance++;
      dict[{S[i], T[i]}] = i + 1;
      error_indexes.insert(i);
      errors_by_char[S[i] - 'a'].insert(i);
    }
  }

  if(distance <= 1){
    cout << distance << endl;
    cout << -1 << " " << -1 << endl;
  }
  else {
    bool flag1 = false;
    for(auto i: error_indexes){
      if(dict.count({T[i], S[i]}) > 0){
        flag1 = true;
        distance -= 2;
        cout << distance << endl;
        cout << (i + 1) << " " << dict[{T[i], S[i]}] << endl;
        break;
      }
    }

    if(!flag1){
      for(auto i: error_indexes){
        for(char c = 'a'; c <= 'z'; c++){
          if(dict.count({T[i], c}) > 0){
            flag1 = true;
            distance -= 1;
            cout << distance << endl;
            cout << (i + 1) << " " << dict[{T[i], c}] << endl;
            break;
          }
        }
        if(flag1) break;
      }
    }

    if(!flag1) {
      cout << distance << endl;
      cout << -1 << " " << -1 << endl;
    }
  }
}
