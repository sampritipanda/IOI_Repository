// Consecutive Integers

#include <vector>
#include <string>
#include <iostream>
#include <cmath>

using namespace std;

class TheConsecutiveIntegersDivTwo {
  public:
  int find(vector <int> numbers, int k){
    int N = numbers.size();
    if(k == 1) return 0;
    else {
      int min_operations = -1;
      for(int i = 0; i < N; i++){
        for(int j = i + 1; j < N; j++){
          int operations = abs(numbers[j] - numbers[i]) - 1;
          if(min_operations == -1 || operations < min_operations) min_operations = operations;
        }
      }
      return min_operations;
    }
  }
};

