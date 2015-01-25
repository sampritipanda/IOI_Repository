// Peaceful Line

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

class PeacefulLine {
  public:
  string makeLine(vector <int> x) {
    int count[30] = {0};
    int max = (x.size() + 1)/2;
    for(auto it: x){
      count[it]++;
    }
    for(int i = 0; i < 30; i++){
      if(count[i] > max) return "impossible";
    }
    return "possible";
  }
};

int main() {
  PeacefulLine test;
  cout << test.makeLine({1,2,3,4}) << endl;
}
