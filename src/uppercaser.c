/*
 * =====================================================================================
 *
 *       Filename:  rot13.c
 *
 *    Description:  Implementation of the ROT13 encryption
 *
 *        Version:  1.0
 *        Created:  Friday, June 05, 2015 11:20:26 HKT
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Steven Chien (sc), steven.chien@connect.polyu.hk
 *        Company:  The Hong Kong Polytechnic University, Hong Kong
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <getopt.h>
#include <stdlib.h>
#include <ctype.h>


void print_usage() {
	printf("./caser [option]\n");
	printf("options: -k [shift length]\n");
	printf("Default key: 13\n");
}


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  mod
 *  Description:  Simple implementation of mod operator
 * =====================================================================================
 */
unsigned mod(int a, unsigned b) {
	return (a >= 0 ? a % b : b - (-a) % b);
}


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  Main function
 * =====================================================================================
 */
int main(int argc, char *argv[]) {

	/* default key size */
	int key = 13;
	char c;

	/* parse command line options */
	int option;
	while ((option = getopt(argc, argv,"k:"))!=-1) {
		switch (option) {
			case 'k': key = atoi(optarg);
			break;
			default: print_usage(); 
		}
	}

	/*-----------------------------------------------------------------------------
	 *  if character read is an alphabet, shift by length specified by key
	 *  offset by value specified for that alphabet in ASCII before applying
	 *  encryption, re-apply the offset afterwards
	 *-----------------------------------------------------------------------------*/
	while((c=fgetc(stdin))!=EOF) {
		if(isalpha(c) && isupper(c)) {
			c = mod((c - 65 + key), 26) + 65;
		}
		else if(isalpha(c) && islower(c)) {
			c = mod((c - 97 + key), 26) + 97;

		}
		printf("%c", c);
	}

	return 0;
}				/* ----------  end of function main  ---------- */
