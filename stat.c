#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

void call_stat() {
    struct stat * node;
    stat("./output.txt", node);
    printf("size: %i\n", node->st_size);
    printf("Acesses:%o\n", node->st_mode);
    printf("Access Time:%i\n", node->st_mtime);
    //printf("Stats:\nSize of File:%i\nFile Access:%i\nLast accessed:%s\n", node->st_size, node->st_mode, node->st_atime);
}

int * random_num_gen() {
    int * pointer;
    int fd;
    fd = open("\\dev\\random", O_RDONLY);
    read(fd, pointer, sizeof(pointer));
    close(fd);
    return pointer;
}

int write_file(int * fd) {
    int file = open("./output.txt", O_WRONLY | O_CREAT);
    write(file, fd, sizeof(fd));
    close(file);
    return file;
}

int main() {
    int arr[10];
    for (int i = 0; i < 10; i++) {
        arr[i] = *(random_num_gen());
        printf("This is the number that has been chosen: %d\n", arr[i]);
    }
    //write_file(arr);    -----> breaks it but it doesn't work well without it?
    call_stat();

}