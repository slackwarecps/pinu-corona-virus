/*
 * login.c
 *
 *  Created on: 11 de nov. de 2020
 *      Author: fabioalvaro
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> //necessário para usar localtime() e struct tm

void limpar(int cmdClean);
void concatenate_string(char*, char*);
int menu();
int cadastro();
int salvar();
int mostrarArquivo();

struct cadastroData {
	char *nome;
	char *cpf;
	char *telefone;
	char *rua;
	char *numero;
	char *bairro;
	char *cidade;
	char *estado;
	char *cep;
	char *dtnasc;
	char *dtdiag;
	char *email;
	char *comorbidade;
};

int main() {

	char nome[50];
	char senha[50];

	printf("digite seu email: ");
	scanf("%s", nome);

	printf("digite a senha e pressione enter: ");
	scanf("%s", senha);

	//printf("voce digitou %s",senha);

	if (strcmp(senha, "123") == 0) {
		//printf("\n\n **** PASSOU colocar o menu aqui \n\n ****");
		menu();

	} else {
		printf("\n\n [ERRO] Usuario e/ou senha invalidas. \n");
		return 0;
	}

}

void limpar(int cmdClean) {
	if (cmdClean == 1) {
		system("clear");
	} else {
		system("cls");
	}

}

// Concatena os textos
void concatenate_string(char *original, char *add) {
	while (*original)
		original++;

	while (*add) {
		*original = *add;
		add++;
		original++;
	}
	*original = '\0';
}

int menu() {
	int cmdClean = 0;
#ifdef _WIN32 // Includes both 32 bit and 64 bit
    #ifdef _WIN64
        //printf("Windows 64 bit\n");
    #else
       // printf("Windows 32 bit\n");
    #endif
#else
	//  printf("Not a Windows OS\n");
	cmdClean = 1;
#endif

	limpar(cmdClean);

	int choice;

	char linhaPadrao[] =
			"============================================================================\n";

	do {
		//============================================================================
		printf("%s", linhaPadrao);
		printf(
				"|             SISTEMA HOSPITALAR DE INFORMACAO SOBRE O COVID               |\n");
		printf(
				"|                      VERSAO 1.0   UNIP   PIM IV                          |\n");

		// print string
		printf("%s", linhaPadrao);
		printf("Menu \n\n");
		printf(" 1)Cadastrar  \n");
		printf(" 2)Exportar lista de infectados\n");
		printf(" 4)Sair \n");
		printf("%s", linhaPadrao);
		scanf("%d", &choice);

		switch (choice) {
		case 1:
			/* faz o cadastro*/
			cadastro();
			break;
		case 2:
			/*mostra o arquivo*/
			mostrarArquivo();
			break;

		case 4:
			printf("saiu do programa \n");
			break;

		default:

			if (cmdClean == 1) {
				system("clear");
			} else {
				system("cls");
			}

			printf("%d. ", choice);
			printf("Escolha invalida, tente novamente!! \n");
			break;
		}

	} while (choice != 4);

	return 0;
}

int cadastro() {

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
	struct cadastroData registro;




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

	//REGISTRO DE EXEMPLO
	registro.nome = nome;
	registro.cpf = cpf;
	registro.telefone = telefone;
	registro.rua = rua;
	registro.numero = numero;
	registro.bairro = bairro;
	registro.cidade = cidade;
	registro.estado = estado;
	registro.cep = cep;
	registro.dtnasc = dtnasc;
	registro.dtdiag = dtdiag;
	registro.email = email;
	registro.comorbidade =comorbidades;


	 salvar(registro);

	return 0;
}

int salvar(struct cadastroData pRegistro) {


	//printf(" Nome is: %s \n", pRegistro.nome);

	FILE *farquivo;
	int i;
	char tsaida[50], car;
	struct cadastroData registro;
	registro = pRegistro;

	char *SEPARADOR = ";";
	char linha[1000] = "";



	concatenate_string(linha, registro.nome);
	concatenate_string(linha, SEPARADOR);
	concatenate_string(linha, registro.cpf);
	concatenate_string(linha, SEPARADOR);
	concatenate_string(linha, registro.telefone);
	concatenate_string(linha, SEPARADOR);
	concatenate_string(linha, registro.rua);
	concatenate_string(linha, SEPARADOR);
	concatenate_string(linha, registro.numero);
	concatenate_string(linha, SEPARADOR);
	concatenate_string(linha, registro.bairro);
	concatenate_string(linha, SEPARADOR);
	concatenate_string(linha, registro.cidade);
	concatenate_string(linha, SEPARADOR);
	concatenate_string(linha, registro.estado);
	concatenate_string(linha, SEPARADOR);
	concatenate_string(linha, registro.cep);
	concatenate_string(linha, SEPARADOR);
	concatenate_string(linha, registro.dtnasc);
	concatenate_string(linha, SEPARADOR);
	concatenate_string(linha, registro.dtdiag);
	concatenate_string(linha, SEPARADOR);
	concatenate_string(linha, registro.email);
	concatenate_string(linha, SEPARADOR);
	concatenate_string(linha, registro.comorbidade);
	concatenate_string(linha, SEPARADOR);
	concatenate_string(linha, "\n");

	// gravando no arquivo texto
	if ((farquivo = fopen("arqtexto.txt", "a+")) == NULL) {
		printf("Erro na abertura do arquivo");
		exit(1);
	}
	fputs(linha, farquivo);
	fclose(farquivo);


	return 0;
}


int mostrarArquivo(){
	FILE *farquivo;
	int i;
	char tsaida[50], car;

	farquivo = fopen("arqtexto.txt", "r");
	if (farquivo == NULL) // Pode-se fazer o teste dessa forma
	{
		printf("Erro na abertura do arquivo");
		exit(1);
	}
	printf("\n\n O ARQUIVO PODE SER LOCALIZADO JUNTO AO EXECUTAVEL E SE CHAMA arqtexto.txt  \n\n");
	i = 0;
	car = fgetc(farquivo);
	while (car != EOF) {
		tsaida[i] = car;
		printf("%c", tsaida[i]);
		i++;
		car = fgetc(farquivo);
	}
	fclose(farquivo);
	return 0;

}
