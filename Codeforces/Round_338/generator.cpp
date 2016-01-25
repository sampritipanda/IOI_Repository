#include <iostream>
#include <algorithm>

using namespace std;

vector<pair<int, int> > edges;

int main() {
  int N = 100000;

  for(int i = 2; i <= 50000; i++) {
    edges.push_back({i - 1, i});
  }

  for(int i = 50001; i <= N; i++) edges.push_back({50000, i});

  cout << N << " " << edges.size() << endl;
  for(auto it: edges) cout << it.first << " " << it.second << endl;
}
