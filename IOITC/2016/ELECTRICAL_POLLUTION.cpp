#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cassert>
#include <climits>
#include <stack>

using namespace std;

int X[10001], Y[10001], A[10001];
int Q_X[10001], Q_Y[10001];
int val[40001];
map<int, int> compres;
int N, M, Q;
vector<int> G[40001];
int vis[40001];
int cycle_root;
stack<int> S;
map<pair<int, int>, int> edge_map;

void reset() {
    compres.clear();
    for(int i = 0; i <= 40000; i++) {
        G[i].clear();
        val[i] = INT_MAX/2;
        vis[i] = false;
    }
}

inline int adj(int x, int i) {
    return X[i] ^ Y[i] ^ x;
}

bool find_cycle(int u, int p) {
    if(vis[u]) {
        cycle_root = u;
        return true;
    }
    vis[u] = true;
    
    S.push(u);
    
    for(int id: G[u]) {
        int v = adj(u, id);
        if(v == p) continue;
        
        if(find_cycle(v, u)) return true;
    }
    
    S.pop();
    
    return false;
}

void mark_answer(int u) {
    vis[u] = true;
    
    for(int id: G[u]) {
        int v = adj(u, id), d = A[id];
        if(val[v] != INT_MAX/2) continue;
        
        val[v] = d - val[u];
        mark_answer(v);
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
            if(X[i] == Y[i]) {
                val[X[i]] = A[i];
                continue;
            }
            
            G[X[i]].push_back(i);
            G[Y[i]].push_back(i);
            
            edge_map[{X[i], Y[i]}] = i;
            edge_map[{Y[i], X[i]}] = i;
        }
        
        for(int i = 1; i <= N; i++) {
            if(val[i] != INT_MAX/2) mark_answer(i);
        }
        
        for(int i = 1; i <= N; i++) {
            if(vis[i]) continue;
            
            while(!S.empty()) S.pop();
            cycle_root = -1;
            find_cycle(i, -1);
            if(cycle_root == -1) continue;
            
            vector<int> cycle;
            while(true) {
                int u = S.top(); S.pop();
                cycle.push_back(u);
                if(u == cycle_root) break;
            }
            reverse(cycle.begin(), cycle.end());
            assert(cycle.size() >= 3);
            
            int curr_ans = 0;
            curr_ans += A[edge_map[{cycle[0], cycle[1]}]];
            curr_ans += A[edge_map[{cycle[0], cycle[cycle.size() - 1]}]];
            
            if(cycle.size() % 2 == 1) {
                for(int i = 1; i < cycle.size() - 1; i++) {
                    if(i % 2 == 0) {
                        curr_ans += A[edge_map[{cycle[i], cycle[i + 1]}]];
                    }
                    else {
                        curr_ans -= A[edge_map[{cycle[i], cycle[i + 1]}]];
                    }
                }
            }
            else {
                for(int i = 1; i < cycle.size() - 1; i++) {
                    if(i % 2 == 0 && i != cycle.size() - 2) {
                        curr_ans += A[edge_map[{cycle[i], cycle[i + 1]}]];
                    }
                    else {
                        curr_ans -= A[edge_map[{cycle[i], cycle[i + 1]}]];
                    }
                    
                }
            }
            
            assert(curr_ans % 2 == 0);
            val[cycle[0]] = curr_ans/2;
            
            mark_answer(cycle[0]);
        }
        
        for(int i = 0; i < Q; i++) {
            if(val[Q_X[i]] == INT_MAX/2 || val[Q_Y[i]] == INT_MAX/2) cout << "*" << endl;
            else {
                if(Q_X[i] == Q_Y[i]) cout << val[Q_X[i]] << endl;
                else cout << val[Q_X[i]] + val[Q_Y[i]] << endl;
            }
        }
        
        cout << "-" << endl;
    }
}
