// Worms - 474B

#include <stdio.h>
#include <vector>
#include <utility>

using namespace std;

int search(vector<pair<int, int> >& piles, int val, int left, int right){
  int mid = (left + right)/2;
  if(val >= piles[mid].first && val <= piles[mid].second){
    return mid;
  }
  else if(val < piles[mid].first){
    return search(piles, val, left, mid - 1);
  }
  else {
    return search(piles, val, mid + 1, right);
  }
}

int main() {
  int N; scanf("%d", &N);
  vector<pair<int, int> > piles;

  int temp = 0;
  for(int i = 0; i < N; i++){
    int curr; scanf("%d", &curr);
    piles.push_back(make_pair(temp + 1, temp + curr));
    temp += curr;
  }

  int M; scanf("%d", &M);
  for(int i = 0; i < M; i++){
    int worm; scanf("%d", &worm);
    printf("%d\n", search(piles, worm, 0, N - 1) + 1);
  }
}
