#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <set>

using namespace std;

int S[200001];
int E[200001];
vector<pair<int, int> > G[200001];
long long D[200001];
set<pair<long long, int> > Q;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int N, M; cin >> N >> M;

    for(int i = 1; i <= N; i++) cin >> S[i] >> E[i];

    while(M--) {
        int u, v, w; cin >> u >> v >> w;
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }

    int s; cin >> s;

    for(int i = 1; i <= N; i++) D[i] = LLONG_MAX/2;

    D[s] = 0;
    Q.insert({D[s], s});

    while(!Q.empty()) {
        auto it = *Q.begin(); Q.erase(Q.begin());
        int u = it.second;

        for(auto it2: G[u]) {
            int v = it2.first, w = it2.second;

            long long wait = 0;
            if((D[u] % (S[u] + E[u])) >= S[u]) wait = (S[u] + E[u]) - (D[u] % (S[u] + E[u]));
            if(D[u] + wait + w < D[v]) {
                if(D[v] != LLONG_MAX/2) {
                    Q.erase({D[v], v});
                }
                D[v] = D[u] + wait + w;
                Q.insert({D[v], v});
            }
        }
    }

    for(int i = 1; i <= N; i++) cout << D[i] << " "; cout << endl;
}
