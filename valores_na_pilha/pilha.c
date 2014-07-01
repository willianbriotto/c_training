#include <stdio.h>
#include <stdlib.h>

# define SIZE 50

void push(int i); //Adicona valor a pilha
int pop(void); //Remove valor na pilha

int *tos, *p1, stack[SIZE];

int main(void) 
{
    int value;

    tos = stack; //Faz tos conter o topo da pilha
    p1 = stack; //Inicializa p1

    do {
        printf("Digite o valor: ");
        scanf("%d", &value);
        if(value)
            push(value);
        else
            printf("Valor do topo é %d \n", pop());
    } while(value != -1);    
    return 0;
}

void push(int i)
{
    p1++;
    if(p1 == (tos + SIZE)) {
        printf("Estouro de pilha");
        exit(1);
    }
    *p1 = i;
}

int pop(void)
{
    if(p1 == tos) {
        printf("Estouro de pilha");
        exit(1);  
    }
    p1--;
    return *(p1+1);
}
