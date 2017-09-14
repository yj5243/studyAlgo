#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <utility>
#include <algorithm>
#include <vector>
#include <set>
#include <limits>

using namespace std;


int main() {

	freopen("Text.txt", "r", stdin);
	setbuf(stdout, NULL);



	int testCase = 0;
	int lines;
	int x[100005];
	int y[100005];
	long  sum = 0;

	memset(x, 0, 100005);
	memset(y, 0, 100005);

	scanf("%d", &testCase);

	for (int T = 1; T <= testCase; T++) {
		scanf("%d", &lines);
		for (int line = 1; line <= lines; line++)
		{
			scanf("%d %d", &x[line], &y[line]);
			//printf("%d %d ", x[line], y[line]);
		} 

		for (int i = 1; i < lines; i++) {
			sum += (x[i] * y[i + 1] ) - abs(x[i + 1] * y[i]);
			//printf("`%d  %d", abs(x[i] * y[i + 1]), abs(x[i + 1] * y[i]));
			//printf("[%d]\n", sum);
 		}
		sum += x[lines] * y[1] - x[1] * y[lines];

		//printf("%d - %d ", (x[lines] * y[1]) , (x[1] * y[lines]));
		//printf("[%d]", sum);

		printf("#%d %0.1f\n ", T, abs((float)sum / 2));
		


		//printf("%d\n", sum);

	}

	

	return 0;
}
