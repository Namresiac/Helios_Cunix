hashtable_t *hash_create(unsigned int size)
{
  if (size <= 0)  return NULL;

  hashtable_t *ht;
  ht = malloc(sizeof(hashtable_t));

  ht->size = size;
  ht->table = (void**)malloc(size * sizeof(void*));

  for(int i = 0; i <  ht-> size; i++)
  {
    ht->table[i] = NULL;
  }
  return ht;
}

void  hash_destroy(hashtable_t *ht, void(*fp)(void *data))
{
  if(!ht) return;

  for (int i = 0; i <  ht->size; i++)
  {
    node = ht->table[i];
    if(node) list_destroy(&node, fp);
  }

  free(ht->table);
  ht->table = NULL
  free(ht);
}

unsigned int  hash_funct(char *key)
{
  if (!key) return NULL;

  int code = 0;
  int i = 0;
  while(key[i] != '\0')
  {
    code += (int)key[i];
    i++;
  }
  return code;
}

void  hash_set(hastable_t *ht, void *data, void(*fp)(void *data))
{
  int index = hash_func(key) % ht->size;

  if(ht->table[index]) list_push(ht->table[index], data);
  else
    ht->table[index] = list_create(data);

  fp(key);
}

void  *hash_get(hastable_t *ht, char *key)
{
  int index = hash_func(key) % ht->size;

  if (! ht->table[index]) return NULL;
  else
    return ((node_t*)ht->table[index])->data;
}
