// Candy Boxes

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  long long int arr[50000];
  long long int vals[5];
  long long int k = 0, n, sum = 0, i = 4;

  while(k < 50000){
    arr[k] = i;
    k++;
    i += 4;
  }
  cin >> n;
  for(i = 0; i < 3; i++){
    cin >> vals[i];
    sum += vals[i];
  }
  int idx = lower_bound(arr, arr + 50000, sum) - arr;
  int toPut = (arr[idx] - sum);


  if(n ==  4){
    cout << "YES" << endl;
  }
  else if(n == 3){
    vals[3] = toPut;
    sort(vals, vals + 4);
    if((sum + toPut)/ 4 == vals[3]-vals[0] && vals[3] - vals[0] == (vals[1]+vals[2]) / 2){
      cout << "YES"<<endl;
      cout << toPut << endl;
    }else{
      cout << "NO"<<endl;
    }
  }
  if(n == 2){
    toPut /= 2;
    for(i = 2; i < 4; i++) vals[i] = toPut;
    sort(vals, vals+4);
    if((sum + toPut*2)/ 4 == vals[3]-vals[0] && vals[3] -vals[0] == (vals[1]+vals[2]) / 2){
      cout << "YES"<<endl;
      cout << toPut << endl;
      cout << toPut << endl;
    }else{
      cout << "NO"<<endl;
    }
  }
  if(n ==  1){
    toPut /= 3;
    for(int i = 1; i < 4; i++) vals[i] = toPut;
    sort(vals, vals+4);
    if((sum + toPut*3)/ 4 == vals[3]-vals[0] && vals[3]-vals[0] == (vals[1]+vals[2])/2){
      cout << "YES"<<endl;
      cout << toPut << endl;
      cout << toPut << endl;
      cout << toPut << endl;
    }else{
      cout << "NO"<<endl;
    }
  }
  return 0;
}
