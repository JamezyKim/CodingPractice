#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int linearSearch(int userSize, int* userArray);
int binarySearch(int userSize, int* userArray);

int main() {
    char userOption[100] = {4,7,3,1};
    int userSize;
    int* userArray = (int*)malloc(userSize * sizeof(int));

    printf("Which search do you want to use? ");
    scanf_s("%s", &userSearchChoice, (unsigned int)_countof(userSearchChoice));

    printf("Please tell me the size of the array: ");
    scanf_s("%s", &userSize, (unsigned int)_countof(userSize));


    if (strcmp(userSearchChoice, "linearSearch") == 0 || strcmp(userSearchChoice, "linear search") == 0 || strcmp(userSearchChoice, "linear") == 0) {
        linearSearch(userSize, userArray);
    }
    else if (strcmp(userSearchChoice, "binarySearch") == 0 || strcmp(userSearchChoice, "binary search") == 0 || strcmp(userSearchChoice, "binary") == 0) {
        binarySearch(userSize, userArray);
    }

    return 0;
}

int linearSearch() {

    return 0;
}

int selectionSort(char userOption) {

    return 0;
}

//int binarySearch(int userSize, int* userArray) {
//    printf("You chose binary search.\n");
//
//    printf("Please tell me the array elements and the number you want to search:\n");
//    for (int i = 0; i < userSize; i++) {
//        scanf_s("%d", &userArray[i]);
//    }
//
//    int target;
//    int targetIndex = -1;
//    int isFound;
//    int lowNum = 0;
//    int highNum = userSize - 1;
//    int midpoint = (highNum - lowNum) / 2;
//    int midpointOfArray = userArray[midpoint];
//
//    printf("Tell me the element you want to search");
//    scanf_s("%d", &target);
//    while (lowNum < highNum) {
//        if (midpointOfArray == target) {
//            targetIndex = midpoint;
//            printf("The index of the target is %d", midpoint);
//            break;
//        }
//        else if (midpointOfArray < midpoint) {
//
//        }
//    }
//
//
//    return 0;
//}


