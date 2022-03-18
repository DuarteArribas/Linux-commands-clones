#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<inttypes.h>
#include<string.h>
#include"ccat.h"
#include"mem.h"
#include"flagHandling.h"
#include"binarySearch.h"
#include"ccatFunctions.h"

static char acceptedFlags[ACCEPTED_FLAGS]={'A','b','E','n','T','h','v','-'};
int main(int argc,char **argv){
  //handle flags
  size_t numOfFlags=1;
  char *flags=memalloc(numOfFlags*sizeof(char));
  bool wrongInput=handleFlags(&numOfFlags,&flags,argc,argv);
  bool fromSTDIN=false;
  if(wrongInput){
    wrongInput=false;
    fromSTDIN=true;
  }
  char invalidChar;
  for(register size_t i=0;i<strlen(flags);i++){
    if(!binarySearch(flags[i],acceptedFlags)){
      invalidChar=flags[i];
      wrongInput=true;
      break;
    }
  }
  if(wrongInput){
    fprintf(stderr,"ccat: invalid option '%c'\nTry 'ccat -h' for more information.\n",invalidChar);
    exit(INVALID_INPUT);
  }
  char *file=memalloc(sizeof(char));
  const bool filesExist=checkExistenceOfFiles(argc,argv,&file,&fromSTDIN);
  if(!filesExist){
    fprintf(stderr,"%s: Fatal Error ",file);
    perror(NULL);
    exit(INVALID_INPUT);
  }
  //program handling
  useCat(argc,argv,fromSTDIN,flags);
  //free memory
  clearMemory(flags);
  clearMemory(file);
  return 0;
}