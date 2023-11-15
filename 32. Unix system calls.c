#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd;
    char buffer[100];
    fd = open("file.txt", O_CREAT | O_RDWR, 0777);
    if (fd == -1) {
        printf("Error opening file\n");
        exit(1);
    }
    printf("Enter text to write in the file:\n");
    int n = read(0, buffer, 100);
    write(fd, buffer, n);
    printf("Data written to file successfully!\n");
    close(fd);
    return 0;
}
