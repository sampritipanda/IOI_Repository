// Drazil and Factorial

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main () {
  int n; cin >> n;
  string a; cin >> a;

  vector<int> candidates;
  for(auto c: a){
    int digit = c - '0';
    if(digit == 9){
      candidates.push_back(7);
      candidates.push_back(3);
      candidates.push_back(3);
      candidates.push_back(2);
    }
    else if(digit == 8){
      candidates.push_back(2);
      candidates.push_back(2);
      candidates.push_back(2);
      candidates.push_back(7);
    }
    else if(digit == 6){
      candidates.push_back(3);
      candidates.push_back(5);
    }
    else if(digit == 4){
      candidates.push_back(2);
      candidates.push_back(2);
      candidates.push_back(3);
    }
    else if(digit > 1){
      candidates.push_back(digit);
    }
  }

  sort(candidates.begin(), candidates.end(), greater<int>());
  for(auto x: candidates) cout << x;
  cout << endl;
}
