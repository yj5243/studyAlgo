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
	for (int row = 1; row <= 5001; row++)
	{
		for (int col = 1; col <= 5001; col++)
		{
			combi[row][col ] = 0;
		}
	}

	

	for (int T = 1; T <= testCase; T++)
	{
		int a, b;
		combi[0][0] = 1;
		scanf("%d %d", &a, &b);
		
		for (int row = 1; row <= a+1; row++)
		{
			for (int col = 1; col <= 5002; col++)
			{		 
				combi[row][col] = combi[row - 1][col - 1] + combi[row - 1][col];
				if (combi[row][col] == 0) {
					break;
				}
				//printf("[ %d ", combi[row][col]);
			}
			//printf("\n");
		}		
		printf("#%d %d\n", T, combi[a+1][b+1]);
		//printf("%d \n", factorial(a) / ( factorial(b) * factorial(a - b)));



	

		
	}



	return 1;
}
