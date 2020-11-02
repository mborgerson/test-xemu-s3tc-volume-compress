#include <stdio.h>
#include <assert.h>
#include "s3tc.h"
#include "s3tc.c"

int main(int argc, char const *argv[])
{
	assert(argc > 2);
	FILE *fd = fopen(argv[1], "rb");
	assert(fd != NULL);
	fseek(fd, 0, SEEK_END);
	size_t fsize = ftell(fd);
	fseek(fd, 0, SEEK_SET);

	uint8_t *compressed = malloc(fsize);
	assert(compressed != NULL);
	assert(fread(compressed, fsize, 1, fd) == 1);
	fclose(fd);

	uint8_t *decompressed = decompress_3d_texture_data(
		GL_COMPRESSED_RGBA_S3TC_DXT1_EXT,
		compressed,
		64, 64, 8);
	size_t decompressed_size = 64 * 64 * 8 * 4;

	fd = fopen(argv[2], "wb");
	assert(fd != NULL);
	assert(fwrite(decompressed, decompressed_size, 1, fd) == 1);
	fclose(fd);

	free(compressed);
	free(decompressed);

	return 0;
}