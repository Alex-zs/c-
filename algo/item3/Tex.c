#include <stdio.h>
#include <string.h>

int main()
{
    char c;
    int q = 1;
    while((c = getchar()) != EOF) {
        if(c == '"'){
            if(q){
                printf("%c", c);
                q = !q;
            }else{
                printf("“");
                q = !q;
            }
        }else{
            printf("%c",c);
        }
        if(c == '\n')
            break;
    }
    return 0;
}

