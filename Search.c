#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int linearSearch(int* userArray, int target, int sizeOfArray);
void selectionSort(int* userArray, int sizeOfArray);


int main() {
	int userArray[4] = { 4,7,3,1 };
	int target;
	char userChoice[100];
	int counter = 0;
	int sizeOfArray = sizeof(userArray)/sizeof(userArray[0]);
	char userOption[2];

	//printf("Which one do you want to use? ");
	//scanf_s("%c", userOption, (unsigned)_countof(userOption));

	//if (strcmp(userOption, "l")==0) {
	//	printf("Please choose your target. The array is { 4,7,3,1 }: \n");
	//	scanf_s("%s", userChoice, (unsigned)_countof(userChoice));
	//	target = atoi(userChoice);
	//	linearSearch(userArray, target, sizeOfArray);
	//}
	//else if (strcmp(userOption, "s") == 0) {
	//	selectionSort(userArray, sizeOfArray);

	//}

	/*selectionSort(userArray, sizeOfArray);*/

	binarySearch(userArray, target, sizeOfArray);

	return 0;
}

int linearSearch(int* userArray,int target, int sizeOfArray) {

	for (int i = 0; i < sizeOfArray; i++) {
		if (target == userArray[i]) {
			printf("The index of your target is %d\n", i);
			return i;
		}
	}

	return 0;
}

int binarySearch(int* userArray, int target, int sizeOfArray) {
	
	int lowNum = 0;
	int highNum = sizeOfArray-1;
	int midPoint = lowNum + (highNum - lowNum) / 2;
	int resultIndex;
	userArray[4] = { 1,3,4,7 };
	
	while (lowNum <= highNum) {
		if (userArray[midPoint] == target) {
			resultIndex = userArray;
			printf("%d", resultIndex);
		}
		else if (userArray[midPoint] < target) {
			lowNum = midPoint + 1;
		}
		else if (userArray[midPoint] > target) {
			highNum = midPoint - 1;
		}

	}
	return 0;

}

void selectionSort(int* userArray, int sizeOfArray) {

	int temp;
	int minIndex;
	int sortedArray[4] = {};
	
	for (int i = 0; i < sizeOfArray - 1; i++) {
		minIndex = i;

		for (int j = i + 1; j < sizeOfArray; j++) {
			if (userArray[minIndex]>userArray[j]) {
				minIndex = j;				
			}
		}

		if (minIndex != i) {
			temp = userArray[i];
			userArray[i] = userArray[minIndex];
			userArray[minIndex] = temp;
		}
	}
	printf("Sorted array: ");
	for (int i = 0; i < sizeOfArray; i++) {
		sortedArray[i] = userArray[i];
	}
	printf("\n");
}

