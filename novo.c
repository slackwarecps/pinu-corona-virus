/*
 * novo.c
 *
 *  Created on: 7 de nov. de 2020
 *      Author: fabioalvaro
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> //necessário para usar localtime() e struct tm


int main() {

	int a, b, c, numerox;
	char nome[50];
	char cpf[50];
	char telefone[50];

	char rua[50];
	char numero[50];
	char bairro[50];
	char cidade[50];
	char estado[50];
	char cep[50];
	char dtnasc[50];
	char dtdiag[50];
	char email[50];
	char comorbidades[50];





	printf("\n CADASTRO \n");
	printf("=========================== \n");

	printf("Primeiro nome: ");
	scanf("%s", nome);

	printf("CPF: ");
	scanf("%s", cpf);

	printf("Telefone: ");
	scanf("%s", telefone);

	printf("Rua: ");
	scanf("%s", rua);

	printf("Numero: ");
	scanf("%s", rua);


	printf("Bairro: ");
	scanf("%s", bairro);


	printf("Cidade: ");
	scanf("%s", cidade);

	printf("Estado: ");
	scanf("%s", estado);

	printf("CEP: ");
	scanf("%s", cep);

	printf("DT.NASCIMENTO: ");
	scanf("%s", dtnasc);

	printf("DT.DIAGNOSTICO: ");
	scanf("%s", dtdiag);


	printf("E-MAIL: ");
	scanf("%s", email);

	printf("COMORBIDADES: ");
	scanf("%s", comorbidades);










	printf("\n \n Dados Recebidos....\n");

	printf("nome: 			%s \n", nome);
	printf("cpf: 			%s \n", cpf);
	printf("telefone: 		%s \n", telefone);
	printf("rua: 			%s \n", rua);
    printf("numero: 		%s \n", numero);
	printf("bairro: 		%s \n", bairro);
	printf("cidade: 		%s \n", cidade);
	printf("estado: 		%s \n", estado);
	printf("cep: 			%s \n", cep);
	printf("dt.nascimento: 	%s \n", dtnasc);
	printf("dt.diagnotico: 	%s \n", dtdiag);
	printf("e-mail: 		%s \n", email);
	printf("comorbidades: 	%s \n", comorbidades);



	printf("FIM DO CADASTRO \n");
	return 0;
}

