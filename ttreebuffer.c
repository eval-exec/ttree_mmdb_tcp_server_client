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
    delim = " ";

    copy_string = malloc(100*sizeof(char));
    memset(copy_string,0,100* sizeof(char));
    char * token;
    token = NULL;



    par1 = malloc(50*sizeof(char));
    par2 = malloc(50*sizeof(char));
    par3 = malloc(50*sizeof(char));
    memset(par1,0,50*sizeof(char));
    memset(par2,0,50*sizeof(char));
    memset(par3,0,50*sizeof(char));

    strcpy(copy_string,string);
    printf("%s is copystring \n",copy_string);
    printf("%s is string \n",string);

    token = strtok(copy_string,delim);

    if (token != NULL){
        printf("%s is token1 \n",token);
        strcpy(par1,token);
    }

    token = strtok(NULL,delim);

    if (token != NULL){
        printf("%s is token2 \n",token);

        strcpy(par2,token);
    }
    token = strtok(NULL,delim);
    if (token != NULL){
        printf("%s is token3 \n",token);

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


//printf("buf:%s",buf);
    token = strtok(buf, delim);
//printf("token0:\t%s\n",token);

    strcpy(parf0, token);


    token = strtok(NULL, delim);
//    printf("token1:\t%s\n",token);
    if (token != NULL){
        token1 = 1;

        strcpy(parf1, token);
    }
free(buf);

}


long int * insertkey;
