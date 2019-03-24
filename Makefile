shm: filesharing.h
	gcc -o upload shm_fileuploader.c -lrt
	gcc -o download shm_filedownloader.c -lrt
clean: 
	rm upload
	rm download
