// Cunning Gena

#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <tuple>
#include <climits>

#define INF LLONG_MAX

using namespace std;

typedef pair<int, pair<long long, long long> > node;   // Mask, {Monitors, Total Cost}

class sort_compare {
  public:
  bool operator() (node a, node b){
    // if(a.second.second == b.second.second) return a.second.first > b.second.first;
    return a.second.second < b.second.second;
  }
};

bool better(pair<long long, long long>& lhs, long long cost, long long monitors){
  // if(lhs.second == cost) return monitors > lhs.first;
  return cost < lhs.second;
}

int main() {
  int n, m; long long b; cin >> n >> m >> b;
  long long X[n], K[n], mask[n];
  for(int i = 0; i < n; i++){
    int m_i; cin >> X[i] >> K[i] >> m_i;
    mask[i] = 0;
    while(m_i--){
      int p; cin >> p; p--;
      mask[i] |= (1 << p);
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (K[i] > K[j]) {
        swap(K[i], K[j]);
        swap(X[i], X[j]);
        swap(mask[i], mask[j]);
      }
    }
  }

  bool visited[1 << 20];
  pair<long long, long long>* D = new pair<long long, long long>[1 << 20];
  for(int i = 0; i < (1 << 20); i++) {
    visited[i] = false;
    D[i] = {INF, INF};
  }
  set<node, sort_compare> Q; Q.insert({0, {0, 0}});
  long long ans = -1;

  while(!Q.empty()){
    auto curr = *Q.begin();
    Q.erase(Q.begin());

    if(visited[curr.first]) continue;
    visited[curr.first] = true;

    if(curr.first == (1 << m) - 1) {
      ans = curr.second.second;
      break;
    }

    for(int i = 0; i < n; i++){
      if((curr.first & mask[i]) == mask[i]) continue;
      long long next_cost = curr.second.second + X[i];
      long long next_monitors = curr.second.first;
      int next_mask = curr.first | mask[i];
      if(next_monitors < K[i]) {
        next_cost += (K[i] - next_monitors) * b;
        next_monitors = K[i];
      }
      if(better(D[next_mask], next_cost, next_monitors)){
        if(D[next_mask].second != INF){
          Q.erase(Q.find({next_mask, {D[next_mask].first, D[next_mask].second}}));
        }
        D[next_mask] = {next_monitors, next_cost};
        Q.insert({next_mask, {next_monitors, next_cost}});
      }
    }
  }

  cout << ans << endl;
}
