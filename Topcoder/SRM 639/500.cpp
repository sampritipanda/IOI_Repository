// Alice Game

#include <iostream>
#include <cmath>

using namespace std;

bool isSum(long long sum){
	long long N = (-1 + sqrt(8 * sum + 1)) / 2;
	long long sum2 = N * (N + 1) / 2;
	return sum == sum2;
}
long long findN(long long sum){
	long long N = (-1 + sqrt(8 * sum + 1)) / 2;
	return N;
}

class AliceGameEasy {
    public:
    long long findMinimumValue(long long x, long long y);
};

long long AliceGameEasy::findMinimumValue(long long x, long long y){
	long long sum = x + y;
	if(!isSum(sum)) return -1;
	
	if(x == 0) return 0;
	if(y == 0) return findN(x);
	
	long long N = findN(sum), count = 1;
	for(long long i = N; i >= 0; i--){
		if(x >= i){
			x -= i;
			count++;
		}
		else {
			break;
		}
	}
	return count;
}

int main() {
	AliceGameEasy test;
	cout << test.findMinimumValue(100000, 400500) << endl;
}