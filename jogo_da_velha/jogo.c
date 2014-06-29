#include <stdio.h>
#include <stdlib.h>

char matrix[3][3]; //Simulation the board

//Prototype of functions
char check(void);
void init_matrix(void);
void get_player_move(void);
void get_computer_move(void);
void disp_matrix(void);

int main() 
{
    char done;

    printf("Este é o jogo-da-velha \n");
    printf("Você vai jogar contra o computador \n");

    done = ' ';
    init_matrix();

    do {
        disp_matrix();
        get_player_move();
        done = check(); //Verify if exists a winner
        if(done != ' ')
            break;//Yes, exists a winner
        get_computer_move();
        done = check();
    } while(done == ' ');

    if(done == 'X')
        printf("Você ganhou! \n");
    else
        printf("Infelizmente esse não foi seu jogo =D \n");
 
    disp_matrix(); //Show the positions end

    return 0;
}

//Initialize the matriz
void init_matrix(void)
{
    int i, j;
   
    for(i = 0; i < 3; i++)
        for(j = 0; j < 3; j++)
            matrix[i][j] = ' ';
}

//Make player action
void get_player_move(void)
{
    int x, y;

    printf("Digite as coordenadas para o X: ");
    scanf("%d%d", &x, &y);

    x--; y--;

    if(matrix[x][y] != ' ') {
        printf("Posição inválidade, tente novamente; \n");
	get_player_move();    
    }
    else
        matrix[x][y] = 'X';
}

//Make Ai action
void get_computer_move(void)
{
    int i, j;

    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++)
            if(matrix[i][j] == ' ')
                break;
        if(matrix[i][j] == ' ')
            break;
    }

    if(i * j == 9) {
        printf("Vocês empataram!\n");        
        exit(0);
    }
    else
        matrix[i][j] = '0';
}

//Draws the board in console
void disp_matrix(void)
{
    int t;

    for(t = 0; t < 3; t++) {
        printf(" %c   |   %c   |   %c ", matrix[t][0], matrix[t][1], matrix[t][2]);
        if(t != 2)
           printf("\n --- |  ---  |  --- \n");
    }
    printf("\n");
}

//Verify if exists a winner
char check(void)
{
    int i;

    for(i = 0; i < 3; i++) //Verify the lines
        if(matrix[i][0] == matrix[i][1] &&
           matrix[i][0] == matrix[i][2])
            return matrix[i][0];
    
    for(i = 0; i < 3; i++)
        if(matrix[0][i] == matrix[1][i] &&
           matrix[0][i] == matrix[2][i])
            return matrix[0][i];

    //Tests the diagonal
    if(matrix[0][0] == matrix[1][1] &&
       matrix[1][1] == matrix[2][2])
        return matrix[0][0];

    if(matrix[0][2] == matrix[1][1] &&
       matrix[1][1] == matrix[2][0])
        return matrix[0][2];

    return ' ';
}
