# ShellSharedMemory
This is a simple file sharing application which is comprised of two separate C programs (shm_fileuploader and shm_filedownloader), which allow users to exchange a single file (maximum size: 10MB) via a shared memory segment. The detailed operations done in each program are presented in the README.

 File Uploader:
- Create a new shared memory object that will be used as a storage to share the content of a single file. The name of the shared object is jsdani1_filesharing”
- Configure the size of the shared memory object. The size is 10MB.
- Memory map the shared memory object
- The structure called filesharing_struct is laid out (i.e., typecast) on the shared memory. The structure has the following fields
  + Flag (in char data type) indicating whether file has been uploaded.
  + Size (in int data type) indicating the size of the file that has been uploaded
  + Character array in which the content of a file is stored
- Ask the user to type in the name of the file that will be shared (e.g., “/bin/ls”, use sizefile placed in repo for convenience)
- The content of the specified file is read from the file system and then copied to the appropriate location in the shared memory. The flag and size fields in the shared memory are updated accordingly

File Downloader:
- Open the shared memory object using “jsdani1_filesharing” as the name of the object 
- Memory map the shared memory object. The size is 10MB.
- Access the shared memory to find out the following information:
  + Whether the content of a file is available on the shared memory
  + Size of the file
  + If there is a file already in the shared memory, download the file to your local directory (will be downloaded to a file called "downfile" locally. 
