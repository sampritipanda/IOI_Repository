#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<int> I[26];

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  string S; cin >> S;
  int N = S.length();

  for(int i = 0; i < N; i++) {
    I[S[i] - 'a'].push_back(i);
  }

  vector<char> stack;
  for(int i = 0; i < N; i++) {
    stack.push_back(S[i]);
    while(!stack.empty()) {
      char curr = stack.back();
      bool keep = false;
      for(int j = 0; j < (curr - 'a'); j++) {
        if(upper_bound(I[j].begin(), I[j].end(), i) != I[j].end()) {
          keep = true;
          break;
        }
      }
      if(keep) break;
      else {
        cout << curr;
        stack.pop_back();
      }
    }
  }
  cout << endl;
}
