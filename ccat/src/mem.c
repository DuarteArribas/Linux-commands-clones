#include<stdio.h>
#include<stdlib.h>
#include"mem.h"

/**
 * Handles malloc allocation
 * @param size the initial size of the array
 * @return the pointer to the new array
 */
void *memalloc(size_t size){
  void *temp=malloc(size);
  if(temp==NULL){
    fprintf(stderr,"ERROR: Could not allocate memory!\n");
    exit(MEMORY_ERROR);
  }
  return temp;
}

/**
 * Handles realloc allocation
 * @param *ptr the pointer to the array
 * @param newSize the new size of the array
 * @return the pointer to the new array
 */
void *memrealloc(void *ptr,size_t newSize){
  void *temp=realloc(ptr,newSize);
  if(temp==NULL){
    fprintf(stderr,"ERROR: Could not reallocate memory!\n");
    exit(MEMORY_ERROR);
  }
  return temp;
}

/**
 * Handles realloc allocation
 * @param *ptr the pointer to the array
 * @param *size size of the previous array to increase by 1
 * @param typeSize the size of the type
 * @return the pointer to the new array
 */
void *memreallocp(void *ptr,size_t *size,size_t typeSize){
  ++(*size);
  void *temp=realloc(ptr,*size*typeSize);
  if(temp==NULL){
    fprintf(stderr,"ERROR: Could not reallocate memory!\n");
    exit(MEMORY_ERROR);
  }
  return temp;
}

/**
 * Handles realloc allocation
 * @param *ptr the pointer to the array
 * @param *size size of the previous array to decrease by 1
 * @param typeSize the size of the type
 * @return the pointer to the new array
 */
void *memreallocm(void *ptr,size_t *size,size_t typeSize){
  --(*size);
  void *temp=realloc(ptr,*size*typeSize);
  if(temp==NULL){
    fprintf(stderr,"ERROR: Could not reallocate memory!\n");
    exit(MEMORY_ERROR);
  }
  return temp;
}

/**
 * Frees and clears memory spaces
 * @param *ptr the pointer to the memory box
 */
void clearMemory(void *ptr){
  free(ptr);
  ptr=NULL;
}