#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

struct edge {
  int x, y;
  long long q, l;
};

bool compare(edge A, edge B) {
  return A.q > B.q;
}

bool compare2(edge A, edge B) {
  return A.l < B.l;
}

vector<edge> E, E2;
int A[5000];

int find(int i) {
  if(A[i] == i) return i;
  else return A[i] = find(A[i]);
}

void merge(int a, int b) {
  a = find(a), b = find(b);

  if(a != b) {
    A[a] = b;
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int N, M; cin >> N >> M;

  for(int i = 0; i < N; i++) A[i] = i;

  E.resize(M);

  for(int i = 0; i < M; i++) {
    cin >> E[i].x >> E[i].y >> E[i].q >> E[i].l;
  }

  sort(E.begin(), E.end(), compare);

  long long qual = LLONG_MAX;
  for(int i = 0; i < M; i++) {
    int x = E[i].x, y = E[i].y;

    if(find(x) != find(y)) {
      qual = min(qual, E[i].q);

      merge(x, y);
    }
  }

  bool pos = true;
  for(int i = 1; i < N; i++) {
    if(find(0) != find(i)) {
      pos = false; break;
    }
  }

  if(pos) {
    for(auto it: E) {
      if(it.q >= qual) E2.push_back(it);
    }

    sort(E2.begin(), E2.end(), compare2);

    for(int i = 0; i < N; i++) A[i] = i;

    long long sum = 0;
    for(auto e: E2) {
      if(find(e.x) != find(e.y)) {
        sum += e.l;

        merge(e.x, e.y);
      }
    }

    cout << qual << " " << sum << endl;
  }
  else cout << -1 << endl;
}
