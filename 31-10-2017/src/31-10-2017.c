/*
 ============================================================================
 Name        : 31-10-2017.c
 Author      : sergio
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define DIM 15
#define vero 1
#define falso 0
typedef int bool;

void inserisci_numeri_vettore(int vettore[],int n);
bool ripetuto(int vettore[],int i);
int valore_piu_presente(int vettore[],int n);
int valore_meno_presente(int vettore[],int n);
int calcolareFrequenza(int vettore[], int i, int n);

int main(void) {

	int vettore[DIM];
	int n;
	int valore_piu_frequente;
	int valore_meno_frequente;


    n=10;

	//inserisci_numeri_vettore(vettore,n);

	vettore[0]=56;
	vettore[1]=56;
	vettore[2]=56;
	vettore[3]=56;
	vettore[4]=56;
	vettore[5]=56;
	vettore[6]=56;
	vettore[7]=56;
	vettore[8]=56;
	vettore[9]=19;



	printf("\necco il valore piu presente\n");
	valore_piu_frequente=valore_piu_presente(vettore,n);
	printf("%d",valore_piu_frequente);

	printf("\necco il valore meno presente\n");
	valore_meno_frequente=valore_meno_presente(vettore,n);
	printf("%d",valore_meno_frequente);


	system("pause");
	return EXIT_SUCCESS;
}

void inserisci_numeri_vettore(int vettore[],int n){

	int i;

	i=0;
	while(i<n){
		printf("inserisci il numero: ");
		scanf("%d",&vettore[i]);
		i=i+1;
	}
}

bool ripetuto(int vettore[],int i){

	bool esito;
	int j;

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

int calcolareFrequenza(int vettore[], int i, int n){

	int frequenza;
	int j;

	frequenza=1;
	j=0;
	while(j<n){
		if(vettore[i]==vettore[j] && i!=j){
			frequenza=frequenza+1;
		}
		j=j+1;
	}
	return frequenza;
}

int valore_piu_presente(int vettore[],int n){


	int i;
	int massima_frequenza;
	int frequenza;
	int piu_presente;

	massima_frequenza=0;
	i=0;
	while(i<n){
		if(ripetuto(vettore,i)==falso){
			frequenza=calcolareFrequenza(vettore,i,n);
			if(frequenza>massima_frequenza){
				massima_frequenza=frequenza;
				piu_presente=vettore[i];
			}
		}
		i=i+1;
	}

	return piu_presente;
}

int valore_meno_presente(int vettore[],int n){

	int i;
	int minima_frequenza;
	int frequenza;
	int meno_presente;

	minima_frequenza=n+1;
	i=0;
	while(i<n){
		if(ripetuto(vettore,i)==falso){
			frequenza=calcolareFrequenza(vettore,i,n);
			if(frequenza<minima_frequenza){
				minima_frequenza=frequenza;
				meno_presente=vettore[i];
			}
		}
		i=i+1;
	}

	return meno_presente;
}
