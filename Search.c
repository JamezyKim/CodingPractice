#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int linearSearch(int* userArray, int target, int sizeOfArray);
void selectionSort(int* userArray, int sizeOfArray);
int binarySearch(int* userArray, int target, int sizeOfArray);
int insertionSort(int* userArray, int sizeOfArray);
void swap(int* userArray, int firstIndex, int secondIndex);
void printArray(int* userArray, int sizeOfArray);


int main() {
	int userArray[4] = { 4,7,3,1 };
	int target = 3;
	char userChoice[100];
	int counter = 0;
	int sizeOfArray = sizeof(userArray)/sizeof(userArray[0]);
	char userOption[2];
	int min = 0;
	int max = sizeOfArray - 1;

	binarySearch(userArray, target, sizeOfArray, max, min);

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
	
	int min = 0;
	int max = sizeOfArray-1;
	int midPoint = (max+min) / 2;
	int resultIndex;
	printf("Original array: ");
	printArray(userArray, sizeOfArray);
	selectionSort(userArray, sizeOfArray);
	
	if (userArray[midPoint] == target) {
		printf("\nSorted array: ");
		printArray(userArray, sizeOfArray);
		return midPoint;
		
	}
	else if (userArray[midPoint] < target) {
		min = midPoint + 1;
		return binarySearch(userArray, target, sizeOfArray, max, min);
	}
	else if (userArray[midPoint] > target) {
		max = midPoint - 1;
		return binarySearch(userArray, target, sizeOfArray, max, min);
	}

}

void selectionSort(int* userArray, int sizeOfArray) {

	int minIndex = 0;

	for (int i = 0; i < sizeOfArray; i++) {
		minIndex = i;
		for (int j = i + 1; j < sizeOfArray; j++) {
			if (userArray[minIndex] != userArray[j]) {
				if (userArray[minIndex] > userArray[j]) {
					minIndex = j;
				}
			}
		}
		swap(userArray, minIndex, i);
	}
}

int insertionSort(int* userArray, int sizeOfArray) {
	int lowNum = 0;
	int counter = 1;
	while (counter != -1) {
		if (userArray[counter] < userArray[counter - 1]) {
			userArray[counter - 1] = userArray[counter];
		}
	}
	return 0;
}


void swap(int* userArray,int firstIndex,int secondIndex) {
	int temp;
	temp = userArray[firstIndex];
	userArray[firstIndex] = userArray[secondIndex];
	userArray[secondIndex] = temp;

	return;
}

void printArray(int* userArray, int sizeOfArray) {
	for (int i = 0; i < sizeOfArray; i++) {
		printf("%d ", userArray[i]);
	}
	printf("\n");

}