// Write CPP code here 
#include <netdb.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/socket.h>
#include "unistd.h"
#include "netinet/in.h"
#include "arpa/inet.h"

#define PORT 43594 
#define SA struct sockaddr 
void func(int sockfd) 
{ 

	char * clientbuff;
	char * clientrecv;
	clientrecv = malloc(1000);
	clientbuff = malloc(100);
	memset(clientbuff,0,100);
    memset(clientrecv,0,1000);
	for (;;) { 
//		bzero(buff, sizeof(buff));
        memset(clientbuff,0,100);
        memset(clientrecv,0,1000);
		printf("Enter the string : \n"); 

		fgets(clientbuff,100,stdin);
		printf("from fgets:%s",clientbuff);
//		while ((buff[n++] = getchar()) != '\n') ;
		send(sockfd,clientbuff,100,0);


//        while(rs)
//        {
//            buflen = recv(activeevents[i].data.fd, buf, 100, 0);
//            if(buflen < 0)
//            {
//                // 由于是非阻塞的模式,所以当buflen为EAGAIN时,表示当前缓冲区已无数据可读
//                // 在这里就当作是该次事件已处理
//                if(buflen == EAGAIN)
//                    break;
//                else
//                    return;
//            }
//            else if(buflen == 0)
//            {
//                // 这里表示对端的socket已正常关闭.
//            }
//
//            if(buflen != sizeof(buf))
//                rs = 0;
//            else
//                rs = 1;// 需要再次读取
//        }
//

		while( (recv(sockfd,clientrecv,1000,0))<=0){
//		    printf("here we in while recv loop\n");
            send(sockfd,clientbuff,100,0);
		}
        if ((strncmp(clientbuff, "EXIT", 4)) == 0) {
            printf("Client Exit...\n");
            break;
        }
		printf("From Server : %s\na client looop end here \n _____________________\n", clientrecv);
	} 
}



int main() 
{
	int sockfd, connfd; 
	struct sockaddr_in servaddr, cli; 

	// socket create and varification 
	sockfd = socket(AF_INET, SOCK_STREAM, 0); 
	if (sockfd == -1) { 
		printf("socket creation failed...\n"); 
		exit(0); 
	} 
	else
		printf("Socket successfully created..\n"); 
	bzero(&servaddr, sizeof(servaddr)); 

	// assign IP, PORT 
	servaddr.sin_family = AF_INET; 
	servaddr.sin_addr.s_addr = inet_addr("127.0.0.1"); 
	servaddr.sin_port = htons(PORT); 

	// connect the client socket to server socket 
	if (connect(sockfd, (SA*)&servaddr, sizeof(servaddr)) != 0) { 
		printf("connection with the server failed...\n"); 
		exit(0); 
	} 
	else
		printf("connected to the server..\n"); 

	// function for chat 
	func(sockfd); 

	// close the socket 
	close(sockfd); 
} 

