/*
 * Lab 08
 * Rafael Gonçalves
 *
 * Objetivo: Representar numeros inteiros muito grandes usando listas ligadas
 * e implementar a operacao de soma entre esse novo tipo de dado que chamei de
 * struct DistStruct na interface 'numero_astronomico.h'.
 */

#include "numero_astronomico.h"
#include <stdio.h>
#include <stdlib.h>

int
main()
{
  char c; /* Caracteres de entrada. */

  p_dist dist;     /* Acumulador, guarda a soma das distancias. */
  p_dist tmp_dist; /* Guarda temporariamente cada distancia a ser somada. */

  dist = new_dist();

  scanf(" %c", &c);
  /* Enquanti ha numeros para serem somados. */
  while (c == '+')
  {
    tmp_dist = new_dist();
    /* Ignora zeros à esquerda. */
    scanf(" %c", &c);
    while (c == '0')
      scanf(" %c", &c);

    /* Armazena em new_dist cada digito da distancia a ser somada. */
    while (c != '+' && c != '#') 
    {
      tmp_dist = add_tail_dist(tmp_dist, c);
      scanf(" %c", &c);
    }

    dist = add_dist(dist, tmp_dist);   /* Soma e armazena no acumulador. */
    tmp_dist = destroy_dist(tmp_dist); /* Destroi distancia temporaria. */
    print_dist(dist);                  /* Imprime numero no acumulador. */
  }

  /* Destroi acumulador (libera memoria alocada dinamicamente). */
  dist = destroy_dist(dist);

  return 0;
}
