// Building Towers

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class BuildingTowers {
  public:
  long long maxHeight(long long N, int K, vector <int> x, vector <int> t){
    int count = x.size();
    if(count == 0){
      return (N - 1) * K;
    }
    else {
      int i = 1;
      long long size = 0;
      long long max_size = 0;
      int j = 0;

      while(j < count){
        if(i == x[j]){
          j++;
          if(j == count) break;
        }
        if(size <= t[j]){
          if(i + 1 == x[j]){
            if((size + K) > t[j]) size = t[j];
            else size += K;
          }
          else {
            if((size + K <= t[j]) && ((size + K - t[j])/K <= (x[j] - i - 1))) size += K;
            else size = t[j];
          }
        }
        else {
          if((size + K - t[j])/K <= (x[j] - i - 1)) size += K;
          else {
            if(size - K > t[j]) size -= K;
            else size = t[j];
          }
        }

        i++;
        if(size > max_size) max_size = size;
        cout << size << endl;
      }

      size += (N - i) * K;
      if(size > max_size) max_size = size;
      return max_size;
    }
  }
};

int main() {
  BuildingTowers test;
  vector<int> first = {3};
  vector<int> second = {1};
  cout << test.maxHeight(3, 1000, first, second) << endl;
}
