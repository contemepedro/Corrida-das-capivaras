/**************************************************
*
* Pedro Henrique Conte de Araujo 
* Trabalho 1
* Professor(a): Diego Padilha Rubert
*
*/
#include <stdio.h>

typedef struct
{
  int numero; 
  int pontuacoes;
} capivara;

void troca(int n, capivara capivaras[], int u);
void intercala(int p, int q, int r, capivara v[]);
void mergesort(int p, int r, capivara v[]);

int main(void)
{
  int n, i, u; // numero de capivaras, contador, ultrapassagens
  scanf("%d", &n);
  capivara capivaras[n]; // cria o vetor
  for (i=0; i<n; i++)
  {
    capivaras[i].numero = i+1; // enumeração das capivaras 
    capivaras[i].pontuacoes = 0; // quantidade de ultrapassagens de cada capivara 
  }
  while (scanf("%d", &u) != EOF) // lê as ultrapassagens
  {
    troca(n, capivaras, u);
  }
  for (i=0; i<n; i++)// posição final das capivaras
  {
    printf("%d ", capivaras[i].numero);
  }
  printf("\n");
  mergesort(0, n, capivaras);
  for (i=0; i<n; i++)
  {
    printf("%d ", capivaras[i].numero);
  }
  printf("\n");
  return 0;
}

void troca(int n, capivara capivaras[], int u) 
{ 
  int i, aux, aux2;
  for(i=0; i<n; i++)
  {
    if(capivaras[i].numero == u)
    {
      capivaras[i].pontuacoes += 1;
      //troca do numero da capivara
      aux = capivaras[i-1].numero;
      capivaras[i-1].numero = capivaras[i].numero;
      capivaras[i].numero = aux;
      //troca da pontuação da capivara
      aux2 = capivaras[i-1].pontuacoes;
      capivaras[i-1].pontuacoes = capivaras[i].pontuacoes;
      capivaras[i].pontuacoes = aux2;
    }
  }
}

void intercala(int p, int q, int r, capivara v[])
{
  int i, j, k;
  int pontu[r];
  int num[r];
  i = p; j = q; k = 0;
  while (i<q && j<r) 
  {
    if (v[i].pontuacoes < v[j].pontuacoes) 
    {
      pontu[k] = v[j].pontuacoes;
      num[k] = v[j].numero;
      j++;
    }
    else if (v[i].pontuacoes == v[j].pontuacoes)
    {
      if(v[i].numero < v[j].numero)
      {
        pontu[k] = v[i].pontuacoes;
        num[k] = v[i].numero;
        i++;
      } 
      else
      {
        pontu[k] = v[j].pontuacoes;
        num[k] = v[j].numero;
        j++;
      } 
    }
    else
    {
      pontu[k] = v[i].pontuacoes;
      num[k] = v[i].numero;
      i++;
    }
    k++;
  }
  while (i < q)
  {
    pontu[k] = v[i].pontuacoes; 
    num[k] = v[i].numero;
    i++; 
    k++;
  }
  while (j<r)
  {
    pontu[k] = v[j].pontuacoes;
    num[k] = v[j].numero; 
    j++; 
    k++; 
  }
  for (i=p; i<r; i++)
  {
    v[i].numero = num[i-p];
    v[i].pontuacoes = pontu[i-p];
  }
}

void mergesort(int p, int r, capivara capivaras[])
{
  int q;
  if (p<r-1) 
  {
    q = (p+r)/2;
    mergesort(p, q, capivaras);
    mergesort(q, r, capivaras);
    intercala(p, q, r, capivaras);
  }
} 