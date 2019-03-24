/*
- Open the shared memory object using “{yourLinuxID}_filesharing” as the name of the object

- Memory map the shared memory object. The size should 10MB.

- Access the shared memory to find out the following information:

- Whether the content of a file is available on the shared memory

- Size of the file

- If there is a file already in the shared memory, download the file to your local directory (i.e., store the store in your local directory). You may choose any name for the file. Otherwise, print out a message indicating that there is no file on the shared memory.
*/

#include "filesharing.h"

int main() {
    	const char *name = "jsdani1_filesharing"; // name of shared mem object
   	int fd, dest_fd; // shared mem file descriptor and destination file descriptor
   	
   	struct filesharing_struct *ptr; // shared mem object
    	
    	FILE *down; // file pointer
    	const char downfile[] = "downfile"; // file name to be created
    
    	fd = shm_open(name, O_RDONLY, 0666); // create shared mem object

   	ptr = (struct filesharing_struct *) mmap(0, SIZE, PROT_READ, MAP_SHARED, fd, 0); // mem map the shared mem object
   	
   	// if file is available to download from shared mem
   	if(ptr->flag == 1) { 
   		dest_fd = open(downfile, O_CREAT | O_WRONLY, 0666); // open shared mem file	
   		write(dest_fd, ptr->content_buff, ptr->size); // write to dest file
   		shm_unlink(name); // remove the shared memory object
   		printf("File has been downloaded called 'downfile'\n");
   	} else {
   		printf("No file available for download\n");
   	}   	
	
	return 0;
}
