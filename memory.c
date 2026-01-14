#include <stdio.h>
#include <stdlib.h>
#include "memory.h"

MemoryBlock* init_memory(int total_size) {
    MemoryBlock* head = (MemoryBlock*)malloc(sizeof(MemoryBlock));
    head->size = total_size;
    head->is_free = 1;
    head->process_id = -1;
    head->next = NULL;
    return head;
}

void display_memory(MemoryBlock* head) {
    MemoryBlock* temp = head;
    printf("\nMemory Status:\n");
    while (temp != NULL) {
        if (temp->is_free)
            printf("[ Free | %d KB ] -> ", temp->size);
        else
            printf("[ P%d | %d KB ] -> ", temp->process_id, temp->size);
        temp = temp->next;
    }
    printf("NULL\n");
}

void allocate_first_fit(MemoryBlock* head, int size, int pid) {
    MemoryBlock* current = head;

    while (current != NULL) {
        if (current->is_free && current->size >= size) {

            // If block is larger, split it
            if (current->size > size) {
                MemoryBlock* newBlock = (MemoryBlock*)malloc(sizeof(MemoryBlock));
                newBlock->size = current->size - size;
                newBlock->is_free = 1;
                newBlock->process_id = -1;
                newBlock->next = current->next;

                current->next = newBlock;
            }

            // Allocate current block
            current->size = size;
            current->is_free = 0;
            current->process_id = pid;

            printf("Memory allocated to Process %d\n", pid);
            return;
        }

        current = current->next;
    }

    printf("Not enough memory for Process %d\n", pid);
}

void free_memory(MemoryBlock* head, int pid) {
    MemoryBlock* current = head;

    while (current != NULL) {
        if (!current->is_free && current->process_id == pid) {
            current->is_free = 1;
            current->process_id = -1;
            printf("Process %d memory freed\n", pid);
            merge_free_blocks(head);
            return;
        }
        current = current->next;
    }

    printf("Process %d not found\n", pid);
}

void merge_free_blocks(MemoryBlock* head) {
    MemoryBlock* current = head;

    while (current != NULL && current->next != NULL) {
        if (current->is_free && current->next->is_free) {
            current->size += current->next->size;
            MemoryBlock* temp = current->next;
            current->next = temp->next;
            free(temp);
        } else {
            current = current->next;
        }
    }
}


int total_free_memory(MemoryBlock* head) {
    int total = 0;
    MemoryBlock* current = head;

    while (current != NULL) {
        if (current->is_free)
            total += current->size;
        current = current->next;
    }

    return total;
}

void display_memory_pretty(MemoryBlock* head) {
    MemoryBlock* current = head;
    printf("\nMemory Layout:\n");

    while (current != NULL) {
        if (current->is_free)
            printf("[ Free : %d KB ] ", current->size);
        else
            printf("[ P%d : %d KB ] ", current->process_id, current->size);

        current = current->next;
        if (current != NULL) printf("-> ");
    }

    printf("\nTotal Free Memory: %d KB\n", total_free_memory(head));
}
