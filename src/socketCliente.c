/*
 ============================================================================
 Name        : socketCliente.c
 Author      : Programadores en fuga
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	struct sockaddr_in direccionServidor;
	direccionServidor.sin_family=AF_INET;
	direccionServidor.sin_addr.s_addr=inet_addr("127.0.0.1");
	direccionServidor.sin_port=htons(8987);

	int cliente=socket(AF_INET,SOCK_STREAM,0);
	if(connect(cliente,(void*) &direccionServidor,sizeof(direccionServidor))!=0){
		perror("No se pudo conectar");
		return 1;
	}
	while(1){
		char mensaje[1000];
		scanf("%s",mensaje);

		send(cliente,mensaje, strlen(mensaje),0);
	}
	return 0;
}
