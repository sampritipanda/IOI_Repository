#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

struct node {
  int x, y, i;
};

vector<node> A;
int ans[200001];
int bit[500001];
map<int, int> compres;

bool compare(node A, node B) {
  return A.y < B.y;
}

int query(int i) {
  int ans = 0;
  while(i > 0) {
    ans += bit[i];
    i -= i & -i;
  }
  return ans;
}

void update(int i, int x) {
  while(i <= 500000) {
    bit[i] += x;
    i += i & -i;
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int N; cin >> N;
  A.resize(N);

  for(int i = 0; i < N; i++) {
    cin >> A[i].x >> A[i].y;
    compres[A[i].x] = 0;
    compres[A[i].y] = 0;
    A[i].i = i;
  }

  int ind = 0;
  for(auto it: compres) compres[it.first] = ++ind;
  for(int i = 0; i < N; i++) {
    A[i].x = compres[A[i].x];
    A[i].y = compres[A[i].y];
  }
  sort(A.begin(), A.end(), compare);

  for(int i = 0; i < N; i++) {
    int ind = A[i].i;
    ans[ind] = query(500000) - query(A[i].x);
    update(A[i].x, 1);
  }

  for(int i = 0; i < N; i++) {
    cout << ans[i] << endl;
  }
}
