#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int linearSearch(int* userArray, int target);

int main() {
	int userArray[4] = { 4,7,3,1 };
	int target;
	char userChoice[100];
	int counter = 0;
	int sizeOfArray = 4;

	printf("Please choose your target. The array is { 4,7,3,1 }: \n");
	scanf_s("%s", userChoice, (unsigned)_countof(userChoice));
	target = atoi(userChoice);

	linearSearch(userArray, target);

	return 0;
}

int linearSearch(int* userArray,int target) {

	for (int i = 0; i < 4; i++) {
		if (target == userArray[i]) {
			printf("The index of your target is %d\n", i);
			return i;
		}
	}

	return 0;
}