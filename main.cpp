#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>

#define STR_SIZE 2600
std::string FILE_PATH_IN = R"(D:\C++Project\Lab5\input.txt)";
std::string FILE_PATH_OUT = R"(D:\C++Project\Lab5\output.txt)";

char a, b;
int N;

void outArray(std::string *myString) {
    std::ofstream file(FILE_PATH_OUT, std::ios::out);
    for (int i = 0; i < N; i++) {
        if (!myString[i].empty()) {
            std::cout << myString[i] << std::endl;
            file << myString[i] << std::endl;
        }
    }
    file.close();
}


bool compareByLength(const std::string &firstStr, const std::string &lastStr) {
    return firstStr.length() > lastStr.length();

}

std::string *mySort(std::string *myStrings) {
    for (int i = 0; i < myStrings->length(); i++) {
        for (int j = i + 1; j < myStrings->length(); j++) {
            if (compareByLength(myStrings[i], myStrings[j]) and !myStrings[i].empty()
                and !myStrings[j].empty()) {
//                if ()
                else
                    std::swap(myStrings[i], myStrings[j]);

            }
        }
    }
    return myStrings;
}

int counts(std::string *s, std::string what) {
    int ans = 0;
    for (int i = 0; i < (s)->length(); ++i) {
        if (s[i] == what)
            ans++;
    }
    return ans;
}


std::string remover(std::string str) {
    std::string ret = "";
    std::string exceptions = " ,;\n'"".?!:(){}[]*&^%$#@-_=+\\|/0123456789";
    for (int i = 0; i <= str.length(); i++) {
        if (exceptions.find(str[i]) == std::string::npos)
            ret += str[i];
    }
    return ret;
}


std::string makeStringLower(std::basic_string<char> word) {
    for (int i = 0; i < word.length(); i++) {
        if (isupper(word[i])) {
            word[i] = tolower(word[i]);
            std::cout << word[i] << " ";

        }
    }
    return word;
}

int main() {
    std::string word;
    std::ifstream file(FILE_PATH_IN, std::ios::in);
    file >> a;
    file >> b;
    file >> N;
    std::cout << "In word's we have these liter: " << a << " " << b << std::endl;
    std::string myString[STR_SIZE];
    int j = 0;
    while (!file.eof() and j < 2600) {

        file >> word;
        word = remover(word);
        word = makeStringLower(word);
//        std::transform(word.begin(), word.end(), word.begin(),
//                       tolower );
        if ((word.length() != 1) and (word.find(a) != std::string::npos) and (word.find(b) != std::string::npos)) {
            myString[j] = word;
//            std::cout << myString[j];
            j++;
        }


    }
    file.close();
    mySort(myString);
    outArray(myString);

    return 0;
}