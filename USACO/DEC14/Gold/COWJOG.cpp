// Cow Jog

#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

long long X[100000];
long long E[100000];

int main() {
  freopen("cowjog.in", "r", stdin);
  freopen("cowjog.out", "w", stdout);

  int N; cin >> N;
  long long T; cin >> T;
  for(int i = 0; i < N; i++) {
    long long x, s; cin >> x >> s;
    X[i] = x;
    E[i] = X[i] + s * T;
  }

  vector<long long> A;
  for(int i = 0; i < N; i++) {
    if(A.empty() || E[i] <= A.back()) A.push_back(E[i]);
    else {
      auto it = lower_bound(A.rbegin(), A.rend(), E[i]);
      *(it - 1) = E[i];
    }
  }

  cout << A.size() << endl;

  fclose(stdin);
  fclose(stdout);
}
