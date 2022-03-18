#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<unistd.h>
#include"mem.h"

bool handleFlags(size_t *numOfFlags,char **flags,int argc,char **argv){
  for(register size_t flag=1;flag<(size_t)argc;flag++){
    if(argv[flag][0]=='-'){
      if(strlen(argv[flag])<2){
        (*flags)[*numOfFlags-1]=argv[flag][0];
        *flags=memreallocp(*flags,numOfFlags,sizeof(char));
        (*flags)[*numOfFlags-1]='\0';
        return true;
      }
      for(register size_t i=1;i<strlen(argv[flag]);i++){
        (*flags)[*numOfFlags-1]=argv[flag][i];
        *flags=memreallocp(*flags,numOfFlags,sizeof(char));
      }
    }
  }
  (*flags)[*numOfFlags-1]='\0';
  return false;
}

bool checkExistenceOfFiles(int argc,char **argv,char **file,bool *fromSTDIN){
  bool isFromStdIn=true;
  for(size_t i=1;i<(size_t)argc;i++){
    if(argv[i][0]!='-'){
      isFromStdIn=false;
      if(access(argv[i],F_OK)!=0){
        *file=memrealloc(*file,(strlen(argv[i])+1)*sizeof(char));
        strcpy(*file,argv[i]);
        return false;
      }
    }
  }
  if(isFromStdIn){
    *fromSTDIN=true;
  }
  return true;
}