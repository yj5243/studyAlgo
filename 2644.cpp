#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <queue>


using namespace std;

int family[200][200] = {0,};
int familyCount = 0;
int start  =0, end = 0;
int list = 0;

int main() {

    int tempa = 0, tempb = 0;

    freopen("2644.txt", "r", stdin);
    setbuf(stdout, NULL);


    scanf("%d", &familyCount);
    scanf("%d %d", &start, &end);
    
    scanf("%d", &list);

    
    for(int i = 1; i<=list ; i++) {
        scanf("%d %d", &tempa, &tempb);
        
        family[tempa][tempb] = 1;
        family[tempb][tempa] = 1;
    }

    
    for( int i=1; i<=familyCount; i++){
        for( int j=1; j<=familyCount; j++){
            printf("%d ", family[i][j]);
        }
        printf("\n");
    }
    


    return 0;
}