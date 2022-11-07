#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define STRLENGTH 100

void find(char *string, int length, int frequency[]){
    char letters[26] = "abcdefghijklmnopqrstuvwxyz";
    for(int i = 0; i < length; i++)
        for(int j = 0; j < 26; j++){
            if(string[i] == letters[j])
                frequency[j]++;
        }  
}

int main(){
    char string[STRLENGTH];
    scanf("%s", string);
    int length = strlen(string);
    for(int i = 0; i < length; i++)
        string[i] = tolower(string[i]);
    int frequency[26] = {0} ;
    find(string, length, frequency);
    for(int j = 0; j < 26; j++)
        printf("%d\n", frequency[j]);
    return 0;
}