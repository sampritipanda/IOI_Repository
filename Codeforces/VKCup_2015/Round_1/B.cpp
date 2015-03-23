#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int N; cin >> N;
  int W[N], H[N];

  for(int i = 0; i < N; i++) cin >> W[i] >> H[i];

  int max_height = 0, width_sum = 0;
  for(int i = 0; i < N; i++){
    max_height = max(max_height, H[i]);
    width_sum += W[i];
  }

  int area = max_height * width_sum;
  for(int i = 0; i < N; i++){
    int new_width = width_sum - W[i] + H[i];
    if(new_width <= 0) continue;
    int new_height;
    if(H[i] < max_height) {
      if(W[i] < max_height) new_height = max_height;
      else new_height = W[i];
    }
    else {
      new_height = W[i];
      for(int j = 0; j < N; j++){
        if(i == j) continue;
        new_height = max(new_height, H[j]);
      }
    }

    if((new_height*new_width) < area) {
      area = new_height*new_width;
      max_height = new_height;
      width_sum = new_width;
    }
  }

  cout << area << endl;
}
