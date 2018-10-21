#include <stdio.h>
#include <string.h>
#define maxn 10010
int list[10010][10];

void nextLine(int line) {
    int i = 0;
    for(; i < 10; i++) {
        list[line][i] = list[line-1][i];
    }
    int num = line;
    while(num){
        list[line][num%10] += 1;
        num /= 10;
    }
}

int main()
{
    memset(list, 0, sizeof(list));
    list[1][1] = 1;
    int T,max = 0;
    int numList[25] = {0};
    scanf("%d", &T);
    int count = 0;
    while(T--){
        scanf("%d", &numList[count++]);
    }
    int i = 0;
    max = numList[0];
    for(i = 1; i < count; i++) {
        if(max < numList[i])
            max = numList[i];
    }
    for(i = 2; i <= max; i++)
        nextLine(i);
    for(i = 0; i < count; i++) {
        int j = 0;
        for(j = 0; j < 9; j++) {
            printf("%d ", list[numList[i]][j]);
        }
        printf("%d\n", list[numList[i]][j]);
    }
    return 0;
}

