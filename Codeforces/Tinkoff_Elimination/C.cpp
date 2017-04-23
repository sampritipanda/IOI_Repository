#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int R_X[100001];
int R_Y[100001];
int V_X[100001];
int V_Y[100001];
double T_S[100001], T_E[100001];

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int N; cin >> N;
  int X1, Y1, X2, Y2; cin >> X1 >> Y1 >> X2 >> Y2;
  for(int i = 1; i <= N; i++) cin >> R_X[i] >> R_Y[i] >> V_X[i] >> V_Y[i];

  bool pos = true;
  for(int i = 1; i <= N; i++) {
    if(R_X[i] > X2 && V_X[i] >= 0) pos = false;
    if(R_X[i] < X1 && V_X[i] <= 0) pos = false;
    if(R_Y[i] > Y2 && V_Y[i] >= 0) pos = false;
    if(R_Y[i] < Y1 && V_Y[i] <= 0) pos = false;
    if((R_X[i] == X1 || R_X[i] == X2) && V_Y[i] == 0) pos = false;
    if((R_Y[i] == Y1 || R_Y[i] == Y2) && V_X[i] == 0) pos = false;
    if(!pos) break;
  }
}
