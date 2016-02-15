#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int T; cin >> T;

  while(T--) {
    int N; cin >> N;
    if(N <= 6) {
      cout << -1 << endl;
    }
    else {
      bool even = (N % 2 == 0 ? true : false);
      if(even) N--;
      N--;

      vector<pair<int, int> > edges;
      for(int i = 1; i < N/2; i++) edges.push_back({i, i + 1});
      for(int i = N/2 + 1; i < N; i++) edges.push_back({i, i + 1});

      edges.push_back({1, N/2 + 1});
      edges.push_back({N/2, N});

      edges.push_back({N/2, N + 1});

      if(even) edges.push_back({N/2, N + 2});

      cout << edges.size() << endl;

      for(auto it: edges) cout << it.first << " " << it.second << endl;

      cout << N/4 + 1 << endl;
    }
  }
}
