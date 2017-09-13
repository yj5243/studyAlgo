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
int person[100010];
int trues = 0, personCount = 0;
int flag = 0, startIndex = 0, endIndex = 0;
int answer = 0;

int finder(int find)
{
	//printf("finder : %d %d\n", find, person[find]);
	if (person[find] != find) {
		//printf("re finder :  %d %d\n", find, person[find]);
		return finder(person[find]);
	}
	
}

int main()
{
	freopen("동맹.txt", "r", stdin);
	setbuf(stdout, NULL); 


	memset(person, 0, sizeof person);

	scanf("%d", &testCase);

	for (int T = 1; T <= testCase; T++)
	{
		for (int i = 0; i < 100010; i++) person[i] = i;

		answer = 0;
		scanf("%d %d", &personCount, &trues);
		for (int question = 1; question <= trues; question++) {
			scanf("%d %d %d", &flag, &startIndex, &endIndex);
			//printf("%d %d %d\n", flag, startIndex, endIndex);
			
			if (flag == 0) {
				person[endIndex] = finder(startIndex);
				/*
				for (int i = 1; i <= personCount; i++) {
					printf(" %d", person[i]);
				}
				printf("\n");
				*/
			}
			else {
				
				if (finder(startIndex) == finder(endIndex)) {
					printf("%d %d\n", finder(startIndex), finder(endIndex));
					answer++;
				}
				
			}


		}
		printf("#%d %d\n", T, answer);
	}


	return 1;
}
