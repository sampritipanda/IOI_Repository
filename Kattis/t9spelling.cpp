// T9 Spelling

#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

int main() {
  map<char, string> dict;
  dict['a'] = "2";
  dict['b'] = "22";
  dict['c'] = "222";
  dict['d'] = "3";
  dict['e'] = "33";
  dict['f'] = "333";
  dict['g'] = "4";
  dict['h'] = "44";
  dict['i'] = "444";
  dict['j'] = "5";
  dict['k'] = "55";
  dict['l'] = "555";
  dict['m'] = "6";
  dict['n'] = "66";
  dict['o'] = "666";
  dict['p'] = "7";
  dict['q'] = "77";
  dict['r'] = "777";
  dict['s'] = "7777";
  dict['t'] = "8";
  dict['u'] = "88";
  dict['v'] = "888";
  dict['w'] = "9";
  dict['x'] = "99";
  dict['y'] = "999";
  dict['z'] = "9999";
  dict[' '] = "0";

  int N; cin >> N;
  getchar();

  for(int i = 1; i <= N; i++){
    string S; getline(cin, S);
    vector<string> ans;
    for(auto c: S) ans.push_back(dict[c]);

    cout << "Case #" << i << ": " << ans[0];
    for(int j = 1; j < ans.size(); j++){
      if(ans[j][0] == ans[j - 1][ans[j - 1].size() - 1]) cout << " ";
      cout << ans[j];
    }
    cout << endl;
  }
}
