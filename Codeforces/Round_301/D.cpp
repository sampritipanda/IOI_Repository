#include <stdio.h>
#include <algorithm>

using namespace std;

double dp[302][102][102];

int main(){
   int r, s, p; scanf("%d %d %d", &r, &s, &p);
   int total = r + s + p;
   double prob_r = 0.0, prob_s = 0.0, prob_p = 0.0;

   dp[0][0][0] = 1;

   for(int i = 0; i <= total; i++){
     for(int j = 0; j <= s; j++){
       for(int k = 0; k <= p; k++){
         int w = s - j;
         int e = p - k;
         int q = r - i + j + k;

         if(q >= 0) {
           if((q + w + e) == q) prob_r += dp[i][j][k];
           if((q + w + e) == w) prob_s += dp[i][j][k];
           if((q + w + e) == e) prob_p += dp[i][j][k];

           double q1 = q * w, w1 = q * e, e1 = w * e;
           double t = q1 + w1 + e1;
           if(t > 0) {
             dp[i + 1][j + 1][k] += dp[i][j][k] * q1/t;
             dp[i + 1][j][k] += dp[i][j][k] * w1/t;
             dp[i + 1][j][k + 1] += dp[i][j][k] * e1/t;
           }
         }
       }
     }
   }

   printf("%.12f %.12f %.12f\n", prob_r, prob_s, prob_p);
}
