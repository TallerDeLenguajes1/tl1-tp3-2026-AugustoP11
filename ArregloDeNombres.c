#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define N 5

int main(){

    int i;
    char *V[N];
    char Buff[50];
    for (int i = 0; i < N; i++)
    {
        printf("\nIngrese el nombre de la persona %d: ", (i+1));
        gets(Buff);
        fflush(stdin);
        int longitud = strlen(Buff);
        V[i] = (char*)malloc((sizeof(char) * longitud + 1));
        V[i] = strcpy(V[i], Buff);
    }
    

    
    return 0;
}