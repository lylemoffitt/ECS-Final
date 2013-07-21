/*
 *  testbed.c
 *  Project Files
 *
 *  Created by Lyle Moffitt on 4/29/13.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */


#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXLEN 16
#define RAKLEN 8
#define ATOZ "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

int strovr(char dest[], char src[], int pos);
int strdlm(char output[],char input[], char delms[], int inclusive);
/* This is a test version to create a deliminator that can handle multiple,
	subsequnt occurances of the deliminator
 */

int main()
{
	char string[40] = "this is a sample string";
	char output[40] = {};
	strdlm(output, string, "#", 0);
	printf("\n%s",output);
	
	return(0);
}

int strdlm(char output[],char input[], char delms[], int inclusive)		// String deliminator
{	/* Reads in from *ptr and returns first portion to match delimination, value=length */
	int i=0 ;
	char * pch1;
	char * pch2;
	int loc;
	
	char * temp1 = NULL;
	char * temp2 = NULL;
	temp1 = (char *) calloc(strlen(input), sizeof(char));
	temp2 = (char *) calloc(strlen(input), sizeof(char));
	memset(temp1,'\0',strlen(input));
	memset(temp2,delms[0],strlen(input));
	
	pch1 = strpbrk(input, delms);	// Find first matching char
	switch (inclusive)
	{
		case 1:
			for (pch1 = strpbrk(input, delms); pch1 ;pch1 = strpbrk(pch1 +1,delms))
			{	/* Inclusive case : 0-9, XY, A-O */
				strncat(temp1,pch1,1);	i++;
			}
			break;
		case 0:				/*	If pch1 != NULL,	THEN IF strbrk() != 0,		ELSE pch1 */
			if(strlen(delms) >1){
				strcpy(temp1,input);
				while(	strovr(temp1, temp2, strdlm(temp1,input,delms,1) )	);
				
			}
		
			
			for (pch2 = pch1 + 1;
				 (long int)pch1 ? (pch2 < strpbrk(pch1+1,delms)) : (long int)pch1 ;
				 pch2++)
			{	/* Exclusive case : "word" or 'word', etc.. */
				strncat(temp1,pch2,1);	i++;
			}
			break;
		default:
			return(-1);
	}
	strcpy(output,temp1);
	free(temp1);
	temp1 = NULL;
	free(temp2);
	temp2 = NULL;
	return(i);
}	// Return = length

int strovr(char dest[], char src[], int pos)			// Places src[] at index = pos(ition) in dest[]
{	/* "String overwrite" */
	int i=0;
	if (strlen(dest) - strlen(src) >0)					// If src is too long or zero-length
		return(0);
	while(	i < strlen(src) &&							/* ..As long as it doesn't pass the end of dest[] */
			pos < strlen(dest)	)
		dest[pos++] = src[i++];							// Copy each char in src[] to dest[]
	return(1);
}	// Return 0 fail; 1 success
