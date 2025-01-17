#include <stdio.h>
#include <string.h>
#include "acao.h"

/* Cria uma nova acao. */
acao
criar_acao(char *nome, double investimento)
{
  acao a;
  strncpy(a.nome, nome, MAX_SIZE_NAME);
  a.investimento = investimento;
  a.n_variacoes = 0;

  return a;
}

/* Adiciona nova variacao a um vetor da acao e incrementa contador. */
acao
adicionar_variacao(acao a, double variacao)
{
  a.variacoes[a.n_variacoes] = variacao;
  a.n_variacoes++;

  return a;
}

/* Imprime nome, quantia remanescente e GANHO/PERDA para uma acao. */
void
reportar_acao(acao a)
{
  double val = a.investimento;
  int i;

  printf("%s ", a.nome);

  for (i = 0; i < a.n_variacoes; i++)
    val += val*a.variacoes[i]/100;

  if (val > a.investimento)
  {
    printf("%.2f GANHO\n", val);
  }
  else
  {
    printf("%.2f PERDA\n", val);
  }
}
