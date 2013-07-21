/*
 *  DictionarySort.c
 *  Project Files
 *
 *  Created by Lyle Moffitt on 4/25/13.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

// GOAL: Sort and organize the dictionary into easily accessable files.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main ()
{
	FILE * dict_src;
	int abet[26]={};
	int length[26][20]={};
	char word[20]={};
	int i=1,j,k;
	char letter;
	int common[26][20]={};
	char temp[16]={};
	int scale;
	int dist[5]={};
	
	
	dict_src=fopen("sowpods.txt","r");
	if (dict_src==0)
    {
		printf("Input file not found.\n");
		return(0);
    }

	
	while (fscanf(dict_src,"%s",word)!=EOF)
    {
		letter = word[0];
		length[ (int) letter -97 ][ strlen(word) ]++;
		abet[ (int) letter - 97 ]++;
		while (word[i]!='\0')	
		{
			if (word[i]==temp[i]){
				common[(int) letter -97 ][i]++;
				i++;
			} else {
				i=1;
				break;
			}
		}
		strcpy(temp,word);
    }

	fclose(dict_src);
	
	/*
	for (i=0; i<26; i++) // Print concurrency histogram
	{
		scale = 250;
		printf("\n\n -NUMBER- | SAME |  GRAPH of Lexical Concurrency For the Letter: %c",(char)(97+i)); 
		printf("\n          |      |%10c = %d words",'@',scale);
		for (j=0; j<20; j++)
		{
			printf(   "\n%8d  |  %2d  |",common[(int) letter -97 ][j],j,'|');
			for (k=0; k<common[i][j]; k+=scale)
			{
				printf("%c",']');
				//if ((k%10000==0) && k>0) {	printf("\n%12c",'|');	}
			}
		}
	}
	*/
	
	printf("\n\n -NUMBER-  |      GRAPH of Alliteration Distribution and Frequency"); // Print alphabet histogram
	scale=300;
	printf("\n\n           |%10c = %d words",'@',scale);
	for (j=0; j<26; j++)
	{
		printf("\n%8d%4c",abet[j],'|');
		for (k=0; k<abet[j]; k+=scale)
		{
			printf("%c",(char)(97+j));
			//if ((k%1000==0) && k>0) {	printf("\n%12c",'|');	}
		}
		printf("\n%12c",'|');
	}
	
	
	/*
	for (i=0; i<26; i++) // Print per-letter histograms
	{
		scale = abet[i]/600;
		if (scale==1) {	scale = abet[i]/400;}
		if (scale==0) {	scale = abet[i]/200;}
		printf("\n There are %d words that start with the letter %c.",abet[i],(char)(97+i));
		printf("\n\n -LENGTH-  |%10c = %d words",(char)(97+i),scale);
		for (j=0; j<20; j++)
		{
			printf("\n%6d%6c",j,'|');
			for (k=0; k<length[i][j]; k+=scale)
			{
				printf("%c",(char)(97+i));
			}
			printf("\n%12c",'|');
		}
	}
	*/
	for (i=0; i<26; i++) // Print per-letter histograms
	{
		scale = abet[i]/600;
		if (scale==1) {	scale = abet[i]/400;}
		if (scale==0) {	scale = abet[i]/200;}
		printf("\n There are %d words that start with the letter %c.",abet[i],(char)(97+i));
		printf("\n\n -LENGTH-  |%10c = %d words",(char)(97+i),scale);
		for (j=0; j<20; j++)
		{
			printf("\n%6d%6c",j,'|');
			for (k=0; k<length[i][j]; k+=scale)
			{
				printf("%c",(char)(97+i));
			}
			printf("\n%12c",'|');
		}
	}

	
	return(0);
}




