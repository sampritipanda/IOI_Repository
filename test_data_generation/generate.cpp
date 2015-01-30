#include <random>
#include <iostream>
#include <string>
#include <limits.h>

int main() {
    std::random_device rd;
    std::mt19937 mt(rd());

    for(int i = 0; i < 7; i++){
      std::string file_name = "test_";
      file_name += std::to_string(i);
      freopen(file_name.c_str(), "w", stdout);
      std::uniform_int_distribution<int> limit(1, INT_MAX);
      std::uniform_int_distribution<unsigned long long> number(1, ULONG_MAX);

      for(int i = 0; i < limit(mt); i++){
        std::cout << number(mt) << std::endl;
      }

      fclose(stdout);
    }
}
