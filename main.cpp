#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <Windows.h>
#define STR_SIZE 2600
std::string FILE_PATH = R"(D:\C++Project\Lab5\text.txt)";

char a, b;
int N;

void outArray(std::string *myString) {
    for (int i = 0; i < N ; i++) {
        if (myString[i].size() != 1)
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


std::string makeStringLower(std::string word) {
    for (int i = 0; i <  word.size(); i++) {
//        std::cout << word.size() << " ";
        if (isupper(word[i])) {
            word[i] = tolower(word[i]);

        }
    }
    return (std::string) word;
}

int main() {
    std::string word;
    std::ifstream file(FILE_PATH, std::ios::in);
    file >> a;
    file >> b;
    std::cout << "In this word's we have these liter: " << a << " " << b << std::endl;
    file >> N;

    std::string myString[STR_SIZE];
    int i = 0;
    while (!file.eof() and i < 2600) {

        file >> word;
        word = remover(word);
        word = makeStringLower(word);
        if (word.size() != 1 || (word.find(a) != std::string::npos) || (word.find(b) != std::string::npos)) {
            myString[i] = word;
            i++;
        }


    }

    file.close();
    std::sort(myString, myString + myString->length(), compareByLength);
    outArray(myString);

    return 0;
}