#include<stdio.h>
#include<string.h>

int main(){
    char num[11];
    int width, height;
    while(scanf("%s", num) != 0){
        scanf("%d%d", &width, &height);
        int len = strlen(num);
        char a[width*len+1], b[width*len+1], c[width*len+1], d[width*len+1], e[width*len+1];
        for(int i = 0; i < len; i++){
            int now = i * width;
            a[now] = ' ';
            int number = num[i] - '0';
            for(int j = now + 1; j < now + width - 2; j++)
                if(number != 1 && number != 4) a[j] = num[i];
                else a[j] = ' ';
            a[now + width - 2] = ' ';
            a[now + width - 1] = ' ';
        }

        for(int i = 0; i < len; i++){
            int now = i * width;
            int number = num[i] - '0';
            if(number != 1 && number != 2 && number != 3) 
                b[now] = num[i];
            else b[now] = ' ';
            for(int j = now + 1; j < now + width - 2; j++)
                b[j] = ' ';
            if(number != 5 && number != 6)
                b[now + width - 2] = num[i];
            else b[now + width - 2] = ' ';
            b[now + width - 1] = ' ';
        }

        for(int i = 0; i < len; i++){
            int now = i * width;
            c[now] = ' ';
            int number = num[i] - '0';
            for(int j = now + 1; j < now + width - 2; j++)
                if(number != 0 && number != 1 && number != 7) c[j] = num[i];
                else c[j] = ' ';
            c[now + width - 2] = ' ';
            c[now + width - 1] = ' ';
        }

        for(int i = 0; i < len; i++){
            int now = i * width;
            int number = num[i] - '0';
            if(number == 0 || number == 2 || number == 6 || number == 8) 
                d[now] = num[i];
            else d[now] = ' ';
            
            for(int j = now + 1; j < now + width - 2; j++)
                d[j] = ' ';
            if(number != 2)
                d[now + width - 2] = num[i];
            else d[now + width - 2] = ' ';
            d[now + width - 1] = ' ';
        }

        for(int i = 0; i < len; i++){
            int now = i * width;
            e[now] = ' ';
            int number = num[i] - '0';
            for(int j = now + 1; j < now + width - 2; j++)
                if(number != 1 && number != 4 && number != 7 && number != 9) e[j] = num[i];
                else e[j] = ' ';
            e[now + width - 2] = ' ';
            e[now + width - 1] = ' ';
        }
        int test = width*len-1;
        a[test] = '\0';
        b[test] = '\0';
        c[test] = '\0';
        d[test] = '\0';
        e[test] = '\0';
        
        test= width*len-2;
        while(a[test] == ' '){
            a[test] = '\0';
        }  

        test= width*len-2;
        while(b[test] == ' '){
            b[test] = '\0';
        }  

        test= width*len-2;
        while(c[test] == ' '){
            c[test] = '\0';
        }  

        test= width*len-2;
        while(d[test] == ' '){
            d[test] = '\0';
        }  

        test= width*len-2;
        while(e[test] == ' '){
            e[test] = '\0';
        }  



        int times = (height - 3) / 2;
        printf("%s\n", a);
        for(int i = 0; i < times; i++) printf("%s\n", b);
        printf("%s\n", c);
        for(int i = 0; i < times; i++) printf("%s\n", d);
        printf("%s\n", e);

    }
}