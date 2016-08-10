#include "dna.h"

#include <cstdlib>
#include <cassert>
#include <string>
#include <algorithm>
#include <ctime>

using namespace std;

string analyse(int N, int t) {
  int L = 0, R = N;
  while(L < R) {
    int mid = (L + R + 1)/2;
    string S = "";
    for(int i = 0; i < mid; i++) S += "1";

    if(make_test(S)) L = mid;
    else R = mid - 1;
  }
  int longest_1 = L;

  string ans = "";

  if(longest_1 == 0) {
    for(int i = 0; i < N; i++) ans += "0";
    return ans;
  }

  for(int i = 0; i < longest_1; i++) {
    ans += "1";
  }

  int false_cnt = 0;
  while(false_cnt <= longest_1) {
    if(make_test(ans + "0")) {
      ans += "0";
      false_cnt = 0;
    }
    else {
      ans += "1";
      false_cnt++;
    }
  }

  L = 1, R = ans.size();
  while(L < R) {
    int mid = (L + R + 1)/2;
    if(make_test(ans.substr(0, mid))) {
      L = mid;
    }
    else {
      R = mid - 1;
    }
  }
  ans = ans.substr(0, L);

  while(ans.size() < N) {
    if(make_test("0" + ans)) ans = "0" + ans;
    else ans = "1" + ans;
  }

  return ans;
}
