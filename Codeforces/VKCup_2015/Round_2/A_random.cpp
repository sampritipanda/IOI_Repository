#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

int H[500001];
int S[500001];
vector<int> G[500001];
int depth[500001];
vector<int> D_map[500001];
int min_D[500001];
int min_el[500001];
bool is_min_el[500001];
int N, K;
vector<pair<int, int> > temp_sort;

void dfs(int i, int p, int d, int el, int dep) {
    if(H[i] < d) {
        d = H[i];
        el = i;
    }
    min_D[i] = d;
    min_el[i] = el;
    depth[i] = dep;
    
    for(int u: G[i]) {
        if(u == p) continue;
        dfs(u, i, d, el, dep + 1);
    }
}

bool check() {
    for(int i = 0; i <= N; i++) {
        depth[i] = 0;
        min_D[i] = INT_MAX/2;
        min_el[i] = -1;
    }
    temp_sort.clear();
        
    dfs(1, 0, INT_MAX, -1, 0);
    
    for(int i = 1; i <= N; i++) {
        temp_sort.push_back({min_D[i], i});
    }
    sort(temp_sort.begin(), temp_sort.end());
    reverse(temp_sort.begin(), temp_sort.end());
    
    int ans = 0;
    for(int i = 1; i <= K; i++) {
        if(S[i] > temp_sort[i - 1].first) {
            return false;
        }
    }
    return true;
}

int solve() {
    int cnt = 0;
    for(int d = 0; d < N; d++) {
        for(int i: D_map[d]) {
            if(!is_min_el[i]) continue;
            cnt++;
            
            int L = 1, R = 1000000001;
            while(L < R) {
                int mid = (L + R)/2;
                H[i] += mid;
                if(check()) {
                    R = mid;
                }
                else {
                    L = mid + 1;
                }
                H[i] -= mid;
            }
            if(L <= 1000000000) return L;
            
            if(cnt == 100) return -1;
        }
    }
    return -1;
}

int main() {
    scanf("%d", &N);
    
    for(int i = 1; i <= N; i++) scanf("%d", &H[i]);
    
    for(int i = 0; i < N - 1; i++) {
        int a, b; scanf("%d %d", &a, &b);
        
        G[a].push_back(b);
        G[b].push_back(a);
    }
    
    scanf("%d", &K);
    
    for(int i = 1; i <= K; i++) scanf("%d", &S[i]);
    sort(S + 1, S + K + 1);
    reverse(S + 1, S + K + 1);
    
    if(check()) {
        cout << 0 << endl;
    }
    else {
        for(int i = 1; i <= N; i++) {
            D_map[depth[i]].push_back(i);
        }
        for(int i = 1; i <= N; i++) {
            is_min_el[min_el[i]] = true;
        }
        
        cout << solve() << endl;
    }
}
