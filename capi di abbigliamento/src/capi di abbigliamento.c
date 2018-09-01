/*
 ============================================================================
 Name        : capi.c
 Author      : sergio
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void aggiornamento_prezzi(FILE *capi,FILE *prezzi,FILE *capi_aggionati);

int main(void) {

	FILE *capi;
	FILE *prezzi;
	FILE *capi_aggiornati;

	capi=fopen("capi.txt","r");
	prezzi=fopen("prezzi.txt","r");
	capi_aggiornati=fopen("capi_aggiornati.txt","w");

	aggiornamento_prezzi(capi,prezzi,capi_aggiornati);

	fclose(capi_aggiornati);
	fclose(prezzi);
	fclose(capi);


	system("pause");
	return EXIT_SUCCESS;
}

void aggiornamento_prezzi(FILE *capi,FILE *prezzi,FILE *capi_aggionati){

	char codice[21];
	char descrizione[21];
	char composizione[21];
	int taglio;
	float prezzo;

	char codice_2[21];
	float prezzo_aggiornato;

	while(!feof(capi) && !feof(prezzi)){
		fscanf(capi,"%s%s%s%d%f",codice,descrizione,composizione,&taglio,&prezzo);
		printf("%s %s %s %d %1.2f\n",codice,descrizione,composizione,taglio,prezzo);
		fscanf(prezzi,"%s%f",codice_2,&prezzo_aggiornato);
		if(strcmp(codice,codice_2)==0){
			fprintf(capi_aggionati,"%s %s %s %d %1.2f",codice,descrizione,composizione,taglio,prezzo_aggiornato);
			printf("%s %s %s %d %1.2f\n",codice,descrizione,composizione,taglio,prezzo_aggiornato);
		}else{
			printf("errore in questo codice %s\n",codice_2);
			while(strcmp(codice,codice_2)!=0){
				fscanf(prezzi,"%s%f",codice_2,&prezzo_aggiornato);
			}
			printf("%s %s %s %d %1.2f\n",codice,descrizione,composizione,taglio,prezzo_aggiornato);
			fprintf(capi_aggionati,"%s %s %s %d %1.2f",codice,descrizione,composizione,taglio,prezzo);
		}
	}
}
