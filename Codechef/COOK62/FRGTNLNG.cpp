#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main() {
  int T; cin >> T;

  while(T--) {
    int N, K; cin >> N >> K;
    vector<string> dict(N);
    for(int i = 0; i < N; i++) cin >> dict[i];
    vector<string> words;

    while(K--) {
      int L; cin >> L;
      while(L--) {
        string w; cin >> w;
        words.push_back(w);
      }
    }

    for(int i = 0; i < N; i++) {
      if(find(words.begin(), words.end(), dict[i]) != words.end()) cout << "YES ";
      else cout << "NO ";
    }
    cout << endl;
  }
}
