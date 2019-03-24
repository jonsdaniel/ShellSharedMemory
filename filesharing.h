#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <errno.h> 

#define SIZE 1024*1024*10 // size in bytes of shared memory object

struct filesharing_struct {
	char flag;
	int size;
	char content_buff[SIZE];
};
