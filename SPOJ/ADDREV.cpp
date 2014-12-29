// Adding Reversed Numbers

#include <stdio.h>
#include <cmath>
#include <stack>

using namespace std;

int main() {
  int N; scanf("%d", &N);

  while(N--){
    int x, y; scanf("%d %d", &x, &y);
    int rev_x = 0, rev_y = 0;

    stack<int> digits_x, digits_y;
    while(x > 0){
      digits_x.push(x % 10);
      x /= 10;
    }
    while(y > 0){
      digits_y.push(y % 10);
      y /= 10;
    }

    int i = 0;
    while(!digits_x.empty()){
      rev_x += pow(10, i) * digits_x.top();
      digits_x.pop();
      i++;
    }
    i = 0;
    while(!digits_y.empty()){
      rev_y += pow(10, i) * digits_y.top();
      digits_y.pop();
      i++;
    }

    int sum = rev_x + rev_y;
    stack<int> digits_sum;
    while(sum > 0){
      digits_sum.push(sum % 10);
      sum /= 10;
    }
    int rev_sum = 0;
    i = 0;
    while(!digits_sum.empty()){
      rev_sum += pow(10, i) * digits_sum.top();
      digits_sum.pop();
      i++;
    }

    printf("%d\n", rev_sum);
  }
}
