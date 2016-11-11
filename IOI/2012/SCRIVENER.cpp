#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

struct node {
  char c;
  int p; // length of string at this node
  node* ancestor[20];

  node() {
    c = '-';
    p = 0;
    for(int i = 0; i < 20; i++) ancestor[i] = NULL;
  }
};

node* A[1500001];

int main() {
  int Q; scanf("%d", &Q);

  A[0] = new node;

  int i = 0;
  while(Q--) {
    char t; scanf(" %c", &t);

    if(t == 'T') {
      ++i;
      char x; scanf(" %c", &x);
      A[i] = new node;
      A[i]->c = x;
      A[i]->p = A[i - 1]->p + 1;
      A[i]->ancestor[0] = A[i - 1];
      for(int j = 1; j < 20; j++) {
        if(A[i]->ancestor[j - 1] != NULL) {
          A[i]->ancestor[j] = A[i]->ancestor[j - 1]->ancestor[j - 1];
        }
      }
    }
    else if(t == 'U') {
      ++i;
      int p; scanf(" %d", &p);
      A[i] = A[i - p - 1];
    }
    else {
      int p; scanf(" %d", &p); p++;
      int lift = A[i]->p - p;
      node* curr = A[i];
      for(int j = 19; j >= 0; j--) {
        if(lift & (1 << j)) {
          curr = curr->ancestor[j];
        }
      }
      printf("%c\n", curr->c);
    }
  }
}
