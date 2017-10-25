#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <utility>
#include <algorithm>
#include <vector>
#include <set>
#include <limits>

using namespace std;

int testCase = 0;
int city[1000][1000];
int answer[1000][1000];

int trues = 0, cityCount = 0;
int answerDistance = -1;
 
int main()
{
	freopen("Text.txt", "r", stdin);
	setbuf(stdout, NULL);


	//memset(node, 0, sizeof node);


	scanf("%d", &testCase);

	for (int T = 1; T <= testCase; T++)
	{
		scanf("%d", &cityCount);

		for (int i = 1; i <= cityCount; i++) {
			for (int j = 1; j <= cityCount; j++) {
				scanf("%d", &city[i][j]);
				answer[i][j] = 0;

			}
		}

		for (int k = 1; k <= cityCount; k++) {
			for (int i = 1; i <= cityCount; i++) {
				for (int j = 1; j <= cityCount; j++) {
					answer[i][j] = min(city[i][j], city[i][k] + city[k][j]);
					if (answerDistance < answer[i][j]) answerDistance = answer[i][j];
				}

			}
		}

		printf("%d", answerDistance);
	}


	return 1;
}
