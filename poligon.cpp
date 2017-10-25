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
		//printf("%d\n", lines);
		for (int line = 1; line <= lines; line++)
		{
			scanf("%d %d", &x[line], &y[line]);
	//		printf("%d %d\n", x[line], y[line]);
		} 
		x[lines + 1] = x[1];
		y[lines + 1] = y[1];

		for (int line = 1; line <= lines; line++) {
			sum += abs(x[line] * y[line + 1] ) - abs(y[line] * x[line+1]);
//			printf("%d  %d \n", abs(x[line] * y[line + 1]), abs(y[line] * x[line + 1]));
		//	printf("[%d]\n", sum);
 		}

		printf("#%d %0.1f\n ", T, abs((float)sum) / 2);
		


		//printf("%d\n", sum);

	}

	

	return 0;
}
