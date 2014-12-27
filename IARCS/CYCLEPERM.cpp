// Cycles in Permutations

#include <stdio.h>
#include <stdlib.h>
#include <set>
#include <string>
#include <sstream>

#define SSTR( x ) dynamic_cast< std::ostringstream & >( \
            ( std::ostringstream() << std::dec << x ) ).str()

int main(){
  int N; scanf("%d", &N);
  std::set<int> unvisited;
  int nums[N+1];
  std::string result = "";

  for(int i = 1; i <= N; i++){
    scanf("%d", &nums[i]);
    unvisited.insert(nums[i]);
  }

  int current = 1;
  int cycles = 0;
  while(unvisited.size() > 0){
    while(true){
      result += SSTR(current);
      result += " ";
      if(unvisited.find(current) == unvisited.end()) break;
      unvisited.erase(current);
      current = nums[current];
    }
    result += "\n";
    current = *unvisited.begin();
    cycles++;
  }
  printf("%d\n", cycles);
  printf("%s", result.c_str());
}
