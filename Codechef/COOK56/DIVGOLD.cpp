// How to Minimize a String

#include <iostream>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

int main() {
  int T; cin >> T;

  while(T--){
    int N; cin >> N;
    string S; cin >> S;
    set<string> all_positions;
    all_positions.insert(S);

    for(int t_i = 0; t_i < N; t_i++){
      for(int t_j = 0; t_j < N; t_j++){
        string next = S;
        next.erase(t_i, 1);
        string ins = ""; ins += S[t_i];
        if(t_j < N - 1) next.insert(t_j, ins);
        else next += S[t_i];
        all_positions.insert(next);
      }
    }

    cout << *all_positions.begin() << endl;
  }
}
