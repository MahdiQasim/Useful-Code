#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Key {
	char c;
	int NumOfIter;
};

vector<Key> RunLenCoder(string str) {

	Key temp;

	temp.c = str[0];
	temp.NumOfIter = 1;
	char check = str[0];

	vector<Key> code;

	for (unsigned int i = 1; i < str.size(); i++) {

		if (check == str[i]) {
			temp.NumOfIter++;
		}
		else {
			code.push_back(temp);
			check = str[i];
			temp.c = str[i];
			temp.NumOfIter = 1;
		}
	}
	code.push_back(temp);
	return code;
}

string RunLenDeCoder(vector<Key> code) {

	string decode;

	for (unsigned int i = 0; i < code.size(); i++) {

		for (int j = 0; j < code[i].NumOfIter; j++) {
			
			decode.push_back(code[i].c);
			
		}
	}
	return decode;
}

void main() {

	std::string input;
	std::cin >> input;
	std::vector<Key> code = RunLenCoder(input);
	std::for_each(code.begin(), code.end(), [](Key element) {cout << element.c << element.NumOfIter;});
	

	std::cout << "\n";
	std::string decode = RunLenDeCoder(code);
	std::cout << decode;
}