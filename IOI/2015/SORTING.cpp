#include <iostream>
#include <cassert>
#include <algorithm>
#include <vector>

using namespace std;

int A[200000];
int S[200000];
int pos[200000];
int X[600000], Y[600000];
int P[600000], Q[600000];
vector<pair<int, int> > temp;
int N, M;

bool check(int T) {
  for(int i = 0; i < N; i++) {
    A[i] = S[i];
  }
  for(int i = 0; i < T; i++) swap(A[X[i]], A[Y[i]]);
  for(int i = 0; i < N; i++) pos[A[i]] = i;

  temp.clear();
  for(int i = 0; i < N; i++) {
    if(pos[i] == i) continue;
    int x = pos[i], y = i;
    swap(pos[i], pos[A[i]]);
    temp.push_back({i, A[i]});
    swap(A[x], A[y]);
  }
  while(temp.size() < T) temp.push_back({0, 0});
  if(temp.size() > T) return false;

  for(int i = 0; i < N; i++) A[i] = S[i];
  for(int i = 0; i < N; i++) pos[A[i]] = i;

  for(int i = 0; i < T; i++) {
    swap(pos[A[X[i]]], pos[A[Y[i]]]);
    swap(A[X[i]], A[Y[i]]);

    int x = temp[i].first, y = temp[i].second;
    P[i] = pos[x], Q[i] = pos[y];
    swap(A[pos[x]], A[pos[y]]);
    swap(pos[x], pos[y]);
  }

  return true;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  cin >> N;
  for(int i = 0; i < N; i++) cin >> S[i];

  cin >> M;
  for(int i = 0; i < M; i++) cin >> X[i] >> Y[i];

  int L = 0, R = M;
  while(L < R) {
    int mid = (L + R)/2;
    if(check(mid)) {
      R = mid;
    }
    else {
      L = mid + 1;
    }
  }
  assert(check(L));

  cout << L << endl;
  for(int i = 0; i < L; i++) cout << P[i] << " " << Q[i] << endl;
}
