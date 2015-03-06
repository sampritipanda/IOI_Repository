// Cart In Supermarket

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class CartInSupermarketEasy {
  public:
  int calc(int N, int K) {
    multiset<int> sequences;
    sequences.insert(N);
    int time = 0;
    while(true){
      time++;
      vector<int> old_list;
      multiset<int> new_list;
      for(auto it: sequences) old_list.push_back(it);
      reverse(old_list.begin(), old_list.end());

      for(auto it: old_list){
        if(it <= 1) continue;
        if((K--) > 0){
          int a = it/2;
          int b = it - a;
          new_list.insert(a);
          new_list.insert(b);
        }
        else {
          new_list.insert(it - 1);
        }
      }
      if(new_list.size() == 0) break;
      sequences = new_list;
    }
    return time;
  }
};

int main() {
  CartInSupermarketEasy test;
  int a, b; cin >> a >> b;
  cout << test.calc(a, b) << endl;
}
