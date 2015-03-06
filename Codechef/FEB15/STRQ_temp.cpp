// Chef and Strings

#include <stdio.h>
#include <cmath>
#include <cstring>
#include <unordered_map>

using namespace std;

struct node {
  long long char_counts[4] = {0, 0, 0, 0};
  long long char_pairs[4][4] = {{0, 0, 0, 0},{0, 0, 0, 0},{0, 0, 0, 0},{0, 0, 0, 0}};
  int L, R;
};

int positions(char a){
  switch(a) {
    case 'c':
      return 0;
      break;
    case 'h':
      return 1;
      break;
    case 'e':
      return 2;
      break;
    case 'f':
      return 3;
      break;
    default:
      return -1;
  }
}

node mergeNodesQuery(node left, node right, int a, int b){
  node curr;
  curr.char_counts[a] = left.char_counts[a] + right.char_counts[a];
  curr.char_counts[b] = left.char_counts[b] + right.char_counts[b];

  curr.char_pairs[a][b] = left.char_pairs[a][b] + right.char_pairs[a][b] + (left.char_counts[a] * right.char_counts[b]);
  return curr;
}

node mergeNodes(node left, node right){
  node curr;
  curr.char_counts[0] = left.char_counts[0] + right.char_counts[0];
  curr.char_counts[1] = left.char_counts[1] + right.char_counts[1];
  curr.char_counts[2] = left.char_counts[2] + right.char_counts[2];
  curr.char_counts[3] = left.char_counts[3] + right.char_counts[3];

  for(int i = 0; i < 4; i++){
    for(int j = 0; j < 4; j++){
      if(i == j) continue;

      curr.char_pairs[i][j] = left.char_pairs[i][j] + right.char_pairs[i][j] + (left.char_counts[i] * right.char_counts[j]);
    }
  }

  return curr;
}

node query(node* segment_tree, int L, int R, int s, int e, int a, int b, int i){
  if(e < L || s > R) {
    node def;
    return def;
  }
  if(s >= L && e <= R) {
    return segment_tree[i];
  }

  int mid = s + (e - s)/2;
  return mergeNodesQuery(query(segment_tree, L, R, s, mid, a, b, 2*i + 1), query(segment_tree, L, R, mid + 1, e, a, b, 2*i + 2), a, b);
}

node constructSTRecur(char P[], node* segment_tree, int L, int R, int i){
  if(L == R){
    node curr;
    curr.char_counts[positions(P[L])] = 1;
    curr.L = L; curr.R = R;
    segment_tree[i] = curr;
    return segment_tree[i];
  }

  int mid = L + (R - L)/2;
  segment_tree[i] = mergeNodes(constructSTRecur(P, segment_tree, L, mid, 2*i + 1), constructSTRecur(P, segment_tree, mid + 1, R, 2*i + 2));
  segment_tree[i].L = L;
  segment_tree[i].R = R;
  return segment_tree[i];
}

node* constructST(char P[], int N){
  int maxHeight = int(ceil(log2(N)));
  int maxSize = 2*int(pow(2, maxHeight)) - 1;

  node* segment_tree = new node[maxSize];
  constructSTRecur(P, segment_tree, 0, N - 1, 0);

  return segment_tree;
}


int main() {
  char P[1000001]; scanf("%s", P);
  int N = strlen(P);
  node* segment_tree = constructST(P, N);

  int Q; scanf(" %d", &Q);
  while(Q--){
    char a, b;
    int L, R;
    scanf(" %c %c %d %d", &a, &b, &L, &R);
    L--; R--;

    printf("%lld\n", query(segment_tree, L, R, 0, N - 1, positions(a), positions(b), 0).char_pairs[positions(a)][positions(b)]);
  }
}
