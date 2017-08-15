#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>

 
int n, S[1000000];

void print_array()
{
    for(int i=0; i<n; i++ ) printf("%d\n", S[i]);
    printf("\n");

}

bool compare(int a, int b)
{
    return a<b;
}


int main() {

    scanf("%d", &n);
    for(int i=0; i<n; i++)
        S[i] = rand();
    
    int start = clock();

    std::sort(S, S+n, compare);

    print_array();

    printf("\n");
    printf("result=%.3lf(Sec)\n", (double)(clock() - start)/CLOCKS_PER_SEC);


    return 0;    
}