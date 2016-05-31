#include <cstdio>
#include <algorithm>
#include <string>

using namespace std;

int main() {
  int hh, mm; scanf("%d:%d", &hh, &mm);

  if(hh == 5 && mm == 0) {
    printf("07:00\n");
  }
  else if(hh < 5 || hh >= 19) {
    printf("%02d:%02d\n", (hh + 2) % 24, mm);
  }
  else if(hh == 6 && mm == 40) {
    printf("10:10\n");
  }
  else if(hh == 13 && mm == 0) {
    printf("15:00\n");
  }
  else if(hh >= 10 && hh < 13) {
    printf("%02d:%02d\n", hh + 2, mm);
  }
  else if(hh >= 5 && hh < 7) {
    int rem = (120 - ((7 * 60) - (hh * 60 + mm))) * 2;
    int ans_hh = 7 + rem/60, ans_mm = rem % 60;
    printf("%02d:%02d\n", ans_hh, ans_mm);
  }
  else if(hh >= 7 && hh < 10) {
    int rem = (240 - ((10 * 60) - (hh * 60 + mm)))/2;
    int ans_hh = 10 + rem/60, ans_mm = rem % 60;
    printf("%02d:%02d\n", ans_hh, ans_mm);
  }
  else if(hh >= 13 && hh < 15) {
    int rem = (120 - ((15 * 60) - (hh * 60 + mm))) * 2;
    int ans_hh = 15 + rem/60, ans_mm = rem % 60;
    printf("%02d:%02d\n", ans_hh, ans_mm);
  }
  else if(hh >= 15 && hh < 19) {
    int rem = (240 - ((19 * 60) - (hh * 60 + mm)))/2;
    int ans_hh = 19 + rem/60, ans_mm = rem % 60;
    printf("%02d:%02d\n", ans_hh, ans_mm);
  }
}
