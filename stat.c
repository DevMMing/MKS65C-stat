#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <time.h>
int main(void) {
  struct stat stuff;
  stat("/dev",&stuff);
  printf("File size:%d\n",stuff.st_size);
  printf("File time: %s\n",ctime(&stuff.st_atime));
  printf("File mode: %o\n",stuff.st_mode);
  return 0;
}