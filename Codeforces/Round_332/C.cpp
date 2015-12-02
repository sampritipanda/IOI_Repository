#include <iostream>
#include <algorithm>
#include <stack>
#include <map>
#include <cstring>

using namespace std;

int A[100001];
int bit[100001];
map<int, int> compres;

int query(int i) {
  int ans = 0;
  while(i > 0) {
    ans += bit[i];
    i -= i & -i;
  }
  return ans;
}

int update(int i, int v) {
  while(i <= 100000) {
    bit[i] += v;
    i += i & -i;
  }
}

int main() {
  memset(bit, 0, sizeof bit);

  int N; cin >> N;
  for(int i = 1; i <= N; i++) {
    cin >> A[i];
    compres[A[i]] = 0;
  }

  int ind = 0;
  for(auto it: compres) compres[it.first] = ++ind;
  for(int i = 1; i <= N; i++) {
    A[i] = compres[A[i]];
  }

  stack<int> breaks;
  for(int i = N; i >= 1; i--) {
    int curr = query(A[i] - 1);
    if(curr == 0) breaks.push(i);
    else {
      while(!breaks.empty()) {
        if(curr > breaks.top() - i) breaks.pop();
        else break;
      }
    }
    update(A[i], 1);
  }

  cout << breaks.size() << endl;
}
