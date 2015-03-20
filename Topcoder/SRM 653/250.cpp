// Country Group

#include <vector>
#include <string>
#include <iostream>

using namespace std;

class CountryGroup {
  public:
  int solve(vector <int> a) {
    for(auto it: a){
      if(it > a.size()) return -1;
    }
    int i = 0; int N = a.size();
    int count = 0;
    while(i < N){
      int curr = a[i];
      int temp = i;
      count++;
      while(i < (temp + curr)){
        if(i >= N || a[i] != curr) return -1;
        i++;
      }
    }
    return count;
  }
};

int main() {
  CountryGroup test;
  cout << test.solve({2,2,3,3,3}) << endl;
}

