//Authour: Yuntae Kim
//Create date: 2024/8/11
//Modified date: 2024/8/
//<summary>This program enable users to use linear search or binary search
// by using selection sort or insertion sort</summary>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//<summary>This function searches the user's target by looping the array in order.</summary>
//<param name = "int* userArray">This is the int pointer that connects to the array in the main function. </param>
//<param name = "int target">The parameter contains the target value of the user.</param>
//<param name = "int sizeOfArray">This variable contains the size of the array.</param>
//<return>The return value contains the index of the target the user is looking for.</return>
int searchByLinear(int* userArray, int target, int sizeOfArray);

//<summary>This function sorts the array by making a comparison between the current element and the next element and swap
// if the next element is smaller than the current element.</summary>
//<param name = "int* userArray">This is the int pointer that connects to the array in the main function. </param>
//<param name = "int sizeOfArray">This variable contains the size of the array.</param>
//<return>none</return>
void sortBySelection(int* userArray, int sizeOfArray);

//<summary>The system repeatedly divides the search interval in half, 
// reducing the number of comparison of the array to find the target.</summary>
//<param name = "int* userArray">This is the int pointer that connects to the array in the main function. </param>
//<param name = "int target">The parameter contains the target value of the user.</param>
//<return>The return value contains the index of the target the user is looking for.</return>
int searchByBinary(int* userArray, int target, int min, int max);

//<summary></summary>
//<param name = "int* userArray">This is the int pointer that connects to the array in the main function. </param>
//<param name = "int sizeOfArray">This variable contains the size of the array.</param>
//<return>none</return>
void sortByInsertion(int* userArray, int sizeOfArray);

//<summary>The system swaps two elements in order to label the elements in oder.</summary>
//<param name = "int* userArray">This is the int pointer that connects to the array in the main function. </param>
//<param name = "int firstIndex">The element that needs to be changed in order to make the array in order.</param>
//<param name = "int secondIndex">The element that needs to swap with the firstIndex. </param>
//<return>none</return>
void swap(int* userArray, int firstIndex, int secondIndex);

//<summary>The system that prints array to describes the difference between the original array and the sorted array.</summary>
//<param name = "int* userArray">This is the int pointer that connects to the array in the main function. </param>
//<param name = "int sizeOfArray">This variable contains the size of the array.</param>
//<return>none</return>
void printArray(int* userArray, int sizeOfArray);


int main() {
	int userArray[100];
	int target = -99;
	char userChoice[100];
	char userOption[2];
	int resultOfSearchByBinary = -1;
	int resultOfSearchByLinear = -1;
	char userInputSizeOfArray[100];
	char userInputTarget[100];
	int sizeOfArray = 0;
	int index = 0;
	char searchOption[100];

	printf("Please tell me the size of the array. \nThe maximum size is 100: ");
	scanf_s("%s", &userInputSizeOfArray, (unsigned int)_countof(userInputSizeOfArray));
	sizeOfArray = atoi(userInputSizeOfArray);
	index = sizeOfArray;

	if (sizeOfArray >= 100) {
		printf("Sorry, you have to enter a number smaller than 100\n");
		return 0;
	}

	printf("\nThe size of the array is %d\n", sizeOfArray);

	while (index > 0) {
		printf("Please enter your %dst number: ", sizeOfArray-index+1);
		scanf_s("%s", &userChoice, (unsigned int)_countof(userChoice));
		userArray[sizeOfArray-index] = atoi(userChoice);
		index--;
	}
	printf("\n");

	printf("Great! Now please tell me your target!: ");
	scanf_s("%s", &userInputTarget, (unsigned int)_countof(userChoice));
	target = atoi(userInputTarget);

	printf("Which search do you want to use?\n");
	printf("The first option: Linear Search\n");
	printf("The second option: Binary Search.\n"); 
	printf("Enter 'linear' for linear search, and 'binary' for binary search: ");
	scanf_s("%s", searchOption, (unsigned int)_countof(userChoice));
	if (strcmp(searchOption, "linear") == 0) {
		printf("Thank you for choosing search by linear.");
		printf("\nThe array is: ");
		printArray(userArray, sizeOfArray);
		printf("\nThe index of the target(%d) you are looking for is: ", target, resultOfSearchByLinear);
		searchByLinear(userArray, target, sizeOfArray);
	}
	else if (strcmp(searchOption, "binary") == 0) {
		printf("\nThank you for choosing search by binary.");
		printf("\nThe oiriginal array is: ");
		printArray(userArray, sizeOfArray);
		printf("The sorted array is: ");
		sortBySelection(userArray, sizeOfArray);
		printArray(userArray, sizeOfArray);
		printf("\n");
	}

	resultOfSearchByBinary = searchByBinary(userArray, target, 0, sizeOfArray-1);
	printf("The index of the target(%d) you are looking for is: %d \n", target, resultOfSearchByBinary);


	return 0;
}

int searchByLinear(int* userArray,int target, int sizeOfArray) {

	for (int i = 0; i < sizeOfArray; i++) {
		if (target == userArray[i]) {
			printf("%d\n", i);
			return i;
		}
	}

	return 0;
}

int searchByBinary(int* userArray, int target, int min, int max) {
	
	int midPoint = (min+max) / 2;
	
	if (userArray[midPoint] == target) {
		return midPoint;
	}
	else if (userArray[midPoint] < target) {
		return searchByBinary(userArray, target, midPoint+1, max);
	}
	else {
		return searchByBinary(userArray, target, min, midPoint-1);
	}

}

void sortBySelection(int* userArray, int sizeOfArray) {

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

void sortByInsertion(int* userArray, int sizeOfArray) {
	int lowNum = 0;
	int counter = 1;
	while (counter != -1) {
		if (userArray[counter] < userArray[counter - 1]) {
			userArray[counter - 1] = userArray[counter];
		}
	}
	
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