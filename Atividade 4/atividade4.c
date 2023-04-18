/*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−*
* UNIFAL − Universidade Federal de Alfenas.
∗ BACHARELADO EM CIENCIA DA COMPUTACAO.
∗ Trabalho .. : Atividade 4
∗ Disciplina. : Programacao
∗ Professor.. : Luiz Eduardo da Silva
∗ Aluno ..... : Caio Eduardo Marcondes
∗ Data ...... : 22/08/2021
*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−*/

#include <stdio.h>

void leSudoku (int n, int sudoku[16][16]){
char s[2];
int i, j, dim = n * n;
  for (i = 0; i < dim; i++)
    for (j = 0; j < dim; j++)
    { 
      scanf ("%s", s);
    
      if (s[0] >= '1' && s[0] <= '9')
        sudoku [i][j] = s[0] - '0';
      if (s[0] >= 'A' && s[0] <= 'G')
        sudoku[i][j] = s[0] - 'A' + 10;
    }
}

void imprimeLinha (int n) {
int i, j;
  for (i = 0; i < n; i++)
  {
    printf ("+");
  
    for ( j = 0; j < n; j++)
      printf ("−−−");
  }
    printf ("+\n");
}

void imprimeSudoku (int n, int sudoku[16][16]) {
  int i, j, dim = n * n;
  imprimeLinha (n);

  for (i = 0; i < dim; i++) {
      printf ("|");
    
      for (j = 0; j < dim; j++) {
    
      int num = sudoku[i][j];
        if (num <= 9)
          printf ("%2d ", num);
        else 
          printf ("%2c ", num - 10 + 'A');
        if ((j + 1) % n == 0)
          printf ("|");
      }
        printf ("\n");
  
      if ((i + 1) % n == 0)
      imprimeLinha (n);
  }
}

/*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
∗ Funcao que testa uma solucao da Sudoku
∗ Parametros :
∗ n = dimensao das regioes
∗ sudoku − jogo preenchido
∗ Retorna :
∗ 1 se a matriz e uma solucao do sudoku
∗ 0 caso contrario, modificando os parametros lin e col para indicar a linha e coluna onde foi detectado o problema.
/−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−*/

int sudokuOk (int n, int sudoku[16][16], int *lin, int *col)
{
    int i, j, k;
    int existe = 0, q1 = 0, q2 = 0;
    
    //Verifica Linha
    for(i = 0; i < n * n; i++)
    {
      for(j = 0; j < n * n; j++)
      {
        for(k = 0; k <= n * n; k++)
        {
          if(sudoku[i][j] == sudoku[i][k])
            {
              existe++;
            }
          if (existe == 2)
            {  
              *lin = i + 1;
              *col = j + 1;
              return 0;
            }
        }
        existe = 0;
      }
    }
            
    //Verifica Coluna
    for(i = 0; i < n * n; i++)
    {
      for(j = 0; j < n * n; j++)
      {
        for(k = 0; k <= n * n; k++)
        {
          if(sudoku[i][j] == sudoku[k][j])
            {
              existe++;
            }
            if (existe == 2)
            {
                *lin = i + 1;
                *col = j + 1;
                return 0;
            }
        }
        existe = 0;
      }
    }
    //Verifica Quadrante
    for(q1 = 0; q1 < n; q1++)
    {
      for(q2 = 0; q2 < n; q2++)
      {
        for(k = 0; k <= n * n; k++)
        {
          for(i = q1 * n; i < ((q1 * n) + n); i++)
          {
            for(j = q2 * n; j < ((q2 * n) + n); j++)
            {
              if(sudoku[i][j] == k)
              { 
                existe++;
              }
              if(existe == 2) 
              {
                *lin = i + 1;
                *col = j + 1;
                return 0;
              }
            }
          }
        existe = 0;
        }
      }
    }
    return 1;
}

//------------------------------------------------//

int main (void)
{
int n, nlin, ncol, ok;
int sudoku[16][16];
  scanf ("%d", &n);
  
  leSudoku (n, sudoku);
  imprimeSudoku (n, sudoku);
  ok = sudokuOk (n, sudoku, &nlin, &ncol);
    if (ok)
      puts ("Sudoku Ok!");
    else
      printf ("Erro na posição (%d, %d)\n", nlin, ncol);
  return 0;
}
