#include <stdio.h>
#include <string.h>
#define maxn 80

char str[maxn];

int checkString(int len, int k) {
    if(len % k != 0)
        return 0;
    int i,j, n = len / k;
    for(i = 0; i < k; i++) {
        char c = str[i];
        for(j = k + i; j <= n * k - 1; j += k ){
            if(str[j] != c)
                return 0;
        }
    }
    return 1;
}

int main()
{
    int i, len, T, count = 0, result[80] = {0};
    scanf("%d", &T);
    while(T--) {
        scanf("%s", str);
        len = (int)strlen(str);
        for(i = 1; i <= len; i++){
            if(checkString(len, i)){
                result[count++] = i;
                break;
            }
        }
    }
    for(i = 0; i < count - 1; i++) {
        printf("%d\n", result[i]);
        printf("\n");
    }
    printf("%d\n", result[count-1]);
    return 0;
}

