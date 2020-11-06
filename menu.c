/*
 * menu.c
 *
 *  Created on: 5 de nov. de 2020
 *      Author: fabioalvaro
 */

#include <stdio.h>
#include <stdlib.h>


void limpar(int cmdClean);


int main() {
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

	 char linhaPadrao[] = "============================================================================\n";




	do {
		      //============================================================================
		printf("%s",linhaPadrao);
		printf("|          SISTEMA DE HOSPITALAR DE INFORMACAO DE COVID-19                 |\n");
		printf("|                      VERSAO 1.0   UNIP   PIM IV                          |\n");

	    // print string
		printf("%s",linhaPadrao);
		printf("Menu \n\n");
		printf(" 1)cadastrar  \n");
		printf(" 2)Alterar / Excluir    \n");
		printf(" 3)exportar lista de infectados\n");
		printf(" 4)sair \n");
		printf("%s",linhaPadrao);
		scanf("%d", &choice);



		switch (choice) {
		case 1:
			/* Add Movie*/
			break;
		case 2:
			/*Search Movie*/
			break;
		case 3:
			/*Search Movie*/
			break;
		case 4:
			printf("saiu do programa \n");
			break;

		default:



			if (cmdClean==1) {
				system("clear");
			}
			else {
				system("cls");
			}

			printf("%d. ",choice);
			printf("Escolha invalida, tente novamente!! \n");
			break;
		}

	} while (choice != 4);

	return 0;
}

void limpar(int cmdClean){
	if (cmdClean==1) {
				system("clear");
			}
			else {
				system("cls");
			}

}


