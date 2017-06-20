#include <iostream>
#include <algorithm>
#include <map>
#include <cassert>

using namespace std;

long long N;
map<pair<long long, long long>, bool> memo;

bool test(long long x, long long y) {
  if(memo.find({x, y}) != memo.end()) return memo[{x, y}];

  if(x < 1 || x > N) return false;
  if(y < 1 || y > N) return false;

  cout << "examine " << x << " " << y << endl;
  string ans; cin >> ans;

  return memo[{x, y}] = (ans == "true");
}

int main() {
  long long X_0, Y_0; cin >> N >> X_0 >> Y_0;

  long long L = X_0;
  long long d = 1;
  while(test(L + d, Y_0)) {
    d *= 2;
  }
  long long R = L + d;
  while(L < R) {
    long long mid = (L + R + 1)/2;
    if(test(mid, Y_0)) {
      L = mid;
    }
    else {
      R = mid - 1;
    }
  }
  long long cell_x_r = R;

  R = X_0;
  d = 1;
  while(test(R - d, Y_0)) {
    d *= 2;
  }
  L = R - d;
  while(L < R) {
    long long mid = (L + R)/2;
    if(test(mid, Y_0)) {
      R = mid;
    }
    else {
      L = mid + 1;
    }
  }
  long long cell_x_l = L;
  long long M = cell_x_r - cell_x_l + 1;

  long long red_cnt = 1 + test(cell_x_l - 2 * M, Y_0) + test(cell_x_l - 4 * M, Y_0)
                  + test(cell_x_l + 2 * M, Y_0) + test(cell_x_l + 4 * M, Y_0);
  long long X_cent;
  if(red_cnt == 3) {
    if(test(cell_x_l - 4 * M, Y_0)) { // right cell
      X_cent = cell_x_l - 2 * M + M/2;
    }
    else if(test(cell_x_l + 4 * M, Y_0)) {  // left cell
      X_cent = cell_x_l + 2 * M + M/2;
    }
    else {  // middle cell
      X_cent = cell_x_l + M/2;
    }
  }
  else {
    if(test(cell_x_l - 2 * M, Y_0)) {  // right cell
      X_cent = cell_x_l - M + M/2;
    }
    else { // left cell
      X_cent = cell_x_l + M + M/2;
    }
  }

  L = Y_0;
  d = 1;
  while(test(X_0, L + d)) {
    d *= 2;
  }
  R = L + d;
  while(L < R) {
    long long mid = (L + R + 1)/2;
    if(test(X_0, mid)) {
      L = mid;
    }
    else {
      R = mid - 1;
    }
  }
  long long cell_y_r = R;

  R = Y_0;
  d = 1;
  while(test(X_0, R - d)) {
    d *= 2;
  }
  L = R - d;
  while(L < R) {
    long long mid = (L + R)/2;
    if(test(X_0, mid)) {
      R = mid;
    }
    else {
      L = mid + 1;
    }
  }
  long long cell_y_l = L;
  assert(cell_y_r - cell_y_l + 1 == M);

  red_cnt = 1 + test(X_0, cell_y_l - 2 * M) + test(X_0, cell_y_l - 4 * M)
              + test(X_0, cell_y_l + 2 * M) + test(X_0, cell_y_l + 4 * M);
  long long Y_cent;
  if(red_cnt == 3) {
    if(test(X_0, cell_y_l - 4 * M)) {  // right cell
      Y_cent = cell_y_l - 2 * M + M/2;
    }
    else if(test(X_0, cell_y_l + 4 * M)) { // left cell
      Y_cent = cell_y_l + 2 * M + M/2;
    }
    else {  // middle cell
      Y_cent = cell_y_l + M/2;
    }
  }
  else {
    if(test(X_0, cell_y_l - 2 * M)) {  // right cell
      Y_cent = cell_y_l - M + M/2;
    }
    else { // left cell
      Y_cent = cell_y_l + M + M/2;
    }
  }

  // cout << cell_x_l << " " << cell_x_r << endl;
  // cout << cell_y_l << " " << cell_y_r << endl;
  cout << "solution " << X_cent << " " << Y_cent << endl;
}
