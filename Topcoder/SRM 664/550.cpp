#include <string>
#include <iostream>
#include <algorithm>
#include <tuple>
#include <set>

using namespace std;

set<tuple<int, int, int> > visited;

bool solve(int A, int B, int C) {
  if(A <= 0 || B <= 0 || C <= 0) return false;
  if(A > 500 || B > 500 || C > 500) return false;

  if(A == B && B == C) return true;

  if(visited.count(make_tuple(A, B, C)) > 0) return false;
  visited.insert(make_tuple(A, B, C));

  if(A != B) {
    if(A > B) {
      if(solve(A - B, B + B, C)) return true;
    }
    else {
      if(solve(A + A, B - A, C)) return true;
    }
  }
  if(A != C) {
    if(A > C) {
      if(solve(A - C, B, C + C)) return true;
    }
    else {
      if(solve(A + A, B, C - A)) return true;
    }
  }
  if(B != C) {
    if(B > C) {
      if(solve(A, B - C, C + C)) return true;
    }
    else {
      if(solve(A, B + B, C - B)) return true;
    }
  }

  return false;
}

class BearPlaysDiv2 {
  public:
  string equalPiles(int A, int B, int C) {
    visited.clear();

    if(solve(A, B, C)) return "possible";
    else return "impossible";
  }
};

