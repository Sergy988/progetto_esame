/*
 ============================================================================
 Name        : progetto_esame.c
 Author      : sergio
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct {

	char mese[21];
	int temperatura;

}vettore_temperature;

void sposta_contenuto_file(FILE *fp,vettore_temperature temp[]);
float media_temperatura(vettore_temperature temp[]);
int temperatura_piu_alta(vettore_temperature temp[]);
void stampa_temperatura_alta(vettore_temperature temp[]);


int main(void) {

	FILE *fp;
	vettore_temperature temp[20];
	float media;


	fp=fopen("vet_temp.txt","r");

	if(fp==NULL){
		printf("errore nell`apertura del file");
	}else{

		sposta_contenuto_file(fp,temp);

		printf("\necco la media delle temperature\n");
		media=media_temperatura(temp);
		printf("%1.2f\n",media);

		stampa_temperatura_alta(temp);

	}

	system("pause");
	return EXIT_SUCCESS;
}

void sposta_contenuto_file(FILE *fp,vettore_temperature temp[]){

	int i;
	char carattere;

	i=0;
	while((carattere=fgetc(fp))!=EOF){
		if(carattere=='('){
			fscanf(fp,"%s%d*c",temp[i].mese,&temp[i].temperatura);
			i=i+1;
		}

	}
}

float media_temperatura(vettore_temperature temp[]){

	int i;
	int somma;
	float media;

	somma=0;
	i=0;
	while(i<12){
		somma=somma+temp[i].temperatura;
		i=i+1;
	}
	media=(float)somma/12;
	return media;

}

int temperatura_piu_alta(vettore_temperature temp[]){

	int i;
	int temp_alta;

	temp_alta=0;
	i=0;
	while(i<12){
		if(temp[i].temperatura>temp_alta){
			temp_alta=temp[i].temperatura;
		}
		i=i+1;
	}
	return temp_alta;
}

void stampa_temperatura_alta(vettore_temperature temp[]){

	int i;
	int temperatura_alta;

	temperatura_alta=temperatura_piu_alta(temp);
	i=0;
	while(i<12){
		if(temp[i].temperatura==temperatura_alta){
			printf("(%s) ",temp[i].mese);
		}
		i=i+1;
	}
}
