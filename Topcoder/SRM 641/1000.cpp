// Shuffling Cards

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class ShufflingCardsDiv2 {
    public:
    string shuffle(vector <int> permutation) {
      int size = permutation.size();
      int N = size/2;
      vector<int> left, right;

      int num_less_left = 0, num_less_right = 0, num_more_left = 0, num_more_right = 0;
      for(int i = 0; i < size; i++){
        if(i % 2 == 0) {
          if(permutation[i] >= 1 && permutation[i] <= N) num_less_left++;
          else num_more_left++;
        }
        else {
          if(permutation[i] >= N + 1 && permutation[i] <= size) num_more_right++;
          else num_less_right++;
        }
      }

      if(N % 2 == 0){
        if(num_less_left == num_more_left && num_less_right == num_more_right) {
          return "Possible";
        }
        else {
          return "Impossible";
        }
      }
      else {
        if(num_less_left == (N/2 + 1) && num_more_left == (N/2) && num_less_right == (N/2) && num_more_right == (N/2 + 1)) {
          return "Possible";
        }
        else {
          return "Impossible";
        }
      }
    }
};

int main() {
  ShufflingCardsDiv2 test;
  int size_arr[] = {8,5,4,9,1,7,6,10,3,2};
  std::vector<int> size (size_arr, size_arr + sizeof(size_arr) / sizeof(int) );

  cout << test.shuffle(size) << endl;
}
