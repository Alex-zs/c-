#include <stdio.h>
#include <string.h>
#define MAX 1000

int result[MAX];

int main()
{
    int a, b, c, n = 0;
    memset(result,0,sizeof(result));
    while(scanf("%d %d %d", &a, &b, &c) == 3) {
    	for(int i = 10; i < 100; i++) {
        	if((i % 3 == a) && (i % 5 == b) && (i % 7) == c){
        		result[n] = i;
        		n++;
        		break;
        	}
    	}
    	n++;
	}
	for (int i = 0; i < n - 1; ++i)
	{
		if (result[i] != 0)
		{
			printf("Case %d: %d\n", i, result[i]);
		}else{
			printf("Case %d: No answer\n", i);
		}
	}
}

