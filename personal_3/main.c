#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {
    int fd = open("file.txt", O_RDWR | O_CREAT, 0666);

    if (fd < 0) {
        perror("open");
        return 1;
    }

    off_t pos_before = lseek(fd, 0, SEEK_CUR);
    printf("position before: %ld\n", (long)pos_before);

    char *data = "HELLO";

    ssize_t written = pwrite(fd, data, strlen(data), 5);
    if (written < 0) {
        perror("pwrite");
        close(fd);
        return 1;
    }

    printf("writed %zd bytes in pos 5\n", written);

    off_t pos_after = lseek(fd, 0, SEEK_CUR);
    printf("position after: %ld\n", (long)pos_after);

    close(fd);
    return 0;
}
