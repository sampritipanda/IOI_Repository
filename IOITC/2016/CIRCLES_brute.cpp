#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool A[1001][1001];

int main() {
    int W, H, N; cin >> W >> H >> N;
    
    while(N--) {
        int x, y, r; cin >> x >> y >> r;
        
        for(int i = 0; i < W; i++) {
            for(int j = 0; j < H; j++) {
                if((i-x)*(i-x) + (j-y)*(j-y) <= r*r) A[i][j] = true;
            }
        }
    }
    
    int ans = 0;
    for(int i = 0; i < W; i++) {
        for(int j = 0; j < H; j++) {
            if(!A[i][j]) ans++;
        }
    }
    cout << ans << endl;
}
