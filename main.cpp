#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <netinet/in.h>

int main(int argc, char** argv) {
	if(argc != 3) {
		fprintf(stderr, "Wrong input format. Should be like : \"./add-nbo file1 file2\"");
		exit(-1);
	}

	FILE* fp1 = fopen(argv[1], "rb");
	uint32_t n1;
	fread(&n1, sizeof(n1), 1, fp1);
	n1 = htonl(n1);
	fclose(fp1);

	FILE* fp2 = fopen(argv[2], "rb");
	uint32_t n2;
	fread(&n2, sizeof(n2), 1, fp2);
	n2 = htonl(n2);
	fclose(fp2);

	uint32_t res = n1 + n2;

	printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", n1, n1, n2, n2, res, res);

	return 0;
}
