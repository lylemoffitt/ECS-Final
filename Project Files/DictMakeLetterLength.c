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
	FILE * dict_src;
	char word[20]={};
	int i=1;
	char filename[10]={};
	char letter;
	
	// -- Used to form letter-length lists --
	dict_src=fopen("sowpods.txt","r");
	if (dict_src==0)
    {
		printf("Input file not found.\n");
		return(0);
    }
	 
	for (letter = 'a'; letter<='z'; letter++)
	{
		for (i=2; i<=15; i++)
		{
			sprintf(filename,"%c%d.txt",letter,i);
			outfile = fopen(filename,"w");
			while (fscanf(dict_src,"%s",word)!=EOF)
			{
				if (word[0] == letter)
				{
					if (strlen(word) == i)
					{
						fprintf(outfile,"%s\n", word);
					}
				} else if (word[0] > letter)
				{
					rewind(dict_src);
					break;
				}
			}
			fclose(outfile);
		}
	}
	fclose(dict_src);
	
	
		return(0);
}




