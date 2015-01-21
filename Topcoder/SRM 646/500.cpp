// The Grid

#include <vector>
#include <string>
#include <iostream>
#include <cmath>
#include <queue>
#include <map>

using namespace std;

class TheGridDivTwo {
  public:
  int find(vector <int> x, vector <int> y, int k){
    int N = x.size();
    int max_distance = 0;
    if(N == 0) return k;
    else {
      bool invalid[2005][2005];
      for(int i = 0; i < N; i++) invalid[x[i] + 1000][y[i] + 1000] = true;
      queue<pair<pair<int, int>, int> > Q;
      Q.push({{0, 0}, k});

      while(!Q.empty()){
        auto curr = Q.front();
        int x = curr.first.first, y = curr.first.second, c = curr.second;
        Q.pop();

        if(invalid[x + 1000][y + 1000]) continue;
        invalid[x + 1000][y + 1000] = true;

        if(x > max_distance) {
          max_distance = x;
        }

        if(c > 0){
          Q.push({{x + 1, y}, c - 1});
          Q.push({{x - 1, y}, c - 1});
          Q.push({{x, y + 1}, c - 1});
          Q.push({{x, y - 1}, c - 1});
        }
      }

      return max_distance;
    }
  }
};

int main() {
  TheGridDivTwo test;
  cout << test.find({1,0,0,-1,-1,-2,-2,-3,-3,-4,-4}, {0,-1,1,-2,2,-3,3,-4,4,-5,5}, 47) << endl;
}
