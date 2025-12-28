#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n) {
    int emptyLeft, emptyRight, i;
    for(i=0; i < flowerbedSize && n>0; i++){
        if(flowerbed[i] == 0){
            emptyLeft = ( i == 0) || (flowerbed[i-1] == 0);
            emptyRight = (i == (flowerbedSize - 1)) || (flowerbed[i+1] == 0);

            if(emptyLeft && emptyRight){
                n--;
                flowerbed[i] = 1;
            }
        }
    }
       
    return n==0;

}