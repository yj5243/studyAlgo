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
int combi[5002][5002];


int answerDistance = -1;

int factorial(int n)
{
	if (n != 0) {
		//printf("%d\n", n * factorial(n - 1));
		return (n * factorial(n - 1)) % 1000000007;
	}
	else {
		return 1;
	}
}

int main()
{
	freopen("Text.txt", "r", stdin);
	setbuf(stdout, NULL);

	scanf("%d", &testCase);

	
	for (int T = 1; T <= testCase; T++)
	{
		scanf("%d %d", &combi[T][1], &combi[T][2]);
		printf("%d %d\n", combi[T][1], combi[T][2]);

		int a = factorial(combi[T][1]) / (factorial(combi[T][2]) * factorial(combi[T][1] - combi[T][2]));
		printf("%d\n", a);
	}



	return 1;
}
