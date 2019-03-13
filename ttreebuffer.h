//
// Created by vory on 3/9/19.
//

#ifndef __TTREEBUFFER_H__
#define __TTREEBUFFER_H__
#define DEBUG 	printf("DEBUG\n")
struct item {
    long int key;
};

struct item *all_items, *cur_item;

int token1;

char * parf0;
char * parf1;
void parseinput(char *string);
void parse_file(char *string);
enum commands{
    INIT = 0,
    FIND,
    INSERT,
    OPENFILE
};
char * file_line;

enum commands COMMANDS;
char par1[50];
char par2[50];
char par3[50];



#endif //__TTREEBUFFER_H__
