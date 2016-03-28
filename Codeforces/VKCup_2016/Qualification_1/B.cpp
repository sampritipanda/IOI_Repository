#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <string>

using namespace std;

map<string, bool> done;
vector<string> A;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int N; cin >> N;
  A.resize(N);
  for(int i = 0; i < N; i++) cin >> A[i];
  reverse(A.begin(), A.end());

  for(auto curr: A) {
    if(done.count(curr) == 0) {
      cout << curr << endl;
      done[curr] = true;
    }
  }
}
