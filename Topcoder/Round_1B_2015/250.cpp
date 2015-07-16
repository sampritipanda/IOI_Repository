#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

class TheNicePair {
  public:
  int solve(vector <int> A) {
    int max_k = -1;
    int N = A.size();
    for(int len = 1; len <= N; len++){
      for(int start = 0; start <= (N - len); start++){
        int max_element = 0;
        for(int i = start; i < (start + len); i++) max_element = max(max_element, A[i]);
        bool flag = false;
        for(int factor = 2; factor <= max_element; factor++){
          int count = 0;
          for(int i = start; i < (start + len); i++) {
            if(A[i] % factor == 0) count++;
          }
          if(count >= len/2.0) {
            flag = true;
            break;
          }
        }
        if(flag) {
          max_k = len - 1;
          break;
        }
      }
    }

    return max_k;
  }
};

int main() {
  TheNicePair test;
  cout << test.solve({5,5,5,5,5}) << endl;
}
