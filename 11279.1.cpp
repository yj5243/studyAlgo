#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>

int n;
int heap[100010];
int heapIndex = 0;

void swap(int a, int b)
{
        int temp = heap[a];
        heap[a] = heap[b];
        heap[b] = temp;  
}



void push(int number)
{
    heap[++heapIndex] = number;
    for( int i = heapIndex; i>1; i=i/2)
    {
        if(heap[i] > heap[i/2]) swap(i, i/2);
    }
}

int pop()
{
    int pollVal = heap[1];
    swap(heapIndex, 1);
    heap[heapIndex--] = -1;
    for(int i=1 ; i * 2 <= heapIndex; i++) {
        if( heap[i*2] > heap[i*2 +1] )
        {
            if( heap[i] < heap[i*2] ) {
                swap(i, i*2);
                i= i*2;
            } else break;
        }
    }
    return pollVal;
}

int main() {
    int number;

    freopen("11279.1.txt","rw", stdin);
    setbuf(stdout, NULL);

    scanf("%d", &n);

    for( int i=1;i<=n;i++) {
        scanf("%d",&number);
        push(number);
    }
 
    for( int i=1;i<=n;i++) {
        printf("%d",heap[i]);
    }

    for( int i=1;i<=n;i++) {
        printf("\n%d",pop());
    }

    return 0;

}