// School Marks

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, k, p, x, y; cin >> n >> k >> p >> x >> y;
  vector<int> A;
  int sum = 0;
  for(int i = 0; i < k; i++){
    int a; cin >> a;
    sum += a;
    A.push_back(a);
  }

  bool possible = true;
  for(int i = k; i < n; i++){
    int curr_median;
    if(A.size() == 0) curr_median = 0;
    else {
      vector<int> temp = A; sort(temp.begin(), temp.end());
      curr_median = temp[(temp.size() + 1)/2 - 1];
    }
    if(curr_median < y){
      if(sum > x) {
        possible = false;
        break;
      }
      A.push_back(min(y, p));
      sum += y;
    }
    else {
      A.push_back(1);
      sum += 1;
    }
  }
  vector<int> temp = A; sort(temp.begin(), temp.end());
  int curr_median = temp[(temp.size() + 1)/2 - 1];
  if(curr_median < y || sum > x) possible = false;

  if(possible){
    for(int i = k; i < n; i++) cout << A[i] << " \n"[i == (n - 1)];
  }
  else cout << -1 << endl;
}
