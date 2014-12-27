// Chef and Apple Trees

#include <stdio.h>
#include <set>

int main() {
  int T; scanf("%d", &T);
  int N;
  std::set<int> trees;

  while(T--){
    scanf("%d", &N);
    while(N--){
      int tree; scanf("%d", &tree);
      trees.insert(tree);
    }
    printf("%lu\n", trees.size());
    trees.clear();
  }
}
