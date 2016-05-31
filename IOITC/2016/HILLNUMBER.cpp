#include <iostream>
#include <algorithm>
#include <string>
#include <cassert>

using namespace std;

int D[100];
int N;
long long dp[100][10][2][2];

// ith digit, j = prev digit, k = decrease started, l = not less/less
long long solve(int i, int j, int k, int l) {
    if(j < 0) return 0;
    if(i == N) return (l == 1);
    if(dp[i][j][k][l] != -1) return dp[i][j][k][l];
    
    long long ans = 0;
    
    if(k == 0) {
        if(l == 0) {
            for(int d = j; d <= D[i]; d++) {
                ans += solve(i + 1, d, 0, (d == D[i] ? 0 : 1));
            }
            for(int d = min(j - 1, D[i]); d >= 0; d--) {
                ans += solve(i + 1, d, 1, (d == D[i] ? 0 : 1));
            }
        }
        else {
            for(int d = j; d <= 9; d++) {
                ans += solve(i + 1, d, 0, 1);
            }
            for(int d = j - 1; d >= 0; d--) {
                ans += solve(i + 1, d, 1, 1);
            }
        }
    }
    else {
        if(l == 1) {
            for(int d = j; d >= 0; d--) {
                ans += solve(i + 1, d, 1, 1);
            }
        }
        else {
            for(int d = min(D[i], j); d >= 0; d--) {
                ans += solve(i + 1, d, 1, (d == D[i] ? 0 : 1));
            }
        }
    }
    
    return dp[i][j][k][l] = ans;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    int T; cin >> T;
    
    while(T--) {
        string S; cin >> S;
        N = S.length();
        for(int i = 0; i < N; i++) D[i] = S[i] - '0';
        
        bool hill = true;
        for(int i = 1; i < N - 1; i++) {
            if(D[i] < D[i - 1] && D[i] < D[i + 1]) {
                hill = false;
                break;
            }
        }
        
        for(int i = 0; i <= N; i++) {
            for(int j = 0; j <= 9; j++) {
                for(int k = 0; k < 2; k++) {
                    for(int l = 0; l < 2; l++) {
                        dp[i][j][k][l] = -1;
                    }
                }
            }
        }
        
        if(hill) {
            cout << solve(0, 0, 0, 0) << endl;
        }
        else {
            cout << -1 << endl;
        }
    }
}
