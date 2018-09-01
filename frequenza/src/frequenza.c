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

#define DIM 10

#define vero 1
#define falso 0
typedef int bool;


void inserisci_numeri_vettore(int vettore[],int n);
int conta_frequenza(int vettore[],int n,int i);
bool ripetuto(int vettore[],int i);
int valore_piu_presente(int vettore[],int n);
int valore_meno_presente(int vettore[],int n);

int main(void) {

	int vettore[DIM];
	int n;
	int val_piu_presente;
	int val_meno_presente;

	n=5;

	inserisci_numeri_vettore(vettore,n);

	printf("\necco il valore piu presente nel vettore\n");
	val_piu_presente=valore_piu_presente(vettore,n);
	printf("%d",val_piu_presente);

	printf("\necco il valore meno presente nel vettore\n");
	val_meno_presente=valore_meno_presente(vettore,n);
	printf("%d",val_meno_presente);



	system("pause");
	return EXIT_SUCCESS;
}

void inserisci_numeri_vettore(int vettore[],int n){

	int i;

	i=0;
	while(i<n){
		printf("inserisici il numero da inserire nel vettore: ");
		scanf("%d",&vettore[i]);
		i=i+1;
	}
}

int conta_frequenza(int vettore[],int n,int i){

	int conta;
	int j;

	conta=1;
	j=0;
	while(j<n){
		if(vettore[i]==vettore[j]){
			conta=conta+1;
		}
		j=j+1;
	}
	return conta;
}

bool ripetuto(int vettore[],int i){

	int j;
	bool esito;

	esito=falso;
	j=0;
	while(j<i && esito==falso){
		if(vettore[i]==vettore[j]){
			esito=vero;
		}
		j=j+1;
	}
	return esito;
}

int valore_piu_presente(int vettore[],int n){

	int i;
	int conta;
	int frequenza_maggiore;
	int valore_piu_frequente;

	frequenza_maggiore=0;
	i=0;
	while(i<n){
		if(ripetuto(vettore,i)==falso){
			conta=conta_frequenza(vettore,n,i);
			if(conta>frequenza_maggiore){
				frequenza_maggiore=conta;
				valore_piu_frequente=vettore[i];
			}
		}
		i=i+1;
	}
	return valore_piu_frequente;
}

int valore_meno_presente(int vettore[],int n){

	int i;
	int minor_frequenza;
	int conta;
	int valore_meno_frequente;

	minor_frequenza=n-1;
	i=0;
	while(i<n){
		if(ripetuto(vettore,i)==falso){
			conta=conta_frequenza(vettore,n,i);
			if(conta<minor_frequenza){
				minor_frequenza=conta;
				valore_meno_frequente=vettore[i];
			}
		}
		i=i+1;
	}
	return valore_meno_frequente;
}
