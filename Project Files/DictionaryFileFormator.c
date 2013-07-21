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
	FILE * outfile;
	FILE * infile;
	FILE * tempfile;
	FILE * dict_src;
	char word[20]={};
	int i=1,j;
	char letter1='a',letter2='a';
	char filename[10]={};
	int director[27]={};

	
	// -- Used to form letter-length lists --
	dict_src=fopen("sowpods.txt","r");
	if (dict_src==0)
    {
		printf("Input file not found.\n");
		return(0);
    }
	
	for (letter1 = 'a'; letter1<='z'; letter1++)
	{
		for (i=2; i<=15; i++)
		{
			sprintf(filename,"%c%d.txt",letter1,i);
			outfile = fopen(filename,"w");
			printf("\nCreating.... \"%s\"",filename);
			rewind(dict_src);
			while (fscanf(dict_src,"%s",word)!=EOF)
			{
				if (word[0] == letter1)
				{
					if (strlen(word) == i)
					{
						fprintf(outfile,"%s\n", word);
					}
				} else if (word[0] > letter1)
				{
					rewind(dict_src);
					break;
				}
			}
			fclose(outfile);
		}
	}
	fclose(dict_src);
	
	
	for (letter1 = 'a'; letter1<='z'; letter1++)
	{
		for (i=2; i<=15; i++)
		{
			memset(director,0,(sizeof(director[0]) * 27 /*The number of indexes*/ ) );
			tempfile= fopen("temp.txt", "w");	// OPEN read file
			sprintf(filename,"%c%d.txt",letter1,i);
			infile = fopen(filename,"r");
			while (fscanf(infile,"%s",word)!=EOF)
			{
				fprintf(tempfile,"%s\n", word); // Copy to temp file
				director[ (int)word[1] - 97 ]++;
				director[26]++;
			}
			
			fclose(infile);						// Close the dictionary
			fclose(tempfile);
			tempfile= fopen("temp.txt", "r");
			outfile = fopen(filename,"w");
			for (j=0;j<=26; j++) {
				fprintf(outfile,"%d  ", director[j]);
			}
			fprintf(outfile,"\n");
			while (fscanf(tempfile,"%s",word)!=EOF) // Read back to original
			{
				fprintf(outfile,"%s\n", word);
			}
			fclose(tempfile);
			fclose(outfile);
			
		}
	}

	fclose(infile);
	

		return(0);
}




