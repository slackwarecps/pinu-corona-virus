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
int salvarRisco();
int mostrarArquivo();
int anoHoje();
int pegaData();
int pegaDataDiag();
int validarCPF();
int ufValida();
void defaultScanf (char *value, char defaultValue);
char gethoje();
int emailValida();

char linhaPadrao[] =
		"============================================================================\n";
int anoNasc, anoDiag;
int idade;
int dataValida = 0;
int dataValidadiag = 0;
char *toda[10];

char teste[50];

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
	int grupoRisco;
};

int main() {





	//============================================================================
	printf("%s", linhaPadrao);
	printf(
			"|             SISTEMA HOSPITALAR DE INFORMACAO SOBRE O COVID               |\n");
	printf(
			"|                      VERSAO 1.0   UNIP   PIM IV                          |\n");
	// print string
	printf("%s", linhaPadrao);
	printf("LOGIN \n\n");
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

	int a, b, c, numerox, grupoRisco;
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
	int x;

	grupoRisco = 0;

	printf("\n CADASTRO \n");
	printf("=========================== \n");

//	printf("Primeiro nome: ");
//	scanf("%s", nome);

	do {
		printf("Primeiro nome: ");
		x = scanf("%s", nome);

		if (x == 0) {
			char c;
			printf(" [Primeiro nome] pressione qualquer tecla \n");
			c = getchar();
		} else {
			if (strlen(nome) > 50) {
				printf(
						" [Primeiro nome] Campo deve ter menor de 50 caracteres.  \n");
				x = 0;
				c = getchar();

			}
		}

	} while (x == 0);

//	printf("CPF [somente numeros]: ");
//	scanf("%s", cpf);
	do {
		printf("CPF [somente numeros]: ");
		x = scanf("%s", cpf);

		if (x == 0) {
			char c;
			printf(" [CPF] pressione qualquer tecla \n");
			c = getchar();
		} else {
			if (strlen(cpf) != 11) {
				printf(
						" [CPF] Campo deve ter 11 caracteres. pressione qualquer tecla  \n");
				x = 0;
				c = getchar();

			}
			if (validarCPF(cpf) == 0) {
				printf(" [CPF] CPF invalido!!!. pressione qualquer tecla \n");
				x = 0;
				c = getchar();
			}
		}

	} while (x == 0);

	printf("Telefone: ");
	scanf("%s", telefone);

	printf("Rua: ");
	scanf("%s", rua);

	printf("Numero: ");
	scanf("%s", numero);

	printf("Bairro: ");
	scanf("%s", bairro);

	printf("Cidade: ");
	scanf("%s", cidade);

//	printf("Estado[UF]: ");
//	scanf("%s", estado);
	do {
		printf("Estado[UF] Letras Maiusculas: ");
		x = scanf("%s", estado);

		if (x == 0) {
			char c;
			printf("Estado[UF] pressione qualquer tecla \n");
			c = getchar();
		} else {
			if (strlen(estado) != 2) {
				printf(
						"Estado[UF] Campo deve ter 2 caracteres texto. pressione qualquer tecla  \n");
				x = 0;
				c = getchar();

			}
			if (ufValida(estado) == 0) {
				printf(
						"Estado[UF] UF invalido!!!. pressione qualquer tecla \n");
				x = 0;
				c = getchar();
			}
		}

	} while (x == 0);

//	printf("CEP: ");
//	scanf("%s", cep);
	do {
		printf("CEP [FORMATO: NNNNNNNN, SOMENTE NUMEROS]: ");
		x = scanf("%s", cep);

		if (x == 0) {
			char c;
			printf("Estado[UF] pressione qualquer tecla \n");
			c = getchar();
		} else {
			if (strlen(cep) != 8) {
				printf(
						"CEP Campo deve ter 8 caracteres NUMEROS. pressione qualquer tecla  \n");
				x = 0;
				c = getchar();

			}

		}

	} while (x == 0);



	//inico do pega e valida o campo dt.nasc.
	do {
		dataValida = pegaData();
		if (dataValida == 1) {
			break;
		} else {
			printf("\n data nascimento invalida, digite novamente....\n");
		}
	} while (dataValida == 0);
	//fim do pega e valida dt.nasc

//	printf("DT.DIAGNOSTICO: ");
//	scanf("%s", dtdiag);
	//inico do pega e valida o campo dt.nasc.
	do {
		dataValidadiag = pegaDataDiag();
		if (dataValidadiag == 1) {
			break;
		} else {
			printf("\n data diagnotico invalida, digite novamente....\n");
		}
	} while (dataValidadiag == 0);
	//fim do pega e valida dt.nasc

	printf("E-MAIL: ");
	scanf("%s", email);

	printf("COMORBIDADES: ");
	scanf("%s", comorbidades);

	printf("\n \n Dados Recebidos....\n");

	printf("nome: 			%s \n", nome);
	printf("cpf: 			%s \n", cpf);
	printf("telefone: 		%s \n", telefone);
	printf("rua: 			%s \n", rua);
	printf("Numero: 		%s \n", numero);
	printf("Bairro: 		%s \n", bairro);
	printf("cidade: 		%s \n", cidade);
	printf("estado: 		%s \n", estado);
	printf("cep: 			%s \n", cep);
	//printf("dt.nascimento: 	%s \n", anoNasc);
	//TestaData

	//printf("dt.diagnotico: 	%s \n", dtdiag);
	printf("e-mail: 		%s \n", email);
	printf("comorbidades: 	%s \n", comorbidades);

	//printf("\n ANO NASCIMENTO: %d.\n", anoNasc);

	idade = anoHoje() - anoNasc;
//	printf("\n Idade : %d.\n", idade);

	if (idade >= 65) {
		grupoRisco = 1;
	}

	if (grupoRisco == 0) {
		printf("\n\n------------------------------- \n");
		printf("|  CADASTRADO COM SUCESSO!    | \n");
		printf("------------------------------- \n\n\n");
	} else {
		printf("\n\n******************************* \n");
		printf("* Paciente de grupo de Risco! * \n");
		printf("*    CADASTRADO COM SUCESSO   * \n");
		printf("******************************* \n\n\n");
	}

	printf("\n\n\n");

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
	registro.comorbidade = comorbidades;
	registro.grupoRisco = grupoRisco;

	salvar(registro);

	return 0;
}

int salvar(struct cadastroData pRegistro, int risco) {

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

	salvarRisco(pRegistro);

	return 0;
}

int salvarRisco(struct cadastroData pRegistro) {

	//printf(" Nome is: %s \n", pRegistro.nome);

	FILE *farquivo;
	int i;
	char tsaida[50], car;
	struct cadastroData registro;
	registro = pRegistro;

	char *SEPARADOR = ";";
	char linha[1000] = "";

	concatenate_string(linha, registro.cpf);
	concatenate_string(linha, SEPARADOR);
	concatenate_string(linha, registro.cep);

	concatenate_string(linha, SEPARADOR);
	concatenate_string(linha, "\n");

	// gravando no arquivo texto
	if ((farquivo = fopen("secretaria_saude.csv", "a+")) == NULL) {
		printf("Erro na abertura do arquivo");
		exit(1);
	}
	fputs(linha, farquivo);
	fclose(farquivo);

	return 0;
}

int mostrarArquivo() {
	FILE *farquivo;
	int i;
	char tsaida[50], car;

	farquivo = fopen("secretaria_saude.csv", "r");
	if (farquivo == NULL) // Pode-se fazer o teste dessa forma
	{
		printf("Erro na abertura do arquivo");
		exit(1);
	}
	printf(
			"\n\n O ARQUIVO PODE SER LOCALIZADO JUNTO AO EXECUTAVEL E SE CHAMA secretaria_saude.csv  \n\n");
	i = 0;
	car = fgetc(farquivo);
	while (car != EOF) {
		tsaida[i] = car;
		printf("%c", tsaida[i]);
		i++;
		car = fgetc(farquivo);
	}
	fclose(farquivo);

	printf("\n\n");
	return 0;

}

int anoHoje() {
	return 2020;
}

int pegaData() { // @suppress("No return")
	int dd, mm, yy;
	dd = -1;
	mm = -1;
	yy = -1;
	int x;
	int retorno = 0;
	int a;
	x = 0;

	do {
		printf("[DT.NASCIMENTO]Entre uma data (DD/MM/YYYY formato): ");
		x = scanf("%d/%d/%d", &dd, &mm, &yy);

		if (x == 0) {
			char c;
			printf(" [dt.nasc] pressione qualquer tecla \n");
			c = getchar();
		}

	} while (x == 0);

//check year
	if (yy >= 1900 && yy <= 9999) {
//check month
		if (mm >= 1 && mm <= 12) {
//check days
			if ((dd >= 1 && dd <= 31)
					&& (mm == 1 || mm == 3 || mm == 5 || mm == 7 || mm == 8
							|| mm == 10 || mm == 12)) {
				//printf("\n dia is valid.\n");
				retorno = 1;
			} else if ((dd >= 1 && dd <= 30)
					&& (mm == 4 || mm == 6 || mm == 9 || mm == 11)) {
				//printf("\n Date is valid.\n");
				retorno = 1;
			} else if ((dd >= 1 && dd <= 28) && (mm == 2)) {
				//printf("\n Date is valid.\n");
				retorno = 1;
			} else if (dd == 29 && mm == 2
					&& (yy % 400 == 0 || (yy % 4 == 0 && yy % 100 != 0))) {
				//printf("\n Date is valid.\n");

				retorno = 1;
			} else {
				printf("\n Dia não é valido.\n");

			}
		} else {
			printf("\n Mes não é valido.\n");
			retorno = 0;
		}
	} else {
		printf("\n A data não é valida. \n");
		retorno = 0;
	}
	//printf("retorno foi %d \n",retorno);
	if (retorno == 1) {
		anoNasc = yy;
	}
	return retorno;
}

int pegaDataDiag() { // @suppress("No return")
	int dd, mm, yy;

	dd = -1;
	mm = -1;
	yy = -1;
	int x;
	int retorno = 0;
	int a;
	x = 0;

	do {
		printf("[DT.DIAGNOSTICO] Entre uma data (DD/MM/YYYY formato): ");
		x = scanf("%d/%d/%d", &dd, &mm, &yy);

		if (x == 0) {
			char c;
			printf(" [dt.diagnotico] pressione qualquer tecla \n");
			c = getchar();
		}

	} while (x == 0);

//check year
	if (yy >= 1900 && yy <= 9999) {
//check month
		if (mm >= 1 && mm <= 12) {
//check days
			if ((dd >= 1 && dd <= 31)
					&& (mm == 1 || mm == 3 || mm == 5 || mm == 7 || mm == 8
							|| mm == 10 || mm == 12)) {
				//printf("\n dia is valid.\n");
				retorno = 1;
			} else if ((dd >= 1 && dd <= 30)
					&& (mm == 4 || mm == 6 || mm == 9 || mm == 11)) {
				//printf("\n Date is valid.\n");
				retorno = 1;
			} else if ((dd >= 1 && dd <= 28) && (mm == 2)) {
				//printf("\n Date is valid.\n");
				retorno = 1;
			} else if (dd == 29 && mm == 2
					&& (yy % 400 == 0 || (yy % 4 == 0 && yy % 100 != 0))) {
				//printf("\n Date is valid.\n");

				retorno = 1;
			} else {
				printf("\n Dia não é valido.\n");

			}
		} else {
			printf("\n Mes não é valido.\n");
			retorno = 0;
		}
	} else {
		printf("\n A data não é valida. \n");
		retorno = 0;
	}
	//printf("retorno foi %d \n",retorno);
	if (retorno == 1) {
		anoDiag = yy;
	}
	return retorno;
}

int validarCPF(char *cpf) {
	int i, j, digito1 = 0, digito2 = 0;
	if (strlen(cpf) != 11)
		return 0;
	else if ((strcmp(cpf, "00000000000") == 0)
			|| (strcmp(cpf, "11111111111") == 0)
			|| (strcmp(cpf, "22222222222") == 0)
			|| (strcmp(cpf, "33333333333") == 0)
			|| (strcmp(cpf, "44444444444") == 0)
			|| (strcmp(cpf, "55555555555") == 0)
			|| (strcmp(cpf, "66666666666") == 0)
			|| (strcmp(cpf, "77777777777") == 0)
			|| (strcmp(cpf, "88888888888") == 0)
			|| (strcmp(cpf, "99999999999") == 0))
		return 0; ///se o CPF tiver todos os números iguais ele é inválido.
	else {
		///digito 1---------------------------------------------------
		for (i = 0, j = 10; i < strlen(cpf) - 2; i++, j--) ///multiplica os números de 10 a 2 e soma os resultados dentro de digito1
			digito1 += (cpf[i] - 48) * j;
		digito1 %= 11;
		if (digito1 < 2)
			digito1 = 0;
		else
			digito1 = 11 - digito1;
		if ((cpf[9] - 48) != digito1)
			return 0; ///se o digito 1 não for o mesmo que o da validação CPF é inválido
		else
		///digito 2--------------------------------------------------
		{
			for (i = 0, j = 11; i < strlen(cpf) - 1; i++, j--) ///multiplica os números de 11 a 2 e soma os resultados dentro de digito2
				digito2 += (cpf[i] - 48) * j;
			digito2 %= 11;
			if (digito2 < 2)
				digito2 = 0;
			else
				digito2 = 11 - digito2;
			if ((cpf[10] - 48) != digito2)
				return 0; ///se o digito 2 não for o mesmo que o da validação CPF é inválido
		}
	}
	return 1;
}

int ufValida(char *uf) {



	int i, retorno = 0, n;

	char uf_list[27][20] = { "AC", "AL", "AM", "AP", "BA", "CE", "DF", "ES",
			"GO", "MA", "MT", "MS", "MG", "PA", "PB", "PR", "PE", "PI", "RJ",
			"RN", "RO", "RS", "RR", "SC", "SE", "SP", "TO" }, name[10];

	for (i = 0; i < 27; i++) {
		if (strcmp(uf, uf_list[i]) == 0) {

			retorno = 1;
			break;
		}
	}

	return retorno;

}


void defaultScanf (char *value, char defaultValue)
{
    char trash;

    *value = getchar();
    /* set your default valut */
    if (*value == '\n') {
        *value = defaultValue;
    } else {
        *value -= '0'; /* transform char to int */

        /* clean your buffer */
        do trash = getchar();
        while (trash != '\n' && trash != EOF);
    }
}



int emailValida (char *email2)
{
	int i, retorno = 0, n;
	char email[50]="eu@eu.com.br";

	printf( "tamanho do email %s \n",  strlen(email)    );

	for (i = 0; i < 50 ; i++) {

		printf("%s \n",  email[i]      );

//		if (strcmp("@",email[i]) == 0) {
//
//			retorno = 1;
//			break;
//		}


	}
//
//	if (strlen(email)<7){
//		retorno = 0;
//		}


	return retorno;
}
