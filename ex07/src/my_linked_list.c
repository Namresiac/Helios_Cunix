#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>

node_t *list_create(void *data){
  node_t* head = (node_t*) malloc(sizeof(node_t));
  head->data = data;
  head->next = NULL;
  return head;
}

node_t *list_end(node_t *head){
  while(head->next){
    head = head->next;
  }
  return head;
}

void list_destroy(node_t **head, void (*fp)(void *data))
{
  if(*head == NULL) return;
  if((*head)->next)
    list_destroy(&((*head)->next), fp);
  fp((*head)->data);
  free(*head);
  *head = NULL;
}

void list_clean(node_t **head){
  if(*head == NULL) return;
  if((*head)->next)
    list_clean(&((*head)->next));
  free(*head);
  *head = NULL;
}

void list_push(node_t *head, void *data){
  node_t *p = list_end(head);
  p->next = list_create(data);
}

void list_unshift(node_t **head, void *data){
  if(*head == NULL){
    *head = list_create(data);
    return;
  }
  node_t *p = list_create(data);
  p->next = *head;
  *head = p;
}

void *list_pop(node_t **head){
  node_t *p = list_end(*head);
  if (p == *head){
    free(p);
    void *data = p->data;
    *head = NULL;
    return data;
  }
  node_t *new_last = *head;
  while(new_last->next != p)
    new_last = new_last->next;
  void *data = p->data;
  free(p);
  new_last->next = NULL;
  return data;
}

void *list_shift(node_t **head){
  if(*head == NULL){
    printf("ERROR");
    return NULL;
  }
  else if ((*head)->next == NULL){
    void *data = (*head)->data;
    free(*head);
    *head = NULL;
    return data;
  }
  void *data = (*head)->data;
  node_t *p = *head;
  *head = (*head)->next;
  free(p);
  return data;
}

void *list_remove(node_t **head, int pos){
  if(*head == NULL){
      printf("ERROR LIST REMOVE HEAD == NULL");
      return NULL;
  }
  if( pos == 0){
    node_t *p = *head;
    *head = (*head)->next;
    void *data = p->data;
    free(p);
    return data;
  }
  node_t *p = *head;
  for(int i = 0;i < pos-1; i++,p=p->next){
    if (p ==  NULL){
     printf("ERROR LIST REMOVE P == NULL");
     return NULL;
    }
  }
  node_t *delete = p->next;
  void *data = delete->data;
  p->next = (p->next == NULL ? NULL : p->next->next);
  free(delete);
  return data;
}

void list_print(node_t *head){
  node_t* cur = head;
  while(cur != NULL)
  {
    printf("%s  ", cur->data);
    cur = cur->next;
  }
}

void list_visitor(node_t *head, void (*fp)(void *data)){
  node_t* cur = head;
  while(cur != NULL)
  {
    fp(cur->data);
    cur = cur->next;
  }
}