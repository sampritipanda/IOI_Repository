// Marathon

#include <stdio.h>
#include <cmath>

using namespace std;

int main() {
  freopen("marathon.in", "r", stdin);
  freopen("marathon.out", "w", stdout);

  int N; scanf("%d", &N);
  int checkpoints[N][2];
  long long total_distance = 0;

  scanf("%d %d", &checkpoints[0][0], &checkpoints[0][1]);
  for(int i = 1; i < N; i++){
    scanf("%d %d", &checkpoints[i][0], &checkpoints[i][1]);
    total_distance += abs(checkpoints[i - 1][0] - checkpoints[i][0]) + abs(checkpoints[i - 1][1] - checkpoints[i][1]);
  }

  long long min_distance = total_distance;

  for(int i = 1; i < N - 1; i++){
    long long original_distance = abs(checkpoints[i - 1][0] - checkpoints[i][0]) + abs(checkpoints[i - 1][1] - checkpoints[i][1]) +
      abs(checkpoints[i][0] - checkpoints[i + 1][0]) + abs(checkpoints[i][1] - checkpoints[i + 1][1]);
    long long new_distance = abs(checkpoints[i - 1][0] - checkpoints[i + 1][0]) + abs(checkpoints[i - 1][1] - checkpoints[i + 1][1]);

    long long new_total = total_distance - (original_distance - new_distance);
    if(new_total < min_distance) min_distance = new_total;
  }

  printf("%llu\n", min_distance);

  fclose(stdin);
  fclose(stdout);
}
