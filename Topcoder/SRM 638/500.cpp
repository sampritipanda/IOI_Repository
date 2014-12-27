// Narrow Passage

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class NarrowPassage2Easy {
    public:
    int count(vector <int> size, int maxSizeSum);
};

int NarrowPassage2Easy::count(vector <int> size, int maxSizeSum){
	sort(size.begin(), size.end());
	int count = 0;
	
	for (int i = 0; i < size.size(); i++)
	{
		for (int j = i + 1; j < size.size(); j++)
		{
			if(size[i] + size[j] <= maxSizeSum) count++;
		}
	}
	return count;
}

int main() {
	NarrowPassage2Easy test;
	int size_arr[] = {2,4,6,1,3,5};
	std::vector<int> size (size_arr, size_arr + sizeof(size_arr) / sizeof(int) );
	
	cout << test.count(size, 8) << endl;
}