/* 
−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
 *   UNIFAL − Universidade Federal de Alfenas .
 *     BACHARELADO EM CIENCIA DA COMPUTACAO.
 * Trabalho.. : Atividade 2
 * Disciplina : Programacao
 * Professor. : Luiz  Eduardo da  Silva
 * Aluno..... : Caio Eduardo Marcondes
 * Data...... : 28/07/2021
 ∗−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−*/

#include <stdio.h>

int piso[20][20];
int caneta = 0, direcao = 1; // posição caneta (0 - norte, 1 -sul) e 
                             // direção (0 - esquerda, 
                                      //(1 - direita,
                                      //(2 - cima,
                                      //(3 - baixo)
int linha = 0, coluna = 0; // posição da tartaruga
int passos; // passos da tartaruga
char comando;

int main (){
  int i, j; // valores da matriz
  int fim = 0; // encerra o programa
  
  for (i = 0; i < 20; i++)
    for (j = 0; j < 20; j++)
      piso[i][j] = '.';
  
  while (fim != 1)
  {
    scanf ("%c", &comando); 
    if (comando == 'p'){
      for (i = 0; i < 20; i++){
          for (j = 0; j < 20; j++){
            printf("%c ", piso[i][j]);
          }
        printf("\n");
      }
    }
    if (comando == 'u'){ 
      caneta = 0;
    }
    if (comando == 'd'){
      caneta = 1;
    }
    if (comando == 'r'){
        direcao = direcao + 1;
      if (direcao == 4){
        direcao = 0;
      }
    }
    if (comando == 'l'){ 
      direcao = direcao - 1;
        if (direcao < 0){
          direcao = 3;
        }
    }
    if (comando == 'e'){ 
       fim = fim + 1;
    }
    if (comando == 'w')
    { 
      scanf("%d", &passos);
      passos--; 
      if ((direcao == 0 && (linha - passos) < 0) ||
       (direcao == 1 && (passos + coluna) > 20) || 
       (direcao == 2 && (passos + linha) > 20) ||
       (direcao == 3 && (coluna - passos) < 0)){ 
        fim++;
        }
      if (direcao == 0){
        for (i = 0; i != passos; i++, linha--)
          if (caneta == 1){
            piso[linha][coluna] = '*';
          }
      }
      if (direcao == 1){ 
        for (i = 0; i != passos; i++, coluna++)
          if (caneta == 1){
            piso[linha][coluna] = '*';
          }
      }
      if (direcao == 2){
        for (i = 0; i != passos; i++, linha++)
          if (caneta == 1){
            piso[linha][coluna] = '*'; 
          }
      }
      if (direcao == 3){
        for (i = 0; i != passos; i++, coluna--)
          if (caneta == 1){
            piso[linha][coluna] = '*';
          }
      }
    }
  }
}
