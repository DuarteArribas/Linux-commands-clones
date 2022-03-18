#include<string.h>
#include<stdbool.h>
#include"ccat.h"
bool binarySearch(char character,char array[]){
  for(register size_t i=0;i<ACCEPTED_FLAGS;i++){
    if(array[i]==character){
      return true;
    }
  }
  return false;
}

void shiftRight(char *vector,size_t vectorSize,size_t index){
  size_t temp=vectorSize;
  for(;temp>index;temp--){
    if(temp!=1){
      vector[temp-1]=vector[temp-2];
    }
  }
}