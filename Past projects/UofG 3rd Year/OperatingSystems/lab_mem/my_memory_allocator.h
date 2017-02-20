/*******************
 * OS(H)
 * my_memory_allocator.h
 * 
 * Students need to add code to this file
 * to implement the memory manager.
 * @jsinger - yes I know, properly we should
 * just have the data structure definitions and
 * function prototypes in here, and a separate
 * my_memory_allocator.c file ... you can do that
 * if you want to write more tidy code ... :-)
 */

#include <stdio.h>
#include <unistd.h>

#define END_OF_LIST (void *)-1
#define NUM_CELLS 1000000
#define CELL_SIZE sizeof(union Cell)

/**
 * STEP 3.1: Define your type carefully.
 * I recommend a union type, with a neat
 * typedef
 */

typedef union Cell{
	union Cell *next;
	char string[16];
} Cell;

/**
 * STEP 3.2: Initialize a large block of memory
 * You might want a global pointer, to point to 
 * the start of your memory block.
 * You can allocate the block using malloc() or
 * sbrk(). I recommend sbrk() here --- search online
 * for details, or (if you are old-fashioned like me)
 * type "man sbrk" on the terminal.
 * 
 * You will need to organize your free_cell-list data
 * structure on top of this flat block of memory,
 * ideally by splitting it into a set of fixed
 * size cells and adding a 'next' pointer from each cell
 * to the next one
 * 
 */
union Cell *first,*end,*free_cell,*last;

void init_mem_pool(){
	union Cell *current = NULL;
	union Cell *block = NULL;
	int i;
	for (i = 0; i < NUM_CELLS; ++i)
		{	
			block = (union Cell *) sbrk(CELL_SIZE+8);
			if(i==0){
				first = block;
				current = first;
				continue;
			}
			current->next = block;
			current = current->next;
		}
		
		current->next = END_OF_LIST;
		end = current;
}

/**
 * STEP 3.3: Write your malloc routine.
 * This routine allocates one of the fixed size blocks ---
 * we only have the num_bytes argument for compatibility with
 * the standard malloc routine. You might do an assertion
 * to check the size is the same as your fixed size cells.
 * Your allocation routine needs to return a pointer to
 * one of these cells, and update the metadata so the returned
 * cell is no longer on the free_celllist.
 * NOTE: if no memory is available then return NULL
 */
void *my_malloc(int num_bytes){
	union Cell *current = last;
	union Cell *previous = NULL;
	

	if(!last){
		last = first;
		free_cell = last->next;
		return last;
	}
	else{
		last = free_cell;
		free_cell = free_cell->next;
		if(free_cell == END_OF_LIST){
			return NULL;
		}
		
	}
	return last;
}

/**
 * STEP 3.4: Write your free_cell routine
 * Given a pointer to a fixed size cell, you need to
 * add this cell to the free_celllist, updating metadata
 * as appropriate.
 */
void my_free(void *ptr){
	end->next = (union Cell *) ptr;
	end = end->next;
	end->next = END_OF_LIST;
}


/**
 * report error, when there is no memory left
 */
void out_of_mem() {
    fprintf(stderr, "out of memory!\n");
    exit(-1);
}
