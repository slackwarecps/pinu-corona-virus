/*
 * login.c
 *
 *  Created on: 11 de nov. de 2020
 *      Author: fabioalvaro
 */
#include <stdio.h>
#include <locale.h>
#include <time.h>

int main() {
	char dtnasc[50];

	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	printf("now: %d-%02d-%02d %02d:%02d:%02d\n", tm.tm_year + 1900,
			tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);

	printf("DT.NASCIMENTO: ");
	scanf("%s", dtnasc);

 printf("data informada: %s",dtnasc );


//	char buf[100];
//	//time_t t;
//	struct tm *timeptr, result;
//
////	    setlocale(LC_ALL,"/QSYS.LIB/EN_US.LOCALE");
//	// setlocale(LC_ALL,"portuguese-brazilian");
//	setlocale(LC_ALL, "pt_BR.utf8");
//
//	// t = time(NULL);
//
//	timeptr = localtime(&t);
//
//	strftime(buf, sizeof(buf), "%a %m/%d/%Y %r", timeptr);
//
//	if (strptime(buf, "%a %m/%d/%Y %r", &result) == NULL)
//		printf("\nstrptime failed\n");
//	else {
//		printf("tm_hour:  %d\n", result.tm_hour);
//		printf("tm_min:  %d\n", result.tm_min);
//		printf("tm_sec:  %d\n", result.tm_sec);
//		printf("tm_mon:  %d\n", result.tm_mon);
//		printf("tm_mday:  %d\n", result.tm_mday);
//		printf("tm_year:  %d\n", result.tm_year);
//		printf("tm_yday:  %d\n", result.tm_yday);
//		printf("tm_wday:  %d\n", result.tm_wday);
//	}


	return 0;
}
