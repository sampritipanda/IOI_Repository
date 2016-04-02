#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>

using namespace std;

map<int, int> row_val, col_val;
map<int, long long> row_cnt, col_cnt;
set<int> xors;
map<pair<int, int>, int> rooks;
long long ans = 0;

void change(int R, int C, int X) {
  ans -= col_cnt[row_val[R]];
  ans -= row_cnt[col_val[C]];
  if(row_val[R] == col_val[C]) ans += 1;

  col_cnt[col_val[C]]--;
  row_cnt[row_val[R]]--;

  col_val[C] ^= X;
  row_val[R] ^= X;

  col_cnt[col_val[C]]++;
  row_cnt[row_val[R]]++;

  ans += col_cnt[row_val[R]];
  ans += row_cnt[col_val[C]];
  if(row_val[R] == col_val[C]) ans -= 1;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  long long N; int K, P; cin >> N >> K >> P;

  row_cnt[0] = N;
  col_cnt[0] = N;

  ans = N * N;

  while(K--) {
    int R, C, X; cin >> R >> C >> X;

    change(R, C, X);
    rooks[{R, C}] = X;
  }

  while(P--) {
    int R1, C1, R2, C2; cin >> R1 >> C1 >> R2 >> C2;
    int X = rooks[{R1, C1}];

    change(R1, C1, X);
    rooks.erase({R1, C1});

    change(R2, C2, X);
    rooks[{R2, C2}] = X;

    cout << N*N - ans << endl;
  }
}
