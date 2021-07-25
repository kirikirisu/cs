#include <stdio.h>

int main(void)
{
  int array[] = {4, 5, 9, 1, 8, 6, 2, 10, 3, 7};
  // int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int i, swap_count = 0, n = 10;

  for (i = 0; i < n - 1; i++)
  {
    // for (int c = n; c >= i; c--)
    // {
    //   printf("%d\n", c);
    //   if (array[c - 1] > array[c])
    //   {
    //     int tmp = array[c];
    //     array[c] = array[c - 1];
    //     array[c - 1] = tmp;
    //   }
    // }

    // Ω(n)の場合
    // ソートされているかを確認するために一回はn-1回ループする必要がある
    if (swap_count == 0 && i >= 1)
      break;

    for (int c = 0; c < n - 1; c++)
    {
      printf("%d\n", c);

      if (array[c] > array[c + 1])
      {
        int tmp = array[c];
        array[c] = array[c + 1];
        array[c + 1] = tmp;

        swap_count++;
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