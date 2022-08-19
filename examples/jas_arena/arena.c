#include <stdio.h>

#include "../../jas_arena.h"

int main()
{
  MemoryArena ma;
  ma_init(&ma, 32);
  char *a = ma_new(&ma, 16);
  char *b = ma_new(&ma, 16);
  char *c = ma_new(&ma, 16);
  if (a) {
    sprintf(a, "a\n");
    printf(a);
  } else {
    printf("Could not allocate a\n");
  }
  if (b) {
    sprintf(b, "b\n");
    printf(b);
  } else {
    printf("Could not allocate b\n");
  }
  if (c) {
    sprintf(c, "c\n");
    printf(c);
  } else {
    printf("Could not allocate c\n");
  }
  return 0;
}
