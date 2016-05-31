#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>
#include <cassert>

using namespace std;

int ROW_SIZE, COL_SIZE, ROW_B, COL_B;
int B;
int N, M;

int id_map[401][401];
bool lazy[160005];
set<int> blocks[160005];

inline bool check(int x, int y, int r, int a, int b) {
    return (a - x)*(a - x) + (b - y)*(b - y) <= r * r;
}

bool full_cover(int row, int col, int x, int y, int r) {
    int row_start = row * ROW_SIZE;
    int col_start = col * COL_SIZE;
    int row_end = min(row_start + ROW_SIZE - 1, N - 1);
    int col_end = min(col_start + COL_SIZE - 1, M - 1);
    
    return check(x, y, r, row_start, col_start)
        && check(x, y, r, row_end, col_start)
        && check(x, y, r, row_start, col_end)
        && check(x, y, r, row_end, col_end);
}

bool any_cover(int row, int col, int x, int y, int r) {
    int row_start = row * ROW_SIZE;
    int col_start = col * COL_SIZE;
    int row_end = min(row_start + ROW_SIZE - 1, N - 1);
    int col_end = min(col_start + COL_SIZE - 1, M - 1);
    
    bool row_side = false;
    if(x <= row_start) row_side = (x + r) >= row_start;
    else row_side = (x - r) <= row_end;
    
    bool col_side = false;
    if(y <= col_start) col_side = (y + r) >= col_start;
    else col_side = (y - r) <= col_end;
    
    return (row_side && col_side);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    int Q; cin >> M >> N >> Q;
    
    ROW_SIZE = 50;//int(sqrt(N));
    COL_SIZE = 50;//int(sqrt(M));
    
    ROW_B = int(ceil(N/double(ROW_SIZE)));
    COL_B = int(ceil(M/double(COL_SIZE)));
    
    B = ROW_B * COL_B;
    
    int timer = 0;
    for(int i = 0; i < ROW_B; i++) {
        for(int j = 0; j < COL_B; j++) {
            id_map[i][j] = timer++;
        }
    }
    
    assert(timer == B);
    
    while(Q--) {
        int x, y, r; cin >> x >> y >> r; swap(x, y);
        int row_start = max(x - r, 0)/ROW_SIZE, row_end = min((x + r)/ROW_SIZE + 2, ROW_B);
        int col_start = max(y - r, 0)/COL_SIZE, col_end = min((y + r)/COL_SIZE + 2, COL_B);
        for(int i = row_start; i < row_end; i++) {
            for(int j = col_start; j < col_end; j++) {
                int id = id_map[i][j];
                if(lazy[id]) continue;
                if(!any_cover(i, j, x, y, r)) continue;
                
                if(full_cover(i, j, x, y, r)) lazy[id] = true;
                else {
                    int end_r = min((i + 1) * ROW_SIZE, N), end_c = min((j + 1) * COL_SIZE, M);
                    for(int a = i * ROW_SIZE; a < end_r; a++) {
                        for(int b = j * COL_SIZE; b < end_c; b++) {
                            if(check(x, y, r, a, b)) blocks[id].insert(a * M + b);
                        }
                    }
                }
            }
        }
    }
    
    int ans = 0;
    for(int i = 0; i < ROW_B; i++) {
        for(int j = 0; j < COL_B; j++) {
            int id = id_map[i][j];
            if(lazy[id]) continue;

            int end_r = min((i + 1) * ROW_SIZE, N), end_c = min((j + 1) * COL_SIZE, M);
            int tot_size = (end_r - i * ROW_SIZE) * (end_c - j * COL_SIZE);
            ans += tot_size - blocks[id].size();
        }
    }
    cout << ans << endl;
}
