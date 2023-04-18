/*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−*
* UNIFAL − Universidade Federal de Alfenas.
∗ BACHARELADO EM CIENCIA DA COMPUTACAO.
∗ Trabalho .. : Atividade 3
∗ Disciplina. : Programacao
∗ Professor.. : Luiz Eduardo da Silva
∗ Aluno ..... : Caio Eduardo Marcondes
∗ Data ...... : 31/07/2021
*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−*/

#include <stdio.h>

/*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
 ∗ Calcula o comprimento do string
 ∗ Recebe o string (s)
 ∗ Retorna o comprimento de s
∗−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−*/
int strlength(char*s)
{
  int i;
  for (i = 0; s[i]; i++);
  return i;
} 

/*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
∗ Lê um string
∗ Parametros :
∗ s = stringa a ser lido
∗ len = tamanho maximo da leitura (contar o \0 e \n).
∗−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−*/
void strread(char *s, int len)
{
    fgets(s, len, stdin); 
    s[strlength(s) - 1] = '\0';
}

/*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
∗ Mostra os elementos do vetor string em modo texto
∗ Parametros :
∗ s = string
∗ name = nome do string
∗−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−*/
void strshow (char *s , char *name)
{
    int i;
  for (i = 0; s [i]; i++)
    printf ("%3d ", i);
    printf ("%3d \n", i);
   for ( i = 0; s [i]; i++)
      printf ("+−−−");
      printf ("+−−−+\n ");
     for (i = 0; s [i]; i++)
        printf ("| %c ", s [i]);
        printf ("| \\0| %s \n ", name);
       for (i = 0; s [i]; i++)
          printf ("+−−−");
          printf ("+−−−+\n ");
}
/*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
* Insere um substring num string na posição específicada
* Parametros :
* pos = posição onde inserir (0 é a primeira posicao)
* sub = sub string que sera inserido em s
* s = string onde inserir sub
∗−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−*/

void strinsert(int pos, char *sub, char *s)
{
    int sizeSub = 0;
    int sizeS = 0;
    int i = 0;

    sizeSub = strlength(sub);
    sizeS = strlength(s);

    char result[sizeSub + sizeS];

    result[sizeSub + sizeS] = '\0';

    while (i < pos && s[i]) //Testa se a string já acabou ou não
    {
        result[i] = s[i];
        i++;
    }

    if( pos > sizeS) {
      while (sub[i-sizeS] != '\0')
      {
          result[i] = sub[i - sizeS];
          i++;
      }
    } else {
      while (sub[i-pos] != '\0')
      {
          result[i] = sub[i - pos];
          i++;
      }
      while (s[i-sizeSub])
      {
          result[i] = s[i - sizeSub];
          i++;
      } 
    }

    i = 0;
      
    while(result[i]){
      s[i] = result[i]; 
      i++;
    } 

    s[i] = '\0';
}

/*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
∗ transforma um literal em inteiro
∗ o literal pode ter sinal (+ ou −) seguido de digitos
∗−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−*/

int str2int(char *s)
{
    int i = 0;
    int intValue = 0;
    int multiplier = 1;

    if (s[0] == '-')
    {
      return -1;
    } else {
      for (i = strlength(s) - 1 ; i >= 0; i--)
      {
          if (s[i] == '+')
          {
              return intValue;
          }

          intValue += ( s[i] - 48 ) * multiplier;

          multiplier *= 10;
      }
      // Retorna -1 se houver algum erro na matriz
      return intValue;
    }
}

int main (void)
{
  char string [100] ;
  char substring [100];
  char posstr [4];
  int posicao;
do
  {
    strread (posstr, 4);
    posicao = str2int (posstr);
    printf ( "\n Posição = %d\n ", posicao);
    if (posicao >= 0)
    {
      strread (substring, 30);
      strshow (substring, " substr. ");
      strread (string, 70);
      strshow (string , " string ");
      strinsert (posicao, substring , string);
      strshow (string , " result. ");
    }
  } while (posicao >= 0);
}
