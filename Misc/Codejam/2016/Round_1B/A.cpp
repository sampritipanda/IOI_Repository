#include <iostream>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

int main() {
  int T; cin >> T;

  for(int t = 1; t <= T; t++) {
    string S; cin >> S;
    map<char, int> M;

    for(char c: S) {
      M[c]++;
    }

    vector<int> ans;
    for(int i = 0; i < M['Z']; i++) {
      ans.push_back(0);
      M['E']--;
      M['R']--;
      M['O']--;
    }
    M['Z'] = 0;

    for(int i = 0; i < M['W']; i++) {
      ans.push_back(2);
      M['T']--;
      M['O']--;
    }
    M['W'] = 0;

    for(int i = 0; i < M['U']; i++) {
      ans.push_back(4);
      M['F']--;
      M['O']--;
      M['R']--;
    }
    M['U'] = 0;

    for(int i = 0; i < M['X']; i++) {
      ans.push_back(6);
      M['S']--;
      M['I']--;
    }
    M['X'] = 0;

    for(int i = 0; i < M['F']; i++) {
      ans.push_back(5);
      M['I']--;
      M['V']--;
      M['E']--;
    }
    M['F'] = 0;

    for(int i = 0; i < M['V']; i++) {
      ans.push_back(7);
      M['S']--;
      M['E']--;
      M['E']--;
      M['N']--;
    }
    M['V'] = 0;

    for(int i = 0; i < M['G']; i++) {
      ans.push_back(8);
      M['E']--;
      M['I']--;
      M['H']--;
      M['T']--;
    }
    M['G'] = 0;

    for(int i = 0; i < M['T']; i++) {
      ans.push_back(3);
      M['H']--;
      M['R']--;
      M['E']--;
      M['E']--;
    }
    M['T'] = 0;

    for(int i = 0; i < M['I']; i++) {
      ans.push_back(9);
      M['N']--;
      M['N']--;
      M['E']--;
    }
    M['I'] = 0;

    for(int i = 0; i < M['N']; i++) {
      ans.push_back(1);
      M['O']--;
      M['E']--;
    }
    M['N'] = 0;

    sort(ans.begin(), ans.end());

    cout << "Case #" << t << ": ";
    for(auto it: ans) cout << it;
    cout << endl;
  }
}
