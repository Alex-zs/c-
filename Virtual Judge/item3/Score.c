#include <stdio.h>
#include <string.h>
#define maxn 200

int main()
{
	int count;
	int i,j;
	char s[maxn];
	int res[maxn] = {0};
	scanf("%d", &count);
	for(j = 0; j < count; j++) {
		scanf("%s", s);
		int n = strlen(s);
		int nowScore = 0;
		int sumScore= 0;
		for(i = 0; i < n; i++) {
			if(s[i] == 'O'){
				nowScore++;
				sumScore += nowScore;
			}else{
				nowScore = 0;
			}
		}
		res[j] = sumScore;
	}
	for(i = 0; i < count; i++) {
		printf("%d\n", res[i]);
	}
	return 0;
}

