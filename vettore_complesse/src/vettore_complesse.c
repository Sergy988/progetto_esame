/*
 ============================================================================
 Name        : vettore_complesse.c
 Author      : sergio
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define DIM 15

typedef struct {

	int numero;
	int ricorrenza;

}vettore_complesso;

void sposta_contenuto_file(FILE *fp,int vettore[]);
int conta_ricorrenze_consecutive(int vettore[],int i);
void vett_complesso(vettore_complesso vet_comp[],int vettore[]);
void stampa_vettore_complesso(vettore_complesso vet_comp[]);

int main(void) {

	FILE *fp;
	vettore_complesso vet_comp[DIM];
	int vettore[DIM];

	fp=fopen("vettore.txt","r");

	if(fp==NULL){
		printf("errore nell`apertura del file");
	}else{

		sposta_contenuto_file(fp,vettore);

		vett_complesso(vet_comp,vettore);

		stampa_vettore_complesso(vet_comp);



	}

	system("pause");
	return EXIT_SUCCESS;
}

void sposta_contenuto_file(FILE *fp,int vettore[]){

	int i;

	i=0;
	while(fscanf(fp,"%d",&vettore[i])!=EOF){
		i=i+1;
	}
}

int conta_ricorrenze_consecutive(int vettore[],int i){

	int conta;

	conta=1;
	while(vettore[i]==vettore[i-1]){
		conta=conta+1;
		i=i+1;
	}
	return conta;
}

void vett_complesso(vettore_complesso vet_comp[],int vettore[]){

	int i;
	int j;
	int conta;

	j=0;
	i=1;
	while(vettore[i]>=-1){
		conta=conta_ricorrenze_consecutive(vettore,i);
		vet_comp[j].numero=vettore[i-1];
		vet_comp[j].ricorrenza=conta;
		j=j+1;
		i=i+conta;
	}
	vet_comp[j].numero=-1;
}

void stampa_vettore_complesso(vettore_complesso vet_comp[]){

	int i;

	i=0;
	while(vet_comp[i].numero!=-1){
		printf("(%d,",vet_comp[i].numero);
		printf("%d)",vet_comp[i].ricorrenza);
		i=i+1;
	}
}
