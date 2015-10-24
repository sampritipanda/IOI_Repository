#include <random>
#include <iostream>
#include <string>
#include <limits.h>

int main() {
    std::random_device rd;
    std::mt19937 mt(rd());
    
    int TEST_FILES = 7;
    
    for(int i = 0; i < TEST_FILES; i++){
      std::string file_name = "test_";
      file_name += std::to_string(i);
      file_name += ".in";
      freopen(file_name.c_str(), "w", stdout);

      // Generate Input - Start

      std::uniform_int_distribution<int> limit(1, INT_MAX);
      std::uniform_int_distribution<unsigned long long> number(1, ULONG_MAX);

      for(int i = 0; i < limit(mt); i++){
        std::cout << number(mt) << std::endl;
      }

      // Generate Input - End

      fclose(stdout);
    }
}
