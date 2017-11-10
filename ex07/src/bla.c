#include<stdio.h>
#include<stdlib.h>
#include"linked_list.h"

node_t *list_create(void *data) {
  node_t* nd = (node_t*) malloc(sizeof(node_t));
  nd->data = data;
  nd->next = NULL;
  return nd;
}

void list_destroy(node_t **head, void (*fp)(void *data)) {
  if (!*head) return;
  if (!(*head)->next) list_destroy(&((*head)->next), fp);

  fp((*head)->data);
  free(*head);
  *head = NULL;
}

void list_push(node_t *head, void *data) {
  if (!head) {
     head = list_create(data);
     return;
  }

  node_t *tmp = head;
  while (tmp->next) tmp = tmp->next;
  tmp->next = list_create(data);
}

void list_unshift(node_t **head, void *data) {
  if (!*head) {
    *head = list_create(data);
  }

  node_t* tmp = *head;
  (*head) = list_create(data);
  (*head)->next = tmp;
}

void *list_pop(node_t **head) {
  if (!*head) return NULL;
  if (!(*head)->next) {
   void *data = (*head)->data;
    free(*head);
    head = NULL;
    return data;
 }

  node_t *tmp = *head;
  while (tmp->next->next) tmp = tmp->next;
  void *data = tmp->next->data;
  if (tmp->next->data) free(tmp->next->data);
  free(tmp->next);
  tmp->next = NULL;
  return data;
}

void *list_shift(node_t **head) {

  if (!*head) return NULL;

  node_t *tmp = *head;
  *head = (*head)->next;
  void* data = tmp->data;
  free(tmp);

  return data;
}

void list_print(node_t *head) {
  for (node_t* tmp = head; tmp; tmp = tmp->next) printf("%s ", tmp->data);
}

void list_visitor(node_t *head, void (*fp)(void *data)) {
  node_t* tmp = head;

  while(tmp) {
    fp(tmp->data);
    tmp = tmp->next;
  }
}

void *list_remove(node_t **head, int pos) {
  node_t *tmp = *head;

  for (int i = 0; i < pos - 1; i++) {
    if (tmp->next->next == NULL) return NULL;
    tmp = tmp->next;
  }
  
  void *data = tmp->next->data;
  node_t *temp;
  temp = tmp->next;
  tmp->next = tmp->next->next;
  free(temp->data);
  free(temp);
  temp = NULL;
  return data;
}