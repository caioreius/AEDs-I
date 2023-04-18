/*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
∗ UNIFAL − Universidade Federal de Alfenas.
∗ BACHARELADO EM CIENCIA DA COMPUTACAO.
∗ Trabalho .. : Atividade 1
∗ Disciplina  : Programação
∗ Professor . : Luiz Eduardo da Silva
∗ Aluno ..... : Caio Eduardo Marcondes
∗ Data ...... : 04/07/2021
∗−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−*/

#include <stdio.h>

int main(void) {
  
  int codigo, idade, somaIdades = 0, totalPessoas = 0, homens = 0, mulheres = 0, outros = 0, maiorIdade = -1, IDmaisVelho = -1, menorIdade = -1, IDmaisNovo = -1, codigoAnterior = 0, ID = 0;
  char sexo;
  float mediaIdades = 0;

  do {

    scanf("%d %c %d", &codigo, &sexo, &idade);
    //Define uma condição para que o progrma entre no meu 'if'
    if (codigo != 0 && sexo != 'X' && idade != 0){
      //Somar idades e total de pessoas
      somaIdades = somaIdades + idade;
      totalPessoas = totalPessoas + 1;
      
      //Quantidade de Homens, Mulheres e outros
      if (sexo == 'm' || sexo == 'M'){
        homens = homens + 1;
      } 
      if (sexo == 'f' || sexo == 'F'){
        mulheres = mulheres + 1;
      }
      else if (sexo != 'm' && sexo != 'f'){
        outros = outros + 1;
      }
      //Idade e Codigo mais Velho
      if (maiorIdade <= idade || maiorIdade == -1){
        if(maiorIdade == idade){
          if(codigo > IDmaisVelho){ 
            IDmaisVelho = codigo;
          }
        } else{
          IDmaisVelho = codigo;
          maiorIdade = idade;
        }
      }
      //Idade e Codigo mais Novo
      if(idade <= menorIdade || menorIdade == -1){
        if(menorIdade == idade){
          if(codigo > IDmaisNovo){
            IDmaisNovo = codigo;
          }
        } else{
          IDmaisNovo = codigo;
          menorIdade = idade; 
        }
      }
    }
  } while (codigo != 0 && sexo != 'X' && idade != 0);

  mediaIdades = (float) somaIdades / totalPessoas;
  
  //Impressão formatada da tabela
  printf("\nRelatório\n");
  printf("+------------------+--------+\n");
  printf("| Soma das idades  | %6d |\n", somaIdades);
  printf("| Total de pessoas | %6d |\n", totalPessoas);
  printf("| Média de idades  | %6.1f |\n", mediaIdades);
  printf("| Homens           | %6d |\n", homens);
  printf("| Mulheres         | %6d |\n", mulheres);
  printf("| Outros           | %6d |\n", outros);
  printf("| Maior idade      | %6d |\n", maiorIdade);
  printf("| ID do mais velho | %6d |\n", IDmaisVelho);
  printf("| Menor idade      | %6d |\n", menorIdade);
  printf("| ID do mais novo  | %6d |\n", IDmaisNovo);
  printf("+------------------+--------+\n");
  return 0;
}
