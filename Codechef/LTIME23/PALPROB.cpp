// Palindromeness 

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool palidrome(string s){
  string rev = s; reverse(rev.begin(), rev.end());
  return rev == s;
}

int palindromeness(string s){
  int N = s.length();
  if(N == 1) return 1;
  if(!palidrome(s)) return 0;
  return 1 + palindromeness(s.substr(0, N/2));
}

int main() {
  int T; cin >> T;

  while(T--){
    string S; cin >> S;
    int N = S.length();
    long long ans = 0;
    for(int len = 1; len <= N; len++){
      for(int start = 0; start <= (N - len); start++){
        ans += palindromeness(S.substr(start, len));
      }
    }
    cout << ans << endl;
  }
}
