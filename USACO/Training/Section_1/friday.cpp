/*
ID: sampdin1
PROG: friday
LANG: C++11
*/

#include <stdio.h>

bool is_leap(int year){
  if(year % 100 == 0){
    return year % 400 == 0;
  }
  return year % 4 == 0;
}

int main() {
  freopen("friday.in", "r", stdin);
  freopen("friday.out", "w", stdout);

  int N; scanf("%d", &N);
  int curr_year = 1;
  int curr_month = 1;
  int curr_date = 1;
  int curr_day = 1;
  int month[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
  int frequencies[] = { 0, 0, 0, 0, 0, 0, 0 };

  while(curr_year <= N){
    if(curr_date == 13) frequencies[curr_day]++;
    curr_day = (curr_day + 1) % 7;
    curr_date++;
    if(curr_month == 2 && is_leap(1900 + curr_year - 1)){
      if(curr_date > 29) {
        curr_date %= 29;
        curr_month++;
      }
    }
    else {
      if(curr_date > month[curr_month]){
        curr_date %= month[curr_month];
        curr_month++;
      }
    }

    if(curr_month > 12) {
      curr_month %= 12;
      curr_year++;
    }
  }

  printf("%d ", frequencies[6]);
  for(int i = 0; i <= 5; i++) printf("%d%c", frequencies[i], " \n"[i == 5]);

  fclose(stdin);
  fclose(stdout);
}
