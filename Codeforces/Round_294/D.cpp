// A and B and Interesting Substrings

#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

int main() {
  int vals[26]; for(int i = 0; i < 26; i++) cin >> vals[i];
  string s; cin >> s;
  int N = s.length();
  int arr[N], sums[N];
  for(int i = 0; i < N; i++) arr[i] = vals[s[i] - 'a'];
  sums[0] = arr[0];
  for(int i = 1; i < N; i++) sums[i] = sums[i - 1] + arr[i];

  vector<vector<int> > indexes(26);
  for(int i = 0; i < N; i++) indexes[s[i] - 'a'].push_back(i);

  for(int i = 0; i < 26; i++) {
  }
}
