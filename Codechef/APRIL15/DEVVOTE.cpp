// Devus and their voting system

#include <iostream>

using namespace std;

int votes[36], freq[36], freq_2[36];

bool check(int votes[], int N){
  for(int i = 1; i < N; i++){
    if(votes[i] == votes[i + 1]) return false;
  }
  return true;
}

int calc(int votes[], int N){
  int max_votes = 0;
  for(int i = 1; i <= N; i++) freq[i] = 0;
  for(int i = 1; i <= N; i++){
    freq[votes[i]]++;
    max_votes = max(max_votes, freq[votes[i]]);
  }
  int count = 0;
  for(int i = 1; i <= N; i++){
    if(freq[i] == max_votes) count++;
  }
  return count;
}

int main() {
  int T; cin >> T;

  while(T--){
    int N; cin >> N;
    for(int i = 0; i <= N; i++) freq_2[i] = 0;

    long long num_presidents = 0, num_arrangements = 0;
    long long count = 0;

    if(N == 1) {
      num_presidents = 1;
      num_arrangements = 1;
    }
    else if(N == 2) {
      num_presidents = 4;
      num_arrangements = 2;
    }
    else if(N == 3){
      for(int v_1 = 1; v_1 <= N; v_1++){
        for(int v_2 = 1; v_2 <= N; v_2++){
          for(int v_3 = 1; v_3 <= N; v_3++){
            votes[1] = v_1; votes[2] = v_2; votes[3] = v_3;
            if(check(votes, N)) {
              num_presidents += calc(votes, N);
              num_arrangements++;
              freq_2[calc(votes, N)]++;
            }
          }
        }
      }
    }
    else if(N == 4){
      for(int v_1 = 1; v_1 <= N; v_1++){
        for(int v_2 = 1; v_2 <= N; v_2++){
          for(int v_3 = 1; v_3 <= N; v_3++){
            for(int v_4 = 1; v_4 <= N; v_4++){
              votes[1] = v_1; votes[2] = v_2; votes[3] = v_3; votes[4] = v_4;
              if(check(votes, N)) {
                num_presidents += calc(votes, N);
                num_arrangements++;
                freq_2[calc(votes, N)]++;
              }
            }
          }
        }
      }
    }
    else if(N == 5){
      for(int v_1 = 1; v_1 <= N; v_1++){
        for(int v_2 = 1; v_2 <= N; v_2++){
          for(int v_3 = 1; v_3 <= N; v_3++){
            for(int v_4 = 1; v_4 <= N; v_4++){
              for(int v_5 = 1; v_5 <= N; v_5++){
                votes[1] = v_1; votes[2] = v_2; votes[3] = v_3; votes[4] = v_4; votes[5] = v_5;
                if(check(votes, N)) {
                  num_presidents += calc(votes, N);
                  num_arrangements++;
                  freq_2[calc(votes, N)]++;
                }
              }
            }
          }
        }
      }
    }
    else if(N == 6){
      for(int v_1 = 1; v_1 <= N; v_1++){
        for(int v_2 = 1; v_2 <= N; v_2++){
          for(int v_3 = 1; v_3 <= N; v_3++){
            for(int v_4 = 1; v_4 <= N; v_4++){
              for(int v_5 = 1; v_5 <= N; v_5++){
                for(int v_6 = 1; v_6 <= N; v_6++){
                  votes[1] = v_1; votes[2] = v_2; votes[3] = v_3; votes[4] = v_4; votes[5] = v_5; votes[6] = v_6;
                  if(check(votes, N)) {
                    num_presidents += calc(votes, N);
                    num_arrangements++;
                    freq_2[calc(votes, N)]++;
                  }
                }
              }
            }
          }
        }
      }
    }
    else if(N == 7){
      for(int v_1 = 1; v_1 <= N; v_1++){
        for(int v_2 = 1; v_2 <= N; v_2++){
          for(int v_3 = 1; v_3 <= N; v_3++){
            for(int v_4 = 1; v_4 <= N; v_4++){
              for(int v_5 = 1; v_5 <= N; v_5++){
                for(int v_6 = 1; v_6 <= N; v_6++){
                  for(int v_7 = 1; v_7 <= N; v_7++){
                    votes[1] = v_1; votes[2] = v_2; votes[3] = v_3; votes[4] = v_4; votes[5] = v_5; votes[6] = v_6; votes[7] = v_7;
                    if(check(votes, N)) {
                      num_presidents += calc(votes, N);
                      num_arrangements++;
                      freq_2[calc(votes, N)]++;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    else if(N == 8){
      for(int v_1 = 1; v_1 <= N; v_1++){
        for(int v_2 = 1; v_2 <= N; v_2++){
          for(int v_3 = 1; v_3 <= N; v_3++){
            for(int v_4 = 1; v_4 <= N; v_4++){
              for(int v_5 = 1; v_5 <= N; v_5++){
                for(int v_6 = 1; v_6 <= N; v_6++){
                  for(int v_7 = 1; v_7 <= N; v_7++){
                    for(int v_8 = 1; v_8 <= N; v_8++){
                      votes[1] = v_1; votes[2] = v_2; votes[3] = v_3; votes[4] = v_4; votes[5] = v_5; votes[6] = v_6; votes[7] = v_7; votes[8] = v_8;
                      if(check(votes, N)) {
                        num_presidents += calc(votes, N);
                        num_arrangements++;
                        freq_2[calc(votes, N)]++;
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }


    double ans = double(num_presidents)/double(num_arrangements);
    for(int i = 1; i <= N; i++) cout << freq_2[i] << " \n"[i == N];
    printf("%.6lf\n", ans);
  }
}
