#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    // Open a file to write output to
    int file_fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (file_fd < 0) {
        perror("Failed to open file");
        exit(1);
    }

    // Duplicate the file descriptor to replace stdout (file descriptor 1)
    if (dup2(file_fd, STDOUT_FILENO) < 0) {
        perror("Failed to redirect stdout");
        close(file_fd);
        exit(1);
    }

    // Close the original file descriptor
    close(file_fd);

    // Now, anything written to stdout goes to "output.txt"
    printf("e file instead of the console!\n");

    return 0;
}
