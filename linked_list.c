/* SYSC 2006 
   linked_list.c - functions that operate on singly-linked lists of integers. 
 */

#include <assert.h>  // assert
#include <stdlib.h>  // malloc, free
#include <stdbool.h>
#include <stdio.h>   // printf

#include "linked_list.h"

/*************************************************************
 * Functions presented in lectures.
 *************************************************************/

/* Insert a new node containing data at the front of the linked list
 * pointed to by head. (If head is NULL, the linked list is empty.)
 * Return a pointer to the first node in the modified list.
 * Terminate (via assert) if memory for the node cannot be allocated.
 */
node_t *push(node_t *head, int data)
{
    node_t *newnode = malloc(sizeof(node_t));
    assert(newnode != NULL);
    newnode->data = data;
    newnode->next = head;
    return newnode;
}

/* Return the number of nodes in the linked list pointed to by head.
 * (Return 0 if the linked list is empty.) 
 */
int length(node_t *head)
{
    int count = 0;
    for (node_t *current = head;
        current != NULL;
        current = current->next) {
        count += 1;    
    }
    return count;
}

/* Print the linked list pointed to by head, using the format:
       value1 -> value2 -> value3 -> ... -> last_value
   Print NULL if the list is empty.
 */
void print_list(node_t *head)
{
    if (head == NULL) {
        printf("NULL");
        return; 
    }

    node_t *curr;

    /* This loop prints every node in the linked list except the last one,
       using the format "value -> ", where "->" represents the link from 
       the currentnode to the node to the following node.

       Notice that the loop condition is:
           curr->next != NULL
       and not:
           curr != NULL

       During the last iteration, the value in the second-last node is
       printed, then curr is updated to point to the last node. The
       condition curr->next != NULL now evaluates to false, so the 
       loop exits, with curr pointing to the last node (which has  
       not yet been printed.) 
     */

    for (curr = head; curr->next != NULL; curr = curr->next) {
        printf("%d -> ", curr->data);
    }

    /* Print the last node. */
    printf("%d", curr->data);
}



/*****************************************************************
 * Solutions to Lab 9 exercises
 *****************************************************************/

// Exercise 1

/* Parameter head points to the first node in a linked list, or is
 * NULL if the list is empty.
 *
 * Count the number of nodes in the linked list that contain an integer
 * equal to target, and return that count.
 * 
 * Return 0 if the linked list is empty.
 */ 
int count(node_t *head, int target)
{
	int c = 0;
    if (head == NULL)
	{
		return c;
	}
	node_t *d = head;
	while(d != NULL)
	{
		if(d->data == target)
		{
			c++;
		}
		d = d->next;
	}
	return c;
} 


// Exercise 2

/* Parameter head points to the first node in a linked list, or is
 * NULL if the list is empty.
 *
 * Return the largest integer in the linked list.
 *
 * The function terminates (via assert) if the linked list is empty.
 */
int max(node_t *head)
{
	assert(head != NULL);
	int c = 0;
    if (head == NULL)
	{
		return c;
	}
	node_t *d = head;
	while(d != NULL)
	{
		if(d->data > c)
		{
			c = d->data;
		}
		d = d->next;
	}
	return c;
}

// Exercise 3

/* Parameter head points to the first node in a linked list, or is
 * NULL if the list is empty.
 *
 * Return the integer stored in the node at the specified index.
 * (The first node is at index 0, the second node is at index 1, etc.)
 *
 * The function terminates (via assert) if the linked list is empty
 * or if index is invalid.
 */
int fetch(node_t *head, int index)
{
 	assert(index >= 0 && head != NULL);
	int c = 0;   
	node_t *d = head;
	while(c < index)
	{
		d = d->next;
		c++;
	}
	return d->data;
}


// Exercise 4

/* Parameter head points to the first node in a linked list, or is
 * NULL if the list is empty.
 *
 * Return the index (location) of the first node that contains an 
 * integer equal to target. The first node is at index 0, the second node
 * is at index 1, etc.
 *
 * Return -1 if target is not in the linked list, or if the linked list
 * is empty.
 */
int index(node_t *head, int target)
{	
	int c = -1;
	if(head == NULL)
		return c;
	node_t *d = head;
	while(d != NULL)
	{
		if(d->data == target)
		{
			return c+1;
		}
		c++;
		d = d->next;
	}
    return -1;
}

// Exercise 5

/* Parameter head points to the first node in a linked list, or is
 * NULL if the list is empty.
 *
 * Parameter other points to the first node in a linked list, or is
 * NULL if the list is empty.
 *
 * Extend the linked list pointed to by head so that it contains
 * copies of the values stored in the linked list pointed to by other.
 *
 * The function terminates (via assert) if the the linked list 
 * pointed to by head is empty.
 */
void extend(node_t *head, node_t *other)
{
	assert(head != NULL);
	node_t *d = head;
	node_t *e = other;

	//for (; d->next != NULL; d = d->next);
 	while(d->next != NULL)
	{
		d = d->next;
	}
	
	if (other == NULL)
        return;

	while(e != NULL)
	{
		d->next = push(NULL, e->data);
		e = e->next;
		d = d->next;
	}
}
