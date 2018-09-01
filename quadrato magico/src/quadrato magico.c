/*
 ============================================================================
 Name        : quadrato.c
 Author      : sergio
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define DIM 10

int somma_riga(int matrice[][DIM],int n,int i);
int somma_colonna(int matrice[][DIM],int n,int j);
int somma_diagonale_principale(int matrice[][DIM],int n);
int somma_diagonale_secondaria(int matrice[][DIM],int n);
int verifica_quadrato_magico(int matrice[][DIM],int n);

int main(void) {

	int matrice[DIM][DIM];
	int valore;
	int n;

	n=3;

	matrice[0][0]=2;
	matrice[0][1]=7;
	matrice[0][2]=6;

	matrice[1][0]=9;
	matrice[1][1]=5;
	matrice[1][2]=1;

	matrice[2][0]=4;
	matrice[2][1]=3;
	matrice[2][2]=8;

	valore=verifica_quadrato_magico(matrice,n);
	printf("%d",valore);

	system("pause");
	return EXIT_SUCCESS;
}

int somma_riga(int matrice[][DIM],int n,int i){

	int somma;
	int j;

	somma=0;
	j=0;
	while(j<n){
		somma=somma+matrice[i][j];
		j=j+1;
	}
	return somma;
}

int somma_colonna(int matrice[][DIM],int n,int j){

	int somma;
	int i;

	somma=0;
	i=0;
	while(i<n){
		somma=somma+matrice[i][j];
		i=i+1;
	}
	return somma;
}

int somma_diagonale_principale(int matrice[][DIM],int n){

	int somma;
	int i;
	int j;

	somma=0;
	i=0;
	j=0;
	while(i<n){
		somma=somma+matrice[i][j];
		i=i+1;
		j=j+1;
	}
	return somma;
}

int somma_diagonale_secondaria(int matrice[][DIM],int n){

	int i;
	int j;
	int somma;

	somma=0;
	i=0;
	j=n-1;
	while(i<n){
		somma=somma+matrice[i][j];
		i=i+1;
		j=j-1;
	}
	return somma;
}

int verifica_quadrato_magico(int matrice[][DIM],int n){

	int somma_rig;
	int somma_col;
	int i;
	int j;
	int valore;

	i=0;
	while(i<n){
		somma_rig=somma_riga(matrice,n,i);
		i=i+1;
	}
	j=0;
	while(j<n){
		somma_col=somma_colonna(matrice,n,j);
		j=j+1;
	}
	if(somma_rig==somma_col && somma_diagonale_principale(matrice,n)==somma_riga(matrice,n,0) && somma_diagonale_secondaria(matrice,n)==somma_riga(matrice,n,0)){
		valore=1;
	}else{
		valore=0;
	}
	return valore;
}
