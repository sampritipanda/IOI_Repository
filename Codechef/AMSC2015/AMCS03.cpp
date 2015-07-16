// Devu and his Brothers

#include <iostream>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

double S[100010], D[100010];
double L = 0.0 , R = 1e9;
double ans = (1LL << 60LL);
int N; double K;

double f(double t){
    double mn = 1e15;
    double mx = 0.0;
    for(int i = 1 ; i <= N ; ++i){
      double temp = S[i];
      temp *= t;
      temp += D[i];
      mn = min(mn , temp);
      mx = max(mx , temp);
    }
    return mx - mn;
}

int main(){
    cin >> N >> K;
    R = double(K);
    for(int i = 1 ; i <= N ; i++) cin >> S[i] >> D[i];

    for(int i = 1 ; i <= 100 ; i++){
      double mid1 = L+(R-L)/3;
      double mid2 = R-(R-L)/3;
      double x = f(mid1), y = f(mid2);
      ans = min(ans , min(x,y) );
      if(x < y) R = mid2;
      else L = mid1;
    }
    printf("%.6lf\n", ans);
}

