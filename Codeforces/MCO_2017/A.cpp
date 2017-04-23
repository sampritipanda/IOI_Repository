#include <iostream>
#include <algorithm>

using namespace std;

int A[1000001];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int N; cin >> N;

    int j = 0;
    for(int i = 1; i <= N; i++) {
        cin >> A[i];
        if(A[i] == N) j = i;
    }

    int ans = 0;

    int curr_max = 0;
    for(int i = j + 1; i <= N; i++) {
        curr_max = max(curr_max, A[i]);
        if(A[i] == curr_max) ans++;
    }

    curr_max = 0;
    for(int i = j - 1; i >= 1; i--) {
        curr_max = max(curr_max, A[i]);
        if(A[i] == curr_max) ans++;
    }

    cout << ans << endl;
}
