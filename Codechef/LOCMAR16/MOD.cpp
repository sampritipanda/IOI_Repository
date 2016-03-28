#include <stdio.h>
#include <set>

using namespace std;

set<int> A;

int main() {
  int N; scanf("%d", &N);

  while(N--) {
    int x; scanf("%d", &x);
    A.insert(x);
  }

  int first = 0, second = 0;

  if(A.size() > 0) {
    first = *A.rbegin();
    A.erase(*A.rbegin());
  }

  if(A.size() > 0) {
    second = *A.rbegin();
    A.erase(*A.rbegin());
  }
  else {
    second = first;
  }

  printf("%d\n", second % first);
}
