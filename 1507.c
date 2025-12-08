#include <string.h>
#include <stdio.h>

int isSubString(char *string1, char *string2){
	int i, j, tamString1, tamString2;
	tamString1 = strlen(string1);
	tamString2 = strlen(string2);
	for (i = 0, j = 0; i < tamString2 && j < tamString1; i++)
		if (string1[j] == string2[i])
			j++;
	if (j == tamString1)
		return 1;
	else
		return 0;
}

void saida(char a[1100], char b[100060]){
    if (isSubString(a, b))
	    printf("Yes\n");
	else
	    printf("No\n");
}

void main (){
	int i, j;
	char string[100060];
	char subString[1100];
	int qtsCasos, qtsStrings;
	scanf("%hu", &qtsCasos);
	scanf("%s", string);
	for (i = 0; i < qtsCasos; ++i){
		scanf("%hu", &qtsStrings);
		for (j = 0; j < qtsStrings; ++j){
			scanf("%s", subString);
			saida (subString, string);
		}
		scanf("%s", string);
	}
}
