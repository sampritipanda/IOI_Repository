// Cart In Supermarket 

#include <iostream>
#include <vector>
#include <set>

using namespace std;

class CartInSupermarketEasy {
  public:
  int calc(int N, int K) {
    multiset<int> sequences;
    sequences.insert(N);
    int time = 0;
    while(!sequences.empty()){
      if(K == 0){
        for(auto it: sequences) time += it;
        sequences.clear();
      }
      else {
        int top = *sequences.begin();
        if(sequences.size() == 1) {
          sequences.clear();
          sequences.insert(top/2);
          sequences.insert(top - top/2);
        }
        else {
          int top = *sequences.begin();
          vector<int> added, removed;
          for(auto it: sequences){
            if(it == top){
              removed.push_back(top);
              if((top - 1) > 0) added.push_back(top - 1);
            }
          }
          for(auto it = sequences.rbegin(); it != sequences.rend(); it++){
            if(K == 0 || *it == top) break;
            removed.push_back(*it);
            added.push_back((*it)/2);
            added.push_back(*it - (*it)/2);
            K--;
          }
          for(auto it: removed) sequences.erase(sequences.find(it));
          for(auto it: added) sequences.insert(it);
        }
        time++;
      }
    }
    return time;
  }
};

int main() {
  CartInSupermarketEasy test;
  cout << test.calc(5, 2) << endl;
}
