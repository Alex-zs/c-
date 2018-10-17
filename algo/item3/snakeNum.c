#include <stdio.h>
#include <string.h>
#define MAX 100
int a[MAX][MAX];

int main()
{
    int x, y, n;
    scanf("%d", &n);
    memset(a, 0 , sizeof(a));
    int count = 1;
    x = 0, y = n- 1;
    a[x][y] = count;
    while(count < n * n) {
        while(x + 1 < n && !a[x+1][y]) a[++x][y] = ++count;
        while(y - 1 >= 0 && !a[x][y-1]) a[x][--y] = ++count;
        while(x - 1 >= 0 && !a[x-1][y]) a[--x][y] = ++count;
        while(y + 1 < n && !a[x][y+1]) a[x][++y] = ++count;
    }
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            printf("%3d ",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}

