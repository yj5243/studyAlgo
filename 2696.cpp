#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

int TestCase = 0;
int numberListCount = 0, number = 0;
int numberList[10001];

bool compare(int a , int b)
{
    return a<b;
}

int main()
{
    freopen("2696.txt", "rw", stdin);
    setbuf(stdout, NULL);
    int answer = 0;
    scanf("%d", &TestCase);
    for(int i=0; i<TestCase; i++)
    {
        scanf("%d", &numberListCount);
        printf("%d\n",numberListCount/2);

        for( int j =0; j < numberListCount; j++) {
            scanf("%d", &numberList[j]);
            //printf("%d ",numberList[j]);
            if( !(j & 1) ) {
               // printf("홀수 %d  ",j);
                std::sort(numberList, numberList + j+1, compare);
                printf("%d ",numberList[j/2]);  
                //printf("[j=%d  %d : %d]", j, j/2, numberList[j/2]);     
   
            }

            
        }
        
        printf("\n");
    }
    // std::sort(numberList, numberList + numberListCount, compare);
    // for(int i=1; i<numberListCount;i++) printf("%d ", numberList[i]);


    return 1;
}