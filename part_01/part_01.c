#include <stdio.h>
#include <assert.h>

#define ALLOCATOR_CAPACITY 4 * 1024 // 4KB

char memory[ALLOCATOR_CAPACITY];
size_t occupied_memory = 0;

void * mem_alloc(size_t size) {
  size_t new_size = occupied_memory + size;
  
  assert(new_size < ALLOCATOR_CAPACITY &&
         "ERROR: Reached allocator capacity");
  
  char * address = &memory[occupied_memory]; 
  occupied_memory = new_size;
  
  return address;
}

int main(void) {
  char * s1 = mem_alloc(sizeof(char[32]));
  char * s2 = mem_alloc(sizeof(char[32]));
  
  s1 = "Hello ";
  s2 = "World\n";
  printf("%s%s", s1, s2);
  
  return 0;
}

