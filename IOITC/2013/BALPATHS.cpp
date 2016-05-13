#include <algorithm>
#include <vector>
#include <cassert>

using namespace std;

const int MAX_LOG = 17;

vector<pair<int, int> > G[100001];
int cnt_0[100001], cnt_1[100001];
int D[100001];
int subSize = 0;
int sz[100001];
int label[100001];
vector<int> C_G[100001];
int P[100001];
int lca[100001][MAX_LOG];

long long dp_1[100001]; // number of nodes in subtree of i such that 0-type and 1-type edges are equal in path from i
long long dp_2[100001]; // number of balanced paths with centroid LCA at i

void reset() {
    const int MAX_N = 100000;
    for(int i = 1; i <= MAX_N; i++) {
        G[i].clear();
        cnt_0[i] = cnt_1[i] = 0;
        D[i] = 0;
        sz[i] = 0;
        label[i] = 0;
        P[i] = 0;
        C_G[i].clear();
        for(int j = 0; j < MAX_LOG; j++) {
            lca[i][j] = 0;
        }
    }
}

void dfs_precalc(int u, int p, int t0, int t1, int d) {
    P[u] = p;
    cnt_0[u] = t0; cnt_1[u] = t1;
    D[u] = d;
    
    for(auto it: G[u]) {
        int v = it.first, t = it.second;
        if(v == p) continue;
        dfs_precalc(v, u, t0 + (t == 0 ? 1 : 0), t1 + (t == 1 ? 1 : 0), d + 1);
    }
}

void dfs_calcsize(int u, int p) {
    sz[u] = 1;
    subSize++;
    
    for(auto it: G[u]) {
        int v = it.first, t = it.second;
        if(v == p || label[v]) continue;
        
        dfs_calcsize(v, u);
        sz[u] += sz[v];
    }
}

int find_centroid(int u, int p) {
    for(auto it: G[u]) {
        int v = it.first;
        if(v == p || label[v]) continue;
        
        if(sz[v] > subSize/2) return find_centroid(v, u);
    }
    return u;
}

int centroid_decompose(int u, int j) {
    subSize = 0;
    dfs_calcsize(u, 0);
    
    int root = find_centroid(u, 0);
    label[root] = j;
    
    for(auto it: G[root]) {
        int v = it.first;
        if(label[v]) continue;
        int nextRoot = centroid_decompose(v, j + 1);
        C_G[root].push_back(nextRoot);
    }
    
    return root;
}

int lca_query(int u, int v) {
    if(D[u] > D[v]) swap(u, v);
    
    for(int j = MAX_LOG - 1; j >= 0; j--) {
        if(D[v] - (1 << j) >= D[u]) 
            v = lca[v][j];
    }
    
    if(u == v) return u;
    
    for(int j = MAX_LOG - 1; j >= 0; j--) {
        if(lca[u][j] && lca[v][j] && lca[u][j] != lca[v][j]) {
            u = lca[u][j]; v = lca[v][j];
        }
    }
    
    assert(lca[u][0] == lca[v][0]);
    return lca[u][0];
}

int count_0(int u, int v) {
    int l = lca_query(u, v);
    return cnt_0[u] + cnt_0[v] - cnt_0[l] - cnt_0[P[l]];
}

int count_1(int u, int v) {
    int l = lca_query(u, v);
    return cnt_1[u] + cnt_1[v] - cnt_1[l] - cnt_1[P[l]];
}

vector<int> rec_stack;

void dfs_dp1(int u) {
    for(auto it: G[u]) {
        int v = it.first;
        dfs(v);
    }    
    
    for(int v: rec_stack) {
        if(count_0(u, v) == count_1(u, v)) dp_1[u]++;
    }
    
    rec_stack.push_back(u);
}

long long countPaths(int N, int * u, int * v, int * type) {
    reset();
    
    for(int i = 0; i < N - 1; i++) {
        int a = u[i], b = v[i], t = type[i];
        G[a].push_back({b, t});
        G[b].push_back({a, t});
    }
    
    dfs_precalc(1, 0, 0, 0, 0);
    
    int centroidRoot = centroid_decompose();
    
    for(int i = 1; i <= N; i++) lca[i][0] = P[i];
    
    for(int j = 1; j < MAX_LOG; j++) {
        for(int i = 1; i <= N; i++) {
            if(lca[i][j - 1])
                lca[i][j] = lca[lca[i][j - 1]][j - 1];
        }
    }
}
