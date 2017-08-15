#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

int n, k, A[100001];
    
int solve(int s, int e)
{
    if( s>e) return -1;

    int m=(s+e)/2;
    if( A[m] ==k ) return m+1;

    if( A[m] <k )
        return solve(m+1, e);
    else 
        return solve(s, m-1);
}
int main()
{
    freopen("test5.txt", "rw", stdin);
    setbuf(stdout, NULL);

    
    scanf("%d", &n);
    for(int i=0; i<n; i++)
        scanf("%d", A+i);
    
    scanf("%d", &k);
    printf("%d\n", solve(0, n-1));
    return 1;
}