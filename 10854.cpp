#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string.h>
#include <vector>

using namespace std;

int n = 0;
int numArray[100001];
char order[5];
int numIndex = 0;
int num;

int main()
{
    freopen("10854.txt","rw", stdin);
    setbuf(stdout, NULL);
    scanf("%d", &n);
    
    for(int i=0;i<n;i++) {
        scanf("%s %d",order, &num); 
        if(strcmp(order, "push") == 0) {
            numArray[numIndex] = num;
            numIndex++;
 
        } else if(strcmp(order, "pop")== 0) {
            if( numIndex > 0) {
                printf("%d\n", numArray[0]);
                for(int j=0;j<numIndex;j++) {
                    numArray[j] = numArray[j+1];
                }
                numIndex--;
            } else {
                printf("-1\n");
            }
        } else if(strcmp(order,"size") == 0) {
            printf("%d\n", numIndex);

        } else if(strcmp(order,"empty")== 0) {
            if( numIndex == 0) printf("1\n");
            else printf("0\n");
        
        } else if(strcmp(order,"front") == 0) {
             if( numIndex != 0) printf("%d\n", numArray[0]);
            else printf("-1\n");
          
        } else if(strcmp(order,"back") == 0) {
            if( numIndex != 0) printf("%d\n", numArray[numIndex-1]);
            else printf("-1\n");
        }

     }

    return 0;
} 