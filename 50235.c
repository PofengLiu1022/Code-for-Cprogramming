#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdbool.h>

int function(char* name){
    int length = strlen(name);
    int hash = 0;
    for(int i = 0; i < length; i++){
        hash = (hash + (int)name[i]) % 1000;
    }
    return hash;
}

void hashTable(int f, char* name, char table[1000][3][22], int count[1000][3]){
    for(int i = 0; i < 3; i++){
        if(count[f][i] == 0 || strcmp(table[f][i], name) == 0){
            strcpy(table[f][i], name);
            count[f][i]++;
            printf("%s %d\n", name, count[f][i]);
            break;
        }
    }
}

int main(void){
    char name[22];
    char table[1000][3][22];
    int count[1000][3];
    memset(count, 0, sizeof(count));
    while(scanf("%s", name) != EOF){
        int length = strlen(name);
        bool valid = isalpha(name[0]) || name[0] == '_';

        for(int i = 1; i < length; i++){
            if(!isalnum(name[i]) && name[i] != '_')
            valid = 0;
        }
        if(!valid) continue;

        int f = function(name);
        hashTable(f, name, table, count);
    }
    return 0;
}