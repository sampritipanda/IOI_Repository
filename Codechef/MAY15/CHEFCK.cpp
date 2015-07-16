// Chef and Cake

#include <iostream>
#include <cmath>
#include <vector>
#include <climits>

#define MOD 1000000007

using namespace std;

const int MAX_SIZE = 10000000;
const int LOGSIZE = 25;

int A[MAX_SIZE + 1];
int block_prefix[MAX_SIZE + 1], block_suffix[MAX_SIZE + 1];

inline int ceil_div(int a, int b){
  return (a + b - 1)/b;
}

int main() {
  int N, K, Q; cin >> N >> K >> Q;
  long long a, b, c, d, e, f, r, s, t, m; cin >> a >> b >> c >> d >> e >> f >> r >> s >> t >> m >> A[1];
  int L1, La, Lc, Lm, D1, Da, Dc, Dm; cin >> L1 >> La >> Lc >> Lm >> D1 >> Da >> Dc >> Dm;

  int temp_pow = t;
  for(int x = 2; x <= N; x++){
    temp_pow = (temp_pow * t) % s;
    if(temp_pow <= r){
      A[x] = (((a * (A[x-1] * (long long)A[x-1]) % m) % m) + (b * A[x-1]) % m + c) % m;
    }
    else {
      A[x] = (((d * (A[x-1] * (long long)A[x-1]) % m) % m) + (e * A[x-1]) % m + f) % m;
    }
  }

  int i = 1, block_number = 1;
  while(i <= N){
    int curr_pref_min = INT_MAX, curr_suff_min = INT_MAX;
    for(int j = i; j <= min(i + K - 1, N); j++){
      curr_pref_min = min(curr_pref_min, A[j]);
      block_prefix[j] = curr_pref_min;
    }
    for(int j = min(i + K - 1, N); j >= i; j--){
      curr_suff_min = min(curr_suff_min, A[j]);
      block_suffix[j] = curr_suff_min;
    }
    i += K;
    block_number++;
  }

  long long sum = 0, prod = 1;
  int L, R;

  for(int i = 1; i <= Q; i++){
    L1 = ((La * (long long)L1) % Lm + Lc) % Lm;
    D1 = ((Da * (long long)D1) % Dm + Dc) % Dm;
    L = L1 + 1;
    R = min(L + K - 1 + D1, N);

    int start_block = ceil_div(L, K), end_block = ceil_div(R, K);
    int curr_ans = min(block_suffix[L], block_prefix[R]);
    if(end_block - start_block == 2) curr_ans = min(curr_ans, block_prefix[(start_block + 1) * K]);

    sum += curr_ans;
    prod = (prod * curr_ans) % MOD;
  }

  cout << sum << " " << prod << endl;
}
