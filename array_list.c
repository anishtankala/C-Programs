/* SYSC 2006
 * array_list.c 
 *
 * Prototype of a dynamically allocated, fixed-capacity list that supports a 
 * subset of the operations provided by Python's list class.
 */ 

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "array_list.h"

/* Construct a new, empty list, and return a pointer to it
 * Parameter capacity is the # of elements that can be stored in the list.
 * Terminate the program via assert if capacity is <= 0.
 * Terminate the program via assert if memory for the list cannot be 
 * allocated from the heap.
 */
list_t *list_construct(int capacity)
{
	assert(capacity > 0);
    list_t *list = malloc(sizeof(list_t));
	assert(list != NULL);
	list->capacity = capacity;
	list->elems = malloc(capacity * sizeof(int));
	assert(list->elems != NULL);
	list->size = 0; 
    return list;
}

/* Destroy the list pointed to by parameter list, deallocating all memory 
 * that was allocated from the heap.
 * Terminate the program via assert if list is NULL.
 */
void list_destroy(list_t *list)
{
    assert(list != NULL);
    free(list->elems);  /* Return the array to the heap. */
    free(list);         /* Return the structure to the heap. */
}

/* Print the list pointed to by parameter list on the console.
 * Terminate the program via assert if list is NULL.
 */
void list_print(const list_t *list)
{    
    assert(list != NULL);
	printf("[");
    int n = list->size;

    if (n > 0) {
        /* Print all the array elements, with a leading space before
         * all but the first element. 
         */
	    printf("%d", list->elems[0]);

        for (int i = 1; i < n; i += 1) {
	        printf(" %d", list->elems[i]);
	    }
	}
	printf("]");
    printf(", capacity: %d, size: %d\n", list->capacity, list->size);
}


/* Insert element at the end of the list pointed to by parameter list* and return true.
 * If the list is full, double its capacity before appending* the element.
 * Terminate the program via assert if list is NULL. 
 * Terminate the program via assert if the full list's capacity couldn't be doubled.
 */
_Bool list_append(list_t *list, int element)
{
	assert(list != NULL);
	if (list->size >= list->capacity)
	{
		increase_capacity(list, list->capacity*2);
	}
	list->elems[list->size] = element;
	list->size++;
	return true;
}

/* Return the maximum number of integers that can be stored in the list 
 * pointed to by parameter list.
 * Terminate the program via assert if list is NULL.
 */
int list_capacity(const list_t *list)
{
	assert(list != NULL);
	return list->capacity;
}

/* Return the number of integers in the list pointed to by parameter list.
 * Terminate the program via assert if list is NULL.
 */
int list_size(const list_t *list)
{
	assert(list != NULL);
    return list->size;
}

/* Return the element located at the specified index, in the list
 * pointed to by parameter list. 
 * Terminate the program via assert if list is NULL, 
 * or if index is not in the range 0 .. list_size() - 1.
 */
int list_get(const list_t *list, int index)
{
	assert(list != NULL && index >= 0 && index <= list->size-1);
    return list->elems[index];
}

/* Store element at the specified index, in the list pointed to by 
 * parameter list. Return the integer that was previously 
 * stored at that index.
 * Terminate the program via assert if list is NULL, 
 * or if index is not in the range 0 .. list_size() - 1.
 */
int list_set(list_t *list, int index, int element)
{
	assert(list != NULL && index >= 0 && index <= list->size-1);
	int old = list->elems[index];
	list->elems[index] = element;
    return old;
}

/* Empty the list pointed to by parameter list.
 * Memory allocated to the list is not freed, so the emptied list can 
 * continue to be used.
 * Terminate the program via assert if list is NULL.
 */
void list_removeall(list_t *list)
{
	assert(list != NULL);
	free(list->elems);
	list->size = 0;
}

/* SYSC 2006 Summer 2019 Lab 8
 *
 * additional_functions.c 
 */ 

/* Return the index (position) of the first occurrence of an integer
 * equal to target in the list pointed to by parameter list. 
 * Return -1 if target is not in the list.
 * Terminate the program via assert if list is NULL.
 */
int list_index(const list_t *list, int target)
{
	assert(list != NULL);
	int c = 0;
	while(c < list->size){
		if(list->elems[c] == target){
		return c;
		}
		c++;
	}
    return -1;
}

/* Count the number of integers that are equal to target, in the list 
 * pointed to by parameter list, and return that number.
 * Terminate the program via assert if list is NULL.
 */
int list_count(const list_t *list, int target)
{
	assert(list != NULL);
	int c = 0;
	int b = 0;
	while(c < list->size){
		if(list->elems[c] == target){
			b++;
		}
		c++;
	}
	return b;
}

/* Determine if an integer in the list pointed to by parameter list 
 * is equal to target.
 * Return true if target is in the list, otherwise return false.
 * Terminate the program via assert if list is NULL.
 */
_Bool list_contains(const list_t *list, int target)
{
	assert(list != NULL);
	int c = list_index(list, target);
	if(c > -1)
	{
		return true;
	}
    return false;
}

/* Increase the capacity of the list pointed to by parameter list to
 * the specified new capacity.
 * Terminate the program via assert if new_capacity is not greater than the
 * list's current capacity, or if the memory required to increase the
 * list's capacity cannot be allocated.
 */
void increase_capacity(list_t *list, int new_capacity)
{
	assert(new_capacity > list->capacity);
	int *newelems = malloc(sizeof(int)*new_capacity);
	assert(newelems != NULL);
	for(int i = 0; i <= list->size; i++){
		newelems[i] = list->elems[i];
	}
	free(list->elems);
	list->elems = newelems;
	list->capacity = new_capacity;
	
}

/* Delete the integer at the specified position in the list pointed
 * to by parameter list.
 * Parameter index is the position of the integer that should be removed.
 * Terminate the program via assert if list is NULL, or if index
 * is not in the range 0 .. list_size() - 1.

 */
void list_delete(list_t *list, int index)
{
	assert(index >= 0 && index < list->size);
	for(int b = index; b < list->size; b++){
		list->elems[b] = list->elems[b+1];
	}
	list->size--;
}

