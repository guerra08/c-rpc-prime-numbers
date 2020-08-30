#include <stdio.h>
#include <string.h>
#include "prime.h"

int *is_prime_1_svc(int *num, struct svc_req *rqstp)
{
	int i;
    static int isprime = 1;
    static int notprime = 0;
    static int invalid = -1;

    if(*num < 0){
        return &invalid;
    }

	for (i = 2; i < *num; i++)
		if (i != *num && (*num % i == 0))
			return &notprime;
	return &isprime;
}
