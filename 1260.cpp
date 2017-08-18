#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <algorithm>


using namespace std;

typedef struct {
    vector<int> end;
    vector<int> visit;
} NODE;  

vector<NODE> node(10050);
int nodeCount, lineCount, statNode;

void DFS(int start)
{
    for(int i=0; i<(node[start].visit.size()); i++)
    {   
        if(node[start].visit[i] != -1 && start != 0 ) {
            printf("DFS : %d %d\n",start+1, node[start].end[i]);
            node[start].visit[i] = -1;
            DFS(node[start].end[i]);
        }
    }
}

int main()
{
    int start, end;

    freopen("1260.txt", "rw", stdin);
    setbuf(stdout, NULL);
    
    scanf("%d %d %d", &nodeCount, &lineCount, &statNode);
 

    for( int i=0 ; i<lineCount; i++)
    {
        scanf("%d %d",&start, &end);
        node[(start-1)].end.push_back(end);
        node[(start-1)].visit.push_back(0);
    }
    
    printf("DFS\n");
    DFS((statNode -1));
    

    return 1;
}