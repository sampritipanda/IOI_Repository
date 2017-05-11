// Kalila and Dimna in the Logging Industry

#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>

using namespace std;

long long dp[100001];
long long A[100010];
long long B[100010];

vector<pair<long long, long long> > lines;
vector<double> inter;

// x = (c2 - c1)/(m1 - m2)
double intersection(pair<long long, long long> A, pair<long long, long long> B) {
  double ans = B.second - A.second;
  ans /= A.first - B.first;
  return ans;
}

// Insert mx + c
void insert(pair<long long, long long> line) {
  while(inter.size() > 0 && intersection(lines.back(), line) <= inter.back()) {
    inter.pop_back();
    lines.pop_back();
  }
  if(!lines.empty()) {
    inter.push_back(intersection(lines.back(), line));
  }
  lines.push_back(line);
}

int inter_ptr = 0;

long long get_min(long long x) {
  inter_ptr = min(inter_ptr, (int)inter.size());
  while(inter_ptr < inter.size() && inter[inter_ptr] < x) inter_ptr++;
  return x * lines[inter_ptr].first + lines[inter_ptr].second;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int N; cin >> N;
  for(int i = 1; i <= N; i++) cin >> A[i];
  for(int i = 1; i <= N; i++) cin >> B[i];

  dp[1] = 0;
  insert({B[1], dp[1]});

  for(int i = 2; i <= N; i++) {
    dp[i] = get_min(A[i]);
    insert({B[i], dp[i]});
  }

  cout << dp[N] << endl;
}
