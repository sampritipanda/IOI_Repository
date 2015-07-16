// Om Nom and Candies

#include <iostream>
#include <cmath>
#include <random>

using namespace std;

int main() {
  int C, H_r, H_b, W_r, W_b; cin >> C >> H_r >> H_b >> W_r >> W_b;
  double red_ratio = H_r/double(W_r);
  double blue_ratio = H_b/double(W_b);
  double sum_ratio = red_ratio + blue_ratio;
  long long red = (long long)(floor(red_ratio/sum_ratio * C));
  long long blue = (long long)(floor(blue_ratio/sum_ratio * C));
  if(red + blue < C){
    if(red_ratio > blue_ratio) red += C - (red + blue);
    else blue += C - (red + blue);
  }
  red /= W_r;
  blue /= W_b;
  long long remain = C - (red * W_r + blue * W_b);
  long long ans_ratio = red * ((long long)H_r);
  ans_ratio += blue * ((long long)H_b);
  if(remain > 0){
    long long one = remain/W_r * H_r + ((remain % W_r)/W_b * H_b);
    long long two = remain/W_b * H_b + ((remain % W_b)/W_r * H_r);
    ans_ratio += max(one, two);
  }

  long long ans_red = C/W_r * H_r + (C - (C/W_r * W_r))/W_b * H_b;
  long long ans_blue = C/W_b * H_b + (C - (C/W_b * W_b))/W_r * H_r;

  random_device rd;
  mt19937 mt(rd());
  uniform_int_distribution<int> num(1, max(C/W_r, C/W_b));
  long long ans_rand = 0;
  for(int i = 0; i <= 10000000; i++){
    long long r = num(mt);
    if((r * W_r) > C) continue;
    long long b = (C - (r * W_r))/W_b;
    if((b * W_b + r * W_r) > C) continue;
    ans_rand = max(ans_rand, r * H_r + b * H_b);
    if((r * H_r + b * H_b) == 1218){
    }
  }

  long long ans = max(max(ans_rand, ans_ratio), max(ans_red, ans_blue));
  cout << ans << endl;
}
