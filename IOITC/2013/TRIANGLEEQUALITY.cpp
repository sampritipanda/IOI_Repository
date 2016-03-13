#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

struct point {
  int x, y;
};

const int BIT_MAX = 200000;

vector<point> A;
map<int, int> compres;
map<int, long long> freq;

long long ways_more[100000], ways_less[100000];  // ways_more => greater and after, ways_less => lesser and before
long long ways_more2[100000], ways_less2[100000]; // ways_more2 => greater and before, ways_less2 => lesser and after
long long bit[BIT_MAX + 1];

bool compare(point A, point B) {
  if(A.x == B.x) return A.y < B.y;
  else return A.x < B.x;
}

bool compare2(point A, point B) {
  if(A.x == B.x) return A.y > B.y;
  else return A.x < B.x;
}

long long query(int i) {
  long long ans = 0;
  while(i > 0) {
    ans += bit[i];
    i -= i & -i;
  }
  return ans;
}

void update(int i, int val) {
  while(i <= BIT_MAX) {
    bit[i] += val;
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
  }

  int ind = 0;
  for(auto it: compres) {
    compres[it.first] = ++ind;
  }

  for(int i = 0; i < N; i++) {
    A[i].x = compres[A[i].x];
    A[i].y = compres[A[i].y];
  }

  sort(A.begin(), A.end(), compare);

  for(int i = 0; i <= BIT_MAX; i++) bit[i] = 0;
  for(int i = N - 1; i >= 0; i--) {
    ways_more[i] = query(BIT_MAX) - query(A[i].y - 1);
    update(A[i].y, 1);
  }

  for(int i = 0; i <= BIT_MAX; i++) bit[i] = 0;
  for(int i = 0; i < N; i++) {
    ways_less[i] = query(A[i].y);
    update(A[i].y, 1);
  }

  sort(A.begin(), A.end(), compare2);

  for(int i = 0; i <= BIT_MAX; i++) bit[i] = 0;
  for(int i = 0; i < N; i++) {
    ways_more2[i] = query(BIT_MAX) - query(A[i].y - 1);
    update(A[i].y, 1);
  }

  for(int i = 0; i <= BIT_MAX; i++) bit[i] = 0;
  for(int i = N - 1; i >= 0; i--) {
    ways_less2[i] = query(A[i].y);

    update(A[i].y, 1);
  }

  long long ans = 0;
  for(int i = 0; i < N; i++) {
    ans += ways_more[i] * ways_less[i];
    ans += ways_more2[i] * ways_less2[i];
  }

  for(int i = 0; i < N; i++) freq[A[i].x]++;
  for(auto it: freq) {
    long long cnt = it.second;
    ans -= (cnt * (cnt - 1) * (cnt - 2))/6;
  }
  freq.clear();
  for(int i = 0; i < N; i++) freq[A[i].y]++;
  for(auto it: freq) {
    long long cnt = it.second;
    ans -= (cnt * (cnt - 1) * (cnt - 2))/6;
  }

  cout << ans * 2 << endl;
}
