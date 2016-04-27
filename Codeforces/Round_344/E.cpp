#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

long long A[200001];
long long P[200001];
vector<pair<int, int> > S;

// value change when moving element from i to j
inline long long change(int i, int j) {
  if(i <= j) {
    return -(P[j] - P[i]) + A[i] * (j - i);
  }
  else {
    return (P[i - 1] - P[j - 1]) - A[i] * (i - j);
  }
}

long long divide_and_conquer(int start_id, int L, int R, int search_start, int search_end) {
  if(R < L) return 0;
  int mid = (L + R)/2;

  long long ans = LLONG_MIN/2;
  int opt = -1;
  for(int i = search_start; i <= search_end; i++) {
    long long curr = change(S[mid - start_id].second, i);
    if(curr > ans) {
      ans = curr;
      opt = i;
    }
  }

  long long left = divide_and_conquer(start_id, L, mid - 1, search_start, opt);
  long long right = divide_and_conquer(start_id, mid + 1, R, opt, search_end);

  return max(ans, max(left, right));
}

long long solve(int L, int R) {
  if(L == R) return 0;

  int mid = (L + R)/2;

  long long left = solve(L, mid);
  for(int i = L; i <= mid; i++) S.push_back({A[i], i});
  sort(S.begin(), S.end());
  long long cross_left_to_right = divide_and_conquer(L, L, mid, mid + 1, R);
  S.clear();

  long long right = solve(mid + 1, R);
  for(int i = mid + 1; i <= R; i++) S.push_back({A[i], i});
  sort(S.begin(), S.end());
  long long cross_right_to_left = divide_and_conquer(mid + 1, mid + 1, R, L, mid);
  S.clear();

  return max(max(left, right), max(cross_left_to_right, cross_right_to_left));
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int N; cin >> N;
  for(int i = 1; i <= N; i++) cin >> A[i];
  for(int i = 1; i <= N; i++) P[i] = P[i - 1] + A[i];

  long long ans = 0;
  for(int i = 1; i <= N; i++) ans += A[i] * i;
  cout << ans + solve(1, N) << endl;
}
