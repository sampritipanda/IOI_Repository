// Monster’s Inc

#include <stdio.h>
#include <set>
#include <algorithm>

using namespace std;

int grid[1001][1001];

#define MOD 1000000007

struct range_tree {
  long long bit1[1002], bit2[1002];
};

range_tree trees[1005];

int N, M;

inline int scan(){
    char c = getchar_unlocked();
    int x = 0;
    while(c<'0'||c>'9'){
            c=getchar_unlocked();
        }
    while(c>='0'&&c<='9'){
            x=(x<<1)+(x<<3)+c-'0';
            c=getchar_unlocked();
        }
    return x;
}

void update(long long bit[], int idx, long long val){
  for(int x = idx; x <= 1001; x += x & -x) {
    bit[x] += val;
    bit[x] %= MOD;
  }
}

long long query(long long bit[], int idx){
  long long ret = 0;

  for(int x = idx; x > 0; x -= x & -x) {
    ret += bit[x];
    while(ret < 0) ret += MOD;
    ret %= MOD;
  }

  return ret;
}

void range_update(range_tree* ST, int L, int R, int val){
  update(ST->bit1, L, val);
  update(ST->bit1, R + 1, -val);
  update(ST->bit2, L, -(long long)val * (L - 1));
  update(ST->bit2, R + 1, (long long)val * R);
}

long long range_query(range_tree* ST, int L, int R){
  long long ans = 0;
  ans += query(ST->bit1, R) * R;
  ans += query(ST->bit2, R);
  ans -= query(ST->bit1, L - 1) * (L - 1);
  ans -= query(ST->bit2, L - 1);
  while(ans < 0) ans += MOD;
  ans %= MOD;

  return ans;
}

long long init_tree(range_tree* ST, int k){
  for(int i = 0; i < 1002; i++) {
    ST->bit1[i] = 0;
    ST->bit2[i] = 0;
  }

  for(int L = 1; L <= N; L++) {
    if((k - L) >= 0 & (k - L) <= M) range_update(ST, L, L, grid[L][k - L]);
  }
}

int main() {
  set<int> factors[1001];
  for(int k = 1; k <= 1000; k++){
    for(int i = 1; i*i <= k; i++){
      if(k % i != 0) continue;
      factors[k].insert(i);
      factors[k].insert(k/i);
    }
  }

  // int O; scanf("%d %d %d", &N, &M, &O);
  int O;
  N = scan(); M = scan(); O = scan();
  for(int i = 1; i <= N; i++){
    for(int j = 1; j <= M; j++){
      // scanf("%d", &grid[i][j]);
      grid[i][j] = scan();
    }
  }

  for(int i = 0; i <= 1000; i++){
    init_tree(trees + i, i);
  }

  while(O--){
    // int type, x1, y1, x2, y2, k; scanf("%d %d %d %d %d %d", &type, &x1, &y1, &x2, &y2, &k);
    int type, x1, y1, x2, y2, k;
    type = scan(); x1 = scan(); y1 = scan(); x2 = scan(); y2 = scan(); k = scan();

    if(type == 0){
      // int v; scanf("%d", &v);
      int v = scan();
      for(auto f: factors[k]){
        int l = max(f - y2, x1);
        int r = min(f - y1, x2);
        if(l > r) continue;
        range_update(trees + f, l, r, v);
      }
    }
    else {
      long long sum = 0;
      for(auto f: factors[k]){
        int l = max(f - y2, x1);
        int r = min(f - y1, x2);
        if(l > r) continue;
        sum += range_query(trees + f, l, r);
        while(sum < 0) sum += MOD;
        sum %= MOD;
      }
      printf("%lld\n", sum);
    }
  }
}
