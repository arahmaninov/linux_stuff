/* equivalent of cat program, using system calls */

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

enum {
	BUF_SIZE = 10
};

int main(int argc, char **argv)
{
	int fd = open(argv[1], O_RDONLY); // getting file descriptor
	char buf[BUF_SIZE];
	int result;

	if (fd == -1) {
		return 1;
	}
	
	while ((result = read(fd, buf, BUF_SIZE)) > 0) {
		write(1, buf, result);
	}

	return 0;
}
