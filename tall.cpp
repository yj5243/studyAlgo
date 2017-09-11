#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <set>
#include <memory>
#include <utility>


using namespace std;
typedef pair<int, int> PAIR;

set <PAIR> setPair;

int S[10004];

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int main()
{
    freopen("tall.txt","r", stdin);
    setbuf(stdout, NULL);

    int testCase = 0;
    int member = 0, tallMember = 0, tall = 0, trues = 0;
    scanf("%d", &testCase);
    for( int T = 0; T< testCase; T++) {
        scanf("%d %d %d %d", &member, &tallMember, &tall, &trues);
        
        S[1] = tall;
        for(int tr = 1; tr <= trues; tr++) {
            int a, b;
            scanf("%d %d", &a, &b);
            if( a > b) swap(a,b);
            printf("%d %d %ld\n", a,b, setPair.count(PAIR(a,b)));
             if(setPair.count(PAIR(a,b))) continue;
            S[a+1]--;
            S[b]++;
            setPair.insert(PAIR(a,b));


        }
        for( int i =1; i<=member; i++)
        {
            S[i] += S[i-1];
        }
        for(int i=1; i<=member; i++)
        {
            printf(" %d", S[i]);
        }
 
    }

}