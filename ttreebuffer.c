//
// Created by slarsar on 3/9/19.
//
//created ttreebuffer

#include <stdio.h>
#include <string.h>
#include <tkPort.h>
#include "ttreebuffer.h"

void parseinput(char *string){
    char * delim;
    delim = ",";
    char * copy_string;
    copy_string = malloc(100*sizeof(char));
    char * token;
    token = NULL;

    token = strtok(copy_string,delim);
    strcpy(par1,token);
    token = strtok(copy_string,delim);

    if (token != NULL){
        strcpy(par2,token);
    }
    token = strtok(copy_string,delim);

    if (token != NULL){
        strcpy(par3,token);
    }
    free(copy_string);
}

void parse_file(char * string){


    char * buf;

    buf = malloc(1000*sizeof(char));
free(parf0);
free(parf1);

    memset(buf,0, 1000*sizeof(char));
    char * delim;
    delim = NULL;
    delim = ",";
    char * token;
    token = NULL;

    token1 = 0;

    parf0 =malloc(500*sizeof(char));
    memset(parf0,0, 500*sizeof(char));
    parf1 =malloc(500*sizeof(char));
    memset(parf1,0, 500*sizeof(char));
    strcpy(buf, string);


printf("buf:%s",buf);
    token = strtok(buf, delim);
printf("token0:\t%s\n",token);

    strcpy(parf0, token);


    token = strtok(NULL, delim);
    printf("token1:\t%s\n",token);
    if (token != NULL){
        token1 = 1;

        strcpy(parf1, token);
    }
free(buf);

}


//
//    parametercount++;
//    token = strtok(NULL, delim);
//    if (token != NULL){
//        par[parametercount] = malloc(sizeof(string));
//        strcpy(par[parametercount], token);



//
//    all_items[bcount].key = strtol(par[0], NULL, 10);
//    bcount++;
//    hash_user_id = strtol(parameter[0], NULL, 10);
//    strcpy(hash_name, parameter[1]);
//
//    printf("%ld,%s", hash_user_id, hash_name);
//
///////////////add_hash_table//////////////
//    add_user(hash_user_id, hash_name);


