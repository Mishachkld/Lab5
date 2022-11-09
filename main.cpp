#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>
#include <valarray>

#define STR_SIZE 2600
std::string FILE_PATH = R"(D:\C++Project\Lab5\text.txt)";

char a, b;
int N;

void outArray(std::string *myString) {
    for (int i = 0; i < N + 1; i++) {
        if (!myString[i].empty())
            std::cout << myString[i] << std::endl;
    }
}

bool compareByLength(std::string firstStr, std::string lastStr) {
    return firstStr.length() < lastStr.length();

}

std::string remover(std::string str, bool flag = false) {
    std::string ret;
    std::string exceptions = " ,;\n'"".?!:()[]*&^%$#@-_=+\\|/0123456789";
    for (int i = 0; i <= str.length(); i++) {
        if (exceptions.find(str[i]) == std::string::npos)
            ret += str[i];
    }
    return ret;
}


std::string makeStringLower(std::basic_string<char> word) {
    for (int i = 0; i < sizeof(word); i++) {
        if (isupper(word[i])) {

            word[i] = tolower(word[i]);
        }
    }
    return (std::string) word;
}

int main() {
    std::ifstream file(FILE_PATH, std::ios::in);
//    N = 10;
    file >> N;                    // удалить
    std::string *myStringRaw = new std::string[STR_SIZE];
    std::string *myStringAnswer = new std::string[N];
    int i = 0;
    while (!file.eof()) {
        std::string word;
        file >> word;
        word = remover(word);

        if (word.size() != 1) {
            myStringRaw[i] = makeStringLower(word);
            i++;
        }

//        std::transform(word.begin(), word.end(), myStringRaw[i].begin(), std::toupper);
    }

    file.close();
    std::sort(myStringRaw, myStringRaw + myStringRaw->length(), compareByLength);
    outArray(myStringRaw);

    return 0;
}