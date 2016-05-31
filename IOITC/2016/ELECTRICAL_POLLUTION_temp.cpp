#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cassert>
#include <climits>

using namespace std;

int X[10001], Y[10001], A[10001];
int Q_X[10001], Q_Y[10001];
int val[40001];
map<int, int> compres;
int N, M, Q;
vector<int> G[40001];
int dfs_num[40001], dfs_low[40001];
vector<int> bi_comps;
int timer, timer2;
stack<pair<int, int>> S;

void reset() {
    compres.clear();
    for(int i = 0; i <= 40000; i++) {
        G[i].clear();
        dfs_num[i] = dfs_low[i] = 0;
        is_part_of_bicomp[i] = false;
        val[i] = INT_MAX/2;
    }
}

inline int adj(int x, int i) {
    return X[i] ^ Y[i] ^ x;
}

void dfs(int i, int p) {
    dfs_num[i] = dfs_low[i] = ++timer;
    S.push({p, i});
    
    for(int id: G[i]) {
        int u = adj(id);
        
        if(dfs_num[u] == 0) {
            dfs(u, i);
            dfs_low[i] = min(dfs_low[i], dfs_low[u]);
        }
        else {
            dfs_low[i] = min(dfs_low[i], dfs_num[u]);
        }
        
        if(dfs_low[i] >= dfs_num[i]){
            timer2++;
            bi_comps.push_back({});
            while(!S.empty()) {
                auto it = S.top(); S.pop();
                int curr_p = it.first, curr_u = it.second;
                bi_comps[timer2].push_back(curr_u);
                if(curr_p == p) break;
            }
            if(bi_comps[timer2].size() <= 2) {
                bi_comps.pop_back();
                timer2--;
            }
        }
    }
}

bool is_part_of_bicomp[40001];

void mark_answer(int u, int p) {
    for(int id: G[u]) {
        int v = adj(u, id), d = A[id];
        if(!is_part_of_bicomp[v]) continue;
        if(ans[v] != INT_MAX/2) continue;
    }
}

void solve_bicomp(int id) {
    for(int u: bi_comps[id]) {
        is_part_of_bicomp[u] = true;
    }
    
    for(int u: bi_comps[id]) {
        if(ans[u] != INT_MAX/2) {
            mark_answer(u, -1);
            break;
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    int T; cin >> T;
    
    while(T--) {
        reset();
        
        cin >> M >> Q;
        
        for(int i = 0; i < M; i++) {
            cin >> X[i] >> Y[i] >> A[i];
            compres[X[i]];
            compres[Y[i]];
        }
        
        for(int i = 0; i < Q; i++) {
            cin >> Q_X[i] >> Q_Y[i];
            compres[Q_X[i]]; compres[Q_Y[i]];
        }
        
        N = 0;
        for(auto it: compres) {
            compres[it.first] = ++N;
        }
        assert(N <= 40000);
        
        for(int i = 0; i < M; i++) {
            X[i] = compres[X[i]]; Y[i] = compres[Y[i]];
        }
        for(int i = 0; i < Q; i++) {
            Q_X[i] = compres[Q_X[i]];
            Q_Y[i] = compres[Q_Y[i]];
        }
        
        for(int i = 0; i < M; i++) {
            G[X[i]].push_back(i);
            G[Y[i]].push_back(i);
        }
        
        bi_comps.push_back({-1});
        timer = timer2 = 0;
        for(int i = 1; i <= N; i++) {
            if(dfs_num[i]) continue;
            dfs(i, -1);
        }
        
        for(int i = 1; i <= timer2; i++) {
            solve_bicomp(i);
        }
    }
}
