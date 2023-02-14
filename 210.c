#include <stdio.h>
#include <string.h>
#define LEN 80
#define charLEN 10

struct sql{
    char lastname[LEN];
    char firstname[LEN];
    char ID[LEN];
    int salary;
    int age;
};

typedef struct sql SQL;

struct total{
    SQL database[51];
};

typedef struct total TOTAL;

void readData(TOTAL *data, int N){
    SQL *ptr = data->database;
    for(int i = 0; i < N; i++){
        scanf("%s%s%s%d%d", ptr->lastname, ptr->firstname, ptr->ID, 
                            &(ptr->salary), &(ptr->age));
        ptr++;
    }
}

void printData(TOTAL *data, int times, int require){
    SQL *ptr = data->database;
    for(int i = 0; i < times; i++) ptr++;
    if(require == 0) printf("%s ", ptr->lastname);
    if(require == 1) printf("%s ", ptr->firstname);
    if(require == 2) printf("%s ", ptr->ID);
    if(require == 3) printf("%d ", ptr->salary);
    if(require == 4) printf("%d ", ptr->age);
}

void findData1(TOTAL *data, int times, int label, char findstr[LEN]){
    SQL *ptr = data->database;
    for(int i = 0; i < times; i++) ptr++;
    if(label == 0) strcpy(findstr, ptr->lastname);
    if(label == 1) strcpy(findstr, ptr->firstname);
    if(label == 2) strcpy(findstr, ptr->ID);
}

int findData2(TOTAL *data, int times, int label){
    SQL *ptr = data->database;
    for(int i = 0; i < times; i++) ptr++;
    if(label == 3) return ptr->salary;
    if(label == 4) return ptr->age;
}

int main(){
    int N;
    scanf("%d", &N);
    TOTAL data;
    readData(&data, N);

    int M;
    scanf("%d", &M);
    
    for(int i = 0; i < M; i++){
        char select[6];
        scanf("%s", select);
        char where[5] = "where";
        char require[9][charLEN];
        int require1[9];
        int count = 0;
        char lastname_C[charLEN] = "lastname";
        char firstname_C[charLEN] = "firstname";
        char ID_C[charLEN] = "ID";
        char salary_C[charLEN] = "salary";
        char age_C[charLEN] = "age";
        char equal[charLEN] = "==";
        char larger[charLEN] = ">";
        char smaller[charLEN] = "<";
        char nequal[charLEN] = "!=";

        while(1){
            scanf("%s", require[count]);
            if(strncmp(where, require[count], 5) == 0) break;
            if(strcmp(require[count], lastname_C) == 0) require1[count] = 0;  
            if(strcmp(require[count], firstname_C) == 0) require1[count] = 1;
            if(strcmp(require[count], ID_C) == 0) require1[count] = 2;
            if(strcmp(require[count], salary_C) == 0) require1[count] = 3;
            if(strcmp(require[count], age_C) == 0) require1[count] = 4;
            count++;
        }

        char condition[charLEN];
        scanf("%s", condition);
        
        int result[N], label, flag = 0;
        if(strcmp(condition, lastname_C) == 0) label = 0;
        if(strcmp(condition, firstname_C) == 0) label = 1;
        if(strcmp(condition, ID_C) == 0) label = 2;
        if(strcmp(condition, salary_C) == 0) label = 3;
        if(strcmp(condition, age_C) == 0) label = 4;
        
        if(label == 0 || label == 1 || label == 2){
            char operand[LEN], operator[LEN], findstr[LEN];
            scanf("%s%s", operand, operator);

            if(strcmp(operand, equal) == 0)
                for(int j = 0; j < N; j++){
                    findData1(&data, j, label, findstr);
                    if(strcmp(operator, findstr) == 0){
                        result[flag] = j;
                        flag++;
                    }
                }
            
            if(strcmp(operand, nequal) == 0)
                for(int j = 0; j < N; j++){
                    findData1(&data, j, label, findstr);
                    if(strcmp(operator, findstr) != 0){
                        result[flag] = j;
                        flag++;
                    }
                }
        }
        

        if(label == 3 || label == 4){
            char operand[LEN];
            int operator;
            scanf("%s%d", operand, &operator);

            if(strcmp(operand, equal) == 0)
                for(int j = 0; j < N; j++)
                    if(findData2(&data, j, label) == operator){
                        result[flag] = j;
                        flag++;
                    }

            if(strcmp(operand, larger) == 0)
                for(int j = 0; j < N; j++)
                    if(findData2(&data, j, label) > operator){
                        result[flag] = j;
                        flag++;
                    }

            if(strcmp(operand, smaller) == 0)
                for(int j = 0; j < N; j++)
                    if(findData2(&data, j, label) < operator){
                        result[flag] = j;
                        flag++;
                    }
        }

        for(int k = 0; k < flag; k++){
            for(int l = 0; l < count; l++)
                printData(&data, result[k], require1[l]);
            printf("\n");
        }
    }
}