#include "memory.h"
#include <node_api.h>
#include <stdio.h>

/** Memory Block Structure */
typedef struct MemoryBlock {
    void *ptr;                // pointer to the allocated memory block
    size_t size;              // size of the allocated memory block
    struct MemoryBlock *next; // pointer to the next memory block in the list
} MemoryBlock;

MemoryBlock *head = NULL;    // points to the first block in the list (head of the list)
size_t allocated_memory = 0; // tracks the total size of allocated memory

// ------- Helpers 🚀

/** Helper function to find a block by pointer */
MemoryBlock *find_block(void *ptr) {
    MemoryBlock *current = head;
    while (current != NULL) {      // traverse the list
        if (current->ptr == ptr) { // check if current block mastches the pointer
            return current;        // return the block if found
        }
        current = current->next; // move to the next block
    }
    return NULL; // return NULL if not found
}

/** Helper function to add a block to the linked list */
void add_block(void *ptr, size_t size) {
    // allocate memroy for the new block
    MemoryBlock *new_block = (MemoryBlock *)malloc(sizeof(MemoryBlock));
    new_block->ptr = ptr;     // set the block's pointer to the allocated memory
    new_block->size = size;   // set the block's size
    new_block->next = head;   // Point the new block's next to the current head
    head = new_block;         // Make the new block the new head of the list
    allocated_memory += size; // Increase the total allocated memory count
}

/** Helper function to remove a block from the linked list */
void remove_block(void *ptr) {
    MemoryBlock **current = &head;               // Start at the head
    while (*current != NULL) {                   // Traverse the list
        if ((*current)->ptr == ptr) {            // Check if the current block matches
            MemoryBlock *to_remove = *current;   // Temporary pointer to the block to be removed
            allocated_memory -= to_remove->size; // Subtract the block's size from the total
            *current = to_remove->next;          // Update the current pointer to skip the block
            free(to_remove);                     // Free the block's memory
            return;
        }
        current = &(*current)->next; // Move to the next block
    }
}

// ------- Methods 🚀

void *allocate_memory(size_t size) {
    void *ptr = malloc(size);
    if (ptr != NULL) {
        add_block(ptr, size);
    }
    return ptr;
}

void *reallocate_memory(void *ptr, size_t new_size) {
    if (ptr == NULL) {
        return allocate_memory(new_size);
    }

    // Find current block and adjust allocated memory
    MemoryBlock *block = find_block(ptr);
    if (block != NULL) {
        allocated_memory -= block->size;
    }

    // Reallocate memory
    ptr = realloc(ptr, new_size);
    if (ptr != NULL) {
        if (block != NULL) {
            block->size = new_size;
            allocated_memory += new_size;
        } else {
            add_block(ptr, new_size);
        }
    }
    return ptr;
}

void free_memory(void *ptr) {
    if (ptr != NULL) {
        remove_block(ptr);
        free(ptr);
    }
}

size_t get_memory_usage() {
    return allocated_memory;
}

// ------- Expose Functions 🚀

napi_value AllocateMemory(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    size_t size;
    napi_get_value_uint32(env, args[0], &size);

    void *ptr = allocate_memory(size);
    napi_value result;
    napi_create_external(env, ptr, NULL, NULL, &result);
    return result;
}

napi_value ReallocateMemory(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value args[2];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    void *ptr;
    napi_get_value_external(env, args[0], &ptr);
    size_t new_size;
    napi_get_value_uint32(env, args[1], &new_size);

    void *new_ptr = reallocate_memory(ptr, new_size);
    napi_value result;
    napi_create_external(env, new_ptr, NULL, NULL, &result);
    return result;
}

napi_value FreeMemory(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    void *ptr;
    napi_get_value_external(env, args[0], &ptr);
    free_memory(ptr);
    return NULL;
}

napi_value GetMemoryUsage(napi_env env, napi_callback_info info) {
    size_t usage = get_memory_usage();
    napi_value result;
    napi_create_uint32(env, usage, &result);
    return result;
}