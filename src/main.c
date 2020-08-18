/* Tarefa de decifrar uma cifra
 *
 * Raphael Carvalho - RA: 205125
 * Laboratorio - 06
 */

#include <stdio.h>

#define TAM_BUFFER 100 // alterado buffer para nao cortar solucao
char buffer_entrada[TAM_BUFFER];
char buffer_saida[TAM_BUFFER];

const char senha[] = "SENHASECRETA";

/* Decryption function
* Entradas: Caracteres, Chaves
* Saidas: Mensagem
*/
char decrypter(char c, char k) 
{
	/* onde C = c0,c1.. (caracteres); K = k0, k1... (chaves); m é a mensagem */
  char c0, k0, m;	
  if (c >= 'A' && c <= 'Z') {
    c0 = c - 'A';
    k0 = k - 'A';
    
    /* algoritmo para decifrar codigo segundo pagina da Wikipedia */
    m = 'A' + (c0 - k0 + ('Z' - 'A' + 1)) % ('Z' - 'A' + 1);
    return m;
  } else return c; // caso nao seja uma letra
}

int main() {
  int j=0;
  int i=0;

  /* Leitura da entrada */
  fgets(buffer_entrada, TAM_BUFFER, stdin);


  for (i=0; (i<TAM_BUFFER) && (buffer_entrada[i]!='\0') && (buffer_entrada[i]!='\n'); i++)
  {

    buffer_saida[i] = decrypter(buffer_entrada[i], senha[j]);
    j++;
    if (senha[j]=='\0') j=0;
  }
  buffer_saida[i]='\0';


  /* Escrever saida na tela */
  printf("%s\n", buffer_saida);

  return 0;
}
