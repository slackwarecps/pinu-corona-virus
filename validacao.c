/*
 * validacao.c
 *
 *  Created on: 13 de nov. de 2020
 *      Author: fabioalvaro
 */
#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int pegaData();
int anoHoje();

int anoNasc;
int validaNumeros(char limiteInferior,char limiteSuperior);
int inteiro_validado();
int anoHoje(){
	return 2020;
}


int main() {
	int choice,numero;
	int idade;
	char response, Y, N;
	int dataValida=0;

	int i = inteiro_validado();
	printf("passou");
	return 0;


	int tipo;
	tipo = scanf("%d", &numero);
	if(tipo == 0) printf("dado digitado errado");
	       else printf("dado correto");

return 0;



}



int pegaData() { // @suppress("No return")


	int dd, mm, yy;
	int x;
	dd=-1;
	mm=-1;
	yy=-1;


	int retorno=0;
	int *a;

	x=0;

	 do {
	      printf("\nEnter any integer: ");

	      x = scanf("%u",&a);

	      printf("%u",a);

	      if( x == 0)
	      {
	           char c;
	           printf("hit any key \n");
	           c = getchar();
	      }

	    } while(x==0);

		printf("Entre uma data (DD/MM/YYYY formato): ");
		x = scanf("%d/%d/%d", &dd, &mm, &yy);


//check year
	if (yy >= 1900 && yy <= 9999) {
//check month
		if (mm >= 1 && mm <= 12) {
//check days
			if ((dd >= 1 && dd <= 31)
					&& (mm == 1 || mm == 3 || mm == 5 || mm == 7 || mm == 8
							|| mm == 10 || mm == 12)) {
				//printf("\n dia is valid.\n");
				retorno= 1;
			} else if ((dd >= 1 && dd <= 30)
					&& (mm == 4 || mm == 6 || mm == 9 || mm == 11)) {
				//printf("\n Date is valid.\n");
				retorno=  1;
			} else if ((dd >= 1 && dd <= 28) && (mm == 2)) {
				//printf("\n Date is valid.\n");
				retorno= 1;
			} else if (dd == 29 && mm == 2
					&& (yy % 400 == 0 || (yy % 4 == 0 && yy % 100 != 0))) {
				//printf("\n Date is valid.\n");

				retorno=  1;
			} else {
				printf("\n Dia não é valido.\n");

			}
		} else {
			printf("\n Mes não é valido.\n");
			retorno= 0;
		}
	} else {
		printf("\n A data não é valida. \n");
		retorno = 0;
	}
	//printf("retorno foi %d \n",retorno);
	if (retorno ==1) {
		anoNasc=yy;
	}
	return retorno;
}


