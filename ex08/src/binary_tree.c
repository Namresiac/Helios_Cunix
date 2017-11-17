#include <stdio.h>
#include <stdlib.h>
#include "binary_tree.h"

node_t *allocnode()
{
  node_t *element;
  element = malloc(sizeof(node_t));
  element->left = NULL;
  element->right = NULL;
  
  return element;
}

node_t *insert(node_t *root, char *key, void *data)
{
  if (root == NULL)
  {
    root =  allocnode();
    root->key = key;
    root->data = data;
  }
  else
  {
    if(root->key < key) root->left = insert(root->left, key, data);
    else root->right = insert(root->right, key, data);

    return root;
  }
}

void  print_node(node_t *node)
{
  if (node == NULL) return;
  printf("%s  ", node->data);
}

void  visit_tree(node_t *node, void(*fp)(node_t *root))
{
  if (node == NULL) return;

  fp(node);
  visit_tree(node->left, fp);
  visit_tree(node->right, fp);
}

void  destroy_tree(node_t *node, void(*fdestroy)(node_t *root))
{
  if (node == NULL) return;

  destroy_tree(node->left, fdestroy);
  destroy_tree(node->right, fdestroy);

  fdestroy(node);
  free(node);
  node = NULL;
}
