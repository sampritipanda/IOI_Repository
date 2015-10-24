// Cyclic shifts in permutation

#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <set>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define MOD 1000000007

using namespace std;

map<vector<int>, bool> visited;
vector<vector<int> > perms;
using namespace __gnu_pbds;

typedef tree<
  int,
  null_type,
  less<int>,
  rb_tree_tag,
  tree_order_statistics_node_update>
ordered_set;

int N, K;

void solve(vector<int> A) {
  if(visited.count(A) > 0) return;
  visited[A] = true;
  perms.push_back(A);

  for(int i = 0; i <= N - K; i++) {
    vector<int> c = A;
    int t = c[i + K - 1];
    c.erase(c.begin() + i + K - 1);
    c.insert(c.begin() + i, t);
    solve(c);
  }
}

int main() {
  cin >> N >> K;
  vector<int> A(N);
  for(int i = 0; i < N; i++) cin >> A[i];

  solve(A);
  cout << endl;

  sort(perms.begin(), perms.end());
  for(auto it: perms) {
    int inv = 0;
    for(auto it2: it) cout << it2 << " ";
    for(int i = 0; i < N; i++)
      for(int j = i + 1; j < N; j++)
        if(it[i] > it[j])
          inv++;
    cout << " => " << inv;

    ordered_set S;
    long long rank = 0, f = 1;
    for(int i = N - 1; i >= 0; i--) {
      int j = N - i - 1;
      if(j > 0) f *= j;
      rank += (f * S.order_of_key(it[i])) % MOD;
      rank %= MOD;
      S.insert(it[i]);
    }
    rank++;

    cout << " - " << rank;
    cout << endl;
  }
  cout << perms.size() << endl;
}
