#include <netdb.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <stdio.h>
#include "ttreebuffer.h"
#include "ttree_defs.h"
#include "ttree.h"
#include "uthash.h"
#include "hash_table.h"
#include "server_misc.h"



#define PORT 43594
#define SA struct sockaddr
Ttree ttree;
int ret ;
#include <string.h>
// Function designed for chat between client and server.

static int __cmpfunc(void *key1, void *key2)
{
    return (*(int *)key1 - *(int *)key2);
}

static void usage(const char *appname)
{
    fprintf(stderr, "Usage: %s <positive number of keys>\n", appname);
    exit(EXIT_SUCCESS);
}
FILE * fp;
void * res;
int bcount = 0;
void func(int sockfd)
{
	out_buff = malloc(1000* sizeof(char));
	in_buff = malloc(100 * sizeof(char));
	memset(out_buff,0,1000* sizeof(char));
	int n;
	for (;;) {
		memset(in_buff,0, 100*sizeof(char));

		while(  !recv(sockfd,in_buff,100,0)  );

			printf("From client in_buff is : %s \n", in_buff);
			parseinput(in_buff);


		if (strcmp(par1, "INIT") == 0) {
			COMMANDS = INIT;
		}

		if (strcmp(par1, "FIND") == 0) {
			printf("receive FIND \n");
			COMMANDS = FIND;
		}

		if (strcmp(par1, "INSERT") == 0) {
			COMMANDS = INSERT;
		}

		if (strcmp(par1, "OPENFILE") == 0) {
			COMMANDS = OPENFILE;
		}

		if (strcmp(par1, "DELETE") == 0) {
			printf("receive DELETE \n");
			COMMANDS = DELETE;
		}

//
//		printf("receive %s  but go UNKOWN \n",par1);
//		COMMANDS = UNKNOW;

		switch (COMMANDS) {
			case INIT:
			    strcpy(out_buff,"this module hasn't implemted!,sorry");
			    break;
				while (fgets(file_line, 256, fp)){
					parse_file(file_line);
					all_items[bcount].key = strtol(parf0, NULL, 10);
					bcount++;
					hash_user_id = strtol(parf0, NULL, 10);
					strcpy(hash_name, parf1);
					printf("%ld,%s", hash_user_id, hash_name);
					add_user(hash_user_id, hash_name);
				}
				break;

			case FIND:
				finds = find_user(strtol(par2, NULL, 10));
				if (finds != NULL){
					printf("NOW IN FIND SWITCH \n");
					strcpy(out_buff, finds->name);
				}
				else{
					strcpy(out_buff,"key  NOT FOUND!");
				}
				break;
			case INSERT:
				finds = find_user(strtol(par2, NULL, 10));
				if (finds == NULL){

					strcpy(out_buff, "The key you want to insert doesn't in MMDB\n .......Inerting now......\n");
				}
				else{
					strcpy(out_buff,"key already EXIST!!!\n!");
				}
				*insertkey = strtol(par2,NULL,10);
				printf("inserkey = %ld",*insertkey);
                ret = ttree_insert(&ttree, insertkey);
                strcpy(hash_name,par3);
                hash_user_id = strtol(par2,NULL,10);
				add_user(hash_user_id,hash_name);
//                if (ifret < 0) {
//
//                    fprintf(sockfd, "Failed to insert  key %ld! [ERR=%d]\n",  strtol(par2,NULL,100), );
//
//                }

				////insert to ttree ,& insert to hash_table////
				break;
			case DELETE:
				*insertkey = strtol(par2,NULL,10);
				printf("key  %ld deleted ! ",*insertkey);
				finds = find_user(*insertkey);

				ttree_delete(&ttree,&insertkey);
				delete_user(finds);
				res = ttree_delete(&ttree,insertkey);
				if (res == NULL) {
					strcpy(out_buff,"Failed to delete item %d on step %d");
				}



				break;
			case OPENFILE:
				/////open /home/vory/programing/c/key_value_mmdb_via_tcp_server/xlarge.del
				fp = fopen("/home/vory/programing/c/key_value_mmdb/xlarge.del", "r");
				break;
            case PRINT:


                break;

            case UNKNOW:
                strcpy(out_buff,"Recived an unknow commands");
                break;
		}
        free(par1);
        free(par2);
        free(par3);

		printf("out_buff is %s\n",out_buff);
		send(sockfd,out_buff,1000,0);


		// copy server message in the buffer
		// and send that buffer to client
		// if msg contains "Exit" then server exit and chat ended.
		if (strncmp("EXIT", in_buff, 4) == 0) {
			printf("Server Exit...\n");
			break;
		}
		printf("a for loop end here \n________________________________________\n");
	}
}

/////////////////////////////////////////IN MAIN()    HERE   //////////////////////////////////////////////////////////
long int num_keys = 12278;
// Driver function

int main()
{
	int i;
	int ret;

	insertkey = (long int *)malloc(20*sizeof(long int));
	memset(insertkey,0, 20*sizeof(long int));

	TtreeNode *tnode;
	struct hash_struct *s;
	all_items = calloc(num_keys, sizeof(all_items));
//	printf("Inserting keys to the tree...\n");
	 fp = fopen("/home/vory/programing/c/key_value_mmdb_via_tcp/xlarge.del", "r");
	file_line = malloc(1000*sizeof(char));
	memset(file_line,0, 1000*sizeof(char));
	while (fgets(file_line, 1000, fp)){
//		printf("file_line:%s",file_line);
		parse_file(file_line);
//		printf("par0:%s\n",parf0);
//		printf("par1:%s\n",parf1);
		all_items[bcount].key = strtol(parf0, NULL, 10);
//		bcount++;
//		printf("bcount:\t%d\n",bcount);
		hash_name =malloc(500* sizeof(char));
		memset(hash_name,0,500* sizeof(char));
		hash_user_id = strtol(parf0, NULL, 10);
		strcpy(hash_name, parf1);
//		printf("hash_user_id\t%ld,\t\thash_name \t%s\n", hash_user_id, hash_name);
		s = find_user(hash_user_id);
		if(s == NULL){ add_user(hash_user_id, hash_name); }
		free(hash_name);
		memset(file_line,0, 1000*sizeof(char));
	}

	for (i = 0; i < num_keys; i++) {
		printf("%ld ", all_items[i].key);
	}
	////////////print all key;/////////////////////////

	ret = ttree_init(&ttree, 8, false, __cmpfunc, struct item, key);
	if (ret < 0) {
		fprintf(stderr, "Failed to initialize T*-tree. [ERR=%d]\n", ret);
		free(all_items);
		exit(EXIT_FAILURE);
	}

	for (i = 0; i < num_keys; i++) {
		ret = ttree_insert(&ttree, &all_items[i]);
		if (ret < 0) {
			fprintf(stderr, "Failed to insert item %d with key %ld! [ERR=%d]\n", i, all_items[i].key, ret);
			free(all_items);
			exit(EXIT_FAILURE);
		}
	}

//     srandom(time(NULL));
//     printf("Generating %d random numbers...\n", num_keys);
//     printf("all_item size = %zu \n", sizeof(all_items));
	for (i = 0; i < num_keys; i++) {
//          all_items[i].key = (int)(random() % (4096 - 1));
		printf("%ld ", all_items[i].key);
	}
//     printf("}\n");
//    printf("%d",sizeof(char[1 - 2 * !(cond)]));
//    printf("%ld",(  (size_t)&(((struct item *)0)->key) - (size_t)((struct item *)0)          ));
///////////////////////////printf sorted keys:///////////////////////////////////
	printf("\nSorted keys:\n");
	printf("{ ");
	tnode = ttree_node_leftmost(ttree.root);
	while (tnode) {
		tnode_for_each_index(tnode, i) {

			printf("%d ", *(int *) tnode_key(tnode, i));
		}
		tnode = tnode->successor;
	}
	printf("}\n");
//    HASH_FIND_INT(struct hash_struct,1,stdout);
//	char *in;
//	in = malloc(sizeof(long int));
//	fputs("feafawfa:\n", stdout);
//	fgets(in, sizeof(long int), stdin);
//
//	s = find_user(strtol(in, NULL, 10));
//	if (s != NULL) printf("%s", s->name);
//
//	server_main();
//

	///////////////////
	int sockfd, connfd, len;
	struct sockaddr_in servaddr, cli;

	// socket create and verification
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
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(PORT);

	// Binding newly created socket to given IP and verification
	if ((bind(sockfd, (SA*)&servaddr, sizeof(servaddr))) != 0) {
		printf("socket bind failed...\n\n");
		exit(0);
	}
	else
		printf("Socket successfully binded..\n\n");

	// Now server is ready to listen and verification
	if ((listen(sockfd, 5)) != 0) {
		printf("Listen failed...\n\n");
		exit(0);
	}
	else
		printf("Server listening..\n\n");
	len = sizeof(cli);

	// Accept the data packet from client and verification
	connfd = accept(sockfd, (SA*)&cli, &len);
	if (connfd < 0) {
		printf("server acccept failed...\n\n");
		exit(0);
	}
	else
		printf("server acccept the client...\n\n");

	// Function for chatting between client and server
	func(connfd);

	// After chatting close the socket
	close(sockfd);

//////////////trree destuou///
	ttree_destroy(&ttree);
	free(all_items);
	exit(EXIT_SUCCESS);
}
