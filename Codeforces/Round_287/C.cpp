// Guess Your Way Out!

#include <iostream>

using namespace std;

int main() {
  unsigned long long N, h; cin >> h >> N;
  unsigned long long L = 1, R = 1LL << h;
  unsigned long long count = 0, temp = h;
  char curr_dir = 'L', curr_height = 0;

  while(curr_height < h){
    unsigned long long mid = (L + R) >> 1LL;
    if(N <= mid) {
      R = mid;
      if(curr_dir == 'L'){
        curr_dir = 'R';
        count++;
      }
      else {
        count += 1LL << temp;
      }
    }
    else {
      L = mid;
      if(curr_dir == 'R'){
        curr_dir = 'L';
        count++;
      }
      else {
        count += 1LL << temp;
      }
    }

    curr_height++;
    temp--;
  }

  cout << count << endl;
}
