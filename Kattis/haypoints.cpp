// Hay Points

#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
  int m, n; cin >> m >> n;
  map<string, int> dict;

  while(m--){
    string s; int val; cin >> s >> val;
    dict[s] = val;
  }

  for(int i = 0; i < n; i++){
    string s; cin >> s;
    int ans = 0;
    while(s != ".") {
      if(dict.find(s) != dict.end()) ans += dict[s];
      cin >> s;
    }
    cout << ans << endl;
  }
}
