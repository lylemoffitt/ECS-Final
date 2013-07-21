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

int main ()
//int chk_dict(char query[])			// Check the dictionary for the given word query
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
	char query[16]="zip";
	FILE * dict_src;
	int length = strlen(query);
	int skip=0,i;
	char filename[10]={};		// String for holding the filename of the dictionary section we want
	int dir[27] = {};			// Directory array to hold index at beginning of file
	fpos_t wrdz_start;
	int top,bottom,middle,found;
	char word[16]={};
	
	sprintf(filename,"%c%d.txt",query[0],length);				// Open the file
	dict_src = fopen(filename,"r");
	for (i=0;i<27 ; i++) {	fscanf(dict_src,"%d",&dir[i]);	}	// Read the index into the directory array
	for (i=0; i<((int)query[1] -97); i++) {	skip += dir[i];	}	// Skip = sum of dir[0] to dir[ first letter ]
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
		printf("\n\nFOUND\n\n");
		return(0);							// a. return the index .
	} else {										// else
		fclose(dict_src);// Close file
		printf("\n\nNOT FOUND\n\n");
		return (0);							// b. return -1
	}
	// -------- End of binary search --------
}