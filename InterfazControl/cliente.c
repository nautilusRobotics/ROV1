
/*************************************************************************\
 * Copyright (C) Michael Kerrisk, 2010. *
 * *
 * This program is free software. You may use, modify, and redistribute it *
 * under the terms of the GNU Affero General Public License as published *
 * by the Free Software Foundation, either version 3 or (at your option) *
 * any later version. This program is distributed without any warranty. *
 * See the file COPYING.agpl-v3 for details. *
\*************************************************************************/
/* Listing 59-7 */
/* is_seqnum_cl.c
A simple Internet stream socket client. This client requests a sequence
number from the server.
See also is_seqnum_sv.c.
 */
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <getopt.h> /* getopt_long() */
#include <sys/time.h>
#include <sys/mman.h>
#include <sys/ioctl.h>
#include "com.h"

#define PORT_NUM "50002" /* Port number for server */
#define INT_LEN 30 /* Size of string able to hold largest
integer (including terminating '\n') */
#define MAX_READ 614400
unsigned char buffer[MAX_READ];
unsigned char buffer_temp[MAX_READ];

/* Read characters from 'fd' until a newline is encountered. If a newline
character is not encountered in the first (n - 1) bytes, then the excess
characters are discarded. The returned string placed in 'buf' is
null-terminated and includes the newline character if it was read in the
first (n - 1) bytes. The function return value is the number of bytes
placed in buffer (which includes the newline character if encountered,
but excludes the terminating null byte). */
ssize_t readLine(int fd, void *buffer, size_t n){
	printf("into readLine\n");

	ssize_t numRead; /* # of bytes fetched by last read() */
	size_t totRead; /* Total bytes read so far */
	char *buf;
	char ch;
	if (n <= 0 || buffer == NULL) {
		errno = EINVAL;
		return -1;
	}
	buf = buffer; /* No pointer arithmetic on "void *" */
	totRead = 0;
	for (;;) {

		numRead = read(fd, &ch, 1);


		if (numRead == -1) {

			if (errno == EINTR) /* Interrupted --> restart read() */
				continue;
			else
				return -1; /* Some other error */
		} else if (numRead == 0) { /* EOF */

			if (totRead == 0) /* No bytes read; return 0 */
				return 0;
			else /* Some bytes read; add '\0' */
				break;
		} else { /* 'numRead' must be 1 if we get here */

			if (totRead < n - 1) { /* Discard > (n - 1) bytes */
				totRead++;
				if(ch!='\n')  //Discard the jumpline
				*buf++ = ch;
			}
			if (ch == '\n')
				break;
		}
	}
	*buf = '\0';
	return totRead;
}
int
main(int argc, char *argv[])
{
	//Descriptores de archivos y valores de retorno
	char LenStr[INT_LEN]; /* Length of requested sequence */
	char *reqLenStr; /* Requested length of sequence */
	int cfd;
	struct addrinfo hints;
	struct addrinfo *result, *rp;
	if (argc < 2 || strcmp(argv[1], "--help") == 0)
		printf("%s server-host [sequence-len]\n", argv[0]);
	/* Call getaddrinfo() to obtain a list of addresses that
we can try connecting to */
	memset(&hints, 0, sizeof(struct addrinfo));
	hints.ai_canonname = NULL;
	hints.ai_addr = NULL;
	hints.ai_next = NULL;
	hints.ai_family = AF_UNSPEC; /* Allows IPv4 or IPv6 */
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_flags = AI_NUMERICSERV;
	if (getaddrinfo(argv[1], PORT_NUM, &hints, &result) != 0)
		printf("getaddrinfo");
	/* Walk through returned list until we find an address structure
that can be used to successfully connect a socket */
	for (rp = result; rp != NULL; rp = rp->ai_next) {
		cfd = socket(rp->ai_family, rp->ai_socktype, rp->ai_protocol);
		if (cfd == -1)
			continue; /* On error, try next address */
		if (connect(cfd, rp->ai_addr, rp->ai_addrlen) != -1)
			break; /* Success */
		/* Connect failed: close this socket and try next address */
		close(cfd);
	}
	if (rp == NULL)
		printf("Could not connect socket to any address");
	freeaddrinfo(result);
	/* Send requested sequence length, with terminating newline */


	reqLenStr = argv[2]; //See com.h-> defines with commands

	if (write(cfd, reqLenStr, strlen(reqLenStr)) == -1)
		printf("Partial/failed write (reqLenStr)");


	//Read and display sequence number returned by server
	if(strcmp(reqLenStr,GET_DEPTH)==0){
		shutdown(cfd,SHUT_WR);          // Half-Close Socket
		readLine(cfd, LenStr, INT_LEN); //Read Robot Resp
		printf("%s\n",LenStr);          //PrintIt
	}


	//Cerrar archivo
	if(close(cfd) == -1){
		perror("close");
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}
