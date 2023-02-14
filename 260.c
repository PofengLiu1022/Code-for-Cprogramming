#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main(){
    char result[128];
    char now[128];
    scanf("%s", result);
    while(scanf("%s", now) != EOF){
        int lenR = strlen(result);
        int lenN = strlen(now);
        int minlen = (lenR < lenN)? lenR: lenN;
        int same = 0;
        for(int i = minlen; i > 0; i--){
            bool isSame = 1;
            for(int j = 0; j < i; j++){
                if(result[lenR - i + j] != now[j]) isSame = 0;
            }
            if(isSame){
                same = i;
                break;
            }
        }

        for(int i = 0; i < lenN - same; i++){
            result[lenR + i] = now[same + i];
        }
        result[lenR+lenN-same] = '\0';
    }
    printf("%s\n", result);
    return 0;
}