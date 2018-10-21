#include <stdio.h>
#include <string.h>

int main()
{
    int count = 0;
    char s[20], buf[99];
    scanf("%s", s);
    for(int abc = 100; abc <= 999; abc++) {
        for(int de = 10; de <= 99; de++) {
            int abce = abc * (de%10);
            int abcd = abc * (de/10);
            int abcde = abc * de;
            sprintf(buf,"%d%d%d%d%d", abc, de, abce, abcd, abcde);
            int ok = 1;
            for(int i = 0, len = strlen(buf); i < len; i++) {
                if(strchr(s,buf[i]) == NULL){
                    ok = 0;
                    break;
                }
            }
            if(ok) {
                count++;
                printf("%5d\nX%4d\n-----\n%5d\n%4d\n-----\n%5d\n\n", abc, de, abce, abcd, abcde);
            }
        }
    }
    printf("The number of solution = %d\n" , count);
    return 0;
}

