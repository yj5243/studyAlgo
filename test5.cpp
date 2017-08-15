#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

int main()
{
    freopen("test5.txt", "rw", stdin);
    setbuf(stdout, NULL);

    int count = 0;
    int *number = NULL;
    int findNumber = 0;
    int index = -1;


    scanf("%d", &count);
    number = (int *)malloc(sizeof(int)*count);
    for(int i=0; i<count; i++)
    {
        scanf("%d", &number[i]);
    }
    scanf("%d", &findNumber);


    for(int i=0; i<count; i++)
    {
       if( number[i] > findNumber) {
           index = i;
           break;
       }
    }
    printf("%d", index);
    return 1;
}