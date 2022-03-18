#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<inttypes.h>
#include<string.h>
#include"binarySearch.h"
#include"mem.h"

void useCat(int argc,char **argv,bool fromSTDIN,char *flags){
  //flag h
  if(strchr(flags,'h')){
    fputs("NAME\n",stdout);
    fputs("\tccat-display the contents of text.\n\n",stdout);
    fputs("SYNOPSIS\n",stdout);
    fputs("\tccat [__OPTIONS__] [__FILE__...]\n\n",stdout);
    fputs("OPTIONS\n",stdout);
    fputs("\t-A   equivalent to -ET\n",stdout);
    fputs("\t-b   print numbers before lines, but not on empty lines. Cannot be used when the `-n` option is being used.\n",stdout);
    fputs("\t-E   print a $ at the end of every line.\n",stdout);
    fputs("\t-n   print numbers before every line. Cannot be used when the `-b` option is being used.\n",stdout);
    fputs("\t-T   display tab characters as ^I\n",stdout);
    fputs("\t-h   show the help guide\n",stdout);
    fputs("\t-v   show the version of the software\n",stdout);
    fputs("DESCRIPTION\n",stdout);
    fputs("\tThe program can be executed by giving it one or more files (which will be concatenated), which will be \n\tdisplayed to the standard output If no, file is given, or the `-` option is provided, the program will\n\tread input from the standard input instead of from a file, outputting the contents to the standard output too.\n\tIt's based on the Unix cat program available on unix based systems, with some slight differences.\n\n",stdout);
    fputs("EXAMPLES\n",stdout);
    fputs("\tccat file\n",stdout);
    fputs("\tccat\n\n",stdout);
    fputs("AUTHOR\n",stdout);
    fputs("\tWritten by Duarte Arribas\n\n",stdout);
    exit(0);
  }
  //flag v
  if(strchr(flags,'v')){
    fputs("ccat (Cat clone) 1.7.1\n=====================\nWritten by Duarte Arribas\n",stdout);
    exit(0);
  }
  size_t numOfCharacters=1;
  char *fileText=memalloc(sizeof(char));
  char fileText2[1000];
  if(!fromSTDIN){
    FILE *file;
    for(size_t i=1;i<(size_t)argc;i++){
      if(argv[i][0]!='-'){
        file=fopen(argv[i],"r");
        while(true){
          if(feof(file)!=0){
            break;
          }
          fileText[numOfCharacters-1]=fgetc(file);
          fileText=memreallocp(fileText,&numOfCharacters,sizeof(char));
        }
      }
    }
    fileText=memreallocm(fileText,&numOfCharacters,sizeof(char));
    fileText[numOfCharacters-1]='\0';
    //flag E
    if(strchr(flags,'A')||strchr(flags,'E')){
      for(size_t i=0;i<numOfCharacters;i++){
        if(fileText[i]=='\n'){
          fileText=memreallocp(fileText,&numOfCharacters,sizeof(char));
          shiftRight(fileText,numOfCharacters,i);
          fileText[i]='$';
          i++;
        }
      }
    }
    //flag T
    if(strchr(flags,'A')||strchr(flags,'T')){
      for(size_t i=0;i<numOfCharacters;i++){
        if(fileText[i]=='\t'){
          fileText=memreallocp(fileText,&numOfCharacters,sizeof(char));
          shiftRight(fileText,numOfCharacters,i);
          fileText[i]='^';
          fileText[i+1]='I';
          i++;
        }
      }
    }
    //flag n
    size_t newLine=1;
    if(strchr(flags,'n')){
      printf("     %zu  ",newLine++);
      for(size_t i=0;i<numOfCharacters;i++){
        fputc(fileText[i],stdout);
        if(fileText[i]=='\n'){
          if(i<numOfCharacters-2){
            printf("     %zu  ",newLine++);
          }
        }
      }
    }
    //flag b
    else if(strchr(flags,'b')){
      printf("     %zu  ",newLine++);
      for(size_t i=0;i<numOfCharacters;i++){
        fputc(fileText[i],stdout);
        if(fileText[i]=='\n'&&fileText[i+1]!='\n'&&fileText[i+1]!='$'){
          if(i<numOfCharacters-2){
            printf("     %zu  ",newLine++);
          }
        }
      }
    }
    //regular print
    else{
      for(size_t i=0;i<numOfCharacters;i++){
        fputc(fileText[i],stdout);  
      }  
    }
  }
  else{
    size_t newLine=1;
    while(true){
      if(feof(stdin)!=0){
        break;
      }
      if(fgets(fileText2,sizeof(fileText2),stdin)==NULL){
        break;
      }
      
      //flag E
      if(strchr(flags,'A')||strchr(flags,'E')){
        if(fileText2!=NULL&&strlen(fileText2)>0){
          size_t lineLength=strlen(fileText2);
          fileText2[lineLength-1]='$';
          fileText2[lineLength]='\n';
          fileText2[lineLength+1]='\0';
        }
      }
      //flag T
      if(strchr(flags,'A')||strchr(flags,'T')){
        for(size_t i=0;i<strlen(fileText2);i++){
          if(fileText2[i]=='\t'){
            shiftRight(fileText2,sizeof(fileText2),i);
            fileText2[i]='^';
            fileText2[i+1]='I';
            i++;
          }
        }
      }
      
      //flag n
      if(strchr(flags,'n')){
        printf("     %zu  ",newLine++);
      }
      //flag b
      else if(strchr(flags,'b')){
        if(strchr(flags,'A')||strchr(flags,'E')){
          if(strlen(fileText2)-2>0){
            printf("     %zu  ",newLine++);
          }  
        }
        else{
          if(strlen(fileText2)-1>0){
            printf("     %zu  ",newLine++);
          }
        }
      }
      //regular print
      fprintf(stdout,"%s",fileText2);
      memset(fileText2,0,1000);
    }
  }
  clearMemory(fileText);
}