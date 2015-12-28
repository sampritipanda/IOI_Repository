#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <map>

using namespace std;

int main() {
  ios::sync_with_stdio(false);

  string S; cin >> S;
  int N = S.length();

  stack<char> st;
  map<char, char> opp; opp['('] =')'; opp['{'] = '}'; opp['<'] = '>'; opp['['] = ']';
  map<char, int> type; type['('] = 1; type['{'] = 1; type['<'] = 1; type['['] = 1;
                       type[')'] = 2; type['}'] = 2; type['>'] = 2; type[']'] = 2;

  int ans = 0;
  for(int i = 0; i < N; i++) {
    char c = S[i];

    if(c == '(' || c == '[' || c == '{' || c == '<') st.push(c);
    else {
      if(st.empty()) {
        ans = -1;
        break;
      }
      else if(opp[st.top()] != c) ans++;

      st.pop();
    }
  }

  if(!st.empty()) ans = -1;

  if(ans == -1) cout << "Impossible" << endl;
  else cout << ans << endl;
}
