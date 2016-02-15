#include <iostream>
#include <vector>

using namespace std;

vector<int> A;

int main() {
  int N; cin >> N;

  for(int i = 1; i <= N; i++) {
    A.push_back(1);
    while(A.size() >= 2 && A[A.size() - 1] == A[A.size() - 2]) {
      int x = A.back();
      A.pop_back();
      A.pop_back();
      A.push_back(x + 1);
    }
  }

  for(auto it: A) cout << it << " "; cout << endl;
}
