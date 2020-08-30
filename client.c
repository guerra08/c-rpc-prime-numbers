#include <stdio.h>
#include "prime.h"

/* função que chama a RPC add_1 */ 
int is_prime(CLIENT *clnt, int num) {
	int *result;

	/* chama a função remota */
	result = is_prime_1(&num, clnt);
	
	if (result == NULL) {
		printf ("Problemas ao chamar a função remota\n");
		
		return -2;
	}

	return (*result);
}

int main(int argc, char *argv[])
{
	CLIENT *clnt;
	int flag;

	if (argc != 3) {
		fprintf(stderr,"Uso:\n%s <nome_do_servidor> <numero>\n\n",argv[0]);
		
		return 1;
	}
	
	/* cria uma struct CLIENT que referencia uma interface RPC */
	clnt = clnt_create(argv[1], PRIMEPROG, PRIMEVERS, "udp");
	
	/* verifica se a referência foi criada */ 
	if (clnt == (CLIENT *)NULL) {
		clnt_pcreateerror(argv[1]);
		
		return 1;
	}
	
	int num = atoi(argv[2]);

	/* executa os procedimentos remotos */
	flag = is_prime(clnt, num);

	if (flag == -1)
		printf("Valor invalido!\n");
	else if(flag == 0)
		printf("N eh primo");
    else if(flag == 1)
        printf("Eh primo\n");
	
	return 0;
}
