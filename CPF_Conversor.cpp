#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int manipulacao1(char numero, int mul);

int main (){
	int exit = 1; 
	int enable_flag = 1; 
	while(exit){
		int i = 0;
		char str[12] = "";	
		int soma = 0; 
		int resto;
		int digito_verificador;
		printf("Digite o CPF ou 0 para sair: ");
		fflush(stdout);
		fgets(str, 12, stdin);
		fflush(stdin);
		if (str[0] == '0'){
			exit = 0;
			printf("Finalizando execucao!");
			break; 
		}
		for (i; i < sizeof(str) - 2; i++ )  {
			if (str[i] && str[i] + '0' != 58 && isdigit(str[i]) == 1){
				enable_flag = 1;
			}else {
				enable_flag = 0;
				printf("Por favor, digite os 11 digitos do CPF\n\n");
				break;
			}
			switch(i){
				case 0: 
					soma = soma + manipulacao1(str[i], 3);
					break;		
				case 1:
					soma = soma + manipulacao1(str[i], 2);
					break;
				case 2:
					soma = soma + manipulacao1(str[i], 9);
					break;
				case 3:
					soma = soma + manipulacao1(str[i], 8);
					break; 
				case 4: 
					soma = soma + manipulacao1(str[i], 7);
					break;
				case 5: 
					soma = soma + manipulacao1(str[i], 6);
					break;
				case 6:
					soma = soma + manipulacao1(str[i], 5);
					break;
				case 7:
					soma = soma + manipulacao1(str[i], 4);
					break;
				case 8:
					soma = soma + manipulacao1(str[i], 3);
					break;
				case 9:
					soma = soma + manipulacao1(str[i], 2);
			}
		}
		if (enable_flag){
			printf("--------------------------------------------\n");
			printf("CPF UTILIZADO = %s\n", str);
			resto = soma%11; 
			digito_verificador = 11 - resto;
			if (digito_verificador == 11 || digito_verificador == 10){
				digito_verificador = 0;
			}
			printf("Digito verificador: %d\n", digito_verificador);
			str[10] = digito_verificador + '0';
			printf("CPF CONVERTIDO: %s\n", str);
			printf("--------------------------------------------\n");
		}	
	}	
	return 0;
}


int manipulacao1(char numero, int mul){
	int numeroConvertido = numero - '0'; 
	return numeroConvertido*mul;
}