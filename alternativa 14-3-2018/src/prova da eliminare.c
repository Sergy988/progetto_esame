/*
 ============================================================================
 Name        : prova.c
 Author      : sergio
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct {

	char nome[21];
	char cognome[21];
	float media;

}vettore_studente;

void sposta_contenuto_file(FILE *fp,vettore_studente vet[]);
int calcola_dimensione_vettore(FILE *fp);
void scambia_elementi_vettore(vettore_studente vet[],int i,int j);
void ordina_studente_decrescente(vettore_studente vet[],int n);
void stampa_vettore_studenti(vettore_studente vet[],int n);

int main(void) {

	FILE *fp;
	vettore_studente vet[20];
	int n;

	fp=fopen("studenti.txt","r");

	if(fp==NULL){
		printf("errore nell`apertura del file");
	}else{

		sposta_contenuto_file(fp,vet);

		rewind(fp);
		n=calcola_dimensione_vettore(fp);

		ordina_studente_decrescente(vet,n);

		stampa_vettore_studenti(vet,n);


	}
	system("pause");
	return EXIT_SUCCESS;
}

void sposta_contenuto_file(FILE *fp,vettore_studente vet[]){

	int i;

	i=0;
	while(fscanf(fp,"%s%s%f",vet[i].nome,vet[i].cognome,&vet[i].media)!=EOF){
		i=i+1;
	}
}

int calcola_dimensione_vettore(FILE *fp){

	int n;
	char nome[21];
	char cognome[21];
	float media;


	n=0;
	while(fscanf(fp,"%s%s%f",nome,cognome,&media)!=EOF){
		n=n+1;
	}
	return n;
}

void scambia_elementi_vettore(vettore_studente vet[],int i,int j){

	vettore_studente temp;

	temp=vet[i];
	vet[i]=vet[j];
	vet[j]=temp;
}

void ordina_studente_decrescente(vettore_studente vet[],int n){

	int i;
	int j;

	i=0;
	while(i<n){
		j=i+1;
		while(j<n){
			if(vet[i].media<vet[j].media){
				scambia_elementi_vettore(vet,i,j);
			}
			j=j+1;
		}
		i=i+1;
	}
}

void stampa_vettore_studenti(vettore_studente vet[],int n){

	int i;

	i=0;
	while(i<n){
		printf("%s ",vet[i].nome);
		printf("%s ",vet[i].cognome);
		printf("%1.2f\n",vet[i].media);
		i=i+1;
	}
}
