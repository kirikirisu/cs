#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
  int number;
  struct node *next;
} node;

int main(void)
{
  node *list = NULL;

  node *n = malloc(sizeof(node));
  if (n == NULL)
  {
    return 1;
  }
  n->number = 1;
  n->next = NULL;
  list = n;

  n = malloc(sizeof(node));
  if (n == NULL)
  {
    free(list);
    return 1;
  }
  n->number = 2;
  n->next = NULL;
  list->next = n;

  n = malloc(sizeof(node));
  if (n == NULL)
  {
    free(list->next);
    free(list);
    return 1;
  }
  n->number = 3;
  n->next = NULL;
  list->next->next = n;

  for (node *tmp = list; tmp != NULL; tmp = tmp->next)
  {
    printf("%i\n", tmp->number);
  }

  while (list != NULL)
  {
    /* 最初にlistを解放してしまうと、listから参照しているnextのアドレスも消滅してしまい、nextがどこにあるのか分からなくなってしまう。 */
    /* すると、nextやnextの中のnextのメモリーを解放することができない。 -> メモリーリークを引き起こす。 */
    /* 最初のノードを解放して、後続のノードにアクセスできなくならないように、現在のノードと次のノード二つを保持する必要がある  */
    node *tmp = list->next;
    free(list);
    list = tmp;
  }
}
