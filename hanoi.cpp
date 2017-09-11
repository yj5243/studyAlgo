#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>

int A[100010];

static long collect(int n, int t)
{
    if( n == 0 ) return 0;
    if( A[n] == t) return collect(n-1, t);
    int other = 6 - A[n] - t;

    return collect(n-1, other) + (1L << (n-1));

}

int main()
{
    freopen("hanoi.txt","r", stdin);
    setbuf(stdout, NULL);

    char *answer;    
    int testCase = 0, stoneNumber=0;
    scanf("%d", &testCase);

    for( int t=0; t< testCase; t++)
    {
        scanf("%d", &stoneNumber);
        for(int stone = 1; stone <= stoneNumber; stone++) {
            scanf("%d", &A[stone]);
        }

        long from = collect(stoneNumber, 1), to = collect(stoneNumber, 2);

        //printf("%ld %ld \n", from, to);
        if(from+to == (1L << stoneNumber ) - 1) 
            strcpy(answer,"yes");
        else 
            strcpy(answer,"no");
        
        printf("#%d %s\n", t, answer);
        strcpy(answer,"");
        
    }

    

    return 0;
}