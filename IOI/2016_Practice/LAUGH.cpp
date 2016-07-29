#include "laugh.h"

#include <algorithm>
#include <string>

using namespace std;

int longest_laugh(const std::string &S) {
  int ans = 0;
  int curr = 0;
  if(S[0] == 'h' || S[0] == 'a') curr++;
  for(int i = 1; i < (int)S.length(); i++) {
    if(S[i] == 'h') {
      if(S[i - 1] == 'a') curr++;
      else curr = 1;
    }
    else if(S[i] == 'a') {
      if(S[i - 1] == 'h') curr++;
      else curr = 1;
    }
    else {
      curr = 0;
    }
    ans = max(ans, curr);
  }
  return ans;
}
