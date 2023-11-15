#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    int n, fd;
    char buff[50];

    // Prompt user to enter text to write in the file
    printf("Enter text to write in the file:\n");

    // Read input from keyboard, specifying 0 as fd for standard input device
    n = read(0, buff, 50);

    // Create a new file using open
    fd = open("file", O_CREAT | O_RDWR, 0777);

    // Write input data to file (fd)
    write(fd, buff, n);

    // Write to display (1 is standard fd for output device)
    write(1, buff, n);

    // Close the file
    close(fd);

    return 0;
}
