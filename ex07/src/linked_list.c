#include <stdlib.h>
#include <stdio.h>
#include "linked_list.h"

node_t *list_create(void *data)
{
  node_t *element;

  element=malloc(sizeof(node_t));
  element->data = data;
  element->next = NULL;

  return element;
}


void  list_destroy(node_t **head, void (*fp)(void *data))
{

}
void  list_push(node_t *head, void *data)
{
  node_t* newlement;
  newlement=malloc(sizeof(node_t));

  newlement->data = data;
  newlement->next = head;
  head = newlement;
}



void list_destroy(node_t **head, void (*fp)(void *data))
{
if((*head) == NULL)
return;
if((*head) -> next)
list_destroy(&((*head) -> next), fp);
fp((*head) -> data);
free(*head);
*head == NULL;
}
