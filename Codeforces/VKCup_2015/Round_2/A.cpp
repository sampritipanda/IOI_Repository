#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

int H[500001];
int S[500001];
vector<int> G[500001];
int depth[500001];
int min_D[500001];
int min_el[500001];
vector<pair<pair<int, int>, int> > temp_sort;

bool compare(pair<pair<int, int>, int> A, pair<pair<int, int>, int> B) {
    if(A.first.first == B.first.first) {
        if(depth[A.first.second] == depth[B.first.second]) return A.second > B.second;
        return depth[A.first.second] < depth[B.first.second];
    }
    return A.first.first > B.first.first;
}

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

int main() {
    int N; scanf("%d", &N);

    for(int i = 1; i <= N; i++) scanf("%d", &H[i]);

    for(int i = 0; i < N - 1; i++) {
        int a, b; scanf("%d %d", &a, &b);

        G[a].push_back(b);
        G[b].push_back(a);
    }

    int K; scanf("%d", &K);

    for(int i = 1; i <= K; i++) scanf("%d", &S[i]);
    sort(S + 1, S + K + 1);
    reverse(S + 1, S + K + 1);

    for(int i = 0; i <= N; i++) {
            depth[i] = 0;
            min_D[i] = INT_MAX/2;
            min_el[i] = -1;
    }

    dfs(1, 0, INT_MAX/2, -1, 0);

    for(int i = 1; i <= N; i++) {
        temp_sort.push_back({{min_D[i], min_el[i]}, i});
    }
    sort(temp_sort.begin(), temp_sort.end(), compare);

    int ans = 0;
    for(int i = 1; i <= K; i++) {
        if(S[i] > temp_sort[i - 1].first.first) {
            ans = S[i] - temp_sort[i - 1].first.first;
            H[temp_sort[i - 1].first.second] = S[i];
            break;
        }
    }

    if(ans == 0) {
        cout << 0 << endl;
    }
    else {
        for(int i = 0; i <= N; i++) {
            depth[i] = 0;
            min_D[i] = INT_MAX/2;
            min_el[i] = -1;
        }

        dfs(1, 0, INT_MAX/2, -1, 0);

        temp_sort.clear();
        for(int i = 1; i <= N; i++) {
            temp_sort.push_back({{min_D[i], min_el[i]}, i});
        }
        sort(temp_sort.begin(), temp_sort.end(), compare);

        bool pos = true;
        for(int i = 1; i <= K; i++) {
            if(S[i] > temp_sort[i - 1].first.first) {
                pos = false;
                break;
            }
        }

        if(pos) cout << ans << endl;
        else cout << -1 << endl;
    }
}
