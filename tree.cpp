#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <utility>
#include <vector>
#include <set>
#include <limits>

using namespace std;


int main()
{
	freopen("나무.txt", "r", stdin);
	setbuf(stdout, NULL);

	int testCase = 0;
	int treeNumber = 0, trues = 0;
	int startTree = 0, endTree = 0;
	int minHeight = numeric_limits<int>::max();
	int answer = 0;
	scanf("%d", &testCase);

	for (int T = 0; testCase > T; T++) {
		scanf("%d %d", &treeNumber, &trues);
		for (int tr = 0; tr < trues; tr++) {
			scanf("%d %d", &startTree, &endTree);
			if (minHeight > (endTree - startTree + 1)) minHeight = endTree - startTree + 1;
		}

		printf("#%d\n", T + 1);
		printf("%d\n", minHeight);
		for (int AN = 0; AN < treeNumber; AN++) {
			printf("%d ", AN%minHeight);
		}

	}

	return 0;
}
