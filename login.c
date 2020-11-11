/*
 * login.c
 *
 *  Created on: 11 de nov. de 2020
 *      Author: fabioalvaro
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main() {

	char nome[50];
	char senha[50];

	printf("digite seu email: ");
	scanf("%s", nome);

	printf("digite a senha e pressione enter: ");
	scanf("%s", senha);
	if (strcmp(senha, "123") == 0) {
		printf("**** colocar o menu aqui****");

	}else{
		printf("\n [ERRO] usuario e/ou senha inválida!!!!");
	}

}

