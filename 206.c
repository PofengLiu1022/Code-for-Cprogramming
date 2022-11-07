#include <stdio.h>

void shuffle(int *deck[]){
    int index=0;
    while (deck[index] != NULL)
        index++;

    int *result[index];
    int val = (index%2==0)? 0:1;
    if (val == 0)
        val = index/2;
    else
        val = index/2+1; 
    int j = 0;
    for(int i=0; i<val; i++){
        result[j] = deck[i];
        j += 2;
    }
    j=1; 
    for(int i=val; i<index; i++){
        result[j] = deck[i];
        j += 2;
    }
    for(int i=0; i<index; i++){
        deck[i] = result[i];
    }

}

void print(int *deck[]){
    int i=0;
    while (deck[i] != NULL) {
        printf("%d ", *(deck[i]));
        i++;
    }

}

int main()
{
  int card[10000];
  int *deck[10000];
  int index = 0;
 
  while (scanf("%d", &(card[index])) != EOF) {
    deck[index] = &(card[index]);
    index++;
  }

  deck[index] = NULL;
  shuffle(deck);
  print(deck);  
  return 0;
}