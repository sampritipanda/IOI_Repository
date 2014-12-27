// Vanya and Exams

#include <stdio.h>
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

int main(){
  long long N, R, avg;
  std::cin >> N >> R >> avg;

  long long toScore = N * avg;
  long long currScore = 0;
  std::vector<std::pair<long long, long long> > exams;

  for(int i = 0; i < N; i++){
    int x, y;
    scanf("%d %d", &x, &y);
    currScore += x;
    exams.push_back(std::make_pair(y, R - x));
  }
  long long rem = toScore - currScore;

  if(rem <= 0) printf("0\n");
  else {
    std::sort(exams.begin(), exams.end());

    long long numEssays = 0;
    for(int i = 0; i < N; i++){
      if(rem == 0) break;
      long long  diff = std::min(rem, exams[i].second);
      long long essays = diff * exams[i].first;
      rem -= diff;
      numEssays += essays;
    }

    std::cout << numEssays << std::endl;
  }
}
