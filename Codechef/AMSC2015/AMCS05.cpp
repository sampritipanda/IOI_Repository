#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

int main() {
  int T; cin >> T;

  while(T--) {
    string S1, S2; int D; cin >> S1 >> S2 >> D;

    int coord_1[26], coord_2[26];
    memset(coord_1, 0, sizeof coord_1);
    memset(coord_2, 0, sizeof coord_2);

    for(auto c: S1) {
      coord_1[c - 'a']++;
    }
    for(auto c: S2) {
      coord_2[c - 'a']++;
    }

    int manhattan_distance = 0;
    for(int i = 0; i < 26; i++) {
      manhattan_distance += abs(coord_1[i] - coord_2[i]);
    }

    if(manhattan_distance <= D) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
}
