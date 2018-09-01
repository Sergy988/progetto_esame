/*
 ============================================================================
 Name        : media,.c
 Author      : sergio
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define DIM 10

typedef struct {

	int matricola;
	int voto;

}vettore_studenti;

void sposta_file(FILE *fp,vettore_studenti vet[]);
float media_voti_promossi(vettore_studenti vet[],int n);
int percentuale_promossi(vettore_studenti vet[],int n);
int conta_studenti_promossi(vettore_studenti vet[],int n);

int main(void) {

	vettore_studenti vet[DIM];
	FILE *fp;
	int n;
	float media;
	int percentuale;
	int conta;

	fp=fopen("potty.txt","r");

	if(fp==NULL){
		printf("\nerrore nell`apertura del file\n");
	}else{

		fscanf(fp,"%d",&n);

		sposta_file(fp,vet);

		printf("\necco la media degli studenti promossi\n");
		media=media_voti_promossi(vet,n);
		printf("%1.2f",media);

		printf("\necco la percentuale dei studenti promossi\n");
		percentuale=percentuale_promossi(vet,n);
		printf("%d",percentuale);

		printf("\necco quanti studenti sono stati promossi\n");
		conta=conta_studenti_promossi(vet,n);
		printf("%d",conta);


	}



	system("pause");
	return EXIT_SUCCESS;
}

void sposta_file(FILE *fp,vettore_studenti vet[]){

	int i;

	i=0;
	while(fscanf(fp,"%d%d",&vet[i].matricola,&vet[i].voto)!=EOF){
		i=i+1;
	}
}

float media_voti_promossi(vettore_studenti vet[],int n){

	int i;
	int somma;
	float media;
	int conta;

	conta=0;
	somma=0;
	i=0;
	while(i<n){
		if(vet[i].voto>18){
			somma=somma+vet[i].voto;
			conta=conta+1;
		}
		i=i+1;
	}
	media=(float)somma/conta;
	return media;
}

int percentuale_promossi(vettore_studenti vet[],int n){

	int i;
	int conta;
	float divisione;
	int percentuale;

	conta=0;
	i=0;
	while(i<n){
		if(vet[i].voto>18){
			conta=conta+1;
		}
		i=i+1;
	}
	divisione=((float)conta/n);
	percentuale=divisione*100;
	return percentuale;
}

int conta_studenti_promossi(vettore_studenti vet[],int n){

	int i;
	int conta;

	conta=0;
	i=0;
	while(i<n){
		if(vet[i].voto>18){
			conta=conta+1;
		}
		i=i+1;
	}
	return conta;
}
