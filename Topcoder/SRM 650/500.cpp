// Taro Filling a String

#include <string>
#include <algorithm>

using namespace std;

class TaroFillingAStringDiv2 {
	public:
	int getNumber(string S) {
		int N = S.length();
		
		string temp = S;
		if(temp[0] == '?') temp[0] = 'A';
		for(int i = 1; i < N; i++){
			if(temp[i] == '?'){
				temp[i] = (temp[i - 1] == 'A') ? 'B' : 'A';
			}
		}
		int count1 = 0;
		for(int i = 1; i < N; i++){
			if(temp[i] == temp[i - 1]) count1++;
		}
		
		temp = S;
		if(temp[0] == '?') temp[0] = 'B';
		for(int i = 1; i < N; i++){
			if(temp[i] == '?'){
				temp[i] = (temp[i - 1] == 'A') ? 'B' : 'A';
			}
		}
		int count2 = 0;
		for(int i = 1; i < N; i++){
			if(temp[i] == temp[i - 1]) count2++;
		}
		
		return min(count1, count2);
	}
};