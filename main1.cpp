#include<iostream>
#include<cstring>
#include<fstream>

#define STR_SIZE 1000

char myStringPart1[STR_SIZE];

char ALL_SOGL[] = "bcdfghjklmnpqrstvwxyz";

void makeStringUpper(char *string) {
	for (int i = 0; i < strlen(string); i++) {
		if (islower(string[i])) {
			for (int j = 0; j < strlen(ALL_SOGL); j++) {
				if (string[i] == ALL_SOGL[j])
					string[i] = toupper(string[i]);
			}
		}
	}
}


int main1() {


	std::cin >> myStringPart1;
	makeStringUpper(myStringPart1);
	std::cout << myStringPart1;

    return 0;
}
