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
//<param name = "int sizeOfArray">This variable contains the size of the array.</param>
//<return>The return value contains the index of the target the user is looking for.</return>
int searchByBinary(int* userArray, int target, int sizeOfArray);

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
	int userArray[4] = { 4,7,3,1 };
	int target = 3;
	char userChoice[100];
	int counter = 0;
	int sizeOfArray = sizeof(userArray)/sizeof(userArray[0]);
	char userOption[2];
	int min = 0;
	int max = sizeOfArray - 1;

	printf("Thank you for choosing search by linear.");
	printf("\nThe array is: ");
	printArray(userArray, sizeOfArray);
	printf("\nThe index of the target(3) you are looking for is: ");
	searchByLinear(userArray, target, sizeOfArray);

	printf("\nThank you for choosing search by binary.");
	
	searchByBinary(userArray, target, sizeOfArray, max, min);

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

int searchByBinary(int* userArray, int target, int sizeOfArray) {
	
	int min = 0;
	int max = sizeOfArray-1;
	int midPoint = (max+min) / 2;
	int resultIndex;
	printf("\nThe oiriginal array is: ");
	printArray(userArray, sizeOfArray);
	sortBySelection(userArray, sizeOfArray);
	
	if (userArray[midPoint] == target) {
		printf("The sorted array is: ");
		printArray(userArray, sizeOfArray);
		printf("\n");
		printf("The index of the target(3) you are looking for is: %d\n",midPoint);
		
	}
	else if (userArray[midPoint] < target) {
		min = midPoint + 1;
		return searchByBinary(userArray, target, sizeOfArray, max, min);
	}
	else if (userArray[midPoint] > target) {
		max = midPoint - 1;
		return searchByBinary(userArray, target, sizeOfArray, max, min);
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