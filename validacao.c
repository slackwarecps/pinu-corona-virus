/*
 * validacao.c
 *
 *  Created on: 13 de nov. de 2020
 *      Author: fabioalvaro
 */
#include <stdio.h>
#include <locale.h>
#include <time.h>

int pegaData();
char *dtnasc;

int main() {
	int choice;
	char response, Y, N;

	//strcpy(dtnasc, "abcde...");
	pegaData();

	for (;;) {
		if (pegaData() == 0)
			break;
		printf("\n is Invalid selection, choose again.\n");
	}
	printf("\n Fim do programa .\n");
	printf("Data informada foi %s .", dtnasc);
}

int pegaData() {
	int dd, mm, yy;
	printf("Entre uma data (DD/MM/YYYY formato): ");
	scanf("%d/%d/%d", &dd, &mm, &yy);



    sprintf(dtnasc, "%d/%d/%d", dd, mm, yy);

//check year
	if (yy >= 1900 && yy <= 9999) {
//check month
		if (mm >= 1 && mm <= 12) {
//check days
			if ((dd >= 1 && dd <= 31)
					&& (mm == 1 || mm == 3 || mm == 5 || mm == 7 || mm == 8
							|| mm == 10 || mm == 12)) {
				printf("\n dia is valid.\n");
				return 0;
			} else if ((dd >= 1 && dd <= 30)
					&& (mm == 4 || mm == 6 || mm == 9 || mm == 11)) {
				printf("\n Date is valid.\n");
				return 0;
			} else if ((dd >= 1 && dd <= 28) && (mm == 2)) {
				printf("\n Date is valid.\n");
				return 0;
			} else if (dd == 29 && mm == 2
					&& (yy % 400 == 0 || (yy % 4 == 0 && yy % 100 != 0))) {
				printf("\n Date is valid.\n");

				return 0;
			} else {
				printf("\n Dia não é valido.\n");

			}
		} else {
			printf("\n Mes não é valido.\n");
			return 1;
		}
	} else {
		printf("\n A data não é valida. \n");
		return 1;
	}

}
