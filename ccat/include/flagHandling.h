#ifndef FLAG_HANDLING_H
#define FLAG_HANDLING_H
bool handleFlags(size_t *numOfFlags,char **flags,int argc,char **argv);
bool checkExistenceOfFiles(int argc,char **argv,char **file,bool *fromSTDIN);
#endif