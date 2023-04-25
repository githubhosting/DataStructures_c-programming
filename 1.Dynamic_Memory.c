// Dynamic Memory allocation in C

#include <stdio.h>
#include <stdlib.h>

int main()
{

    // This pointer will hold the
    // base address of the block created
    int *ptr;
    int n, i;

    // Get the number of elements for the array
    printf("Enter number of elements:");
    scanf("%d", &n);
    printf("Entered number of elements: %d\n", n);

    // Dynamically allocate memory using malloc()
    // Since the size of int is 4 bytes, this statement will allocate n*4 bytes of memory. And, the pointer ptr holds the address of the first byte in the allocated memory.
    ptr = (int *)malloc(n * sizeof(int));

    // Dynamically allocate memory using calloc()
    // This statement allocates contiguous space in memory for n elements each with the size of the float.
    ptr = (float *)calloc(n, sizeof(float));

    // Dynamically re-allocate memory using realloc()
    ptr = realloc(ptr, n * sizeof(int));

    // Check if the memory has been successfully
    // allocated by malloc/calloc or not
    if (ptr == NULL)
    {
        printf("Memory not allocated.\n");
        exit(0);
    }
    else
    {
        // Memory has been successfully allocated
        printf("Memory successfully allocated using malloc.\n");

        // Get the elements of the array
        for (i = 0; i < n; ++i)
        {
            ptr[i] = i + 1;
        }

        // Print the elements of the array
        printf("The elements of the array are: ");
        for (i = 0; i < n; ++i)
        {
            printf("%d, ", ptr[i]);
        }

        // Free the memory
        free(ptr);
        printf("Malloc Memory successfully freed.\n");
    }

    return 0;
}
