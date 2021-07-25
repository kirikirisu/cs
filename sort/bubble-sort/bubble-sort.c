#include <stdio.h>

int main(void)
{
  int array[] = {4, 5, 9, 1, 8, 6, 2, 10, 3, 7};
  int i, n = 10;

  for (i = 0; i < n - 1; i++)
  {
    for (int c = n; c >= i; c--)
    {
      printf("%d\n", c);
      if (array[c - 1] > array[c])
      {
        int tmp = array[c];
        array[c] = array[c - 1];
        array[c - 1] = tmp;
      }
    }
  }

  printf("Sorted\n");
  for (i = 0; i < n; i++)
  {
    printf("%d", array[i]);
  }
  return 0;
}