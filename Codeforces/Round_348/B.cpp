/* Ruby Bruteforce

   def result(n, qu)
     a = (1..n).to_a
     qu.each do |q|
       if q[0] == 1
         a.rotate!(-q[1])
       else
         (0...n).step(2) do |i|
           a[i], a[i + 1] = a[i + 1], a[i]
         end
       end
     end
     a
   end

*/

#include <cstdio>

using namespace std;

int main() {
  int N, Q; scanf("%d %d", &N, &Q);

  int A = 1, B = 2;

  while(Q--) {
    int t; scanf("%d", &t);

    if(t == 1) {
      int x; scanf("%d", &x);
      if(x < 0) x = N + x;

      if(N/2 % 2 == 1) {
        A -= x; B -= x;

        if(A <= 0) A = N + A;
        if(B <= 0) B = N + B;
      }
      else {
        A += x; B += x;

        if(A > N) A -= N;
        if(B > N) B -= N;
      }
    }
    else {
      int T = A;
      A = B;
      B = T;
    }
  }

  for(int i = 1; i <= N; i += 2) {
    printf("%d %d ", A, B);
    A += 2;
    B += 2;

    if(A > N) A -= N;
    if(B > N) B -= N;
  }
  printf("\n");
}
