#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>


#define MAXN 9

bool compare(int a, int b)
{
    return a < b;
}

int main()
{
    freopen("test3.txt", "r", stdin);
    setbuf(stdout, NULL);

    int *number;
    int  count=0;
    number = (int *)calloc(1, sizeof(int));

    while(scanf("%d", &number[count]) != -1)
    {
   //     printf("%d\n", number[count]);
        count++;
        number = (int *)realloc(number, sizeof(int)*(count+1));

    } 

    printf("count : %d\n", count);
    std::sort(number, number + count, compare );

    for(int i=0;i<count;i++)
    {
        printf("%d\n", number[i]);
    }
    
    printf("count : %d\n", count);

  return 0;
}