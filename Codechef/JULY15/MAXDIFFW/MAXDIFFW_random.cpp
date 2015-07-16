// Maximum Difference Walk 

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <iterator>
#include <random>

using namespace std;

vector<int> graph[51];
int cost[51][51];

template<typename Iter, typename RandomGenerator>
Iter select_randomly(Iter start, Iter end, RandomGenerator& g) {
  std::uniform_int_distribution<> dis(0, std::distance(start, end) - 1);
  std::advance(start, dis(g));
  return start;
}

template<typename Iter>
Iter select_randomly(Iter start, Iter end) {
  static std::random_device rd;
  static std::mt19937 gen(rd());
  return select_randomly(start, end, gen);
}

int random_number(int start, int end) {
  std::random_device rd;
  std::mt19937 mt(rd());
  std::uniform_int_distribution<int> num(start, end);

  return num(mt);
}

int main() {
  int N; scanf("%d", &N);

  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= N; j++) {
      scanf("%d", &cost[i][j]);
      if(i != j) graph[i].push_back(j);
    }
  }

  int i = random_number(1, N), j;
  do {
    j = random_number(1, N);
  } while(i == j);

  while(true) {
    printf("%d %d\n", i, j);
    fflush(stdout);
    graph[i].erase(find(graph[i].begin(), graph[i].end(), j));

    if(graph[j].size() == 0) break;

    scanf("%d %d", &i, &j);
    graph[i].erase(find(graph[i].begin(), graph[i].end(), j));
    if(graph[j].size() == 0) break;
    i = j;
    j = *select_randomly(graph[j].begin(), graph[j].end());
  }
}
