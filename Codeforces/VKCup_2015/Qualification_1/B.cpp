#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int N; cin >> N;
  long long width[N], height[N];
  long long width_sum = 0;
  long long max_prefix[N], max_suffix[N];

  for(int i = 0; i < N; i++) {
    cin >> width[i] >> height[i];
    width_sum += width[i];
  }

  max_prefix[0] = height[0];
  for(int i = 1; i < N; i++) max_prefix[i] = max(max_prefix[i - 1], height[i]);
  max_suffix[N - 1] = height[N - 1];
  for(int i = N - 2; i >= 0; i--) max_suffix[i] = max(max_suffix[i + 1], height[i]);

  for(int i = 0; i < N; i++){
    long long curr_width = width_sum - width[i];
    long long curr_height = 0;
    if(i > 0) curr_height = max(curr_height, max_prefix[i - 1]);
    if(i < (N - 1)) curr_height = max(curr_height, max_suffix[i + 1]);

    cout << (curr_width * curr_height) << " ";
  }

  cout << endl;
}
