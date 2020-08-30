all:
	rpcgen prime.x
	gcc server.c prime_svc.c -o server -lnsl
	gcc client.c prime_clnt.c -o client -lnsl

clean:
	rm -f client server prime_svc.c prime_clnt.c prime_xdr.c prime.h