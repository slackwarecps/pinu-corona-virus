//================================================================
// Nome Do Arquivo: string_substring.c
// File Name: string_substring.c
//
// Descrição: O programa retorna uma string a partir de um dado
//            intervalo: [start, end[
//================================================================

// Libs
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Protótipo da função
char* string_substring(char str[], int start, int end);

// Função main
// Main Function
int main(int argc, char** argv)
{
 char str[100], *sub;
 int start, end;

 // Lê a string
 printf("Digite a string: ");
 gets(str);


 printf("ch conta com %d caracteres\n", strlen(str));


 printf("Digite a posição inicial: ");
 scanf("%d", &start);
 printf("Digite a posição final: ");
 scanf("%d", &end);

 // Retorna a substring
 sub = string_substring(str, start, end);

 // Imprime a substring
 printf("A substring: %s", sub);

// system("pause");
 return 0;
}

int validaCampoData(){

}

char* string_substring(char str[], int start, int end) {
    int i, j;
    char *sub;

    // Verifica valores incompatíveis e
    // retorna NULL
    if(start >= end || end > strlen(str)) {
        return NULL;
    }

    // Aloca memória para a substring
    sub = (char *) malloc(sizeof(char) * (end - start + 1));

    // Copia a substring para a variável
    for(i = start, j = 0; i < end; i++, j++) {
        sub[j] = str[i];
    }

    // Terminador de string
//    sub[j] = '&#092;&#048;';


    return sub;
}
