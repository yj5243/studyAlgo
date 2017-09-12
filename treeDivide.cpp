#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <utility>
#include <limits>
#include <vector>
#include <set>

using namespace std;



int main()
{
	freopen("treeDivide.txt", "r", stdin);
	setbuf(stdout, NULL);

	int min = numeric_limits<int>::min();
	int testCase = 0;
	int trues = 0;
	int line[3005];
	int D[3005];

	

	scanf("%d", &testCase);

	for (int T = 0; T < testCase; T++) {
		memset(D, min, sizeof D);
		scanf("%d", &trues);
		for (int tr = 1; tr <= trues; tr++) {
			scanf("%d", &line[tr]);
		}

		
		for (int n = 1; n <= trues; n++)
		{
			for (int m = 1; m <= n; m++) {
				if( D[n] < D[n-m] + line[m]) D[n] =  D[n - m] + line[m];
			}
			if (n == trues )  printf("#%d %d\n", T + 1, D[n]);
		}

		
	}



	return 0;
}
