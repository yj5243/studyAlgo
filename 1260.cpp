#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string.h>
#include <queue>

using namespace std;


int node[1005][1002];
int nodeCount =0, lineCount = 0;
int startNode = 0;
int nodeVisit[1005];

queue <int> q;


void dfs(int curNode)
{

    int i;
    nodeVisit[curNode] = 1;
    printf("- %d -",curNode);
    for( int i=1; i<=nodeCount; i++)
    {
        if(node[curNode][i] == 1&& nodeVisit[i] == 0) {
            dfs(i);
        }
    }
}

void bfs(int curNode)
{
    q.push(curNode);
    q.push(22);
    printf("- %d",q.front());
    q.pop();
    printf(" - %d",q.front());
    q.pop();
    printf(" - %d",q.front());
 
    q.pop();
    printf(" - %d",q.front());
 
}


int main() {

    freopen("1260.txt", "r", stdin);
    setbuf(stdout, NULL);

    scanf("%d %d %d",&nodeCount, &lineCount, &startNode );

    for (int i = 0; i <= nodeCount; i++) nodeVisit[i] = 0;
   
    for( int line=1; line<=lineCount; line++)
    {
        int tempStart = 0, tempEnd=0;
        scanf("%d %d", &tempStart, &tempEnd);
        node[tempStart][tempEnd] = 1;
        node[tempEnd][tempStart] = 1;

    }
    
    for( int i=1; i<=nodeCount; i++){
        for( int j=1; j<=nodeCount; j++){
            printf("%d ", node[i][j]);
        }
        printf("\n");
    }
    

    dfs(startNode);
    printf("\n");
    bfs(startNode);

    return 0;
} 