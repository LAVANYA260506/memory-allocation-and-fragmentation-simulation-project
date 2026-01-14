#include <stdio.h>
#include "memory.h"

int main() {
    int total_memory;
    printf("Enter total memory size (KB): ");
    scanf("%d", &total_memory);

    MemoryBlock* memory = init_memory(total_memory);

    int choice;
    int pid, size;

    while (1) {
        printf("\n=== Memory Manager ===\n");
        printf("1. Allocate Memory\n");
        printf("2. Free Memory\n");
        printf("3. Display Memory\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Process ID: ");
                scanf("%d", &pid);
                printf("Enter Memory Size: ");
                scanf("%d", &size);
                allocate_first_fit(memory, size, pid);
                break;

            case 2:
                printf("Enter Process ID to free: ");
                scanf("%d", &pid);
                free_memory(memory, pid);
                break;

            case 3:
                display_memory_pretty(memory);
                break;


            case 4:
                printf("Exiting program...\n");
                return 0;

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
