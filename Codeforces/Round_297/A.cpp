#include <iostream>
#include <string>

using namespace std;

int main() {
  int N; cin >> N;
  string S; cin >> S;

  int count = 0;
  int keys[26];
  for(int i = 0; i < 26; i++) keys[i] = 0;

  for(int i = 0; i < (N - 1); i++){
    if(S[i*2] == tolower(S[i*2 + 1])) continue;
    else if(keys[S[i*2+1] - 'A'] > 0) {
      keys[S[i*2+1] - 'A']--;
      keys[S[i*2] - 'a']++;
    }
    else {
      keys[S[i*2] - 'a']++;
      count++;
    }
  }

  cout << count << endl;
}
