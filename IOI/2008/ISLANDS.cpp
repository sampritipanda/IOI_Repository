#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

vector<pair<int, pair<int, int> > > G[1000001];

// Solves answer for one component
namespace Solve {
  vector<int> A;
  vector<long long> A2;
  vector<long long> B;
  bool on_cycle[1000001];
  bool vis[1000001];
  vector<int> cycle;
  vector<int> stack;
  int N;
  long long ans;
  set<pair<long long, int> > S;

  void dfs_cycle(int i, int p_id) {
    if(vis[i]) {
      auto it = stack.rbegin();
      while(true) {
        cycle.push_back(*it);
        on_cycle[*it] = true;
        if(*it == i) break;
        it++;
      }
      return;
    }
    vis[i] = true;
    stack.push_back(i);

    for(auto it: G[i]) {
      int v = it.first, id = it.second.second;
      if(id == p_id || on_cycle[v]) continue;
      dfs_cycle(v, id);
    }

    stack.pop_back();
  }

  long long dfs_tree(int i, int p) {
    long long max_curr = 0, max_curr_2 = 0;

    for(auto it: G[i]) {
      int v = it.first, l = it.second.first;
      if(on_cycle[v] || v == p) continue;

      long long curr = dfs_tree(v, i) + l;
      if(curr > max_curr) {
        max_curr_2 = max_curr;
        max_curr = curr;
      }
      else if(curr > max_curr_2) {
        max_curr_2 = curr;
      }
    }

    ans = max(ans, max_curr + max_curr_2);
    return max_curr;
  }

  long long get_ans(vector<int>& _A) {
    A = _A;
    N = A.size();
    ans = 0;

    dfs_cycle(A[0], 0);
    int M = cycle.size();

    for(int x: cycle) {
      B.push_back(dfs_tree(x, 0));
    }

    A2.resize(M);
    for(int i = 0; i < M; i++) {
      int nxt = i == (M - 1) ? cycle[0] : cycle[i + 1];
      for(auto it: G[cycle[i]]) {
        int u = it.first, l = it.second.first;
        if(u == nxt) {
          A2[i] = max(A2[i], (long long)l);
        }
      }
    }

    A2.resize(2 * M);
    B.resize(2 * M);

    for(int i = 0; i < M; i++) {
      A2[i + M] = A2[i];
      B[i + M] = B[i];
    }
    for(int i = 1; i < 2 * M; i++) A2[i] = A2[i - 1] + A2[i];
    for(int i = M; i < M + (M - 1); i++) S.insert({A2[i - 1] + B[i], i});

    for(int i = M - 1; i >= 0; i--) {
      ans = max(ans, B[i] + S.rbegin()->first - (i == 0 ? 0 : A2[i - 1]));
      if(i > 0) {
        S.erase({A2[i + M - 2] + B[i + M - 1], i + M - 1});
        S.insert({A2[i - 1] + B[i], i});
      }
    }

    // for(int i = 0; i < M; i++) {
    //   long long sum = B[i] + A2[i];
    //   for(int j = (i + 1) % M; j != i; j = (j + 1) % M) {
    //     ans = max(ans, sum + B[j]);
    //     sum += A2[j];
    //   }
    // }

    A2.clear();
    B.clear();
    cycle.clear();
    S.clear();
    for(int x: A) {
      on_cycle[x] = false;
      vis[x] = false;
    }

    return ans;
  }
};

vector<int> curr_comp;
int vis[1000001];

void dfs(int i) {
  curr_comp.push_back(i);
  vis[i] = true;

  for(auto it: G[i]) {
    int v = it.first;
    if(!vis[v]) {
      dfs(v);
    }
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int N; cin >> N;

  for(int i = 1; i <= N; i++) {
    int v, l; cin >> v >> l;
    G[i].push_back({v, {l, i}});
    G[v].push_back({i, {l, i}});
  }

  long long ans = 0;
  for(int i = 1; i <= N; i++) {
    if(vis[i]) continue;
    curr_comp.clear();
    dfs(i);
    ans += Solve::get_ans(curr_comp);
  }
  cout << ans << endl;
}
