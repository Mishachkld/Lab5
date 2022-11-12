#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>


#define STR_SIZE 2600
std::string FILE_PATH_IN = "input.txt";
std::string FILE_PATH_OUT = "TEXT.txt";

char a, b;
int N;

void outArray(std::string* myString) {
	std::ofstream file(FILE_PATH_OUT, std::ios::out);
	for (int i = 0; i < N; i++) {
		if (!myString[i].empty()) {
			//std::cout << myString[i] << " ";
			file << myString[i] << std::endl;
		}
	}
	std::cout << std::endl;


	file.close();
}


bool compareByLength(const std::string firstStr, const std::string lastStr) {
	return firstStr.length() > lastStr.length();

}

std::string* mySort(std::string* myStrings, int n) {
	for (int i = 0; i < n-1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (compareByLength(myStrings[i], myStrings[j]) && !myStrings[i].empty()
				&& !myStrings[j].empty()) {
				std::swap(myStrings[i], myStrings[j]);
			}
		}
	}
	return myStrings;
}

int counts(std::string* s, std::string what, int j) {
	for (int i = 0; i < j; ++i) {
		if (s[i] == what)
			return false;
	}
	return true;
}


std::string remover(std::string str) {
	std::string ret = "";
	std::string exceptions = " ,;\n'"".?!:(){}[]*&^%$#@-_=+\\|/0123456789";
	for (int i = 0; i < str.length(); i++) {
		if (exceptions.find(str[i]) == std::string::npos)
			ret += str[i];
	}
	return ret;
}



int main() {
	setlocale(0, "");
	std::string word;
	std::ifstream file(FILE_PATH_IN, std::ios::in);
	file >> a;
	file >> b;
	file >> N;
	std::cout << "In word's we have these liter: " << a << " " << b << std::endl;
	std::string myString[STR_SIZE];
	std::string resultString[STR_SIZE];
	int j = 0;
	while (!file.eof() && j < 2600) {

		file >> word;
		word = remover(word);
		std::transform(word.begin(), word.end(), word.begin(),
			tolower);
		if ((word.length() != 1) && (word.find(a) != std::string::npos) && (word.find(b) != std::string::npos) && counts(myString, word, j)) {
			myString[j] = word;
			//std::cout << myString[j] << " ";
			j++;
		}
	}
	file.close();
	//outArray(myString);
	mySort(myString, j);
	//outArray(myString);

	outArray(myString);
	system("pause");

	return 0;
}
