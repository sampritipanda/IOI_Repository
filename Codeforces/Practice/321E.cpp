// Ciel and Gondolas

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int N, K;
int U[4010][4010];
int SUM[4010][4010];
int C[4010][4010];
int DP[4010][4010];

inline int scan(){
    char c = getchar();
    int x = 0;
    while(c<'0'||c>'9'){
            c=getchar();
        }
    while(c>='0'&&c<='9'){
            x=(x<<1)+(x<<3)+c-'0';
            c=getchar();
        }
    return x;
}

void divide_and_conquer(int j, int L, int R, int search_start, int search_end) {
  int mid = (L + R) >> 1;
  DP[mid][j] = 1000000007;

  int best_index = -1;
  for(int i = search_start; i <= min(mid - 1, search_end); i++) {
    int curr = DP[i][j - 1] + C[i + 1][mid];
    if(curr < DP[mid][j]) {
      best_index = i;
      DP[mid][j] = curr;
    }
  }

  if(mid > L) divide_and_conquer(j, L, mid - 1, search_start, best_index);
  if(mid < R) divide_and_conquer(j, mid + 1, R, best_index, search_end);
}

int main(){
  N = scan(); K = scan();

  for(int i = 1 ; i <= N ; i++)
    for(int j = 1 ; j <= N ; j++)
      U[i][j] = scan();

  for(int i = 1 ; i <= N ; i++) 
    for(int j = 1 ; j <= N ; j++)
      SUM[i][j] = SUM[i-1][j] + SUM[i][j-1] - SUM[i-1][j-1] + U[i][j];

  for(int i = 1 ; i <= N ; i++)
    for(int j = 1 ; j <= N ; j++)
      C[i][j] =   ( SUM[j][j] - SUM[i-1][j] - SUM[j][i-1] + SUM[i-1][i-1] ) / 2 ;

  for(int i = 1 ; i <= N ; i++) DP[i][1] = C[1][i]; 
  for(int i = 2 ; i <= K ; i++) divide_and_conquer( i , 1 , N , 1 , N);

  cout << DP[N][K] << endl; 
}
