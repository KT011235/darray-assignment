/*
 * darray.c
 * A simple dynamic array for storing integers
 *
 * Copyright (C) 2024 Douglas Rumbaugh <dbrumbaugh@harrisburgu.edu>
 *
 * Distributed under the Modified BSD License.
 */
#include "darray.h"

struct darray {
  /* your attributes go here */
  int *dynamicArray;
  size_t size;
};

/*
 * Create an empty darray object of size 0 and return a pointer to it. If the
 * creation should fail, return NULL.
 */
darray *da_create() {

  int numElements = 1; //確保する要素数
  // Allocate memory
  darray *array = malloc(sizeof(darray)); // this is same as doing self._darray = [] in Python
  array -> dynamicArray = calloc(numElements, sizeof(int));

  // If creation fails, return NULL
  if (array == NULL) {
    printf("Failed to allocate memory. \n");
    return NULL; // I get error when I try to return NULL here
  }
}

/*
 * Access the element stored at index idx within the darray and return a
 * pointer to it. If the idx is out of range for the darray, return NULL
 * instead. If the provided array pointer is NULL, return NULL.
 */
int *da_get(darray *array, size_t idx) {
  
  int *ptr;

  // If the array pointer is NULL, return NULL
  if (array == NULL){
      return NULL;
  }
  /* If the idx is out of range, return NULL*/
  if (idx > (sizeof array)){
      return NULL;
  }
  /* Return a pointer to the index*/
  ptr = array;
  return ptr[idx];
}

/*
 * Increase the length of array by 1 and place value within the newly created
 * spot. If the append operation fails, return 0. Otherwise return 1. Return 0
 * also if the provided array pointer is null.
 */
int da_append(darray *array, int value) {

  // Change the length of array by 1
  int newSize = array->size + 1; // new_size = old_size + 1 (array->sizeは、darray構造体に格納されている今の配列の要素数)
  int *newArray = realloc((*array).dynamicArray, newSize * sizeof(int)); //メモリを再割り当てするのはdynamicArrayに対して

  // If operation fails, return 0
  if (newArray == NULL) {
    return 0;
  }
  // If succeed, place value within the newly created spot
  (*array).dynamicArray[(*array).size] = value; // array[old_size+1]

  // Update its size
  (*array).size = newSize; // newSizeは、配列のインデックスではなく、新しいサイズ

  // Otherwise, return 1
  return 1;
}

/*
 * Returns the size of the array. Note that this size should be the accessible
 * size (using get, for example), not the physical size of the allocation,
 * which may be larger. If array is NULL, return 0.
 */
size_t da_size(darray *array) {

  // If array is NULL, return 0
  if (array == NULL) {
    return 0;
  }

  //　Accessible size of the array
  return (array -> size);
}

/*
 * Free all the allocated memory associated with array. If array is NULL, do
 * nothing.
 */
void da_delete(darray *array) {

  //free all the memory
  free(array);
  return 0;
}