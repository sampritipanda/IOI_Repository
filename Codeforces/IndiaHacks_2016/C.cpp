#include <iostream>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

int A[150002];
vector<int> T;
set<pair<int, int> > fix;
int N;

bool check2(int i) {
  if(i < 0 || i > N) return true;
  if(i == 0) i++;
  if(i == N) i--;

  if(i % 2 == 0) {
    if(A[i] <= A[i + 1]) return false;
  }
  else {
    if(A[i] >= A[i + 1]) return false;
  }

  return true;
}

bool check(int i) {
  return check2(i) && check2(i - 1) && check2(i + 1);
}

void add(int a, int b) {
  if(a > b) swap(a, b);
  fix.insert({a, b});
}

int main() {
  int M = 150000;
  ios::sync_with_stdio(false); cin.tie(0);

  cin >> N;
  for(int i = 1; i <= N; i++) cin >> A[i];

  for(int i = 1; i < N; i++) {
    if(!check2(i)) {
      T.push_back(i);
      i++;
    }
  }

  if(T.size() == 1) {
    int x = T[0];
    for(int i = 1; i <= N; i++) {
      if(i == x) continue;

      swap(A[i], A[x]);
      if(check(i) && check(x)) add(i, x);
      swap(A[i], A[x]);
    }

    x = T[0] + 1;
    for(int i = 1; i <= N; i++) {
      if(i == x) continue;

      swap(A[i], A[x]);
      if(check(i) && check(x)) add(i, x);
      swap(A[i], A[x]);
    }

    cout << fix.size() << endl;
  }
  else if(T.size() == 2) {
    int x = T[0];
    for(int i = 1; i <= N; i++) {
      if(i == x) continue;

      swap(A[i], A[x]);
      if(check(i) && check(x) && check(T[1])) add(i, x);
      swap(A[i], A[x]);
    }

    x = T[0] + 1;
    for(int i = 1; i <= N; i++) {
      if(i == x) continue;

      swap(A[i], A[x]);
      if(check(i) && check(x) && check(T[1])) add(i, x);
      swap(A[i], A[x]);
    }

    x = T[1];
    for(int i = 1; i <= N; i++) {
      if(i == x) continue;

      swap(A[i], A[x]);
      if(check(i) && check(x) && check(T[0])) add(i, x);
      swap(A[i], A[x]);
    }

    x = T[1] + 1;
    for(int i = 1; i <= N; i++) {
      if(i == x) continue;

      swap(A[i], A[x]);
      if(check(i) && check(x) && check(T[0])) add(i, x);
      swap(A[i], A[x]);
    }

    cout << fix.size() << endl;
  }
  else {
    cout << 0 << endl;
  }

  // for(auto it: fix) cout << it.first << " " << it.second << endl;
}
