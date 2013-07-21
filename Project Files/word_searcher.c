/*
 *  test.c
 *  Project Files
 *
 *  Created by Lyle Moffitt on 4/25/13.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 16

int chk_dict(char query[]);			// Check the dictionary for the given word query
void load_tiles(char tiles[][MAXLEN]);
void make_upper( char string[]);  // Convert to UPPERcase
void make_lower( char string[]);	// Convert to lowerCASE

int main ()
// int word_searcher(char tiles[][MAXLEN])
{
	//From function prototype:
	char tiles[MAXLEN][MAXLEN] = {};
	
	// From function definition
	char row[MAXLEN] = {};
	char string[MAXLEN] = {};
	char word[MAXLEN] = {};
	int i,j,flag;
	int first_letter,last_letter;
	int numwrds=0,numrow=0;
	//int status=0;
	FILE * found_words;
	const char* ptr;
	
	found_words = fopen("found_words.txt", "w");
	
	load_tiles(tiles);		// Debug only
	
	for (flag=1; flag<3; flag++)
	{
		for (numrow=0; numrow<MAXLEN; numrow++)
		{
			switch (flag)
			{
				case 1:
					strcpy(row,tiles[numrow]);
					break;
				case 2:
					for (i=0; i<MAXLEN; i++) 
						row[i] = tiles[i][numrow];	
					break;
				default:
					return(numwrds);
			}
			
			for (ptr = strtok(row, "- |" );  ptr;  ptr = strtok( NULL, "- |" ))
			{
				strcpy(string,ptr);
				for (first_letter=0; first_letter<strlen(string); first_letter++) 		
				{
					for (last_letter=first_letter+1; last_letter<strlen(string); last_letter++)
					{
						j=0; memset(word,'\0',MAXLEN);
						for (i=first_letter; i<=last_letter; i++){
							word[j]=string[i];	j++;
						}
						if (chk_dict(word)) // Word is exactly matched
						{
							make_upper(word);
							fprintf(found_words,"%s\n", word);
							printf("\nFound the word %-10s in row %d. ",word,numrow);
							numwrds++;
						} 
					}
				}
			}
		} 
	}
	return(numwrds);
}


int chk_dict(char query[])			// Check the dictionary for the given word query
/* Description of dictionary file format
 *	Each file contains all the words that start with the first letter of the file
 *	The length of everyword in the file is equal to the numerical suffix of the filename
 *	The first line is an index listing the number of words that have #index as their second letter
 *	The last node of the index is the total number of words in the file (not including the index).
 *	
 *	Algorithm:
 *	1)	letter = word[0]
 *	2)	length = strlen(word)
 *	3)	skip to word[1] ,; n = (int)skip -97
 *	4)	Open filename = ("%c%d.txt",letter,length)
 *	5)	Read index into dir[26]
 *	6)	Number of lines to skip is equal to sum of dir[0]...dir[n-1]
 *	7)	Begin search with this line as START
 *	8)	END = START + dir[n]
 *	9)	If list is very large, use binary search with these points as terminaters
 *	10)	Other wise a linear search will do.
 */
{
	// char query[16]="zip";	// Comment in for debug
	FILE * dict_src;
	int length = strlen(query);
	int skip=0,i;
	char filename[10]={};		// String for holding the filename of the dictionary section we want
	int dir[27] = {};			// Directory array to hold index at beginning of file
	fpos_t wrdz_start;
	int top,bottom,middle,found;
	char word[16]={};
	
	make_lower(query);			// Required because dictionary is entirely lowercase
	if (length<=1) {	return(0);	}
	
	sprintf(filename,"%c%d.txt",query[0],length);				// Open the file
	dict_src = fopen(filename,"r");
	for (i=0;i<27 ; i++) {	fscanf(dict_src,"%d",&dir[i]);	}	// Read the index into the directory array
	for (i=0; i<( (int)query[1] -97); i++) {	skip += dir[i];	}	// Skip = sum of dir[0] to dir[ first letter ]
	fgetpos(dict_src, &wrdz_start /* Begin word list */ );
	
	// --- Begin binary seach for query in word list -----
	bottom = skip;				// 1. Let bottom be the subscript of the initial array element.
	top = dir[i] - 1 + skip;	// 2. Let top be the subscript of the last array element.
	found = -1;					// 3. Let found be false.
	while (	(bottom<=top)		/* 4. Repeat as long as bottom isn't greater than top	*/
			&&(found == -1)	)	/*			and the target has not been found.			*/
	{
		middle = (top-bottom)/2 + bottom  ;	// a. Let middle be the subscript of the element halfway between bottom and top.
		fsetpos(dict_src, &wrdz_start);
		fseek(dict_src, ( middle * (length +1) ) + 3 , SEEK_CUR);
		fscanf(dict_src,"%s",word);
		if (strcmp(word,query)==0){			// b. if the element at middle is the target
			found = middle;						// i. Set found to true and index to middle.
		}else if(strcmp(word,query) > 0){			// else if the element at middle is larger than the target 
			top = middle -1;					// ii. Let top be middle-1.
		}else {										// else
			bottom = middle +1;					// iii. Let bottom be middle + 1.
		}
	}
	if (found!=-1) {			// 5. If the target was found
		fclose(dict_src);// Close file
		return(1);							// a. return the index .
	} else {										// else
		fclose(dict_src);// Close file
		return (0);							// b. return -1
	}
	// -------- End of binary search --------

}

void load_tiles(char tiles[][MAXLEN])
{
	int i,j;
	FILE * fpntr;
	// char line[80]={};
	
	fpntr = fopen("board.txt", "r");
	
	for (i=0; i<(MAXLEN-1); i++)
	{
		for (j=0; j<(MAXLEN-1); j++)
		{
			fscanf(fpntr, " %c",&tiles[i][j]);
		}
	}
	fclose(fpntr);
}

void make_upper( char string[])  // Convert to UPPERcase
{
	int i;
	for (i=0; i<=strlen(string); i++)
	{
		if ( (string[i]>='a') && (string[i]<='z') )	
		{
			string[i] = (char)((int)string[i] - 32);
		}								
	}
}
void make_lower( char string[])	// Convert to lowerCASE
{
	int i;
	for (i=0; i<=strlen(string); i++)
	{
		if ( (string[i]>='A') && (string[i]<='Z') )	
		{
			string[i] = (char)((int)string[i] + 32);
		}								
	}
}




