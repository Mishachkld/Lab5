#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>

#define STR_SIZE 2600
std::string FILE_PATH_IN = R"(D:\C++Project\Lab5\text.txt)";
std::string FILE_PATH_OUT = R"(D:\C++Project\Lab5\output.txt)";

char a, b;
int N;

void outArray(std::string *myString) {
    std::ifstream file(FILE_PATH_OUT, std::ios::out);
    for (int i = 0; i < N; i++) {
        if (!myString[i].empty()) {
            std::cout << myString[i] << std::endl;
            myString[i] += " ";
            file >> myString[i];
        }
        else
            i++;
    }
}


bool compareByLength(const std::string& firstStr, const std::string& lastStr) {
    return firstStr.length() > lastStr.length();

}

std::string *mySort(std::string *myStrings) {
    for (int i = 0; i < myStrings->length(); i++) {
        for (int j = i + 1; j < myStrings->length(); j++) {
            if (compareByLength(myStrings[i], myStrings[j]) and !myStrings[i].empty() and !myStrings[j].empty())
                std::swap(myStrings[i], myStrings[j]);

        }
    }
    return myStrings;
}

std::string remover(std::string str) {
    std::string ret = "";
    std::string exceptions = " ,;\n'"".?!:()[]*&^%$#@-_=+\\|/0123456789";
    for (int i = 0; i <= str.length(); i++) {
        if (exceptions.find(str[i]) == std::string::npos)
            ret += str[i];
    }
    return ret;
}


std::string makeStringLower(std::string word) {
    for (int i = 0; i < word.length() ;i++) {
        if (isupper(word[i])) {
            char x = word[i];
            x = tolower(x);                         //авхыавхахыхвахыхва
            word[i] = x;
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
//        std::cout << word << "->";
//        std::cout << word << " ";
        word = makeStringLower(word);

        if ((word.length() != 1) and (word.find(a) != std::string::npos) and (word.find(b) != std::string::npos)) {
            myString[j] = word;
//            std::cout << myString[j];
            j++;
        }


    }
    file.close();
//    std::sort(std::begin(myString), std::end(myString), compareByLength);
    mySort(myString);
    outArray(myString);

    return 0;
}