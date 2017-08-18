#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <functional> 
#include <queue>
#include <vector>

using namespace std;

priority_queue<int> q;
priority_queue< int,vector<int>,greater<int> > pq;

int TestCase = 0;
int numberCount =0, number = 0;

int main()
{

    freopen("2696.txt", "rw", stdin);
    setbuf(stdout, NULL);

    scanf("%d", & TestCase);
    for( int i = 1; i <=TestCase; i++) {
        scanf("%d",&numberCount);
        q = priority_queue<int>();  
        pq = priority_queue< int, vector <int>, greater<int> >();
        int cccc = 0;

        printf("%d\n", numberCount/2 + 1);
        for( int j = 1; j<=numberCount; j++) {
            scanf("%d", &number); 

            if( j & 1 )  {
                q.push(number);
            }
            else  {
                pq.push(number); 
            } 
 
            
            if( j >= 2) {
                if( q.top() > pq.top() ) {
                    int tmp = q.top();
                    q.pop();
                    q.push(pq.top());
                    pq.pop();
                    pq.push(tmp);
                }
            } 
            if( j & 1) {
                cccc++;
                printf("%d ", q.top());
                if( (cccc%10) == 0 ) printf("\n");
             }
        }
        printf("\n");
    }
     
 

    return 0;
}