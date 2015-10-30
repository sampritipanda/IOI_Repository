// What is the Rank?

#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> A, B;
map<int, int> M;
int bit[50001];

int query(int a) {
  int ans = 0;
  while(a > 0) {
    ans += bit[a];
    a -= a & -a;
  }
  return ans;
}

void update(int i) {
  while(i <= 50000) {
    bit[i] += 1;
    i += i & -i;
  }
}

int main(){
  int N; cin >> N;

  for(int i = 0; i < N; i++) {
    int x; cin >> x;
    A.push_back(x);
  }
  B = A;
  sort(B.begin(), B.end());

  for(int i = 0; i < N; i++) {
    M[B[i]] = i + 1;
  }

  for(int i = 0; i <= 50000; i++) bit[i] = 0;

  for(int i = 0; i < N; i++) {
    int ind = M[A[i]];
    cout << (i + 1) - (query(ind - 1) + 1) + 1 << endl;
    update(ind);
  }
}
