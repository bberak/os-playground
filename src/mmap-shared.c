// Reference: https://courses.engr.illinois.edu/cs241/sp2014/lecture/11-MemoryMapping_annotated_sol.pdf
// Reference: https://courses.engr.illinois.edu/cs241/sp2014/lecture/09-VirtualMemory_II_sol.pdf

#include <sys/mman.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

#define  PAGESIZE   4096

int main(int argc, char **argv) {
    int fd;
    char string[] ="CS241 takeaway: mmap can be used to map files in memory";
    char *ptr;

    // open a regular file, write a string, and map it into memory
    fd = open(argv[1],O_RDWR|O_CREAT,S_IRWXU);
    write(fd, string, sizeof(string) - 1);
    ptr = (char*) mmap(NULL,PAGESIZE,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
    close(fd);

    printf("pointer to memory mapped file: %p \n", ptr);
    printf("%s \n", ptr);
    ptr[2]='4'; ptr[3]='3'; ptr[4]='1'; // changes to memory are written to the underlying backing store (file)
    printf("%s \n", ptr);
}