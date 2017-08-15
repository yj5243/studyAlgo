#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>


int Heap[100050];
int HeapIndex = 0;
int count = 0, number = 0;
  
  
void printAll()
{
    for (int i = 0; i < HeapIndex; i++)
    {
        printf("---%d\n", Heap[i]);
    }
}

bool compare(int a, int b)
{
    return a > b;
}
  
int main()
{
    freopen("1927.txt", "rw", stdin);
    setbuf(stdout, NULL);

    scanf("%d", &count);

    for (int i = 0; i < count; i++)
    {
        scanf("%d", &number);
        if (number != 0) {
            Heap[HeapIndex++] = number;

        }
        if (number == 0) {
            if( HeapIndex > 0 ) {
                std::sort(Heap, Heap + HeapIndex+1, compare );

                printf("%d\n",Heap[HeapIndex--]);
            } else {
                printf("0\n");

            }
        }
    }

   // printAll();

   printf("-----\n");
   printAll();
   return 1;
}