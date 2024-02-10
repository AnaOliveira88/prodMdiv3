/* -----------------
  -- Ana Oliveira --
--------------------*/
#include <stdio.h>
#include<stdlib.h>
#include <string.h>

// print do array
void mostraArray(int arr[], int n) {
  int i;
  for(i = 0; i < n; ++i) {
    printf("%d  ", arr[i]);
  }
  printf("\n");
}

// ve se o produto calculado previamente é multiplo de 3
int auxResto3(int produto){
    int restoDivInt = produto%3;
    if(restoDivInt==0){
        return 1;
    }else{
        return 0;
    }
}

// quadratica
// ordena o array por ordem decrescente que assim percorre apenas dos maiores numeros e pode nem chegar aos menores, se encontrar logo o resto da divisao inteira por 3 ==0
/*void ordenaArray(int vetor[], int tamanho){
    for (int i = 0; i <= tamanho-1; i++){
        for (int j = i; j <= tamanho-1; j++){
            if (vetor[i] < vetor[j]){
                int temp = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = temp;
            }
        }
    }
    printf("lista ordenada por ordem decrescente: ");
     for (int i = 0; i <= tamanho-1; i++){
        printf("i %d ",i);
        printf(" %d   ", vetor[i]);
    }
    printf("\n ");

}
*/

// calcula o produto maximo
int auxCalculoMax(int valores[], int valori, int j,int lenarray){
    int maior = 0, produto=0, valR = 0 ;
        while(j<lenarray){
            produto = valori * valores[j];
            if(produto > maior){
               valR = auxResto3(produto);
                if(valR==1){
                    maior = produto;
                    printf("PRODUTO: %d, de a=%d por b=%d , é multiplo de 3 \n \n", maior,valori,valores[j]);
                    return maior;
                }
            }
            j++;
        }
   return maior;
}

// Reverse array
void reverse(int arr[], int n){
  int rArr[n], i;
  for(i = 0; i < n; i++){
      rArr[i] = arr[n - i - 1];
  }
  // Copiar o array reverse para o original
  for(i = 0; i < n; i++){
    arr[i] = rArr[i];
  }
}

// ordenacao linear baseado no algoritmo de counting sort
void ordenaArrayLinear(int array[], int size){
  int output[size+4], conta[size+4];
  int max = array[0], i;

  // o maior numero presente no array
  for(i = 1; i < size; i++) {
    if(array[i] > max){
        max = array[i];
    }
  }
  // Inicializa o array a 0
  for(i = 0; i <= max; ++i){
      conta[i] = 0;
  }
  // para cada elemento, guarda a contagem desse mesmo
  for(i = 0; i < size; i++){
      conta[array[i]]++;
  }
    // e armazena essa contagem
  for(i = 1; i <= max; i++){
	    conta[i] += conta[i - 1];
  }
	// pelo inidice de cada elemento no array introduzido, pesquisa no de contagem e coloca os elementos no final
	// place the elements in output array
  for(i = size - 1; i >= 0; i--){
    output[conta[array[i]] - 1] = array[i];
    conta[array[i]]--;
  }
  // passa para o array final
  for(i = 0; i < size; i++){
    array[i] = output[i];
  }
}


int main(){

  int tamArr=0, restoDivInt = 0, ii=0, num=-1, i, j, mult=0, maior =0,multipMaior=0, valR=0;
  printf("Coloque o tamanho do array que pretende criar: \n");
  scanf("%d", &tamArr);
  int valores[tamArr];
  printf("Introduza os valores inteiros positivos que pretende atribuir ao array: \n");
  while(ii<tamArr){
    scanf("%i", &num);
    if(num>0){
      valores[ii]=num;
      ii++;
    }else{
      printf("Introduza apenas valores inteiros positivos: \n");
    }
  }

  int lenarray = sizeof(valores)/sizeof(int);
  ordenaArrayLinear(valores, lenarray);
  reverse(valores,lenarray);
  printf("array ordenado por ordem decrescente:\n");
  mostraArray(valores,lenarray);

  // multiplos de 3 sao os numeros cujo o resto da divisao inteira por %3 == 0
  for(i=0; i<lenarray ; i++){
    multipMaior = auxCalculoMax(valores,valores[i],i+1, lenarray);
    if(multipMaior!=0){
      printf("Sucesso\n");
      return 1;
    }else{
      printf("Insucesso, o produto dos numeros inseridos não é divisível por 3 \n");
      return 0;
    }
  }
}
