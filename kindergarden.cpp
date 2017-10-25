#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;


int member[100010];
int between[100010];

bool cmp(int a, int b)
{
	return a > b;
}
void main()
{
	freopen("Text.txt", "r", stdin);
	setbuf(stdout, NULL);
	int testCase = 0;
	int student = 0, group = 0;

	scanf("%d", &testCase);
	for (int i = 0; i < testCase; i++) {
		scanf("%d %d", &student, &group);
		for (int j = 0; j < student; j++)
		{
			scanf("%d", &member[j]);
			if (j > 0 ) between[j] = member[j] - member[j - 1];
		}

		sort(between, between + student, cmp);
		for (int j = 0; j < student; j++)
		{
			printf("%d", between[j]);

		}

		memset(between, 0, student);
		printf("\n");

 	}



 


}
