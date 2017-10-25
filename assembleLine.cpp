#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
#include <set>
#include <limits>
#include <memory>

using namespace std;

int intMax = numeric_limits<int>::max();
int intMin = numeric_limits<int>::min();


int v0[30010];
int v1[30010];

int s0[30010];
int s1[30010];

int t0[30010];
int t1[30010];


int main()
{


	freopen("assembleLine.txt", "r", stdin);
	setbuf(stdout, NULL);

	int testCase = 0;
	int N = 0;
	int nodeCount = 0;

	scanf("%d", &testCase);

	
	for (int T = 1; T <= testCase; T++) {
		memset(s1, 0, sizeof s1);
		memset(s0, 0, sizeof s0);
		memset(t1, 0, sizeof t1);
		memset(t0, 0, sizeof t0);
		memset(v1, 0, sizeof v1);
		memset(v0, 0, sizeof v0);

		scanf("%d", &nodeCount);
		scanf("%d %d %d %d", &s0[0], &s1[0], &s0[nodeCount+1], &s1[nodeCount+1]);

		for (int i = 1; i <= nodeCount; i++) {
			scanf("%d", &s0[i]);
		}

		for (int i = 1; i <= nodeCount; i++) {
			scanf("%d", &s1[i]);
		}

		for (int i = 1; i < nodeCount; i++) {
			scanf("%d", &t0[i]);
		}
		for (int i = 1; i < nodeCount; i++) {
			scanf("%d", &t1[i]);
		}

		for (int i = 1; i <= nodeCount + 1; i++) {
			printf("%d", s0[i]);
		}
		printf("\n");

		for (int i = 0; i <= nodeCount; i++) {
			printf("%d", t0[i]);
		}
		printf("\n");
		for (int i = 0; i <= nodeCount; i++) {
			printf("%d", t1[i]);
		}
		printf("\n");

		for (int i = 1; i <= nodeCount + 1; i++) {
			printf("%d", s1[i]);
		}
		printf("\n");

		 
 
		for (int x = 0; x <= (nodeCount+1); x++)
		{
			if (x <= 1) {
				v0[x] = s0[x-1] + s0[x];
				v1[x] = s1[x - 1] + s1[x];

				printf("v0[%d] = %d :  %d=%d+%d  \n",
				x, 
				v0[x],
				s0[x-1] + s0[x], 
				s0[x-1], s0[x] );

				printf("v1[%d] = %d :  %d=%d+%d \n",
				x, 
				v1[x], 
				s1[x-1] + s1[x],   
				s1[x-1],s1[x]);
			}
			else if (x == nodeCount + 1)
			{
				v0[x] = v0[x- 1] + s0[x];
				v1[x] = v1[x - 1] + s1[x];

				printf("v0[%d] = %d :  %d=%d+%d  \n",
				x, 
				v0[x],
				v0[x - 1] + s0[x], 
				v0[x - 1], s0[x] );

				printf("v1[%d] = %d :  %d=%d+%d \n",
				x, 
				v1[x], 
				v1[x - 1] + s1[x],   
				v1[x - 1],s1[x]);


			}
			else {
				v0[x] = min(v1[x - 1] + t1[x - 1], v0[x - 1]) + s0[x];
				v1[x] = min(v0[x - 1] + t0[x - 1], v1[x - 1]) + s1[x];



				printf("v0[%d] = %d :  %d=%d+%d , %d=%d+%d+%d\n",
				x, 
				v0[x],
				v0[x - 1] + s0[x], 
				v0[x - 1], s0[x],
				v1[x - 1] + t1[x - 1] + s0[x],
				v1[x - 1], t1[x - 1], s0[x]);

				printf("v1[%d] = %d :  %d=%d+%d, %d=%d+%d+%d\n",
				x, 
				v1[x], 
				v1[x - 1] + s1[x],   
				v1[x - 1],s1[x],
				v0[x - 1] + t0[x - 1] + s1[x],
				v0[x - 1], t0[x - 1] , s1[x]);



			}


			
		}
		
		//printf("%d %d\n", v0[nodeCount+1], v1[nodeCount+1] );
		printf("#%d %d\n", T, min( v0[nodeCount+1], v1[nodeCount+1] ));
		
	}

	return 0;
}
