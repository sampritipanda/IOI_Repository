// Bored of Nim

#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <vector>

using namespace std;

int A[100010];
int sub_count[100010];
map<int, vector<int> > indexes;

int main() {
  ios::sync_with_stdio(false);

  int T; cin >> T;

  while(T--) {
    indexes.clear();

    int N; cin >> N;
    for(int i = 1; i <= N; i++) {
      cin >> A[i];
      sub_count[i] = 0;
    }

    long long sum = 0;
    for(int i = 1; i <= N; i++) {
      sum ^= A[i];

      for(auto it: indexes[sum]) {
        sub_count[i - it + 1]++;
      }
      indexes[sum].push_back(i);
    }

    for(int i = 1; i <= N; i++) {
      cout << sub_count[i] << " ";
    }
    cout << endl;
  }
}
