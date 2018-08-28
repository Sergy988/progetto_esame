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

int media_valori_primi(int vett[],int n);
int valore_assoluto(int numero);
int valore_vicino_media(int vett[],int n);

int main(void) {

	int n;
	int valore;

	n=7;

	int vett[n];

	vett[0]=3;
	vett[1]=12;
	vett[2]=7;
	vett[3]=4;
	vett[4]=2;
	vett[5]=11;
	vett[6]=2;

	printf("\necco il valore vicino alla media\n");
	valore=valore_vicino_media(vett,n);
	printf("%d",valore);




	system("pause");
	return EXIT_SUCCESS;
}

int media_valori_primi(int vett[],int n){

	int i;
	int somma;
	int media;
	int conta;

	conta=0;
	somma=0;
	i=0;
	while(i<n){
		if(vett[i]%2==0){
			somma=somma+vett[i];
			conta=conta+1;
		}
		i=i+1;
	}
	media=somma/conta;
	return media;
}

int valore_assoluto(int numero){

	int valore;

	if(numero<0){
		valore=numero*-1;
	}else{
		valore=numero;
	}
	return valore;
}

int valore_vicino_media(int vett[],int n){

	int i;
	int media;
	int differenza;
	int valore;
	int numero_vicino;

	media=media_valori_primi(vett,n);
	valore=valore_assoluto(media-vett[0]);
	i=0;
	while(i<n){
		if((differenza=valore_assoluto(media-vett[i]))<valore){
			valore=differenza;
			numero_vicino=vett[i];
		}
		i=i+1;
	}
	return numero_vicino;
}
