#include <stdlib.h>
#include <stdio.h>

typedef struct element element;
struct element
{
  int val;
  int liste;
  struct element *nxt;
};

typedef element* llist;



llist addHeadlement(llist liste, int value)
{
  element* newElement = malloc(sizeof(element));

  newElement->val = value;

  newElement->nxt = liste;

  return newElement;
}

llist addEndlement(llist liste, int value)
{
  element* newElement = malloc(sizeof(element));

  newElement->val = value;

  newElement->nxt = NULL;

  if(liste == NULL)
  {
    return newElement;
  }
  else
  {
    element* tmp=liste;
    while(tmp->nxt != NULL)
    {
      tmp = tmp->nxt;
    }
    tmp->nxt = newElement;
    return liste;
  }
}

void printListe(llist liste)
{
  element *tmp = liste;

  while(tmp != NULL)
  {
    printf("%d -> ", tmp->val);
    tmp = tmp->nxt;
  }
}

llist eraseListe(llist liste)
{
  if(liste == NULL)
  {
    return NULL;
  }
  else
  {
    element *tmp;
    tmp = liste->nxt;
    free(liste);
    return eraseListe(tmp);
  }
}

int main(int argc, char **argv)
{
  llist ma_liste = NULL;
  int i;

  for (i=1; i<=10; i++)
  {
    ma_liste = addHeadlement(ma_liste, i);
    ma_liste = addEndlement(ma_liste, i);
  }
  printListe(ma_liste);

  eraseListe(ma_liste);

  return 0;
}




























