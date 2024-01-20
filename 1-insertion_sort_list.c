#include "sort.h"
/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * in ascending order using the Insertion Sort algorithm.
 * @list: Pointer to the head of the doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
listint_t *current = (*list)->next;
listint_t *temp, *predecessor;
if (list == NULL || *list == NULL || (*list)->next == NULL)
{
return;
}
while (current != NULL)
{
temp = current;
predecessor = temp->prev;
while (predecessor != NULL && temp->n < predecessor->n)
{
if (temp->next)
temp->next->prev = predecessor;
if (predecessor->prev != NULL)
{
predecessor->prev->next = temp;
}
else
{
*list = temp;
}
temp->prev = predecessor->prev;
predecessor->next = temp->next;
temp->next = predecessor;
predecessor->prev = temp;
temp = predecessor->prev;
predecessor = temp->prev;
print_list(*list);
}
current = current->next;  
}
}
