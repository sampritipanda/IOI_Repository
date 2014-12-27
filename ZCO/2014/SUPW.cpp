// SUPW
 
#include <stdio.h>
#include <iostream>
#include <vector>
 
using namespace std;
 
int main() {
        int N;
        cin >> N;
        int limit = 2147483646;
        int size = N/3 + 1;
        if(N%3 == 0) size -= 1;
        vector<vector<int> > data(size, std::vector<int>(3));;
        if(N%3 != 0){
                data[N/3][0] = limit;
                data[N/3][1] = limit;
                data[N/3][2] = limit;
        }
        long long sum = 0;
        for(int i = 0; i < N; i++){
                cin >> data[i/3][i%3];
        }
        
        for(int i = 0; i < size; i++){
                sum += min(data[i][0], min(data[i][1], data[i][2]));
        }
        
        cout << sum;
        cout << endl;
}