#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class CliqueParty {
  public:
  int maxsize(vector <int> A, int k) {
    int N = A.size();
    sort(A.begin(), A.end());

    int ans = 0;
    for(int i = 0; i < N; i++) {
      for(int j = i; j < N; j++) {
        vector<int> curr;
        for(int k = i; k <= j; k++) {
          for(int l = i; l <= j; l++) {
            if(k == l) continue;
            curr.push_back(abs(A[k] - A[l]));
          }
        }
        if(curr.empty()) continue;
        int min_el = *min_element(curr.begin(), curr.end());
        int max_el = *max_element(curr.begin(), curr.end());

        if(max_el <= min_el * k) ans = max(ans, j - i + 1);
      }
    }

    return ans;
  }
};

int main() {
  CliqueParty test;
  cout << test.maxsize({1,2,3}, 2) << endl;
}
