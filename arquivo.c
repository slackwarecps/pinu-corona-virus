/*
 * Principal.c
 *
 *  Created on: 6 de nov. de 2020
 *      Author: fabioalvaro
 */

// ************************************************************
//   Exemplo de uso de arquivo texto
//   Este programa lê um arquivo texto e imprime o seu
//   conteudo na tela.
// ************************************************************
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void concatenate_string(char*, char*);

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
	FILE *farquivo;
	int i;
	char tsaida[50], car;
	struct cadastroData registro;

	char *SEPARADOR = ";";
	char linha[1000] = "";

	//REGISTRO DE EXEMPLO
	registro.nome = "FABIO ALVARO PEREIRA";
	registro.cpf = "26721993877";
	registro.telefone = "11983477360";
	registro.rua = "DOUTOR LUCIO PEREIRA PEIXOTO";
	registro.numero = "9090";
	registro.bairro = "JARDIM CHAPADAO";
	registro.cidade = "CAMPINAS";
	registro.estado = "SP";
	registro.cep = "13070-028";
	registro.dtnasc = "20-04-1979";
	registro.dtdiag = "06-11-2020";
	registro.email = "fabio.alvaro@gmail.com";
	registro.comorbidade =
			"Diabetes, obesidade, hipertensão, tuberculose, outros";

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

	// gravando no arquivo texto
	if ((farquivo = fopen("arqtexto.txt", "w")) == NULL) {
		printf("Erro na abertura do arquivo");
		exit(1);
	}
	fputs(linha, farquivo);
	fputs("\r\n", farquivo);
	fclose(farquivo);

	// Abrindo e mostrando...
	farquivo = fopen("arqtexto.txt", "r");
	if (farquivo == NULL) // Pode-se fazer o teste dessa forma
	{
		printf("Erro na abertura do arquivo");
		exit(1);
	}

	printf("\n\nVou ler e mostrar o texto gravado....\n\n");
	i = 0;
	car = fgetc(farquivo);
	while (car != EOF) {
		tsaida[i] = car;
		printf("%c", tsaida[i]);
		i++;
		car = fgetc(farquivo);
	}
	fclose(farquivo);

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
