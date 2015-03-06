// Taro Jiro Dividing

#include <vector>
#include <algorithm>

using namespace std;

class TaroJiroDividing {
	public:
	int getNumber(int A, int B) {
		vector<int> A_nums, B_nums;
		
		A_nums.push_back(A);
		while(A % 2 == 0){
			A /= 2;
			A_nums.push_back(A);
		}
		
		B_nums.push_back(B);
		while(B % 2 == 0){
			B /= 2;
			B_nums.push_back(B);
		}
		
		sort(A_nums.begin(), A_nums.end());
		sort(B_nums.begin(), B_nums.end());
		
		vector<int> fin(A_nums.size() + B_nums.size());
		auto it = set_intersection(A_nums.begin(), A_nums.end(), B_nums.begin(), B_nums.end(), fin.begin());
		return it - fin.begin();
	}
};