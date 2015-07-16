// Calories From Fat

#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

int main() {
  int multiplier[5] = {9, 4, 4, 4, 7};

  while(true){
    string S; getline(cin, S);
    if(S == "-") break;

    double total_calories = 0, fat_calories = 0;
    do {
      istringstream iss(S);
      string fat; iss >> fat;
      iss.str(S); iss.clear();

      double curr_total = 0, curr_tot_percent = 0;
      for(int i = 0; i < 5; i++) {
        string curr; iss >> curr;
        char type = curr.back(); curr.pop_back();

        if(type == 'C'){
          curr_total += stoi(curr);
        }
        else if(type == 'g'){
          curr_total += stoi(curr) * multiplier[i];
        }
        else {
          curr_tot_percent += stoi(curr);
        }
      }
      curr_total = (curr_total * 100)/(100 - curr_tot_percent);
      total_calories += curr_total;
      char type = fat.back(); fat.pop_back();
      if(type == 'C'){
        fat_calories += stoi(fat);
      }
      else if(type == 'g'){
        fat_calories += stoi(fat) * multiplier[0];
      }
      else {
        fat_calories += (stoi(fat) * curr_total)/100;
      }

      getline(cin, S);
    } while(S != "-");

    cout << round(fat_calories/total_calories * 100) << "%" << endl;
  }
}
