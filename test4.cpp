#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string.h>

int main()
{
    freopen("test4.txt","rw",stdin);
    setbuf(stdout, NULL);

    int count = 0;
    scanf("%d", &count);

    for( int i=1;i<=count;i++)
    {
        if(i%3 == 0) printf("x");
        else printf("%d", i);
        printf(" ");
    }
    
    return 1;
}