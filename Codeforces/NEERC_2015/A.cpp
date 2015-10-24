#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <string>

using namespace std;

map<string, vector<string> > M;

int main() {
  int N; cin >> N;

  while(N--) {
    string S; cin >> S;
    string T = S;
    for(int i = 0; i < T.size(); i++) {
      T[i] = tolower(T[i]);
    }
    string domain = T.substr(T.find('@') + 1);
    if(domain == "bmail.com") {
      T = "";
      bool stop = false, domain_start = false;
      for(int i = 0; i < S.length(); i++) {
        if(S[i] == '@') domain_start = true;

        if(stop) {
          if(S[i] == '@') {
            T += tolower(S[i]);
            stop = false;
          }
        }
        else {
          if(S[i] == '+') stop = true;
          else if(S[i] != '.' || domain_start) T += tolower(S[i]);
        }
      }
    }

    M[T].push_back(S);
  }

  cout << M.size() << endl;
  for(auto it: M) {
    cout << it.second.size() << " ";
    for(auto it2: it.second) cout << it2 << " ";
    cout << endl;
  }
}
