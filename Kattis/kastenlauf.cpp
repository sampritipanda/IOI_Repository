#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

int union_find[110];
vector<pair<int, int> > points;

int find(int a) {
  if(union_find[a] == a) return a;
  return union_find[a] = find(union_find[a]);
}

void merge(int a, int b) {
  union_find[find(a)] = find(b);
}

int main() {
  int T; cin >> T;

  while(T--) {
    int N; cin >> N;
    points.resize(N + 2);
    for(int i = 0; i < (N + 2); i++) {
      cin >> points[i].first >> points[i].second;
      union_find[i] = i;
    }

    for(int i = 0; i <= N; i++) {
      for(int j = 0; j < (N + 2); j++) {
        if(i == j) continue;

        if(abs(points[j].first - points[i].first) + abs(points[j].second - points[i].second) <= 1000) {
          merge(i, j);
        }
      }
    }

    if(find(0) == find(N + 1)) cout << "happy" << endl;
    else cout << "sad" << endl;
  }
}
