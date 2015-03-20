#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

int main() {
  int N; cin >> N;
  map<string, int> reposts;

  for(int i = 0; i < N; i++){
    string a, temp, b; cin >> a >> temp >> b;
    for(int i = 0; i < a.length(); i++) a[i] = tolower(a[i]);
    for(int i = 0; i < b.length(); i++) b[i] = tolower(b[i]);

    if(reposts.find(b) == reposts.end()) reposts[b] = 1;
    reposts[a] = reposts[b] + 1;
  }

  int max_chain = 0;
  for(auto it: reposts) max_chain = max(max_chain, it.second);
  cout << max_chain << endl;
}
