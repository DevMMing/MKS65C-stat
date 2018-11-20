#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <time.h>

void printSize(int size){
  printf("File Size: ");
  if(size % 1073741824 / 10000000 > 0){
    printf("%d MB ",size % 1073741824 / 10000000);
  }
  if(size % 1048576 / 1000 > 0){
    printf("%d KB ",size % 1048576 / 1000);
  }
  if(size % 1024 > 0){
    printf("%d B",size % 1024);
  }
  printf("\n");
}

int main(void) {
  struct stat stuff;
  stat("/dev",&stuff);
  printSize(stuff.st_size);
  printf("File time: %s\n",ctime(&stuff.st_atime));
  printf("File mode: %o\n",stuff.st_mode);
  printf("File mode(in ls-l form) : ");
   printf( (S_ISDIR(stuff.st_mode)) ? "d" : "-");
   printf( (stuff.st_mode & S_IRUSR) ? "r" : "-");
    printf( (stuff.st_mode & S_IWUSR) ? "w" : "-");
    printf( (stuff.st_mode & S_IXUSR) ? "x" : "-");
    printf( (stuff.st_mode & S_IRGRP) ? "r" : "-");
    printf( (stuff.st_mode & S_IWGRP) ? "w" : "-");
    printf( (stuff.st_mode & S_IXGRP) ? "x" : "-");
    printf( (stuff.st_mode & S_IROTH) ? "r" : "-");
    printf( (stuff.st_mode & S_IWOTH) ? "w" : "-");
    printf( (stuff.st_mode & S_IXOTH) ? "x" : "-");
	printf("\n");
  return 0;
}