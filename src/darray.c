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
  //int *dynamicArray;?
  size_t size;
};

/*
 * Create an empty darray object of size 0 and return a pointer to it. If the
 * creation should fail, return NULL.
 */
darray *da_create() {

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
    return 1; // I get error when I try to return NULL here
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
  int newSize = 1;
  int *array = realloc(array, newSize * sizeof(int)); // array = (int *) realloc(array, 1 * sizeof(int))?

  // If succeed, place value within the newly created spot
  if (array != NULL) {
    int array[original_size + 1] = value; // I want to do something like this
  }

  // If fails or array pointer is null, return 0
  else {
    free(array);
    return 0;
  }

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
