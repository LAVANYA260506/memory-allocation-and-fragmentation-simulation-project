#ifndef MEMORY_H
#define MEMORY_H

typedef struct MemoryBlock {
    int size;                   
    int is_free;                
    int process_id;             
    struct MemoryBlock* next;   
} MemoryBlock;

MemoryBlock* init_memory(int total_size);
void display_memory(MemoryBlock* head);


void allocate_first_fit(MemoryBlock* head, int size, int pid);
void free_memory(MemoryBlock* head, int pid);
void merge_free_blocks(MemoryBlock* head);
int total_free_memory(MemoryBlock* head);
void display_memory_pretty(MemoryBlock* head);

#endif
