// An arena allocator.
// Julian Sniffen, August 2022

#include <stdlib.h>
#include <string.h>

typedef struct {
  char *buffer;
  size_t index;
  size_t length;
} MemoryArena;

int ma_init(MemoryArena *ma, size_t size)
{
  ma->buffer = malloc(size);
  if (!ma->buffer) {
    return 0;
  }
  memset(ma->buffer, 0, size);
  ma->index = 0;
  ma->length = size;
  return 1;
}

void ma_deinit(MemoryArena *ma)
{
  free(ma->buffer);
  ma->index = 0;
  ma->length = 0;
}

char *ma_new(MemoryArena *ma, size_t size)
{
  if (ma->index+size > ma->length) {
    return 0;
  }
  char *buffer = ma->buffer+ma->index;
  ma->index += size;
  return buffer;
}
