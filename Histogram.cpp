#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>

using namespace std;


int main() {

	vector<int> vec = { 1,1,3,3,3,4,9,-2,-2 };  // Test data

	map<int, unsigned int> hist;
	
	auto min = min_element(vec.begin(), vec.end());
	auto max = max_element(vec.begin(), vec.end());
	
	for (int i = *min; i <= *max; i++)
	{
		hist.insert(make_pair(i, 0));
	}

	for (size_t i = 0; i < vec.size(); i++)
	{
		map<int, unsigned int>::iterator itr = hist.find(vec[i]);
		if (itr != hist.end())
		{
			itr->second++;
		}
	}
	

	for (auto it = hist.begin(); it != hist.end(); ++it)
		cout << it->first << " " << it->second << "\n";
	
	return 0;
}
