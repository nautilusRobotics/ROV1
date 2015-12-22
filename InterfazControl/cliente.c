
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

	ssize_t numRead; /* # of bytes fetched by last read() */
	size_t totRead; /* Total bytes read so far */
	char *buf;
	char ch;
	if (n <= 0 || buffer == NULL) {
		errno = EINVAL;
		 printf(" EINVAL\n");
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

int main(int argc, char *argv[])
{
	
	if (argc < 2 || strcmp(argv[1], "--help") == 0){
	  printf("%s server-host [sequence-len]\n", argv[0]);
	  exit(1);
	}
		
	//Descriptores de archivos y valores de retorno
   char server_resp[INT_LEN]; /* Length of requested sequence */
   char *command; /* Requested length of sequence */

   int sockfd, portno, n;
   struct sockaddr_in serv_addr;
   struct hostent *server;
   
   char buffer[256];
   	
   portno = atoi(PORT_NUM);
   
   /* Create a socket point */
   sockfd = socket(AF_INET, SOCK_STREAM, 0);   
   if (sockfd < 0) {
      printf("ERROR_socket\n");
      exit(EXIT_FAILURE);	
   }
	
   server = gethostbyname(argv[1]);   
   if (server == NULL) {
      printf("ERROR_host\n");
      exit(EXIT_FAILURE);
   }
   
   bzero((char *) &serv_addr, sizeof(serv_addr));
   serv_addr.sin_family = AF_INET;
   bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
   serv_addr.sin_port = htons(portno);
   
   /* Now connect to the server */
   if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
      printf("ERROR_connecting\n");
      exit(EXIT_FAILURE);
   }

   command = argv[2]; //See com.h-> defines with commands
    		
    if (write(sockfd, command, strlen(command)) == -1){
		printf("ERROR_writting\n");   
		exit(EXIT_FAILURE);	
    } 	
		
	if(strspn(command, REQUEST_KEY)==1){		
	    shutdown(sockfd,SHUT_WR);          // Half-Close Socket			
		if(readLine(sockfd, server_resp, INT_LEN)<=0) //Read Robot Resp
		   printf("ERROR_readLine\n");
		else
		  printf("%s\n",server_resp);          //PrintIt       
	}

	//Cerrar archivo
	if(close(sockfd) == -1){
		printf("ERROR_closing\n");
		exit(EXIT_FAILURE);
	}
	
	exit(EXIT_SUCCESS);
}
