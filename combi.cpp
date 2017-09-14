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
int combi[5003][5003];


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


	for (int row = 1; row <= 5001; row++)
	{
		for (int col = 1; col <= 5001; col++)
		{
			combi[row][col ] = 0;
		}
	}

	combi[0][0] = 1;
	for (int row = 1; row <= 5002; row++)
	{
		for (int col = 1; col <= 5002; col++)
		{
			combi[row][col] = ( combi[row - 1][col - 1]  + combi[row - 1][col] ) % 1000000007;
			if (combi[row][col] == 0) {
				break;
			}
//			printf("[ %d ", combi[row][col]);
		}
		//printf("\n");
	}


	for (int T = 1; T <= testCase; T++)
	{
		int a, b;
		scanf("%d %d", &a, &b); 
		printf("#%d %d\n", T, combi[a+1][b+1]  );
 		
	}



	return 1;
}
