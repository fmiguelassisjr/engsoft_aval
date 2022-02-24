//Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

//Constantes
#define tamanho 8

//Variáveis
int lista[8] = {1,7,3,6,7,1,7,5};
int ordenado[8];
int opt=-1;
int qtd;

//Prototipação
void menu_mostrar(void);
void lista_mostrar(void);
void ordenado_limpar(void);
void lista_mostrar_ordenado(void);

void troca(int* a, int* b);

int mergeSort(int vec[], int tam, int qtd);
void junta(int vec[], int tam);


//Função Principal
int main(void){
	setlocale(LC_ALL, "");
	do {
		system("cls");
		lista_mostrar();
		lista_mostrar_ordenado();
		lista_limpar();
		qtd=0;
		menu_mostrar();
		scanf("%d",&opt);
		switch (opt){
			case 1:
				qtd = mergeSort(ordenado, tamanho, qtd);
				break;


			default:
				if(opt != 0){
					printf("OpÃ§Ã£o invÃ¡lida.\n");
					system("pause");
				}
				break;
		}
	}while(opt!=0);
	system("pause");
	return(0);
}

void lista_mostrar(void){
	int i;
	printf("[ ");
	for (i = 0; i < tamanho; i++ ){
		printf("%d ",lista[i]);
	}
	printf("]\n\n");
}

//Mostra o menu
void menu_mostrar(void){
	printf("1 - Ordenar com MergeSort\n");
	printf("0 - Sair...\n\n");
}

//Mostra o conteÃºdo da lista
//Permite que o usuário entre com os valores da lista
void lista_ler(void){
	int i;
	for (i = 0; i < tamanho; i++){
		system("cls");
		lista_mostrar();
		printf("\nDigite o valor para a posicao %d: ", i);
		scanf("%d", &lista[i]);
	}
}

//Preparar a lista para ordenação
void lista_limpar(void){
	int i;
	for (i = 0; i < tamanho; i++) {
		ordenado[i] = lista[i];
	}
}

void ordenado_limpar(void){
	int i;
	for (i = 0; i < tamanho; i++) {
		ordenado[i] = 0;
	}
}

//Mostra o conteúdo da lista ordenada
void lista_mostrar_ordenado(void){
	int i;
	printf("[ ");
	for (i = 0; i < tamanho; i++ ){
		printf("%d ",ordenado[i]);
	}
	printf("] Tempo = %d iteracoes\n\n", qtd);
}

//Função genérica de troca de valores
void troca(int* a, int* b) {
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

//Aplica o modo MergeSort
int mergeSort(int vec[], int tam, int qtd) {
	int meio;
	if (tam > 1) {
		meio = tam / 2;
		qtd = mergeSort(vec, meio, qtd);
		qtd = mergeSort(vec + meio, tam - meio, qtd);
		junta(vec, tam);
	}
	return (qtd+1);
}

//Junta os pedaços num novo vetor ordenado
void junta(int vec[], int tam) {
	int i, j, k;
	int meio;
	int* tmp;
	tmp = (int*) malloc(tam * sizeof(int));
	if (tmp == NULL) {
		exit(1);
	}
	meio = tam / 2;
	i = 0;
	j = meio;
	k = 0;
	while (i < meio && j < tam) {
		if (vec[i] < vec[j]) {
			tmp[k] = vec[i];
			++i;
		}
		else {
			tmp[k] = vec[j];
			++j;
		}
		++k;
	}
	if (i == meio) {
		while (j < tam) {
			tmp[k] = vec[j];
			++j;
			++k;
		}
	}
	else {
		while (i < meio) {
			tmp[k] = vec[i];
			++i;
			++k;
		}
	}
	for (i = 0; i < tam; ++i) {
		vec[i] = tmp[i];
	}
	free(tmp);
}
