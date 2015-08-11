// Little Elephant and Subarrays

#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int A[50];
int B[1000001];
int k1[50], k2[50];

int main() {
  int N; cin >> N;
  for(int i = 0; i < N; i++) cin >> A[i];

  for(int i = 0; i <= 1000000; i++) B[i] = 0;

  stack<int> V;
  for(int i = 0; i < N; i++) {
    while(!V.empty() && A[V.top()] > A[i]) {
      V.pop();
    }

    if(V.empty()) k1[i] = 0;
    else k1[i] = 1 + V.top();

    V.push(i);
  }

  while(!V.empty()) V.pop();

  for(int i = N - 1; i >= 0; i--) {
    while(!V.empty() && A[V.top()] >= A[i]) {
      V.pop();
    }

    if(V.empty()) k2[i] = N -1;
    else k2[i] = V.top() - 1;

    V.push(i);
  }

  for(int i = 0; i < N; i++) {
    B[A[i]] += (i - k1[i] + 1) * (k2[i] - i + 1);
  }

  int Q; cin >> Q;

  while(Q--) {
    int a; cin >> a;
    cout << B[a] << endl;
  }
}
