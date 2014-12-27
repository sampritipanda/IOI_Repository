// Forgetful Addition

#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

class ForgetfulAddition {
public:
  int minNumber(string);
};

int ForgetfulAddition::minNumber(string expression) {
  int N = expression.length();
  unsigned int min_sum = -1;
  for(int i = 0; i < N - 1; i++){
    int a = std::stoi(std::string(expression, 0, i + 1));
    int b = std::stoi(std::string(expression, i + 1, N - i));
    unsigned int sum = a + b;
    if(sum < min_sum) min_sum = sum;
  }

  return min_sum;
}

int main(){
  string exp; cin >> exp;
  ForgetfulAddition test;
  cout << test.minNumber(exp) << endl;
}
