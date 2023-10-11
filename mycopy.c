/* equivalent of cp program */

#include <stdio.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
	FILE *src = fopen(argv[1], "rb"); // read raw bytes from the source file
	FILE *dst = fopen(argv[2], "wb"); // write raw bytes to the destination file
	
	BYTE b;

	while (fread(&b, sizeof(b), 1, src) != 0) { // reading 1 byte at a time from src
		fwrite(&b, sizeof(b), 1, dst);      // writing 1 byte at a time to dst
	}
	
	fclose(dst);
	fclose(src);

	return 0;
}
