#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
  priority_queue<long long> A;
  int N; cin >> N;

  for(int i = 1; i <= N; i++) {
    int x; cin >> x;
    A.push(x);
  }

  long long X = A.top(); A.pop();
  long long Y = 0, Z = 0;

  int type = 1;
  while(!A.empty()) {
    if(type == 1) {
      Y += A.top();
    }
    else {
      Z += A.top();
    }
    A.pop();
    type == (type == 1 ? 2 : 1);
  }

  cout << (X - (Y + Z)) + 1 << endl;
}
