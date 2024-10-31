#include <stdio.h>
#include <stdlib.h>

int main() {
    int numElements = 1; //確保する要素数
    int *dynamicArray;
    // Allocate memory
    dynamicArray = (int *)calloc(numElements, sizeof(int));

    /*int *darray = (int *)malloc(n * sizeof(int));
    int *addr;
    addr = (int*)malloc(4); */

    // If creation fails, return NULL
    if (dynamicArray == NULL) {
        printf("Failed to allocate memory. \n");
        return 1;
    }
    // 確保したメモリの内容を表示
    for (int i = 0; i < numElements; i++) {
        printf("dynamicArray[%d] = %d\n", i, dynamicArray[i]);
    }
    
}