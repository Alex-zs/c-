#include <stdio.h>
#include <string.h>
#define maxn 110


//计算质量
double weight(char s, int num) {
    switch(s) {
        case 'C':
            return 12.01 * num;
        case 'O':
            return 16.0 * num;
        case 'H':
            return 1.008 * num;
        case 'N':
            return 14.01 * num;
    }
    return 0.0;
}

//判断字符后面的数字长度
int numLen(char* s, int index) {
    int num = 0;
    int strLen = strlen(s);
    int i = index + 1;
    for(; i < strLen; i++) {
        if(s[i] >= '0' && s[i] <= '9') {
            num++;
        }else{
            break;
        }
    }
    return num;
}

//把数字的字符串转化为int
int num(char * s, int index, int numLen) {
    if(numLen == 0) {
        return 1;
    }
    int sum = 0;
    int i = index + 1;
    for(;i <= (numLen + index); i++) {
        sum *= 10;
        sum += (s[i] - '0');
    }
    return sum;
}

int main()
{
    int T;
    char s[maxn];
    double result[maxn] =  { 0.0 };
    scanf("%d", &T);
    int count = 0;
    while(T--) {
        scanf("%s", s);
        int len = strlen(s);
        int i;
        for(i = 0; i < len;) {
            if(!(s[i]>= '0' && s[i] <= '9')){
                int numlength = numLen(s, i);
                result[count++] = weight(s[i], num(s, i, numlength));
                if(numlength == 0)
                    i += 1;
                else
                    i += (numlength + 1);
            }
        }
    }
    int i;
    for(i = 0; i < count; i++) {
        printf("%.3lf\n", result[i]);
    }
    return 0;
}


