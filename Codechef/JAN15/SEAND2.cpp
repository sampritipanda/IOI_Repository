// Sereja and Number Division 2

#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <set>

using namespace std;

void swap(int* arr, int i, int j){
  int temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
}

void generatePrimeFactors(set<int>& factor_list, int n) {
  if(n % 2 == 0) factor_list.insert(2);
  while (n%2 == 0) {
    n = n/2;
  }

  for (int i = 3; i <= sqrt(n); i = i+2){
    if(n % i == 0) factor_list.insert(i);
    while (n%i == 0){
      n = n/i;
    }
  }

  if (n > 2){
    factor_list.insert(n);
  }
}

int main() {
  int T; scanf("%d", &T);

  while(T--){
    char A[1005];
    scanf(" %s", A);
    int len = strlen(A);

    int num[len];
    for(int i = 0; i < len; i++){
      num[i] = A[i] - '0';
    }

    int N; scanf("%d", &N);
    int B[N];

    for(int i = 0; i < N; i++) scanf("%d", &B[i]);
    sort(B, B+N);

    set<int> prime_factors;
    bool even = false;
    long long digit_sum = 0;
    for(int i = 0; i < N; i++){
      if(B[i] % 2 == 0) even = true;
      generatePrimeFactors(prime_factors, B[i]);
      digit_sum += B[i];
    }

    // Basic Sorting
    sort(num, num + len, greater<int>());

    // Divisible by 2
    if(num[len - 1] % 2 == 1){
      for(int i = len - 2; i >= 0; i--){
        if(num[i] % 2 == 0){
          swap(num, i, len - 1);
          break;
        }
      }
    }

    // Divisible by 4
    if(binary_search(num, num + len, 4)){
      int last_2_digits_mod = (num[len - 2] * 10 + num[len - 1]) % 4;
      if(last_2_digits_mod != 0){
        for(int i = len - 2; i >= 0; i--){
          int new_mod = (last_2_digits_mod - num[len - 1] + num[i]) % 4;
          if(new_mod < last_2_digits_mod){
            swap(num, i, len - 1);
            last_2_digits_mod = new_mod;
            if(new_mod == 0) break;
          }
        }
      }
    }

    // Divisible by 5
    if(prime_factors.find(5) != prime_factors.end()){
      if(num[len - 1] != 5 && num[len - 1] != 0){
        for(int i = len - 1; i >= 0; i--){
          if(num[i] == 0){
            swap(num, i, len - 1);
          }
        }
      }
    }

    for(int i = 0; i < len; i++){
      printf("%d", num[i]);
    }
    printf("\n");
  }
}
