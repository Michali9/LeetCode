/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 // find max in the candies array
 // for each kid i if the new number is greater or equal to the max, put true in the a[i]


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int findMax(int* arr, int size){
    int max = arr[0];
    int i;
    for(i=1; i<size; i++){
        if(max < arr[i]){
            max = arr[i];
        }
    }
    return max;
}
 
bool* kidsWithCandies(int* candies, int candiesSize, int extraCandies, int* returnSize) {
    bool* result = malloc(candiesSize * sizeof(bool));
    int i;
    int max = findMax(candies, candiesSize);
    for(i=0;i<candiesSize; i++){
        if(candies[i]+extraCandies >= max){
            result[i] = true;
        }
        else{
            result[i] = false;
        }
    }
    return result;
}

int main() {
    int candies[] = {2, 3, 5, 1, 3};
    int extraCandies = 3;
    int candiesSize = sizeof(candies) / sizeof(candies[0]);
    int returnSize = candiesSize;
    
    bool* result = kidsWithCandies(candies, candiesSize, extraCandies, &returnSize);
    
    printf("Result: [");
    for(int i = 0; i < returnSize; i++) {
        printf("%s", result[i] ? "true" : "false");
        if(i < returnSize - 1) {
            printf(", ");
        }
    }
    printf("]\n");
    
    free(result);
    return 0;
}