// Sereja and Random Array 

#include <iostream>
#include <string>

using namespace std;

/* ------------------ start here ---------------------*/
unsigned X; // we assume that unsigned is a 32bit integer type

void srand1(unsigned S){
  X = S;
}

unsigned nextInteger1(void){
  X = X * 1103515245 + 12345;
  return (X / 65536) % 32768;
}

void generator1(int N, unsigned S, int A[]){
  srand1(S);
  for(int i=1;i<=N;i++){
    A[i] = nextInteger1() % 2; 
  }
}
/* ------------------ end here -----------------------*/

int main () {
  int T; cin >> T;

  while(T--){
    string seq; cin >> seq;
    int N = seq.length();
    int orig[N + 1], A[N + 1];
    for(int i = 1; i <= N; i++) orig[i] = seq[i - 1] - '0';
    bool flag = false;
    for(int s = 0; s <= 200000; s++){
      generator1(min(N, 50), s, A);
      bool flag2 = true;
      for(int i = 1; i <= min(N, 50); i++){
        if(orig[i] != A[i]) {
          flag2 = false;
          break;
        }
      }
      if(flag2) {
        flag = true;
        break;
      }
    }

    if(flag) cout << "LCG" << endl;
    else cout << "Xorshift" << endl;
  }
}
