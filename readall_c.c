#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

struct buffer {
	char *data;
	size_t length;
	size_t capacity;
};

void buffer_grow(struct buffer *buffer)
{
	buffer->capacity *= 2;
	buffer->data = realloc(buffer->data, buffer->capacity);
	assert(buffer->data);
}

int main(int argc, char *argv[])
{
	size_t block_size = 1024;

	// Use either a custom block size or the preferred one according to `fstat`.
	if (argc >= 2) {
		block_size = atoll(argv[1]);
	} else {
		struct stat statbuf;
		fstat(STDIN_FILENO, &statbuf);
		block_size = statbuf.st_blksize;
	}

	printf("block size: %ld\n", block_size);

	{
		FILE *result = freopen(NULL, "rb", stdin);
		assert(result);
	}

	struct buffer buffer = {
	    .capacity = block_size,
	};

	buffer.data = malloc(buffer.capacity);
	assert(buffer.data);

	while (!feof(stdin) && !ferror(stdin)) {
		if (buffer.capacity < buffer.length + block_size) {
			buffer_grow(&buffer);
		}

		size_t bytes_read = fread(buffer.data + buffer.length, 1, block_size, stdin);
		buffer.length += bytes_read;
	}

	printf("length: %ld\n", buffer.length);

	return ferror(stdin) ? EXIT_FAILURE : EXIT_SUCCESS;
}
