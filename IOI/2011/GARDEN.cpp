#include <cstdio>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

vector<pair<int, int> > O_G[150000];
int G[300000];  // 2*i => taking 1st path from i, 2*i + 1 => taking 2nd path from i
vector<int> R_G[300000];

int comp_id[300000];
vector<vector<int> > comp;
int dfs_num[300000], dfs_low[300000];
int timer = 0;
stack<int> S;
bool on_stack[300000];

bool on_cycle[300000];
bool on_cycle1[300000];
bool on_cycle2[300000];

int cycle_pos[300000];
int cycle_source[300000];
int cycle_dist[300000];

int cycle_pos2[300000];
int cycle_source2[300000];
int cycle_dist2[300000];

int P_dist[300000];
int P_dist2[300000];

int dist_in_cycle1[300000][2];
int dist_in_cycle2[300000][2];

void dfs(int i) {
  dfs_num[i] = dfs_low[i] = ++timer;
  S.push(i); on_stack[i] = true;

  int v = G[i];
  if(v != -1) {
    if(!dfs_num[v]) {
      dfs(v);
    }
    if(on_stack[v]) {
      dfs_low[i] = min(dfs_low[i], dfs_low[v]);
    }
  }

  if(dfs_num[i] == dfs_low[i]) {
    comp.push_back({});
    while(true) {
      int v = S.top(); S.pop(); on_stack[v] = false;
      comp.back().push_back(v);
      if(v == i) break;
    }
  }
}

void back_dfs_cycle(int u, int s, int d) {
  cycle_source[u] = s;
  cycle_dist[u] = d;

  for(int v: R_G[u]) {
    if(on_cycle[v]) continue;
    back_dfs_cycle(v, s, d + 1);
  }
}

void back_dfs_cycle2(int u, int s, int d) {
  cycle_source2[u] = s;
  cycle_dist2[u] = d;

  for(int v: R_G[u]) {
    if(on_cycle[v]) continue;
    back_dfs_cycle2(v, s, d + 1);
  }
}


void back_dfs2(int u, int d) {
  P_dist[u] = d;

  for(int v: R_G[u]) {
    if(on_cycle[v]) continue;
    back_dfs2(v, d + 1);
  }
}

void back_dfs2_2(int u, int d) {
  P_dist2[u] = d;

  for(int v: R_G[u]) {
    if(on_cycle[v]) continue;
    back_dfs2_2(v, d + 1);
  }
}


int main() {
  int N, M, P; scanf("%d %d %d", &N, &M, &P);

  for(int i = 0; i < M; i++) {
    int u, v; scanf("%d %d", &u, &v);
    O_G[u].push_back({v, i});
    O_G[v].push_back({u, i});
  }

  int Q; scanf("%d", &Q);

  for(int i = 0; i < N; i++) {
    sort(O_G[i].begin(), O_G[i].end(), [](pair<int, int> a, pair<int, int> b) {
        return a.second < b.second;
    });
    while(O_G[i].size() > 2) O_G[i].pop_back();
  }

  for(int i = 0; i < 2 * N; i++) G[i] = -1;

  for(int i = 0; i < N; i++) {
    for(int j = 0; j < O_G[i].size(); j++) {
      int v = O_G[i][j].first;
      int v_j = (O_G[i][j].second == O_G[v][0].second ? 1 : 0);
      if(O_G[v].size() == 1) v_j = 0;
      G[2*i + j] = (2*v + v_j);
    }
  }

  for(int i = 0; i < 2 * N; i++) {
    R_G[G[i]].push_back(i);
  }

  comp.push_back({});

  for(int i = 0; i < 2 * N; i++) {
    if(dfs_num[i]) continue;
    dfs(i);
  }

  for(int i = 0; i < comp.size(); i++) {
    for(int v: comp[i]) {
      comp_id[v] = i;
    }
  }

  for(int i = 0; i < 2 * N; i++) {
    if(comp[comp_id[i]].size() > 1) on_cycle[i] = true;
  }

  if(comp[comp_id[2 * P]].size() > 1 || comp[comp_id[2 * P + 1]].size() > 1) {
    int C_V = (comp[comp_id[2 * P]].size() > 1 ? 2 * P : 2 * P + 1);
    vector<int> cycle;
    vector<int> cycle2;
    int u = C_V;
    while(true) {
      cycle.push_back(u);
      if(G[u] == C_V) break;
      u = G[u];
    }
    for(int i = 0; i < 2 * N; i++) cycle_source[i] = cycle_dist[i] = cycle_pos[i] = -1;
    for(int i = 0; i < 2 * N; i++) dist_in_cycle1[i][0] = dist_in_cycle1[i][1] = -1;
    for(int i = 0; i < cycle.size(); i++) {
      int v = cycle[i];
      cycle_pos[v] = i;
      back_dfs_cycle(v, v, 0);
    }
    for(int x: cycle) on_cycle1[x] = true;

    for(int x: cycle) {
      dist_in_cycle1[x][0] = (cycle_pos[2 * P] - cycle_pos[x] + cycle.size()) % cycle.size();
      dist_in_cycle1[x][1] = (cycle_pos[2 * P + 1] - cycle_pos[x] + cycle.size()) % cycle.size();
    }

    if(O_G[P].size() > 1) {
      if(!on_cycle[C_V ^ 1]) {
        back_dfs2(C_V ^ 1, 0);
      }
      else {
        int u = C_V ^ 1;
        while(true) {
          cycle2.push_back(u);
          if(G[u] == (C_V ^ 1)) break;
          u = G[u];
        }
        for(int x: cycle2) on_cycle2[x] = true;
        for(int i = 0; i < 2 * N; i++) cycle_source2[i] = cycle_dist2[i] = cycle_pos2[i] = -1;
        for(int i = 0; i < 2 * N; i++) dist_in_cycle2[i][0] = dist_in_cycle2[i][1] = -1;
        for(int i = 0; i < cycle2.size(); i++) {
          int v = cycle2[i];
          cycle_pos2[v] = i;
          back_dfs_cycle2(v, v, 0);
        }
        for(int x: cycle2) {
          dist_in_cycle2[x][0] = (cycle_pos2[2 * P] - cycle_pos2[x] + cycle2.size()) % cycle2.size();
          dist_in_cycle2[x][1] = (cycle_pos2[2 * P + 1] - cycle_pos2[x] + cycle2.size()) % cycle2.size();
        }
      }
    }

    while(Q--) {
      int K; scanf("%d", &K);

      int cnt = 0;
      for(int i = 0; i < N; i++) {
        if(on_cycle[2 * i] && (on_cycle[C_V] && comp_id[2 * i] != comp_id[C_V]) && (on_cycle[C_V ^ 1] && comp_id[2 * i] != comp_id[C_V ^ 1])) continue;

        int T_K = K;
        int v = 2 * i;

        bool ok = true;
        if(!on_cycle1[v]) {
          if(cycle_source[v] == -1) ok = false;
          T_K -= cycle_dist[v];
          if(T_K < 0) {
            T_K = 0;
            ok = false;
          }
          v = cycle_source[v];
        }
        T_K %= cycle.size();

        int dist = -1, dist2 = -1;
        if(cycle_pos[2 * P] != -1) dist = dist_in_cycle1[v][0];
        if(cycle_pos[2 * P + 1] != -1) dist2 = dist_in_cycle1[v][1];

        if(ok && (dist == T_K || dist2 == T_K)) cnt++;
        else if(O_G[P].size() > 1) {
          if(!on_cycle[C_V ^ 1]) {
            if(P_dist[2 * i] == K) cnt++;
          }
          else {
            T_K = K;
            v = 2 * i;
            if(!on_cycle2[v]) {
              if(cycle_source2[v] == -1) continue;
              T_K -= cycle_dist2[v];
              if(T_K < 0) {
                T_K = 0;
                continue;
              }
              v = cycle_source2[v];
            }
            T_K %= cycle2.size();
            dist = -1, dist2 = -1;
            if(cycle_pos2[2 * P] != -1) dist = dist_in_cycle2[v][0];
            if(cycle_pos2[2 * P + 1] != -1) dist2 = dist_in_cycle2[v][1];

            if(dist == T_K || dist2 == T_K) cnt++;
          }
        }
      }
      printf("%d ", cnt);
    }
    printf("\n");
  }
  else {
    for(int i = 0; i < 2 * N; i++) P_dist[i] = P_dist2[i] = -1;

    back_dfs2(2 * P, 0);
    back_dfs2_2(2 * P + 1, 0);

    while(Q--) {
      int K; scanf("%d", &K);

      int cnt = 0;
      for(int i = 0; i < N; i++) {
        if(P_dist[2 * i] == K || P_dist2[2 * i] == K) cnt++;
      }

      printf("%d ", cnt);
    }
    printf("\n");
  }
}
