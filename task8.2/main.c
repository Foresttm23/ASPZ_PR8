#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

int main() {
    int fd = open("testfile.bin", O_RDWR | O_CREAT, 0666);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    unsigned char data[] = {4, 5, 2, 2, 3, 3, 7, 9, 1, 5};
    write(fd, data, sizeof(data));

    lseek(fd, 3, SEEK_SET);

    unsigned char buffer[4];
    ssize_t n = read(fd, buffer, 4);
    if (n < 0) {
        perror("read");
        close(fd);
        return 1;
    }

    printf("Readed %zd bytes: ", n);
    for (int i = 0; i < n; i++)
        printf("%u ", buffer[i]);
    printf("\n");

    close(fd);
    return 0;
}
