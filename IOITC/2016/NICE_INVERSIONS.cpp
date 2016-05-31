#include <iostream>
#include <algorithm>
#include <map>
#include <cstring>

using namespace std;

int N;
int R[100000];
int B[100000];
int bit[100001];

map<int, int> compres;
vector<pair<int, int> > A;

bool compare_1(pair<int, int> A, pair<int, int> B) {
    if(A.first == B.first) return A.second < B.second;
    return A.first < B.first;
}

bool compare_2(pair<int, int> A, pair<int, int> B) {
    if(A.second == B.second) return A.first < B.first;
    return A.second < B.second;
}

int query(int i) {
    int ans = 0;
    while(i > 0) {
        ans += bit[i];
        i -= i & -i;
    }
    return ans;
}

void update(int i, int d) {
    while(i <= 100000) {
        bit[i] += d;
        i += i & -i;
    }
}

long long count_inv() {
    long long ans = 0;
    
    memset(bit, 0, sizeof bit);
    for(int i = N - 1; i >= 0; i--) {
        ans += query(A[i].first - 1);
        update(A[i].first, 1);
    }
    
    memset(bit, 0, sizeof bit);
    for(int i = N - 1; i >= 0; i--) {
        ans += query(A[i].second - 1);
        update(A[i].second, 1);
    }
    
    return ans;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    cin >> N;
    
    for(int i = 0; i < N; i++) {
        cin >> R[i] >> B[i];
    }
    
    for(int i = 0; i < N; i++) compres[R[i]];
    int timer = 0;
    for(auto it: compres) compres[it.first] = ++timer;
    for(int i = 0; i < N; i++) R[i] = compres[R[i]];
    
    compres.clear(); timer = 0;
    for(int i = 0; i < N; i++) compres[B[i]];
    for(auto it: compres) compres[it.first] = ++timer;
    for(int i = 0; i < N; i++) B[i] = compres[B[i]];
    
    for(int i = 0; i < N; i++) A.push_back({R[i], B[i]});
    
    long long ans = count_inv();
    
    sort(A.begin(), A.end(), compare_1);
    ans = min(ans, count_inv());
    
    sort(A.begin(), A.end(), compare_2);
    ans = min(ans, count_inv());
    
    cout << ans << endl;
}
