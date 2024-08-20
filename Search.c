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
int sortBySelection(int* userArray, int sizeOfArray);

//<summary>The system repeatedly divides the search interval in half, 
// reducing the number of comparison of the array to find the target.</summary>
//<param name = "int* userArray">This is the int pointer that connects to the array in the main function. </param>
//<param name = "int target">The parameter contains the target value of the user.</param>
//<return>The return value contains the index of the target the user is looking for.</return>
int searchByBinary(int* userArray, int target, int min, int max);

//<summary>This system repeatedly loop and compare the current element and the element before it.
// If the previous element is bigger than the current element, they swap until the array sorts.</summary>
//<param name = "int* userArray">This is the int pointer that connects to the array in the main function. </param>
//<param name = "int sizeOfArray">This variable contains the size of the array.</param>
//<return>none</return>
int sortByInsertion(int* userArray, int sizeOfArray);

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
int printArray(int* userArray, int sizeOfArray);

void testSearchByLinear();
void negativeSizeOfArraySearchByLinear();
void idealSearchByLinearReturnTargetIndex();
void noSizeOfArraySearchByLinear();
void hundredSizeOfArraySearchByLinear();
void findTheFirstIndexSearchByLinear();

void testSearchByBinary();
void negativeSizeOfArraySearchByBinary();
void idealSearchByBinaryReturnTargetIndex();
void noSizeOfArraySearchByBinary();
void hundredSizeOfArraySearchByBinary();
void findTheFirstIndexSearchByBinary();

void testSortBySelection();
void idealSortBySelection();
void noSizeOfArraySortBySelection();
void alreadySortedBySelection();
void duplicatedElementsSortBySelection();
void oneElementsSortBySelection();

void testSortByInsertion();
void idealSortByInsertion();
void noSizeOfArraySortByInsertion();
void alreadySortedByInsertion();
void manyElementsSortByInsertion();
void oneElementsSortByInsertion();

void testPrintArray();
void idealPrintArray();
void noPrintArray();
void manyPrintArray();
void singlePrintArray();
void duplicatedPrintArray();


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
	char doesUserQuit[10];
	int isFound = -1;
	
	//while (1) {
	//	printf("Hi, welcome to Search program. \nYou would choose either the linear search and the binary search.\n");
	//	printf("\nIf you want to quit, please press -1. \nOtherwise, please tell me the size of the array.");
	//	printf("\nThe maximum size is 100: ");

	//	scanf_s("%s", &userInputSizeOfArray, (unsigned int)_countof(userInputSizeOfArray));
	//	sizeOfArray = atoi(userInputSizeOfArray);
	//	index = sizeOfArray;

	//	if (sizeOfArray == -1) {
	//		printf("Ok, see you again. Good bye!\n");
	//		return 0;
	//	}
	//	if (sizeOfArray >= 100) {
	//		printf("Sorry, you have to enter a number smaller than 100\n");
	//		return 0;
	//	}

	//	printf("\nThe size of the array is %d\n", sizeOfArray);

	//	while (index > 0) {
	//		printf("Please enter your %dst number: ", sizeOfArray - index + 1);
	//		scanf_s("%s", &userChoice, (unsigned int)_countof(userChoice));
	//		userArray[sizeOfArray - index] = atoi(userChoice);
	//		index--;
	//	}
	//	printf("\n");

	//	printf("Great! Now please tell me your target!: ");
	//	scanf_s("%s", &userInputTarget, (unsigned int)_countof(userChoice));
	//	target = atoi(userInputTarget);


	//	for (int i = 0; i < sizeOfArray; i++) {
	//		if (target == userArray[i]) {
	//			isFound = 1;
	//		}
	//	}

	//	if (isFound != 1) {
	//		printf("\nSorry, the target you chose does not exist in the array.\n");
	//		printf("Press 'y', if you want to continue the search.\n");
	//		printf("Else, press any other keyboard: ");
	//		scanf_s("%s", &doesUserQuit, (unsigned int)_countof(doesUserQuit));
	//		if (strcmp(doesUserQuit, "y") == 0) {
	//			printf("\n");
	//			printf("Ok, I will bring you to the main menu.\n\n");
	//			continue;
	//		}
	//		else {
	//			printf("Ok, good bye!");
	//			return 0;
	//		}
	//	}


	//	printf("\nWhich search do you want to use?\n");
	//	printf("The first option: Linear Search\n");
	//	printf("The second option: Binary Search.\n");
	//	printf("Enter 'linear' for linear search, and 'binary' for binary search: ");
	//	scanf_s("%s", searchOption, (unsigned int)_countof(userChoice));
	//	if (strcmp(searchOption, "linear") == 0) {
	//		printf("\nThank you for choosing search by linear.");
	//		printf("\nThe array is: ");
	//		printArray(userArray, sizeOfArray);
	//		printf("\nThe index of the target(%d) you are looking for is: ", target, resultOfSearchByLinear);
	//		searchByLinear(userArray, target, sizeOfArray);
	//		printf("\n\n");
	//	}
	//	else if (strcmp(searchOption, "binary") == 0) {
	//		printf("\nThank you for choosing search by binary.");
	//		printf("\nThe oiriginal array is: ");
	//		printArray(userArray, sizeOfArray);
	//		printf("The sorted array is: ");
	//		sortByInsertion(userArray, sizeOfArray);
	//		printArray(userArray, sizeOfArray);
	//		printf("\n");
	//		resultOfSearchByBinary = searchByBinary(userArray, target, 0, sizeOfArray - 1);
	//		printf("The index of the target(%d) you are looking for is: %d \n\n", target, resultOfSearchByBinary);
	//	}

	//}
	testSearchByLinear();
	testSearchByBinary();
	testSortBySelection();
	testSortByInsertion();
	testPrintArray();
	return 0;
}



int searchByLinear(int* userArray,int target, int sizeOfArray) {

	if (sizeOfArray < 0) {
		return -1;
	}

	if (sizeOfArray >= 100) {
		return -1;
	}

	for (int i = 0; i < sizeOfArray; i++) {
		if (target == userArray[i]) {
			printf("%d\n", i);
			return i;
		}
	}

	return 0;
}

int searchByBinary(int* userArray, int target, int min, int max) {
	
	if (min > max) {
		return -1;
	}

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

int sortBySelection(int* userArray, int sizeOfArray) {

	if (sizeOfArray <= 0) {
		return -1;
	}
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
	return 0;
}

int sortByInsertion(int* userArray, int sizeOfArray) {

	if (sizeOfArray <= 0) {
		return -1;
	}

	for (int i = 0; i < sizeOfArray; i++) {
		for (int j = i - 1; j > 0; j--) {
			if (userArray[j] < userArray[j - 1]) {
				swap(userArray, j, j - 1);
			}
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

int printArray(int* userArray, int sizeOfArray) {
	for (int i = 0; i < sizeOfArray; i++) {
		printf("%d ", userArray[i]);
	}
	printf("\n");

	return 0;
}




















void testSearchByLinear() {
	idealSearchByLinearReturnTargetIndex();
	negativeSizeOfArraySearchByLinear();
	noSizeOfArraySearchByLinear();
	hundredSizeOfArraySearchByLinear();
	findTheFirstIndexSearchByLinear();
	printf("\n\n");
}

void testSearchByBinary() {
	idealSearchByBinaryReturnTargetIndex();
	negativeSizeOfArraySearchByBinary();
	noSizeOfArraySearchByBinary();
	hundredSizeOfArraySearchByBinary();
	findTheFirstIndexSearchByBinary();
	printf("\n\n");
}

void testSortBySelection() {
	idealSortBySelection();
	noSizeOfArraySortBySelection();
	alreadySortedBySelection();
	duplicatedElementsSortBySelection();
	oneElementsSortBySelection();
	printf("\n\n");
}

void testSortByInsertion() {
	idealSortByInsertion();
	noSizeOfArraySortByInsertion();
	alreadySortedByInsertion();
	oneElementsSortByInsertion();
	manyElementsSortByInsertion();
	printf("\n\n");
}

void testPrintArray() {
	idealPrintArray();
	noPrintArray();
	manyPrintArray();
	singlePrintArray();
	duplicatedPrintArray();
	printf("\n\n");
}

void duplicatedPrintArray() {
	//arrange
	int userArray[] = { 10 };
	int sizeOfArray = 1;
	int expectedResult = 0;

	//act
	int actualResult = printArray(userArray, sizeOfArray);


	//assert
	if (expectedResult == actualResult) {
		printf("duplicatedPrintArray: passed");
	}
	else {
		printf("duplicatedPrintArray: passed");
	}

	return;
}

void singlePrintArray() {
	//arrange
	int userArray[] = {10};
	int sizeOfArray = 1;
	int expectedResult = 0;

	//act
	int actualResult = printArray(userArray, sizeOfArray);


	//assert
	if (expectedResult == actualResult) {
		printf("singlePrintArray: passed");
	}
	else {
		printf("singlePrintArray: passed");
	}

	return;
}

void manyPrintArray() {
	//arrange
	int userArray[] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 };
	int sizeOfArray = 20;
	int expectedResult = 20;

	//act
	int actualResult = printArray(userArray, sizeOfArray);


	//assert
	if (expectedResult == actualResult) {
		printf("idealPrintArray: passed");
	}
	else {
		printf("idealPrintArray: passed");
	}

	return;
}

void idealPrintArray() {
	//arrange
	int userArray[] = { 1,2,3 };
	int sizeOfArray = 3;
	int expectedResult = 0;


	//act
	int actualResult = printArray(userArray, sizeOfArray);


	//assert
	if (expectedResult == actualResult) {
		printf("idealPrintArray: passed");
	}
	else {
		printf("idealPrintArray: passed");
	}

	return;
}

void noPrintArray() {
	//arrange
	int sizeOfArray = 0;
	int userArray[] = {0};
	int expectedResult = 0;


	//act
	int actualResult = printArray(userArray, sizeOfArray);


	//assert
	if (expectedResult == actualResult) {
		printf("noPrintArray: passed");
	}
	else {
		printf("noPrintArray: passed");
	}

	return;
}

void manyElementsSortByInsertion() {
	//arrange
	int sizeOfArray = 20;
	int userArray[] = { 2,19,18,11,7,17,9,4,20,6,14,12,1,13,8,5,3,15,16,10 };
	int expectedResult[] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 };

	//act
	int isPassed = 1;
	int actualResult = sortBySelection(userArray, sizeOfArray);

	for (int i = 0; i < sizeOfArray; i++) {
		if (userArray[i] != expectedResult[i]) {
			isPassed = 0;
			printf("manyElementsSortByInsertion: failed\n");
		}
	}

	//assert
	if (isPassed) {
		printf("manyElementsSortByInsertion: passed\n");
	}

	else {
		printf("idealSortByInsertionReturnTargetIndex: failed\n");
	}
	return;
}

void oneElementsSortByInsertion() {
	//arrange
	int sizeOfArray = 1;
	long long userArray[] = { 1 };
	long long expectedResult[] = { 1 };

	//act
	int isPassed = 1;
	int actualResult = sortByInsertion(userArray, sizeOfArray);

	for (int i = 0; i < sizeOfArray; i++) {
		if (userArray[i] != expectedResult[i]) {

			isPassed = 0;
			printf("oneElementsSortByInsertion: failed\n");
		}
	}

	//assert
	if (isPassed) {
		printf("oneElementsSortByInsertion: passed\n");
	}

	else {
		printf("oneElementsSortByInsertion: failed\n");
	}
	return;
}

void duplicatedElementsSortBySelection() {
	//arrange
	int sizeOfArray = 4;
	int userArray[] = { 2,1,3,1 };
	int expectedResult[] = { 1, 1, 2, 3 };

	//act
	int isPassed = 1;
	int actualResult = sortBySelection(userArray, sizeOfArray);

	for (int i = 0; i < sizeOfArray; i++) {
		if (userArray[i] != expectedResult[i]) {
			isPassed = 0;
			printf("duplicatedElementsSortBySelection: failed\n");
		}
	}

	//assert
	if (isPassed) {
		printf("duplicatedElementsSortBySelection: passed\n");
	}

	else {
		printf("duplicatedElementsSortBySelection: failed\n");
	}
	return;
}

void alreadySortedByInsertion() {
	//arrange
	int sizeOfArray = 3;
	int userArray[] = { 1,2,3 };
	int expectedResult[] = { 1, 2, 3 };

	//act
	int isPassed = 1;
	int actualResult = sortByInsertion(userArray, sizeOfArray);

	for (int i = 0; i < sizeOfArray; i++) {
		if (userArray[i] != expectedResult[i]) {
			isPassed = 0;
			printf("alreadySortedByInsertion: failed");
		}
	}

	//assert
	if (isPassed) {
		printf("alreadySortedByInsertion: passed\n");
	}

	else {
		printf("alreadySortedByInsertion: failed\n");
	}
	return;
}




void idealSortByInsertion() {
	//arrange
	int sizeOfArray = 3;
	int userArray[] = { 2,1,3 };
	int expectedResult[] = { 1, 2, 3 };

	//act
	int isPassed = 1;
	int actualResult = sortBySelection(userArray, sizeOfArray);

	for (int i = 0; i < sizeOfArray; i++) {
		if (userArray[i] != expectedResult[i]) {
			isPassed = 0;
			printf("idealSortByInsertionReturnTargetIndex: failed\n");
		}
	}

	//assert
	if (isPassed) {
		printf("idealSortByInsertionReturnTargetIndex: passed\n");
	}

	else {
		printf("idealSortByInsertionReturnTargetIndex: failed\n");
	}
	return;
}

void noSizeOfArraySortByInsertion() {
	//arrange
	int sizeOfArray = 0;
	int userArray[] = { 2,1,3 };
	int sortedArray[] = { 1,2,3 };
	int expectedResult = -1;

	//act
	int actualResult = sortBySelection(userArray, sizeOfArray);


	//assert
	if (actualResult == expectedResult) {
		printf("noSizeOfArraySortByInsertion: passed\n");
	}

	else {
		printf("noSizeOfArraySortByInsertion: failed\n");
	}
	return;
}

void idealSortBySelection() {
	//arrange
	int sizeOfArray = 3;
	int userArray[] = { 2,1,3 };
	int expectedResult[] = {1, 2, 3};

	//act
	int isPassed = 1;
	int actualResult = sortBySelection(userArray, sizeOfArray);

	for (int i = 0; i < sizeOfArray; i++) {
		if (userArray[i] != expectedResult[i]) {
			isPassed = 0;
			printf("idealSortBySelectionReturnTargetIndex: failed");
		}
	}

	//assert
	if (isPassed) {
		printf("idealSortBySelectionReturnTargetIndex: passed\n");
	}

	else {
		printf("idealSortBySelectionReturnTargetIndex: failed\n");
	}
	return;
}

void noSizeOfArraySortBySelection() {
	//arrange
	int sizeOfArray = 0;
	int userArray[] = { 2,1,3 };
	int sortedArray[] = {1,2,3};
	int expectedResult = -1;

	//act
	int actualResult = sortBySelection(userArray, sizeOfArray);


	//assert
	if (actualResult == expectedResult) {
		printf("noSizeOfArraySortBySelection: passed\n");
	}

	else {
		printf("noSizeOfArraySortBySelection: failed\n");
	}
	return;
}


void oneElementsSortBySelection() {
	//arrange
	int sizeOfArray = 1;
	int userArray[] = { 1 };
	int expectedResult[] = { 1 };

	//act
	int isPassed = 1;
	int actualResult = sortBySelection(userArray, sizeOfArray);

	for (int i = 0; i < sizeOfArray; i++) {
		if (userArray[i] != expectedResult[i]) {
		
			isPassed = 0;
			printf("oneElementsSortBySelection: failed\n");
		}
	}

	//assert
	if (isPassed) {
		printf("oneElementsSortBySelection: passed\n");
	}

	else {
		printf("oneElementsSortBySelection: failed\n");
	}
	return;
}



void alreadySortedBySelection() {
	//arrange
	int sizeOfArray = 3;
	int userArray[] = { 1,2,3 };
	int expectedResult[] = { 1, 2, 3 };

	//act
	int isPassed = 1;
	int actualResult = sortBySelection(userArray, sizeOfArray);

	for (int i = 0; i < sizeOfArray; i++) {
		if (userArray[i] != expectedResult[i]) {
			isPassed = 0;
			printf("alreadySortedBySelection: failed");
		}
	}

	//assert
	if (isPassed) {
		printf("alreadySortedBySelection: passed\n");
	}

	else {
		printf("alreadySortedBySelection: failed\n");
	}
	return;
}


void idealSearchByLinearReturnTargetIndex() {
	//arrange
	int sizeOfArray = 3;
	int userArray[] = { 1,2,3 };
	int target = 2;
	int expectedResult = 1;
	

	//act
	int actualResult = searchByLinear(userArray, target, sizeOfArray);

	//assert

	if (expectedResult == actualResult) {
		printf("idealSearchByLinearReturnTargetIndex: pass\n");
	}
	else {
		printf("idealSearchByLinearReturnTargetIndex: failed\n");
	}
	return;
}

void negativeSizeOfArraySearchByLinear() {

	//arrange
	int sizeOfArray = -1;
	int* userArray[] = {1,2,3};
	int target = 2;

	//act
	int expectedResult = -1;

	//assert
	if (expectedResult == searchByLinear(userArray, target, sizeOfArray)) {
		printf("negativeSizeOfArraySearchByLinear: passed\n");
	}
	else {
		printf("negativeSizeOfArraySearchByLinear: failed\n");
	}


	return;
}

void noSizeOfArraySearchByLinear() {
	//arranage
	int sizeOfArray = 0;
	int* userArray = NULL;
	int target = NULL;

	//act
	int expectedResult = NULL;

	//assert
	if (expectedResult == searchByLinear(userArray, target, sizeOfArray)) {
		printf("noSizeOfArraySearchByLinear: passed\n");
	}
	else {
		printf("noSizeOfArraySearchByLinear: failed\n");
	}


	return;
}

void hundredSizeOfArraySearchByLinear() {
	//arranage
	int sizeOfArray = 100;
	int* userArray[100] = {3};
	int target = 3;

	//act
	int expectedResult = -1;

	//assert
	if (expectedResult == searchByLinear(userArray, target, sizeOfArray)) {
		printf("hundredSizeOfArraySearchByLinear: passed\n");
	}
	else {
		printf("hundredSizeOfArraySearchByLinear: failed\n");
	}


	return;
}

void findTheFirstIndexSearchByLinear() {
	//arranage
	int sizeOfArray = 4;
	int* userArray[100] = { 0,4,7,1 };
	int target = 0;


	//act
	int expectedResult = 0;

	//assert
	if (expectedResult == searchByLinear(userArray, target, sizeOfArray)) {
		printf("findTheFirstIndexSearchByLinear: passed\n");
	}
	else {
		printf("findTheFirstIndexSearchByLinear: failed\n");
	}


	return;
}





void idealSearchByBinaryReturnTargetIndex() {
	//arrange
	int sizeOfArray = 3;
	int userArray[3] = { 1,2,3 };
	int target = 2;
	int expectedResult = 1;
	int min = 0;
	int max = sizeOfArray - 1;


	//act
	int actualResult = searchByBinary(userArray, target, min, max);

	//assert

	if (expectedResult == actualResult) {
		printf("idealSearchByBinaryReturnTargetIndex: pass\n");
	}
	else {
		printf("idealSearchByBinaryReturnTargetIndex: failed\n");
	}
	return;
}

void negativeSizeOfArraySearchByBinary() {

	//arrange
	int sizeOfArray = -1;
	int userArray[3] = { 1,2,3 };
	int target = 2;
	int min = 0;
	int max = sizeOfArray - 1;

	//act
	int expectedResult = -1;

	//assert
	if (expectedResult == searchByBinary(userArray, target, min, max)) {
		printf("negativeSizeOfArraySearchByBinary: passed\n");
	}
	else {
		printf("negativeSizeOfArraySearchByBinary: failed\n");
	}


	return;
}

void noSizeOfArraySearchByBinary() {
	//arranage
	int sizeOfArray = 0;
	int userArray = NULL;
	int target = 0;
	int min = 0;
	int max = sizeOfArray - 1;

	//act
	int expectedResult = -1;

	//assert
	if (expectedResult == searchByBinary(userArray, target, min, max)) {
		printf("noSizeOfArraySearchByBinary: passed\n");
	}
	else {
		printf("noSizeOfArraySearchByBinary: failed\n");
	}


	return;
}

void hundredSizeOfArraySearchByBinary() {
	//arranage
	int sizeOfArray = 100;
	int userArray[100] = { 3 };
	int target = 3;
	int min = 0;
	int max = sizeOfArray - 1;

	//act
	int expectedResult = -1;

	//assert
	if (expectedResult == searchByBinary(userArray, target, min, max)) {
		printf("hundredSizeOfArraySearchByBinary: passed\n");
	}
	else {
		printf("hundredSizeOfArraySearchByBinary: failed\n");
	}


	return;
}

void findTheFirstIndexSearchByBinary() {
	//arranage
	int sizeOfArray = 4;
	int userArray[4] = { 0,4,7,1 };
	int target = 0;
	int min = 0;
	int max = sizeOfArray - 1;

	//act
	int expectedResult = 0;

	//assert
	if (expectedResult == searchByBinary(userArray, target, min, max)) {
		printf("findTheFirstIndexSearchByBinary: passed\n");
	}
	else {
		printf("findTheFirstIndexSearchByBinary: failed\n");
	}


	return;
}

