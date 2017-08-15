#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>

int Heap[100050];
int HeapIndex = 0;
int count = 0, number = 0;

void swap(int a, int b)
{
    int tmp = Heap[a];
    Heap[a] = Heap[b];
    Heap[b] = tmp;
}
void push(int number)
{
    number = number * -1;
    Heap[++HeapIndex] = number;
    for( int i=HeapIndex;i > 1;i /= 2) {
        if (Heap[i] > Heap[i / 2]) {
            swap(i, i / 2);
        } else break;
    }
}


int pop()
{
    int pollVal = 0;
    if( HeapIndex >= 1) {
        pollVal = Heap[1];
        swap(1, HeapIndex);
        Heap[HeapIndex--] = -2147483647;
        for(int i = 1; i * 2 <= HeapIndex; ) {
            if (Heap[i * 2] > Heap[i * 2 + 1]) {
                if (Heap[i] < Heap[i * 2]) {
                    swap(i, i * 2);
                    i = i * 2;
                } else break;
            } else {
                if (Heap[i] < Heap[i * 2 + 1]) {
                    swap(i, i * 2 + 1);
                    i = i * 2 + 1;
                } else break;
            }
        }
    }
     return pollVal * -1;
}



void printAll()
{
    for (int i = 1; i <= HeapIndex; i++)
    {
        printf("---%d\n", Heap[i]);
    }
}
int main()
{
    freopen("1927.txt", "rw", stdin);
    setbuf(stdout, NULL);

    scanf("%d", &count);

    for (int i = 0; i < count; i++)
    {
        scanf("%d", &number);
        if (number != 0)
            push(number);
        if (number == 0)
             printf("%d\n",  pop());
    }

   // printAll();

//    printf("-----\n");
//     for( int i =1; i<= 8; i++) {
//        printf("%d\n",pop());
//      //  printAll();
//     }

    return 1;
}