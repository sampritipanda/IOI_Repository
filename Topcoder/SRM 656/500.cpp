// Random Pancake Stack

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

class RandomPancakeStackDiv2 {
  public:
  double expectedDeliciousness(vector <int> d) {
    int N = d.size();
    vector<int> order; for(int i = 0; i < N; i++) order.push_back(i);

    long long totalDeliciousness = 0, numWays = 0;
    do {
      numWays++;
      long long currDelicious = 0;
      int curr_width = -1;
      for(auto it: order){
        if(curr_width == -1) {
          curr_width = it + 1;
        }
        else {
          if((it + 1) > curr_width) break;
          else curr_width = it + 1;
        }
        currDelicious += d[it];
      }
      totalDeliciousness += currDelicious;
    } while(next_permutation(order.begin(), order.end()));
    return double(totalDeliciousness)/double(numWays);
  }
};

