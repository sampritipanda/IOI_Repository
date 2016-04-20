#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
  if(b == 0) return a;
  return gcd(b, a % b);
}

vector<long long> A;

int main() {
  int N; cin >> N;

  int prev; cin >> prev;
  A.push_back(prev);

  for(int i = 2; i <= N; i++) {
    int curr; cin >> curr;

    if(gcd(curr, prev) == 1) {
      A.push_back(curr);
      prev = curr;
    }
    else {
      A.push_back(1);
      A.push_back(curr);
      prev = curr;
    }
  }

  cout << A.size() - N << endl;
  for(auto it: A) cout << it << " ";
  cout << endl;
}
