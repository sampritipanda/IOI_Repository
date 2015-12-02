#include <iostream>
#include <algorithm>

using namespace std;

long long B[200001];

int main() {
  int N; cin >> N;

  for(int i = 1; i <= N; i++) cin >> B[i];
  long long steps = 0, curr_val = 0;

  for(int i = 1; i <= N; i++) {
    steps += abs(B[i] - curr_val);
    curr_val += B[i] - curr_val;
  }

  cout << steps << endl;
}
