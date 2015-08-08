#include <string>
#include <iostream>

using namespace std;

class BearCheats {
  public:
  string eyesight(int A, int B) {
    int diff = 0;
    string A_s = to_string(A), B_s = to_string(B);

    int N = A_s.length();
    for(int i = 0; i < N; i++) {
      if(A_s[i] != B_s[i]) diff++;
    }

    if(diff <= 1) return "happy";
    else return "glasses";
  }
};

