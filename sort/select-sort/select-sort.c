#include <stdio.h>

int main(void)
{
  int array[] = {4, 5, 9, 1, 8, 6, 2, 10, 3, 7};
  int i, n = 10;

  for (i = 0; i < n - 1; i++)
  {
    for (int c = i + 1; c < n; c++)
    {
      int min_index = i;
      if (array[i] > array[c])
      {
        min_index = c;
      }

      int tmp = array[i];
      array[i] = array[min_index];
      array[min_index] = tmp;
    }

    printf("loopted %d time =>", i);
    for (int j = 0; j < n; j++)
    {
      printf("%d", array[j]);
    }
    printf("\n");
  }

  printf("Sorted\n");
  for (i = 0; i < n; i++)
  {
    printf("%d", array[i]);
  }
  return 0;
}