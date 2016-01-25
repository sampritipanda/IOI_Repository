#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int A[1001];

int main() {
  int N; cin >> N;
  string S; cin >> S;

  A[1] = 1;
  for(int i = 2; i <= N; i++) {
    if(S[i - 2] == 'L') {
      A[i] = 1;
      for(int j = i; j >= 2; j--) {
        if(S[j - 2] == 'L' && A[j] >= A[j - 1]) {
          A[j - 1] += 1;
        }
        else if(S[j - 2] == '=') {
          A[j - 1] = A[j];
        }
        else break;
      }
    }
    else if(S[i - 2] == 'R') {
      A[i] = A[i - 1] + 1;
    }
    else {
      A[i] = A[i - 1];
    }
  }

  for(int i = 1; i <= N; i++) cout << A[i] << " "; cout << endl;
}
