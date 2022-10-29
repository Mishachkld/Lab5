#include<iostream>

#define STR_SIZE 1000

char myString[STR_SIZE];

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


int main() {
	std::cin >> myString;
	makeStringUpper(myString);
	std::cout << myString;


	system("pause");
	return 0;
}
