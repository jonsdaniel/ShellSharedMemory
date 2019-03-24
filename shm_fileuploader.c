/*
- Create a new shared memory object that will be used as a storage to share the content of a single file. The name of the shared object should be “{yourLinuxID}_filesharing” ({yourLinuxID} should be replaced by your actual Linux user account)

- Configure the size of the shared memory object. The size should be 10MB.

- Memory map the shared memory object

- The structure called filesharing_struct is laid out (i.e., typecast) on the shared memory. The structure has the following fields

- Flag (in char data type) indicating whether file has been uploaded.

- Size (in int data type) indicating the size of the file that has been uploaded

- Character array in which the content of a file is stored

- Ask the user to type in the name of the file that will be shared (e.g., “/bin/ls”)

- The content of the specified file is read from the file system and then copied to the appropriate location in the shared memory. The flag and size fields in the shared memory are updated accordingly
*/   

#include "filesharing.h"
#include <sys/stat.h>

int main() {
	const char *name = "jsdani1_filesharing"; // name of shared mem object

	int fd, src_fd; // shared memory file descriptor and src file descriptor
	char filename[256]; // filename buffer
	
	struct filesharing_struct *ptr; // shared mem object
	
	int n; // bytes read
    	struct stat fs; // object to get filesize
	
	printf("Enter filename to upload: "); // user input for filename to share
	scanf("%s", filename);
	
	src_fd = open(filename, O_RDONLY); // open file
	
	fd = shm_open(name, O_CREAT | O_RDWR, 0666); // create the shared memory object
	
	ftruncate(fd, SIZE); // configure the size of the shared memory object
	
	ptr = (struct filesharing_struct *) mmap(0, SIZE, PROT_WRITE, MAP_SHARED, fd, 0); // memory map the shared memory obj
	
    	stat(filename, &fs); // get file size
    	ptr->size = fs.st_size;

	if (read(src_fd, ptr->content_buff, ptr->size) == ptr->size) { 
    		ptr->flag = 1; // update flag to indicate successful read
    	}
    	
	close(src_fd); // close fd
	close(fd);

	return 0;
}
