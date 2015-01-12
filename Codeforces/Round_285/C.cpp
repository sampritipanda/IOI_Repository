// Misha and Forest

#include <iostream>
#include <vector>
#include <set>
#include <utility>
#include <algorithm>

using namespace std;

int main() {
  int N; cin >> N;
  vector<set<int> > graph(N);
  vector<pair<int, int> > vertices;
  set<pair<int, int> > edges;

  for(int i = 0; i < N; i++){
    int deg, s; cin >> deg >> s;
    vertices.push_back({deg, s});
  }

  sort(vertices.begin(), vertices.end());

}
