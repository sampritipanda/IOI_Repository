#include <iostream>
#include <set>
#include <string>

using namespace std;

multiset<pair<string, string> > M;

int main() {
  int N; cin >> N;
  string H; cin >> H;

  for(int i = 0; i < N; i++) {
    string curr; cin >> curr;
    string A = curr.substr(0, 3);
    string B = curr.substr(5, 3);

    M.insert({A, B});
  }

  bool pos = false;
  for(auto it: M) {
    if(M.count({it.second, it.first}) != M.count(it)) {
      pos = true;
      break;
    }
  }

  if(pos) cout << "contest" << endl;
  else cout << "home" << endl;
}
