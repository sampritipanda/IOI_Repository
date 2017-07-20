#include <cstdio>
#include <algorithm>
#include <climits>

using namespace std;

struct line {
  long long m, c;

  line(long long _m, long long _c) : m(_m), c(_c) {};

  long long at(long long x) {
    return m * x + c;
  }

  double intersect(line other) {
    return double(other.c - c)/(m - other.m);
  }
};

int N, K;
int A[100001];
long long P[100001];
long long dp[2][100002];
int nxt[202][100002];

vector<pair<line, int> > lines;
vector<double> inter;

void insert(line x, int k) {
  while(!lines.empty() && lines.back().first.m == x.m) {
    if(lines.back().first.c >= x.c) return;
    lines.pop_back();
    if(!inter.empty()) inter.pop_back();
  }

  while(!inter.empty() && x.intersect(lines.back().first) <= inter.back()) {
    inter.pop_back();
    lines.pop_back();
  }

  if(!lines.empty()) {
    inter.push_back(x.intersect(lines.back().first));
  }

  lines.push_back({x, k});
}

int inter_ptr;
pair<line, int> get_best(long long x) {
  inter_ptr = min(inter_ptr, (int)inter.size());
  while(inter_ptr < inter.size() && x > inter[inter_ptr]) inter_ptr++;
  return lines[inter_ptr];
}

int main() {
  scanf("%d %d", &N, &K);
  for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
  for(int i = 1; i <= N; i++) P[i] = P[i - 1] + A[i];

  dp[0][0] = LLONG_MIN/10;
  int t = 1;

  for(int _k = 2; _k <= K + 1; _k++) {
    dp[t][0] = LLONG_MIN/10;

    lines.clear();
    inter.clear();
    inter_ptr = 0;

    for(int i = 1; i <= N; i++) {
      insert(line(P[i - 1], dp[t ^ 1][i - 1] - P[i - 1] * P[i - 1]), i);

      auto it = get_best(P[i]);
      dp[t][i] = it.first.at(P[i]);
      nxt[_k][i] = it.second;
    }

    t ^= 1;
  }

  printf("%lld\n", dp[t ^ 1][N]);

  int i = N, j = K + 1;
  while(j > 1) {
    printf("%d ", nxt[j][i] - 1);
    i = nxt[j][i] - 1;
    j--;
  }
  printf("\n");
}
