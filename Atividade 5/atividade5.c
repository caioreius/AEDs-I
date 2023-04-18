/* −−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
 * UNIFAL − Universidade Federal de Alfenas .
 * BACHARELADO EM CIENCIA DA COMPUTACAO.
 * Trabalho.. : Atividade 5
 * Disciplina : Programacao
 * Professor. : Luiz  Eduardo da  Silva
 * Aluno..... : Caio Eduardo Marcondes
 * Data...... : 07/09/2021
 ∗−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−*/

#include <stdio.h>

void printISBN(int matriz[3][10]){

    for (int j = 0; j < 9; ++j) {
        printf("%d", matriz[0][j]);
    }
    if (matriz[0][9] == 10){
        printf("-X");
    } else {
        printf("-%d", matriz[0][9]);
    }
    printf("\n");
}

void calculaDigito(int matriz[3][10]){
    for(int i = 0; i <= 10; i++){
        matriz[1][9] = matriz[1][8] + i;
        matriz[2][9] = matriz[2][8] + matriz[1][9];
        if(matriz[2][9] % 11 == 0){
            matriz[0][9] = i;
        }
    }
}

void somaMatriz(int matriz[3][10]){
    int s1;
    for(int i = 0; i < 2; ++i){
        s1 = 0;
        for (int j = 0; j < 9; ++j) {
            s1 += matriz[i][j];
            matriz[i+1][j] = s1;
        }
    }
}

int verifique(int m[3][10], int v){
    v = 0;
    for(int i = 0; i < 9; i++){
        v += m[0][i];
    }
    return v;
}

void str2int(const char* isbn, int m[3][10]){
    int pos = 0;
    int n;

    for (int i = 0; isbn[i] != '\0'; ++i){
        n = pos * 10 + isbn[i] - '0';
        m[0][i] = n;
    }
}

int main(void){
    char isbn[10];
    int m[3][10];
    int v = 0;

    do {
        scanf(" %s",isbn);
        str2int(isbn, m);
        v = verifique(m, v);
        if(v != 0){

            somaMatriz(m);

            calculaDigito(m);

            printISBN(m);
        }
    } while(v != 0);
}
