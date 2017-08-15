#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

int TestCase =0;
int count = 0, findNum=0;;
int *numList = NULL;

int solve(int s, int e) {
    int indx =0;
     while(e-s>0) {
        indx =  (s+e) /2;
        if(numList[indx] < findNum) s= indx+1;
        else e = indx;
        
    }
    return indx+1;
}
int main()
{
    freopen("test7.txt", "rw", stdin);
    setbuf(stdout, NULL);

    scanf("%d", &TestCase);
    for( int i =1; i<=TestCase; i++) {
        scanf("%d", &count);
        numList = (int *)malloc(sizeof(int)*count);
        for(int j=0; j<count; j++)
            scanf("%d", &numList[j]);
        scanf("%d", &findNum);
        for(int j=0; j<count; j++)
            printf("%d", numList[j]);    
        printf("\n");

        printf("%d\n", solve(0,count));

        free(numList);
    }
    
    return 0;
}