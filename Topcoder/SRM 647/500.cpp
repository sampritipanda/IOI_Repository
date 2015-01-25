// Travelling Salesman

#include <vector>
#include <set>
#include <algorithm>
#include <iostream>

using namespace std;

class TravellingSalesmanEasy {
  public:
  int getMaxProfit(int M, vector <int> profit, vector <int> city, vector <int> visit){
    vector<multiset<int> > items(M + 1);
    int N = profit.size();
    for(int i = 0; i < N; i++){
      items[city[i]].insert(profit[i]);
    }
    int max_profit = 0;
    for(auto it: visit){
      if(!items[it].empty()){
        max_profit += *items[it].rbegin();
        items[it].erase(std::prev(items[it].end()));
      }
    }

    return max_profit;
  }
};

