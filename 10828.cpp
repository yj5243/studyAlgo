#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
 
 
// 100000000
int numArray[100050];
int n, num, numIndex =0;
char order[7];

int main() {
    int answer = 0;

    freopen("10828.txt","r", stdin);
    setbuf(stdout,NULL);

    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        scanf("%s %d",order, &num); 
        if(strcmp(order, "push") == 0) {
            numArray[numIndex] = num;
            numIndex++;
 
        } else if(strcmp(order, "pop")== 0) {
            if( numIndex > 0) {
                printf("%d\n", numArray[numIndex-1]);
                numIndex--;
            } else {
                printf("-1\n");
            }
        } else if(strcmp(order,"size") == 0) {
            printf("%d\n", numIndex);

        } else if(strcmp(order,"empty")== 0) {
            if( numIndex == 0) printf("1\n");
            else printf("0\n");
        
        }   else if(strcmp(order,"top") == 0) {
            if( numIndex != 0) printf("%d\n", numArray[numIndex-1]);
            else printf("-1\n");
        }

    
 
    }

    return 0;
}