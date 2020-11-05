/*
 ============================================================================
 Name        : Principal.c
 Author      : Fabio Pereira
 Version     :
 Copyright   : UNIP
 Description : UNIP PIM 4
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	puts("UNIP PIM IV"); /* prints !!!Hello World!!! */

	int testInteger;
	puts("digite sua idade!!");
	scanf("%d", &testInteger);
	printf("Idade = %d", testInteger);

	puts("fim do programa."); /* prints !!!Hello World!!! */
	return EXIT_SUCCESS;
}
