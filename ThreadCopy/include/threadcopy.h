#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
void pram_check(int argc,const char*sfile,int thrno);

int file_block(const char* sfile,int thrno);

void copy(const char*sfile,const char*dfile,int block_size,int offset);

void thread_create(pthread_attr_t *attr,const char*sfile,const char*dfile,int blocksize,int thrno);
